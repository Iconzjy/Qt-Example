#include "personalinformation.h"
#include <QDate>
#include <QDebug>
PersonalInformation::PersonalInformation(QVariant allInformation[])
{
    connect(this, &PersonalInformation::equalType, this, &WarningDlg::getErrorMessage);
    connect(this, &PersonalInformation::errorMessage, this, &WarningDlg::getErrorMessage);
    for(int i = 0; i < 44; i++)
    {
        personValue.data[i]=allInformation[i];
    }
}

int PersonalInformation::returnIndex(const QString &propertyName)
{
    return changeStringToIndex(propertyName);
}

QString PersonalInformation::returnID()
{
    return this->personValue.data[changeStringToIndex(QObject::tr("姓名"))].toString();
}

QString PersonalInformation::returnType()
{
    return this->personValue.data[changeStringToIndex(QObject::tr("人员类别"))].toString();
}

bool PersonalInformation::returnThoughtReport()
{
    QString type_1 = QObject::tr("积极分子");
    QString type_2 = QObject::tr("预备党员");
    QString type_3 = QObject::tr("正式党员");
    int typeIndex = this->changeStringToIndex(QObject::tr("人员类别"));
    int numberIndex = this->changeStringToIndex(QObject::tr("思想汇报篇数"));//积极分子思想汇报
    int numberIndex1 = this->changeStringToIndex(QObject::tr("预备党员思想汇报篇数"));//党员思想汇报
    QDate currentDate = QDate::currentDate ();

    if(this->personValue.data[typeIndex].toString()== type_1)
    {//返回积极分子的思想汇报是否符合要求
        int number = this->personValue.data[numberIndex].toInt();
        return (number*90) < subDate(currentDate, this->returnDate (QObject::tr("列为积极分子时间_支委会")));
    }else if(this->personValue.data[typeIndex].toString()== type_2){//返回预备党员的思想汇报是否符合要求
        int number = this->personValue.data[numberIndex1].toInt();
        return (number*90) < subDate(currentDate, this->returnDate (QObject::tr("列为积极分子时间_支委会")));
    }else if(this->personValue.data[typeIndex].toString()== type_3){//返回正式党员的思想汇报是否符合要求
        int number = this->personValue.data[numberIndex1].toInt();
        return (number*90) < subDate(currentDate, this->returnDate (QObject::tr("列为积极分子时间_支委会")));
    }else{
        emit errorMessage(QObject::tr("返回思想汇报篇数是否满足要求失败，查看数据是否出错或排查代码"));
        return false;
    }
}

QDate PersonalInformation::returnDate(const QString &propertyName)
{
    int index = changeStringToIndex(propertyName);
    if((index == changeStringToIndex(QObject::tr("出生年月日"))) ||  (index == changeStringToIndex(QObject::tr("入学时间"))) ||
            (index == changeStringToIndex(QObject::tr("同申请人谈话时间"))) ||  (index == changeStringToIndex(QObject::tr("申请入党时间"))) ||
            (index == changeStringToIndex(QObject::tr("入团时间"))) ||  (index == changeStringToIndex(QObject::tr("团支部推优时间"))) ||
            (index == changeStringToIndex(QObject::tr("辅导员推荐时间"))) ||  (index == changeStringToIndex(QObject::tr("团委推荐时间"))) ||
            (index == changeStringToIndex(QObject::tr("列为积极分子时间-支委会"))) ||  (index == changeStringToIndex(QObject::tr("列为积极分子时间-基层备案"))) ||
            (index == changeStringToIndex(QObject::tr("党课结业日期"))) ||  (index == changeStringToIndex(QObject::tr("自传时间"))) ||
            (index == changeStringToIndex(QObject::tr("培养联系人··列··时间"))) ||  (index == changeStringToIndex(QObject::tr("党小组··列··时间"))) ||
            (index == changeStringToIndex(QObject::tr("支委会讨论确定时间"))) ||  (index == changeStringToIndex(QObject::tr("基层党委备案时间（发展对象）"))) ||
            (index == changeStringToIndex(QObject::tr("函调时间"))) ||  (index == changeStringToIndex(QObject::tr("政审时间"))) ||
            (index == changeStringToIndex(QObject::tr("基层党委预审意见时间"))) ||  (index == changeStringToIndex(QObject::tr("支部大会讨论接收申请人为预备党员会议时间"))) ||
            (index == changeStringToIndex(QObject::tr("基层党委审批意见"))) ||  (index == changeStringToIndex(QObject::tr("转正申请书时间"))) ||
            (index == changeStringToIndex(QObject::tr("支部大会通过预备党员能否转为正式党员的会议时间"))) ||  (index == changeStringToIndex(QObject::tr("基层党委审批时间"))) )
    {
        return this->personValue.data[index].toDate ();
    }else{
        emit errorMessage(QObject::tr("该数值不是日期，请调用其它对应的return函数"));
        return QDate();
    }

}

int PersonalInformation::returnInt(const QString &propertyName)
{
    int index = changeStringToIndex(propertyName);
    if((index == changeStringToIndex(QObject::tr("征求党内外党员人数"))) ||  (index == changeStringToIndex(QObject::tr("群众人数"))) ||
            (index == changeStringToIndex(QObject::tr("预备党员思想汇报篇数"))) ||  (index == changeStringToIndex(QObject::tr("思想汇报篇数"))) )
    {
        return this->personValue.data[index].toInt();
    }else{
        emit errorMessage(QObject::tr("该数值不是日期，请调用其它对应的return函数"));
        return -1;
    }
}

QString PersonalInformation::returnString(const QString &propertyName)
{
    int index = changeStringToIndex(propertyName);
    if((index == changeStringToIndex(QObject::tr("ID"))) ||  (index == changeStringToIndex(QObject::tr("姓名"))) ||
            (index == changeStringToIndex(QObject::tr("班级"))) ||  (index == changeStringToIndex(QObject::tr("性别"))) ||
            (index == changeStringToIndex(QObject::tr("民族"))) ||  (index == changeStringToIndex(QObject::tr("身份证号"))) ||
            (index == changeStringToIndex(QObject::tr("联系方式"))) ||  (index == changeStringToIndex(QObject::tr("籍贯"))) ||
            (index == changeStringToIndex(QObject::tr("家庭住址"))) ||  (index == changeStringToIndex(QObject::tr("培养联系人1"))) ||
            (index == changeStringToIndex(QObject::tr("培养联系人2"))) ||  (index == changeStringToIndex(QObject::tr("更换后培养联系人"))) ||
            (index == changeStringToIndex(QObject::tr("更换后培养联系人2"))) ||  (index == changeStringToIndex(QObject::tr("入党介绍人2"))) ||
            (index == changeStringToIndex(QObject::tr("入党介绍人1"))))
    {
        return this->personValue.data[index].toString();
    }else{
        emit errorMessage(QObject::tr("该数值不是字符串，请调用其它对应的return函数"));
        return QString();
    }
}

bool PersonalInformation::operator ==(const PersonalInformation &other)
{
    if(this->personValue.data[0] == other.personValue.data[0])
    {
        emit this->equalType (QObject::tr("ID重复"));
        return true;
    }else if(this->personValue.data[1] == other.personValue.data[1]){
        emit this->equalType (QObject::tr("姓名重复"));
        return true;
    }else{
        return false;
    }
}

bool PersonalInformation::operator ==(const PersonalInformation &&other)
{

    if(this->personValue.data[0] == std::move(other.personValue.data[0]))
    {
        emit this->equalType (QObject::tr("ID重复"));
        return true;
    }else if(this->personValue.data[1] == std::move(other.personValue.data[1])){
        emit this->equalType (QObject::tr("姓名重复"));
        return true;
    }else{
        return false;
    }
}

bool PersonalInformation::moreThanEighteenYears()
{
    int index_1 = changeStringToIndex(QObject::tr("出生年月日")); //出生日期的索引值
    int index_2 = changeStringToIndex(QObject::tr("申请入党时间"));//申请入党时间索引值
    return (366*18) > subDate(this->personValue.data[index_1].toDate (), this->personValue.data[index_2].toDate ());
}

bool PersonalInformation::moreThanSixMonthes()
{
    int index_1 = changeStringToIndex(QObject::tr("列为积极分子时间_支委会")); //列为积极分子时间_支委会的索引值
    int index_2 = changeStringToIndex(QObject::tr("申请入党时间"));//申请入党时间索引值
    return (366/2) > subDate(this->personValue.data[index_1].toDate (), this->personValue.data[index_2].toDate ());
}

bool PersonalInformation::moreThanOneYear()
{
    int index_1 = changeStringToIndex(QObject::tr("列为积极分子时间_支委会")); //列为积极分子时间_支委会的索引值
    int index_2 = changeStringToIndex(QObject::tr("基层党委备案时间（发展对象）"));//基层党委备案时间（发展对象）时间索引值
    return 366 > subDate(this->personValue.data[index_1].toDate (), this->personValue.data[index_2].toDate ());
}

bool PersonalInformation::moreThanOneMonth()
{
    int index_1 = changeStringToIndex(QObject::tr("同申请人谈话时间")); //同申请人谈话时间的索引值
    int index_2 = changeStringToIndex(QObject::tr("申请入党时间"));//申请入党时间索引值
    return 31 > subDate(this->personValue.data[index_1].toDate (), this->personValue.data[index_2].toDate ());
}

bool PersonalInformation::isTakeOrder()
{
    return (this->personValue.data[changeStringToIndex(QObject::tr("申请入党时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("同申请人谈话时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("同申请人谈话时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("团支部推优时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("团支部推优时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("列为积极分子时间-支委会"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("列为积极分子时间-支委会"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("列为积极分子时间-基层备案"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("列为积极分子时间-基层备案"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("自传时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("自传时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("培养联系人··列··时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("培养联系人··列··时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("党小组··列··时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("党小组··列··时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("支委会讨论确定时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("支委会讨论确定时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("基层党委备案时间（发展对象）"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("基层党委备案时间（发展对象）"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("函调时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("函调时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("基层党委预审意见时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("基层党委预审意见时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("支部大会讨论接收申请人为预备党员会议时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("支部大会讨论接收申请人为预备党员会议时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("基层党委审批意见"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("基层党委审批意见"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("转正申请书时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("转正申请书时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("支部大会通过预备党员能否转为正式党员的会议时间"))].toDate())&&
            (this->personValue.data[changeStringToIndex(QObject::tr("支部大会通过预备党员能否转为正式党员的会议时间"))].toDate() <= this->personValue.data[changeStringToIndex(QObject::tr("基层党委审批时间"))].toDate());
}

int PersonalInformation::subDate(const QDate &date1, const QDate &date2) const
{
    return qAbs(std::move(date1.daysTo(date2)));
}

int PersonalInformation::changeStringToIndex(const QString &propertyName)
{
    if(propertyName == QObject::tr("ID")){
        return 0;
    }else if(propertyName == QObject::tr("人员类别")){
        return 1;
    }else if(propertyName == QObject::tr("姓名")){
        return 2;
    }else if(propertyName == QObject::tr("班级")){
        return 3;
    }else if(propertyName == QObject::tr("性别")){
        return 4;
    }else if(propertyName == QObject::tr("民族")){
        return 5;
    }else if(propertyName == QObject::tr("身份证号")){
        return 6;
    }else if(propertyName == QObject::tr("联系方式")){
        return 7;
    }else if(propertyName == QObject::tr("籍贯")){
        return 8;
    }else if(propertyName == QObject::tr("家庭住址")){
        return 9;
    }else if(propertyName == QObject::tr("出生年月日")){
        return 10;
    }else if(propertyName == QObject::tr("入学时间")){
        return 11;
    }else if(propertyName == QObject::tr("同申请人谈话时间")){
        return 12;
    }else if(propertyName == QObject::tr("申请入党时间")){
        return 13;
    }else if(propertyName == QObject::tr("入团时间")){
        return 14;
    }else if(propertyName == QObject::tr("团支部推优时间")){
        return 15;
    }else if(propertyName == QObject::tr("辅导员推荐时间")){
        return 16;
    }else if(propertyName == QObject::tr("团委推荐时间")){
        return 17;
    }else if(propertyName == QObject::tr("列为积极分子时间_支委会")){
        return 18;
    }else if(propertyName == QObject::tr("列为积极分子时间_基层备案")){
        return 19;
    }else if(propertyName == QObject::tr("培养联系人1")){
        return 20;
    }else if(propertyName == QObject::tr("培养联系人2")){
        return 21;
    }else if(propertyName == QObject::tr("更换后培养联系人")){
        return 22;
    }else if(propertyName == QObject::tr("更换后培养联系人2")){
        return 23;
    }else if(propertyName == QObject::tr("思想汇报篇数")){
        return 24;
    }else if(propertyName == QObject::tr("党课结业日期")){
        return 25;
    }else if(propertyName == QObject::tr("自传时间")){
        return 26;
    }else if(propertyName == QObject::tr("培养联系人··列··时间")){
        return 27;
    }else if(propertyName == QObject::tr("党小组··列··时间")){
        return 28;
    }else if(propertyName == QObject::tr("征求党内外党员人数")){
        return 29;
    }else if(propertyName == QObject::tr("群众人数")){
        return 30;
    }else if(propertyName == QObject::tr("支委会讨论确定时间")){
        return 31;
    }else if(propertyName == QObject::tr("基层党委备案时间（发展对象）")){
        return 32;
    }else if(propertyName == QObject::tr("函调时间")){
        return 33;
    }else if(propertyName == QObject::tr("政审时间")){
        return 34;
    }else if(propertyName == QObject::tr("基层党委预审意见时间")){
        return 35;
    }else if(propertyName == QObject::tr("支部大会讨论接收申请人为预备党员会议时间")){
        return 36;
    }else if(propertyName == QObject::tr("入党介绍人1")){
        return 37;
    }else if(propertyName == QObject::tr("入党介绍人2")){
        return 38;
    }else if(propertyName == QObject::tr("基层党委审批意见")){
        return 39;
    }else if(propertyName == QObject::tr("预备党员思想汇报篇数")){
        return 40;
    }else if(propertyName == QObject::tr("转正申请书时间")){
        return 41;
    }else if(propertyName == QObject::tr("支部大会通过预备党员能否转为正式党员的会议时间")){
        return 42;
    }else if(propertyName == QObject::tr("基层党委审批时间")){
        return 43;
    }else{
        emit errorMessage (QObject::tr("请检查输入属性值是否有误！"));
        return 44;
    }

}

const QVariant &PersonalInformation::getPropertyValue(const QString &property)
{
    if(this->changeStringToIndex(property) == this->personValue.returnSize())
        return std::move(QVariant());
    return this->personValue.data[this->changeStringToIndex(property)];
}

const QVariant &PersonalInformation::at(const int i)
{
    if(i<44)
    {
        return this->personValue.data[i];
    }else{
        return std::move(QVariant());
    }
}

int propertyValue::returnSize() const
{
    return 44;
}
