#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H
#include <QWidget>

class QLabel;
class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = nullptr);

signals:

public slots:
    void timeChange();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *label;
};

#endif // ANALOGCLOCK_H
