#include "datedelegate.h"
#include <QDateTimeEdit>
DateDelegate::DateDelegate(QWidget *parent):QItemDelegate(parent)
{

}

QWidget* DateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    QDateTimeEdit   *editor = new QDateTimeEdit(parent);
    editor->setDisplayFormat("yyyy-MM-dd");
    editor->setCalendarPopup(true);
    editor->installEventFilter(const_cast<DateDelegate*>(this));
    return editor;
}

void DateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString dateStr= index.model()->data(index).toString (); // (a)
    QDate date = QDate::fromString (dateStr,Qt::ISODate); // (b)
    QDateTimeEdit *edit=static_cast<QDateTimeEdit*>(editor);//(c)
    edit->setDate (date);
}

void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *edit=static_cast<QDateTimeEdit*> (editor); //(a)
    QDate date = edit->date (); // (b)
    model->setData(index,QVariant(date.toString(Qt::ISODate)));
}

void DateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}




