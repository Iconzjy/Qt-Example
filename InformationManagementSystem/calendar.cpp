#include "calendar.h"
#include <QDialog>
#include <QCalendarWidget>
#include <QDebug>
Calendar::Calendar(QLineEdit *parent)
{
    pointerItem = parent;
    cdialog = new QDialog(parent);
    cdialog->setMinimumSize(280,179);
    cdialog->setWindowTitle(tr("日历"));
    cdialog->move(QCursor::pos());

    calendar = new QCalendarWidget(cdialog);
    calendar->setGridVisible(true);

    connect(calendar, &QCalendarWidget::selectionChanged, this, &Calendar::setEditText);
    QTextCharFormat calendarFormat;
    calendarFormat.setBackground(QColor(200,100,100));
}

void Calendar::setEditText()
{
    pointerItem->setText(calendar->selectedDate().toString("yyyy-MM-dd"));
    showCalendar();
}

void Calendar::showCalendar()
{
    this->cdialog->show();
}
