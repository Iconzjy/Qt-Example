#ifndef DBSTRUCT_H
#define DBSTRUCT_H
/*输入路径，读取整个数据库的内容*/
#include <QVector>
#include <QVariant>
#include "personalinformation.h"
#include "warningdlg.h"
#include <QStringList>
class QString;
class QVariant;
class DBStruct : public QObject
{
    Q_OBJECT
public:

    explicit DBStruct(const QString& path);
    explicit DBStruct(QString&& path);
    QMap<int,PersonalInformation *>* getPersonalDate();//返回所有人的数据,注：由于之前传递的是副本，在MainWindow类中改变不了值，所以就传个指针
    QStringList getProperty()const;//获取属性名

private:
    bool connectToDB(const QString& path);

signals:
    void getDBPropertyName(QVariant[]); //返回数据库属性名的QVariant数组
    void sendErrorMessage(const QString);//发送错误信息情况

public slots:

private:
    QMap<int,PersonalInformation*> allPersonInDB;//用来存储数据库所有人的信息
    PersonalInformation* propertyName;//用来存储属性名

    QString data1=QObject::tr("ID");
    QString data2=QObject::tr("人员类别");
    QString data3=QObject::tr("姓名");
    QString data4=QObject::tr("班级");
    QString data5=QObject::tr("性别");
    QString data6=QObject::tr("民族");
    QString data7=QObject::tr("身份证号");
    QString data8=QObject::tr("联系方式");
    QString data9=QObject::tr("籍贯");
    QString data10=QObject::tr("家庭住址");
    QString data11=QObject::tr("出生年月日");
    QString data12=QObject::tr("入学时间");
    QString data13=QObject::tr("同申请人谈话时间");
    QString data14=QObject::tr("申请入党时间");
    QString data15=QObject::tr("入团时间");
    QString data16=QObject::tr("团支部推优时间");
    QString data17=QObject::tr("辅导员推荐时间");
    QString data18=QObject::tr("团委推荐时间");
    QString data19=QObject::tr("列为积极分子时间_支委会");
    QString data20=QObject::tr("列为积极分子时间_基层备案");
    QString data21=QObject::tr("培养联系人1");
    QString data22=QObject::tr("培养联系人2");
    QString data23=QObject::tr("更换后培养联系人");
    QString data24=QObject::tr("更换后培养联系人2");
    QString data25=QObject::tr("思想汇报篇数");
    QString data26=QObject::tr("党课结业日期");
    QString data27=QObject::tr("自传时间");
    QString data28=QObject::tr("培养联系人··列··时间");
    QString data29=QObject::tr("党小组··列··时间");
    QString data30=QObject::tr("征求党内外党员人数");
    QString data31=QObject::tr("群众人数");
    QString data32=QObject::tr("支委会讨论确定时间");
    QString data33=QObject::tr("基层党委备案时间（发展对象）");
    QString data34=QObject::tr("函调时间");
    QString data35=QObject::tr("政审时间");
    QString data36=QObject::tr("基层党委预审意见时间");
    QString data37=QObject::tr("支部大会讨论接收申请人为预备党员会议时间");
    QString data38=QObject::tr("入党介绍人1");
    QString data39=QObject::tr("入党介绍人2");
    QString data40=QObject::tr("基层党委审批意见");
    QString data41=QObject::tr("预备党员思想汇报篇数");
    QString data42=QObject::tr("转正申请书时间");
    QString data43=QObject::tr("支部大会通过预备党员能否转为正式党员的会议时间");
    QString data44=QObject::tr("基层党委审批时间");
};

#endif // DBSTRUCT_H
