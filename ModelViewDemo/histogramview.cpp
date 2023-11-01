#include "histogramview.h"
#include <QPainter>
HistogramView::HistogramView(QWidget *parent):QAbstractItemView(parent){

}



void HistogramView::paintEvent(QPaintEvent *){
    QPainter painter(viewport());
    painter.setPen(Qt::black);
    int x0=40;
    int y0=250;
    //完成了 坐标轴的绘制，并标注坐标轴的变量＊／
    //y 坐标轴
    painter.drawLine(x0,y0,40,30);
    //画箭头
    painter.drawLine(38,32,40,30);
    painter.drawLine(40,30,42,32);
    painter.drawText (20,30,tr(" 人数")) ;
    for(int i=1;i<5;i++)
    {
        painter.drawLine (x0-1,i*50, x0+1,i*50);
            // (a)
        painter. drawText (x0-20, y0-i*50, tr("%1").arg (i * 5)) ;
    }
    //x 坐标轴
    painter.drawLine (x0, y0, 540,250);
    painter.drawLine(538,248,540,250);
    painter.drawLine(540,250,538,252);
    painter.drawText(545,250,tr(" 部门")) ;
    int posD=x0+20;
    int row;
    //绘制坐标轴变量
    for (row=0; row<model()->rowCount(rootIndex());row++) {
    QModelIndex index=model () ->index (row, 0, rootIndex ());
    QString dep=model()->data(index).toString();
    painter.drawText (posD,y0+20,dep);
    posD+=50;
    }
    //完成了表格第 列数据的柱状统计图的绘制＊／
    //男
    int posM=x0+20;
    MRegionList.clear();
    for (row=0; row<model ()->rowCount (rootIndex()); row++){
    QModelIndex index=model()->index(row, 1, rootIndex());
    int male=model()->data(index).toDouble() ;
    int width=10;
    if(selections->isSelected(index))
    painter.setBrush(QBrush(Qt::blue,Qt::Dense3Pattern));
    else
    painter.setBrush(Qt::blue);
    //(b)
    painter.drawRect(QRect(posM,y0-male*10,width,male*10)); //(c)
    QRegion regionM(posM,y0-male*10,width,male*10);
    MRegionList.insert(row,regionM);
    posM+=50;
    }
    //＊完成了表格第 列数据的柱状统计图的绘制＊／
    //／女
    int posF=x0+30;
    FRegionList.clear();
    for(row=0;row<model()->rowCount(rootIndex());row++){
        QModelIndex index=model()->index(row, 2, rootIndex());
        int female=model()->data(index) .toDouble();
        int width=10;
        if(selections->isSelected(index)){
            painter.setBrush(QBrush(Qt::red,Qt::BDiagPattern));
        }
        else{
            painter.setBrush(Qt::red);
        }
        //画矩形
        painter.drawRect (QRect(posF, y0-female*10, width, female*10));
        QRegion regionF(posF,y0-female*10,width,female*10);
        FRegionList.insert(row,regionF);
        posF+=50;
    }
    //／＊完成了表格第 列数据的柱状统计图的绘制＊／
    //／／退休
    int posS=x0+40;
    SRegionList.clear();
    for (row=0; row<model () ->rowCount (rootIndex()) ; row++){
        QModelIndex index=model () ->index (row, 3, rootIndex ());
        int retire=model() ->data (index).toDouble();
        int width=10;
        if(selections->isSelected(index))
        painter.setBrush(QBrush(Qt::green,Qt::Dense3Pattern));
        else
        painter.setBrush(Qt::green);
        painter.drawRect(QRect(posS,y0-retire*10,width,retire*10));
        QRegion regionS(posS,y0-retire*10,width,retire*10);
        SRegionList.insert(row,regionS);
        posS+=50;
    }
}

void HistogramView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight){
    QAbstractItemView::dataChanged( topLeft,bottomRight);
    viewport()->update();
}

void HistogramView::setSelectionModel(QItemSelectionModel *selectionModel){
    selections=selectionModel;
}


void HistogramView::selectionChanged(const QItemSelection &selected,
                                     const QItemSelection &deselected){
    viewport ()->update();
}


void HistogramView::mousePressEvent(QMouseEvent *event){
    QAbstractItemView::mousePressEvent(event);
    setSelection(QRect(event->pos().x(),event->pos().y(),1,1),QItemSelectionModel::SelectCurrent);
}

void HistogramView::setSelection(const QRect &rect,QItemSelectionModel:: SelectionFlags flags){
    int rows= model()->rowCount(rootIndex()); //获取总行数
    int columns = model() ->columnCount (rootIndex ()); //获取总列数
    QModelIndex selectedindex;
    for (int row=0; row<rows; ++row) {
        for(int column=1; column<columns; ++column){
            QModelIndex index=model () ->index (row, column, rootIndex ());
            QRegion region=itemRegion (index); // (c)
            //判断鼠标点击范围与哪个条形有交集
            if (!region.intersected(rect).isEmpty())
            selectedindex =index;
        }
    }
    if (selectedindex.isValid ())
    selections->select(selectedindex,flags);
    else
    {
        QModelIndex noindex;
        selections->select(noindex,flags);
    }
}

QModelIndex HistogramView::indexAt(const QPoint &point)const{
    QPoint newPoint(point.x(),point.y());
    QRegion region;
    //男列
    foreach(region,MRegionList){
        if(region.contains(newPoint)){
            int row= MRegionList.indexOf(region);
            // (a)
            QModelIndex index = model ()->index (row, 1, rootIndex ());
            return index;
        }
    }
    //女
    foreach(region,FRegionList){
      if(region.contains(newPoint)){
          int row= FRegionList.indexOf(region);
          QModelIndex index = model() ->index (row, 2, rootIndex ());
          return index;
      }
    }
    //合计列
    foreach(region,SRegionList){
        if(region.contains(newPoint)){
            int row= SRegionList.indexOf(region);
            QModelIndex index = model ()->index (row, 3, rootIndex ());
            return index;
        }
    }
    return QModelIndex();
}


QRect HistogramView::visualRect(const QModelIndex &index) const{}
void HistogramView::scrollTo(const QModelIndex &index, ScrollHint hint) {}
QModelIndex HistogramView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers){}
int HistogramView::horizontalOffset () const{}
int HistogramView::verticalOffset() const {}
bool HistogramView::isIndexHidden(const QModelIndex &index) const{}
QRegion HistogramView::visualRegionForSelection (const QItemSelection &selection)  const{}


QRegion HistogramView::itemRegion(QModelIndex index){
    QRegion region;
    if(index.column() == 1) //男
    region= MRegionList[index.row()];
    if(index.column() == 2) //女
    region = FRegionList[index.row()];
    if (index.column() == 3) //退休
    region = SRegionList [index. row()];
    return region;
}
