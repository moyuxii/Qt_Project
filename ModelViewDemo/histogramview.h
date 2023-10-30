#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>
#include <QMouseEvent>
class HistogramView:public QAbstractItemView
{
    Q_OBJECT
public:
    HistogramView(QWidget *parent=nullptr);
    // QWidget interface
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    QRegion itemRegion(QModelIndex index);
    // QAbstractItemView interface
    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint= EnsureVisible);
    QModelIndex indexAt(const QPoint &point) const;
    void setSelectionModel(QItemSelectionModel *selectionModel);
    bool isIndexHidden(const QModelIndex &index) const;

protected slots:
    void selectionChanged(const QItemSelection &selected,
    const QItemSelection &deselected);
    void dataChanged(const QModelIndex &topLeft,const QModelIndex &bottomRight);

protected:
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,
    Qt::KeyboardModifiers modifiers);
    int horizontalOffset()const;
    int verticalOffset () const;
    void setSelection (const QRect &rect, QItemSelectionModel:: SelectionFlags flags);
    // (f)
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
private:
    QItemSelectionModel *selections;
    QList<QRegion> MRegionList;
    QList<QRegion> FRegionList;
    QList<QRegion> SRegionList;
};

#endif // HISTOGRAMVIEW_H
