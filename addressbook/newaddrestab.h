#ifndef NEWADDRESTAB_H
#define NEWADDRESTAB_H

#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class NewAddresTab : public QWidget
{
    Q_OBJECT
public:
    explicit NewAddresTab(QWidget *parent = nullptr);

signals:
    void sendDetailes(QString name, QString address);

public slots:
    void addEntry();

private:
    QLabel *descriptionLabel;
    QPushButton *addButton;
    QVBoxLayout *mainLayout;
};

#endif // NEWADDRESTAB_H
