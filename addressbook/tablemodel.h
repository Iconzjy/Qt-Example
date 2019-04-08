#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>

//使用结构体将姓名和地址进行捆绑
struct Contact
{
    QString name;
    QString address;

    bool operator == (const Contact &other) const
    {
        return name == other.name && address == other.name;
    }
};


//在addressWidget.cpp中的文件读取与写入中使用
inline QDataStream &operator << (QDataStream &stream,const Contact &contact)
{
    return stream << contact.name << contact.address;
}
inline QDataStream &operator >> (QDataStream &stream, Contact &contact)
{
    return stream >> contact.name >> contact.address;
}

//这个需要熟悉模板中的函数接口
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject *parent = nullptr);
    TableModel(QList<Contact> contacts, QObject *parent = nullptr);

    //以下函数都重写QAbstractItemModld的纯虚函数(即实现该函数)
    //Qt助手中可搜索关键字QAbstractItemModel Class查看

    //返回所给parent的children的行（列）数
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    //通过索引（即index）返回存储在所给role的项的存储数据
    QVariant data(const QModelIndex &index,int role) const override;
    //通过具有特定方向的header中给定的role和section返回数据。
    //本函数是标签的实现，即header为标签，section判断为第一列还是第二例，role判断是否为Qt::DisplayRole
    QVariant headerData(int section, Qt::Orientation orientation,int role) const override;
    //通过所给的索引返回项标志
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    //Sets the role data for the item at index to value.
    //设置给定项的索引的值为value。
    bool setData(const QModelIndex &index,const QVariant &value, int role = Qt::EditRole) override;
    //插入和删除行
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QList<Contact> getContacts() const;
private:
    QList<Contact> contacts;
};

#endif // TABLEMODEL_H
