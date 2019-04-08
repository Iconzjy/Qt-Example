#ifndef ADDRESSWIDGET_H
#define ADDRESSWIDGET_H

#include "newaddrestab.h"
#include "tablemodel.h"

#include <QItemSelection>
#include <QTableWidget>

class QSortFilterProxyModel;
class QItemSelectionModel;

class AddressWidget : public QTabWidget
{
    Q_OBJECT
public:
    AddressWidget(QWidget *parent = nullptr);
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);

public slots:
    void showAddEntryDialog();
    void addEntry(QString name, QString address);
    void editEntry();
    void removeEntry();

signals:
    void selectionChanged(const QItemSelection &selected);

private:
    void setupTabs();

    TableModel *table;
    NewAddresTab *newAddressTab;
    QSortFilterProxyModel *proxyModel;

};

#endif // ADDRESSWIDGET_H
