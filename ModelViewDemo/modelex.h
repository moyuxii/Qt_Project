#ifndef MODELEX_H
#define MODELEX_H

#include <QMainWindow>
#include <QAbstractTableModel>

class ModelEx : public QAbstractTableModel
{
    Q_OBJECT

public:
    ModelEx(QWidget *parent = nullptr);

private:
    QVector<short> army;
    QVector<short> weaponType;
    QMap<short,QString> armyMap; //使用 QMap 数据结构保存“数值一文字”的映射
    QMap<short,QString> weaponTypeMap;
    QStringList weapon;
    QStringList header;
    void populateModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};
#endif // MODELEX_H
