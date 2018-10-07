#ifndef INFORMATIONLISTITEM_H
#define INFORMATIONLISTITEM_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
class QTreeWidgetItem;
class InformationList : public QWidget
{
    Q_OBJECT
public:
    explicit InformationList(QWidget *parent = nullptr, const QString div = "");
    void newItem(const QString type,const QString name);//初始化每组的Item，即每个人的信息
    QTreeWidgetItem* returnListItemPointer()const;//返回列表指针
private:
    QString deliverName;//用来创建分组的组名
    QTreeWidgetItem* group;
signals:
    QTreeWidgetItem* returnGroup(QTreeWidgetItem*);

public slots:
    void onItemExpanded(QTreeWidgetItem *);
};

#endif // INFORMATIONLISTITEM_H
