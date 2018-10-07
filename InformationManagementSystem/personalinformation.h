#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H

/**************************************************************************
*如果需要修改属性的顺序，只需要修改changeStringToIndex（）函数
**************************************************************************/

#include <QVariant>
#include <QList>
#include "warningdlg.h"

struct propertyValue
{
    QVariant data[44];//分别记录每个人各属性值
    int returnSize() const;//返回数组大小，即44
};

class QDate;
class PersonalInformation : public QObject
{
    Q_OBJECT
public:
    explicit PersonalInformation(QVariant allInformation[]);   
    bool operator == (const PersonalInformation& other);//判断ID（学号），姓名是否重复
    bool operator == (const PersonalInformation&& other);
    int returnIndex(const QString& propertyName);//返回此人（this）属性下标值，即索引值,等价于changeStringToIndex()函数
    QString returnID(); //返回当下的姓名
    QString returnType();//返回当下人员类别
    const QVariant& getPropertyValue(const QString& property);//返回当下此人（this）的某属性的值
    const QVariant& at(const int i);//返回此人的某属性值，下标索引

              /*主要用于特定情况下特定人员的判断*/
    /************************************************************************************/
    bool moreThanEighteenYears();//判断是否年满十八
    bool moreThanSixMonthes();//判断是否满6个月(申请入党to积极分子）
    bool moreThanOneYear();//判断是否满1年（积极分子to发展对象）
    bool moreThanOneMonth();//判断是否超过1个月（申请入党to同申请人谈话时间）
    bool isTakeOrder();//判断是否按照顺序进行,针对正式党员
    bool returnThoughtReport();//返回思想汇报是否满足条件
    /************************************************************************************/

        /*主要用于返回各属性的值（按照他们原本的应该有的数据类型返回）*/
    /***********************************************************************************/
    QDate returnDate(const QString& propertyName);//以Date数据类型返回
    int returnInt(const QString& propertyName);//以int数据类型返回
    QString returnString(const QString& propertyName);//以QString数据类型返回
    /***********************************************************************************/


signals:
    void equalType(QString);//返回ID（学号）或姓名重复
    void errorMessage(QString);//返回错误信息

private:
    int subDate(const QDate& date1, const QDate& date2) const;//日期相减
    int changeStringToIndex(const QString& propertyName);//将搜索的属性列表名称转化为内部的索引下标值

private:
    propertyValue personValue;
};

#endif // PERSONALINFORMATION_H
