#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addresswidget.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
private slots:
    void updateActions(const QItemSelection &selection);
    void openFile();
    void saveFile();

private:
    void createMenus();
    AddressWidget *addressWidget;
    QMenu *fileMenu;
    QMenu *toolMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *editAct;
    QAction *exitAct;
    QAction *addAct;
    QAction *removeAct;

};

#endif // MAINWINDOW_H
