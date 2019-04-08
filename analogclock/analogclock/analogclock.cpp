#include "analogclock.h"
//#include <QtWidgets>  此头文件包含下面各头文件
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include <QBoxLayout>
AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent)
{
    //计时器timer
    QTimer *timer = new QTimer(this);
    //timeout() 是QTimer中的一个私有非静态函数，不能由用户自己发出
    connect (timer, SIGNAL(timeout()), this, SLOT(update()));
    connect (timer, SIGNAL(timeout()), this, SLOT(timeChange()));
    //启动或重新启动计时器，函数参数单位为毫秒，
    timer->start(1000);

    setWindowTitle (tr("Analog Clock"));
    resize (400,200);

    //获取当前时间
    QTime time = QTime::currentTime();
    //设置label的布局
    QVBoxLayout* layout=new QVBoxLayout;
    QString text = time.toString ();
    label = new QLabel();
    label->setText (text);
    layout->addWidget (label);
    layout->setAlignment (label,Qt::AlignVCenter);
    this->setLayout (layout);

}

void AnalogClock::timeChange()
{
    QTime time = QTime::currentTime();
    QString text = time.toString ();
    label->setText (text);
}

void AnalogClock::paintEvent(QPaintEvent* /*event*/)
{
    //设置指针大小
    //时针
    static const QPoint hourHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-40)
    };
    //分针
    static const QPoint minuteHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-70)
    };
    //秒针
    static const QPoint secondHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-100)
    };

    //改变指针的颜色
    QColor hourColor(127,0,127);
    QColor minuteColor(0,127,127,191);
    QColor secondColor(0,0,100);

    //qMin返回两个参数的最小值
    //width和height为主窗口的边长
    int side = qMin(width(), height());
    //获取当前时间
    QTime time = QTime::currentTime();

    QPainter painter(this);
    //如果为 true, 则在painter上设置给定的渲染提示;否则清除渲染提示。
    painter.setRenderHint (QPainter::Antialiasing);
    //将给定的偏移量转化为坐标系（就是以窗口中心点为坐标系原点）
    painter.translate (width()/2, height () / 2);
    //按比例缩放坐标，在本例题中有没有都没差
    painter.scale (side /200.0, side / 200.0);

    /*时针的运动设置*/
    painter.setPen (Qt::NoPen);//没有边界线
    painter.setBrush (hourColor);//设置颜色
    painter.save ();
    //顺时针旋转坐标系。给定的角度参数以度为单位
    //time.hour() + time.minute () / 60.0  转化为小时
    //每小时角度为30度
    painter.rotate (30.0*((time.hour() + time.minute () / 60.0)));
    //绘制多边形
    painter.drawConvexPolygon (hourHand, 3);
    painter.restore ();
    painter.setPen (hourColor);

    //画时钟边界上每5小格的刻度线,设置数字
    for(int i = 0; i < 12; ++i){
        painter.drawLine (0,88,0,96);
        painter.rotate(30.0);
        painter.drawText(-3,-80,tr("%1").arg(i+1));
    }

    /*分针的运动设置*/
    painter.setPen (Qt::NoPen);
    painter.setBrush (minuteColor);
    painter.save();
    painter.rotate (6.0 * (time.minute () + time.second () /60.0));
    painter.drawConvexPolygon (minuteHand,3);
    painter.restore ();
    painter.setPen (minuteColor);

    //画时钟边界上每小格的刻度线且不为5整除
    for(int j = 0; j < 60; ++j){
        if((j%5) != 0)
            painter.drawLine (92,0,96,0);
        painter.rotate (6.0);
    }

    /*秒针的运动设置*/
    painter.setPen (Qt::NoPen);
    painter.setBrush (secondColor);
    painter.save ();
    painter.rotate (6.0 * time.second ());
    painter.drawConvexPolygon (secondHand,3);
    painter.restore ();


}
