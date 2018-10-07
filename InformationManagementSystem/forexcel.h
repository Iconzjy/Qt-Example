#ifndef FOREXCEL_H
#define FOREXCEL_H

#include <QObject>
#include <QList>
#include "personalinformation.h"

class ForExcel : public QObject
{
    Q_OBJECT
public:
    explicit ForExcel(QList<PersonalInformation *>&, QString);
    void creatExcel_type1();//积极分子备案
    void creatExcel_type2();//发展对象备案报告
    void creatExcel_type3();//发展对象预审请示
    void creatExcel_type4();//接收预备党员
    void creatExcel_type5();//预备党员转正

private:
    QList<PersonalInformation *> information;
signals:

public slots:
};

#endif // FOREXCEL_H
