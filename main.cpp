#include "analogclock.h"
#include <QApplication>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    AnalogClock analogclock;
    analogclock.show();
    return app.exec ();

}
