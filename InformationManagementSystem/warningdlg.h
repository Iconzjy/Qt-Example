#ifndef WARNINGDLG_H
#define WARNINGDLG_H

#include <QWidget>

class QLabel;
class QBoxLayout;
class QPushButton;

class WarningDlg : public QWidget
{
    Q_OBJECT
public:
    explicit WarningDlg();

signals:

public slots:
    static void getErrorMessage(QString);

private:
};

#endif // WARNINGDLG_H
