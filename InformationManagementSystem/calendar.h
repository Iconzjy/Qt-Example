#ifndef CALENDAR_H
#define CALENDAR_H

#include <QLineEdit>
#include <QDate>
class QDialog;
class QCalendarWidget;
class Calendar : public QObject
{
    Q_OBJECT
public:
    explicit Calendar(QLineEdit* parent);
public slots:
    void setEditText();
    void showCalendar();
signals:

private:
    QString date;
    QDialog* cdialog;
    QCalendarWidget* calendar;
    QLineEdit* pointerItem;
};

#endif // CALENDAR_H
