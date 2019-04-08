#include "tablemodel.h"


TableModel::TableModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

TableModel::TableModel(QList<Contact> contacts, QObject *parent)
    :QAbstractTableModel (parent),contacts(contacts)
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    //指示编译器，具有指定名称的参数不在函数体中使用。这可以用来抑制编译器警告，同时允许在函数签名中使用有意义的参数名定义函数。
    Q_UNUSED (parent);
    return contacts.size ();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED (parent);
    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid ())
        return QVariant();
    if(index.row() >= contacts.size () || index.row() <0)
        return QVariant();
    if(role == Qt::DisplayRole){
        const auto &contact = contacts.at(index.row ());

        if(index.column () == 0)
            return contact.name;
        else if(index.column () == 1)
            return  contact.address;
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Address");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid ())
        return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags (index)|Qt::ItemIsEditable;
}


bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //这个函数插入值都是在首行插入的
    if(index.isValid () && role == Qt::EditRole){
        int row = index.row();
        auto contact = contacts.value (row);

        if(index.column () == 0)
            contact.name = value.toString ();
        else if(index.column () == 1)
            contact.address = value.toString ();
        else
            return false;
        contacts.replace (row, contact);
        emit(dataChanged (index, index));

        return true;
    }
    return false;
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED (index);
    beginInsertRows(QModelIndex(), position, position +rows -1);
    for(int row = 0; row < rows; row++)
        contacts.insert(position, {QString(),QString() });
    endInsertRows ();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED (index);
    beginRemoveRows(QModelIndex(), position, position + rows -1);
    for(int row = 0; row < rows; ++row)
        contacts.removeAt (position);
    endRemoveRows ();
    return true;
}

QList<Contact> TableModel::getContacts() const
{
    return contacts;
}

