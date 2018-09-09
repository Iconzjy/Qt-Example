#include "addresswidget.h"
#include "adddialog.h"

#include <QtWidgets>

AddressWidget::AddressWidget(QWidget *parent)
    :QTabWidget (parent)
{
    table = new TableModel(this);
    newAddressTab = new NewAddresTab(this);
    //接收到创建新信息的信号后，槽为addEntry，判断是否存在相同名称的信息（信号与槽之间的参数接收）
    connect(newAddressTab, &NewAddresTab::sendDetailes,
            this, &AddressWidget::addEntry);
    addTab (newAddressTab, "Address Book");
    setupTabs ();
}

void AddressWidget::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open (QIODevice::ReadOnly)){
        QMessageBox::information (this, tr("Unable to open file"),
                                  file.errorString ());
        return;
    }

    QList<Contact> contacts;
    QDataStream in(&file);
    in >> contacts;

    if(contacts.isEmpty ()){
        QMessageBox::information(this,tr("No contacts in file"),
                                 tr("The file are attempting to open contains no contacts."));
    }else{//判断是否有重复的，若无则输入到表格中
        for(const auto &contact: qAsConst(contacts))
            addEntry (contact.name, contact.address);
    }
}

void AddressWidget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::information (this,tr("Unable to open file"),file.errorString ());
        return;
    }

    QDataStream out(&file);
    out << table->getContacts ();
}

void AddressWidget::showAddEntryDialog()
{
    AddDialog aDialog;
    if(aDialog.exec ()){
        QString name = aDialog.nameText->text ();
        QString address = aDialog.addressText->toPlainText ();

        addEntry(name, address);
    }
}

void AddressWidget::addEntry(QString name, QString address)
{
    if(!table->getContacts ().contains ({name, address})){
        table->insertRows (0, 1, QModelIndex());

        QModelIndex index = table->index (0,0,QModelIndex());
        table->setData (index, name, Qt::EditRole);
        index = table->index (0, 1, QModelIndex());
        table->setData (index, address, Qt::EditRole);
        removeTab (indexOf(newAddressTab));
    }else{
        QMessageBox::information (this, tr("Duplicate Name"),
                                  tr("The name \'%1\" already exists.").arg(name));
    }
}

void AddressWidget::editEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model ());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows ();
    QString name;
    QString address;
    int row = -1;

    foreach(QModelIndex index, indexes){
        row = proxy->mapToSource (index).row();
        QModelIndex nameIndex = table->index (row, 0 ,QModelIndex());
        QVariant varName = table->data (nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex addressIndex = table->index (row, 1 ,QModelIndex());
        QVariant varAddr = table->data (addressIndex, Qt::DisplayRole);
        address = varAddr.toString();
    }

    AddDialog aDialog;
    aDialog.setWindowTitle (tr("Edit a Contact"));

    aDialog.nameText->setReadOnly (true);
    aDialog.nameText->setText (name);
    aDialog.addressText->setText (address);

    if(aDialog.exec()){
        QString newAddress = aDialog.addressText->toPlainText ();
        if(newAddress != address){
            QModelIndex index = table->index (row, 1, QModelIndex());
            table->setData (index, newAddress,Qt::EditRole);
        }
    }
}

void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget ());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model ());
    QItemSelectionModel *selectionModel = temp->selectionModel ();

    QModelIndexList indexes = selectionModel->selectedRows ();

    foreach(QModelIndex index, indexes){
        int row = proxy->mapToSource (index).row();
        table->removeRows (row, 1, QModelIndex());
    }

    if(table->rowCount (QModelIndex()) == 0){
            insertTab (0, newAddressTab, "Address Book");
    }
}


//setupTabs()函数用于在AddressWidget中设置9个字母组选项卡、表视图和代理模型。
//每个代理模型依次设置为使用不区分大小写的QRegExp对象根据相关字母表组过滤联系人姓名。表视图也使用相应的代理模型的sort()函数按升序排序
void AddressWidget::setupTabs()
{
    QStringList groups;
    groups << "ABC" << "DEF" << "GHI" << "JKL" << "MNO"
           << "PQR" << "STU" << "VW" << "XYZ";
    for(int i = 0; i < groups.size (); ++i ){
        QString str = groups.at(i);
        QString regExp = QString("^[%1].*").arg(str);//正则表达式

        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel (table);
        proxyModel->setFilterRegExp (QRegExp(regExp, Qt::CaseInsensitive));
        proxyModel->setFilterKeyColumn (0);

        //每个QTableView对象都会自动被赋予一个QItemSelectionModel特性，用来跟踪所选索引。
        QTableView *tableView = new QTableView;
        tableView->setModel (proxyModel);

        //设置选中行
        tableView->setSelectionBehavior (QAbstractItemView::SelectRows);
        tableView->horizontalHeader ()->setStretchLastSection (true);
        tableView->verticalHeader ()->hide ();
        //设置文本不能编辑
        tableView->setEditTriggers (QAbstractItemView::NoEditTriggers);
        //单行选中
        tableView->setSelectionMode (QAbstractItemView::SingleSelection);

        tableView->setSortingEnabled (true);

        //发射信号，如果选中tableView并且改变，会发射一个信号并由selectionChange这个槽接收
        connect(tableView->selectionModel (),&QItemSelectionModel::selectionChanged,
                this, &AddressWidget::selectionChanged);
        //lambada表达式，语法：[函数对象参数](函数参数) mutable或exception声明 -> 返回值类型{函数体}
        //
        connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex){
            auto* tableView = qobject_cast<QTableView*>(widget(tabIndex));
            if(tableView)
                emit selectionChanged(tableView->selectionModel ()->selection ());
        });

        addTab(tableView, str);

    }
}
