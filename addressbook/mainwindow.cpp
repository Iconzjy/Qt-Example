#include "mainwindow.h"

#include <QAction>
#include <QFileDialog>
#include <QMenuBar>

MainWindow::MainWindow()
{
    //主窗口的实现在AddressWidget内实现
    addressWidget = new AddressWidget;
    setCentralWidget (addressWidget);
    createMenus ();
    setWindowTitle (tr("Address Book"));
}

void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes ();

    //判断内容是否为空，若不为空可编辑，否则不能
    if(!indexes.isEmpty ()){
        removeAct->setEnabled (true);
        editAct->setEnabled (true);
    }else{
        removeAct->setEnabled (false);
        editAct->setEnabled (false);
    }
}

//实现打开文件的按钮功能
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName (this);
    if(!fileName.isEmpty ())
        addressWidget->readFromFile (fileName);
}

//保存文件按钮功能
void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName (this);
    if(!fileName.isEmpty ())
        addressWidget->writeToFile (fileName);
}

//按钮的创建
void MainWindow::createMenus()
{
    fileMenu = menuBar ()->addMenu (tr("&File"));

    openAct = new QAction(tr("&Open..."),this);
    fileMenu->addAction (openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    saveAct = new QAction(tr("&Save As..."),this);
    fileMenu->addAction (saveAct);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);

    fileMenu->addSeparator ();

    exitAct = new QAction(tr("&Exit..."),this);
    fileMenu->addAction (exitAct);
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    toolMenu = menuBar ()->addMenu (tr("&Tools"));

    addAct = new QAction(tr("&Add Entry..."),this);
    toolMenu->addAction (addAct);
    connect(addAct, &QAction::triggered, addressWidget, &AddressWidget::showAddEntryDialog);

    editAct = new QAction(tr("&Edit Entry..."),this);
    editAct->setEnabled (false);
    toolMenu->addAction (editAct);
    connect(editAct, &QAction::triggered, addressWidget, &AddressWidget::editEntry);

    toolMenu->addSeparator ();

    removeAct = new QAction(tr("&Remove Entry..."),this);
    removeAct->setEnabled (false);
    toolMenu->addAction (removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);

    connect(addressWidget, &AddressWidget::selectionChanged,
            this, &MainWindow::updateActions);
}
