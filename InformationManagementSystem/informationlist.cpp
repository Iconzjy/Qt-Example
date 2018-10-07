#include "informationlist.h"

#include <QGridLayout>
#include <QAction>
#include <QLineEdit>
#include <QListWidgetItem>

InformationList::InformationList(QWidget *parent, const QString div)
    :QWidget (parent), deliverName(div)
{
//    QLineEdit *groupName = new QLineEdit(this);
//    groupName->setPlaceholderText(deliverName);
//    groupName->hide();

    group = new QTreeWidgetItem();
    group->setData(Qt::UserRole,0);
    group->setSizeHint(QSize(parent->width(),25));
    emit returnGroup(group);
}

void InformationList::newItem(const QString type, const QString name)
{
    QTreeWidgetItem* childItem = new QTreeWidgetItem();
    childItem->setData(Qt::UserRole,1);
    QLabel* label_name = new QLabel(name);
    QLabel* label_type = new QLabel(type);
    QCheckBox* checkBox = new QCheckBox();
    checkBox->setCheckable(true);
    checkBox->setChecked(false);
    label_name->setAlignment(Qt::AlignCenter);
    label_type->setAlignment(Qt::AlignCenter);
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(checkBox,0,0,1,1);
    layout->addWidget(label_name,0,2,1,2);
    layout->addWidget(label_type,0,4,1,2);

}

QTreeWidgetItem *InformationList::returnListItemPointer() const
{
    return group;
}

void InformationList::onItemExpanded(QTreeWidgetItem *pItem)
{

}
