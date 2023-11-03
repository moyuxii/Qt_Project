#include "mainwindow.h"
#include "editdialog.h"
#include <QGridLayout>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QSqlRecord>
#include <QMessageBox>
#include <QtDebug>
extern int uniqueCarid;
extern int uniqueFactoryid;
MainWindow::MainWindow(const QString &factoryTable,
                       const QString &carTable,
                       QFile *carDetails,
                       QWidget *parent)
    :QMainWindow(parent)
{
    file = carDetails;
    readCarData () ; //(a)
    carModel = new QSqlRelationalTableModel(this); //(b)
    carModel->setTable(carTable); //设置模型对应的表名
    carModel->setRelation(2, QSqlRelation(factoryTable, "id", "manufactory")); // 这个表示创建的模型的第二个字段是关联facortyTable的id字段，并取别名为 manufactory
    carModel->setSort(0,Qt::SortOrder::AscendingOrder);//设置排序 升序
    carModel->select();
    factoryModel = new QSqlTableModel(this); //(d)
    factoryModel->setTable(factoryTable);
    factoryModel->select() ;
    QGroupBox *factory = createFactoryGroupBox ();
    QGroupBox *cars= createCarGroupBox();
    QGroupBox *details= createDetailsGroupBox();
    uniqueCarid = carModel->rowCount (); // (a)
    uniqueFactoryid = factoryModel->rowCount();
    QGridLayout *layout= new QGridLayout;
    layout->addWidget(factory, 0, 0);
    layout->addWidget(cars, 1, 0);
    layout->addWidget(details, 0, 1, 2, 1);
    layout->setColumnStretch (1, 1);
    layout->setColumnMinimumWidth(0, 500);
    QWidget *widget= new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    createMenuBar();
    resize (850, 400);
    setWindowTitle(tr("car list")) ;
}

MainWindow::~MainWindow()
{
}

void MainWindow::addCar()
{
    EditDialog *dialog = new EditDialog(carModel,factoryModel,carData,file,this);
    int accepted = dialog->exec();
    if(accepted==1){
        int lastRow = carModel->rowCount()-1;
        carView->selectRow(lastRow);
        carView->scrollToBottom();
        showCarDetails(carModel->index(lastRow,0));
    }
}

void MainWindow::changeFactory(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row()); //_(a)
    QString factoryid = record.value("id") .toString(); //(b)
    carModel->setFilter ("id ='"+ factoryid +"'") ;//等同于sql中的whele，如果当前model连接着数据库，则立即执行select，否则等待下一次select()
    showFactorytProfile(index);
}

void MainWindow::delCar()
{
    QModelIndexList selection= carView->selectionModel()->selectedRows(0);
    if (!selection.empty()){
        QModelIndex idindex = selection.at(0);
        int id = idindex. data().toInt();
        QString name = idindex.sibling(idindex. row(), 1).data().toString () ;
        QString factory = idindex.sibling(idindex. row(), 2).data().toString ();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this, tr(" 删除汽车记录"),
        QString(tr(" 确认删除由 %1 生产的%2吗? ") . arg (factory) . arg(name)) ,QMessageBox::Yes | QMessageBox::No); // (b)
        if (button== QMessageBox::Yes){
            removeCarFromFile(id); //从 XML 文件中删除相关内容
            removeCarFromDatabase(idindex); //从数据库表中删除相关内容
            decreaseCarCount(indexOfFactory(factory));//如果厂商下没有汽车，直接删除厂商
        }
    }else {
        QMessageBox::information (this, tr("删除汽车记录"),tr(" 请选择要删除的记录。")) ;
    }
}

void MainWindow::showCarDetails(QModelIndex index)
{
    QSqlRecord record= carModel->record(index.row()); // (a)
    QString factory= record.value("manufactory") .toString();
    QString name= record.value("name").toString(); //(c)
    QString year= record.value("year") .toString(); // (d)
    QString carId = record. value ("carid").toString () ; //(e)
    qDebug()<<"被选中的车子的ID为"<<carId;
    showFactorytProfile(indexOfFactory(factory)); //(f)
    titleLabel->setText(tr(" 品牌：%1 (%2) ").arg(name).arg(year));
    titleLabel->show();
    QDomNodeList cars = carData.elementsByTagName ("car");
    for(int i = 0; i < cars.count(); i++){
        QDomNode car = cars.item(i);
        if(car.toElement().attribute("id") == carId){
            getAttribList(car.toElement());
            break;
        }
    }
    if (!(attribList->count()== 0)){
        attribList->show ();
    }
}

void MainWindow::showFactorytProfile(QModelIndex index)
{
    QSqlRecord record= factoryModel->record(index.row());//(a)
    QString name= record.value("manufactory").toString () ;// (b)
    int count = carModel->rowCount(); // (c)
    profileLabel->setText(tr("汽车制造商：%1\n产品数 %2").arg(name).arg(count));
    profileLabel->show();
    titleLabel->hide();
    attribList->hide();
}

void MainWindow::decreaseCarCount(QModelIndex index)
{
    int row= index.row();
    int count = carModel->rowCount(); // (a)
    if(count == 0) //(b)
    factoryModel->removeRow(row);
}

void MainWindow::getAttribList(QDomNode car)
{
    attribList->clear();
    QDomNodeList attribs = car.childNodes();
    QDomNode node;
    QString attribNumber;
    for (int j = 0; j < attribs.count(); j++){
        node= attribs.item(j);
        attribNumber = node.toElement() .attribute("number");
        QListWidgetItem *item= new QListWidgetItem(attribList);
        QString showText(attribNumber + ": "+ node.toElement() .text());
        item->setText(tr("%1") .arg(showText));
    }
}

QModelIndex MainWindow::indexOfFactory(const QString &factory)
{
    for(int i = 0; i < factoryModel->rowCount (); i++){
        QSqlRecord record= factoryModel->record(i);
        if(record.value("manufactory") == factory)
        return factoryModel->index(i, 1);
    }
    return QModelIndex();
}

void MainWindow::readCarData()
{
    if (! file->open (QIODevice::ReadOnly)){
        return;
    }
    if (! carData.setContent(file)){ //QDomDocument  setContent 直接解析xml文件，成功返回true，失败返回false
        file->close () ;
        return;
    }
    file->close();
}

void MainWindow::removeCarFromDatabase(QModelIndex index)
{
    carModel->removeRow(index.row());
}

void MainWindow::removeCarFromFile(int id)
{
    QDomNodeList cars= carData.elementsByTagName("car");
    for(int i = 0; i< cars.count(); i++){
        QDomNode node= cars.item(i);
        if(node.toElement() .attribute("id").toInt() == id){
            carData.elementsByTagName("archive").item(0) .removeChild(node);
            break;
        }
    }
}

QGroupBox *MainWindow::createCarGroupBox()
{
    QGroupBox *box= new QGroupBox(tr(" 汽车")) ;
    carView = new QTableView;
    carView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    carView->setSortingEnabled(true);
    carView->setSelectionBehavior(QAbstractItemView::SelectRows);
    carView->setSelectionMode(QAbstractItemView::SingleSelection);
    carView->setShowGrid(true);
    carView->verticalHeader()->hide();
    carView->setAlternatingRowColors(true);
    carView->setModel(carModel);
    connect(carView, SIGNAL(clicked(QModelIndex)), this, SLOT (showCarDetails (QModelIndex)));
    connect(carView, SIGNAL(activated(QModelIndex)), this, SLOT(showCarDetails(QModelIndex)));
    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(carView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createFactoryGroupBox()
{
    factoryView = new QTableView;
    factoryView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //(a)
    factoryView->setSortingEnabled(true);
    factoryView->setSelectionBehavior(QAbstractItemView::SelectRows);
    factoryView->setSelectionMode (QAbstractItemView:: SingleSelection);
    factoryView->setShowGrid(true);
    factoryView->setAlternatingRowColors(true);
    factoryView->setModel(factoryModel);
    connect(factoryView, SIGNAL (clicked(QModelIndex)),this, SLOT(changeFactory(QModelIndex)));
    QGroupBox *box= new QGroupBox(tr(" 汽车制造商")) ;
    QGridLayout *layout= new QGridLayout;
    layout->addWidget(factoryView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createDetailsGroupBox()
{
    QGroupBox *box= new QGroupBox(tr(" 详细信息")) ;
    profileLabel = new QLabel;
    profileLabel->setWordWrap(true);
    profileLabel->setAlignment (Qt::AlignBottom);
    titleLabel = new QLabel;
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignBottom);
    attribList = new QListWidget;
    QGridLayout *layout= new QGridLayout;
    layout->addWidget(profileLabel, 0, 0, 1, 2);
    layout->addWidget(titleLabel, 1, 0, 1, 2);
    layout->addWidget(attribList, 2, 0, 1, 2);
    layout->setRowStretch(2, 1);
    box->setLayout(layout);
    return box;
}

void MainWindow::createMenuBar()
{
    QAction *addAction = new QAction(tr(" 添加"),this);
    QAction *deleteAction = new QAction(tr(" 删除"), this);
    QAction *quitAction = new QAction(tr(" 退出"), this);
    addAction->setShortcut(tr("Ctrl+A"));
    deleteAction->setShortcut(tr("Ctrl+D"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    QMenu *fileMenu = menuBar()->addMenu(tr(" 操作菜单")) ;
    fileMenu->addAction(addAction);
    fileMenu->addAction(deleteAction);
    fileMenu->addSeparator(); //分割线
    fileMenu->addAction (quitAction);
    connect (addAction, SIGNAL (triggered (bool)), this, SLOT (addCar()));
    connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(delCar()));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT (close()));
}

