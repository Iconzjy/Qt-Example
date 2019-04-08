#include "forexcel.h"
#include <QAxObject>
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include "warningdlg.h"
ForExcel::ForExcel(QList<PersonalInformation *> &infos, QString type) : QObject(nullptr)
{
    information = infos;
    if(type == QObject::tr("积极分子备案报告"))
    {
        creatExcel_type1();
    }else if(type == QObject::tr("发展对象备案报告")){
        creatExcel_type2();
    }else if(type == QObject::tr("发展对象预审请示")){
        creatExcel_type3();
    }else if(type == QObject::tr("接收预备党员")){
        creatExcel_type4();
    }else if(type == QObject::tr("预备党员转正")){
        creatExcel_type5();
    }else{
        emit WarningDlg::getErrorMessage(tr("又找到bug，注：ForExcel构造函数"));
    }

}

void ForExcel::creatExcel_type1()
{
    // 连接控件
    QAxObject* excel = new QAxObject(this);
    excel->setControl("Excel.Application");  // 连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false);  // 不显示任何警告信息。如果为true, 那么关闭时会出现类似"文件已修改，是否保存"的提示

    // 打开工作簿
    QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    // 打开工作簿方式二：打开现成
    QAxObject* workbook = workbooks->querySubObject("Open(QString)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/qt/InformationManagementSystem/model/入党积极分子备案.xlsx")));

    // 打开sheet
    QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1); // 获取工作表集合的工作表1， 即sheet1

    for(int ind = 0; ind < information.size(); ind++)
    {
        QVariant value[14];
        value[0] = information.at(ind)->getPropertyValue(tr("班级"));
        value[1] = information.at(ind)->getPropertyValue(tr("ID"));
        value[2] = information.at(ind)->getPropertyValue(tr("姓名"));
        value[3] = information.at(ind)->getPropertyValue(tr("性别"));
        value[4] = information.at(ind)->getPropertyValue(tr("民族"));
        value[5] = information.at(ind)->getPropertyValue(tr("出生年月日"));
        value[6] = information.at(ind)->getPropertyValue(tr("籍贯"));
        value[7] = information.at(ind)->getPropertyValue(tr("身份证号"));
        value[8] = tr("高中");
        value[9] = information.at(ind)->getPropertyValue(tr("联系方式"));
        value[10] = information.at(ind)->getPropertyValue(tr("申请入党时间"));
        value[11] = information.at(ind)->getPropertyValue(tr("团支部推优时间"));
        value[12] = information.at(ind)->getPropertyValue(tr("列为积极分子时间_支委会"));
        value[13] = information.at(ind)->getPropertyValue(tr("培养联系人1"));

        // 读和写
        QString colB = "B" + QString::number(5+ind); //设置要操作的单元格
        QString colC = "C" + QString::number(5+ind);
        QString colD = "D" + QString::number(5+ind);
        QString colE = "E" + QString::number(5+ind);
        QString colF = "F" + QString::number(5+ind);
        QString colG = "G" + QString::number(5+ind);
        QString colH = "H" + QString::number(5+ind);
        QString colI = "I" + QString::number(5+ind);
        QString colJ = "J" + QString::number(5+ind);
        QString colK = "K" + QString::number(5+ind);
        QString colL = "L" + QString::number(5+ind);
        QString colM = "M" + QString::number(5+ind);
        QString colN = "N" + QString::number(5+ind);
        QString colO = "O" + QString::number(5+ind);
        QAxObject* cellB = worksheet->querySubObject("Range(QVariant, QVariant)", colB); //获取单元格
        QAxObject* cellC = worksheet->querySubObject("Range(QVariant, QVariant)", colC);
        QAxObject* cellD = worksheet->querySubObject("Range(QVariant, QVariant)", colD);
        QAxObject* cellE = worksheet->querySubObject("Range(QVariant, QVariant)", colE);
        QAxObject* cellF = worksheet->querySubObject("Range(QVariant, QVariant)", colF);
        QAxObject* cellG = worksheet->querySubObject("Range(QVariant, QVariant)", colG);
        QAxObject* cellH = worksheet->querySubObject("Range(QVariant, QVariant)", colH);
        QAxObject* cellI = worksheet->querySubObject("Range(QVariant, QVariant)", colI);
        QAxObject* cellJ = worksheet->querySubObject("Range(QVariant, QVariant)", colJ);
        QAxObject* cellK = worksheet->querySubObject("Range(QVariant, QVariant)", colK);
        QAxObject* cellL = worksheet->querySubObject("Range(QVariant, QVariant)", colL);
        QAxObject* cellM = worksheet->querySubObject("Range(QVariant, QVariant)", colM);
        QAxObject* cellN = worksheet->querySubObject("Range(QVariant, QVariant)", colN);
        QAxObject* cellO = worksheet->querySubObject("Range(QVariant, QVariant)", colO);
        cellB->dynamicCall("SetValue(conts QVariant&)", value[0]);//写入值
        cellC->dynamicCall("SetValue(conts QVariant&)", value[1]);
        cellD->dynamicCall("SetValue(conts QVariant&)", value[2]);
        cellE->dynamicCall("SetValue(conts QVariant&)", value[3]);
        cellF->dynamicCall("SetValue(conts QVariant&)", value[4]);
        cellG->dynamicCall("SetValue(conts QVariant&)", value[5]);
        cellH->dynamicCall("SetValue(conts QVariant&)", value[6]);
        cellI->dynamicCall("SetValue(conts QVariant&)", value[7]);
        cellJ->dynamicCall("SetValue(conts QVariant&)", value[8]);
        cellK->dynamicCall("SetValue(conts QVariant&)", value[9]);
        cellL->dynamicCall("SetValue(conts QVariant&)", value[10]);
        cellM->dynamicCall("SetValue(conts QVariant&)", value[11]);
        cellN->dynamicCall("SetValue(conts QVariant&)", value[12]);
        cellO->dynamicCall("SetValue(conts QVariant&)", value[13]);

    }
    // 另存为
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/入党积极分子备案.xlsx")));
    // 注意一定要用QDir::toNativeSeparators, 将路径中的"/"转换为"\", 不然一定保存不了
    workbook->dynamicCall("Close (Boolean)", false);  //关闭文件
}

void ForExcel::creatExcel_type2()
{
    // 连接控件
    QAxObject* excel = new QAxObject(this);
    excel->setControl("Excel.Application");  // 连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false);  // 不显示任何警告信息。如果为true, 那么关闭时会出现类似"文件已修改，是否保存"的提示

    // 打开工作簿
    QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    // 打开工作簿方式二：打开现成
    QAxObject* workbook = workbooks->querySubObject("Open(QString)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/qt/InformationManagementSystem/model/发展对象备案报告.xlsx")));

    // 打开sheet
    QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1); // 获取工作表集合的工作表1， 即sheet1

    for(int ind = 0; ind < information.size(); ind++)
    {
        QVariant value[14];
        value[0] = information.at(ind)->getPropertyValue(tr("班级"));
        value[1] = information.at(ind)->getPropertyValue(tr("ID"));
        value[2] = information.at(ind)->getPropertyValue(tr("姓名"));
        value[3] = information.at(ind)->getPropertyValue(tr("性别"));
        value[4] = information.at(ind)->getPropertyValue(tr("民族"));
        value[5] = information.at(ind)->getPropertyValue(tr("出生年月日"));
        value[6] = information.at(ind)->getPropertyValue(tr("籍贯"));
        value[7] = information.at(ind)->getPropertyValue(tr("身份证号"));
        value[8] = tr("高中");
        value[9] = information.at(ind)->getPropertyValue(tr("申请入党时间"));
        value[10] = information.at(ind)->getPropertyValue(tr("列为积极分子时间_支委会"));
        value[11] = information.at(ind)->getPropertyValue(tr("党课结业日期"));
        value[12] = information.at(ind)->getPropertyValue(tr("支委会讨论确定时间"));
        value[13] = information.at(ind)->getPropertyValue(tr("基层党委备案时间（发展对象）"));

        // 读和写
        QString colB = "B" + QString::number(5+ind); //设置要操作的单元格
        QString colC = "C" + QString::number(5+ind);
        QString colD = "D" + QString::number(5+ind);
        QString colE = "E" + QString::number(5+ind);
        QString colF = "F" + QString::number(5+ind);
        QString colG = "G" + QString::number(5+ind);
        QString colH = "H" + QString::number(5+ind);
        QString colI = "I" + QString::number(5+ind);
        QString colJ = "J" + QString::number(5+ind);
        QString colK = "K" + QString::number(5+ind);
        QString colL = "L" + QString::number(5+ind);
        QString colM = "M" + QString::number(5+ind);
        QString colN = "N" + QString::number(5+ind);
        QString colO = "O" + QString::number(5+ind);
        QAxObject* cellB = worksheet->querySubObject("Range(QVariant, QVariant)", colB); //获取单元格
        QAxObject* cellC = worksheet->querySubObject("Range(QVariant, QVariant)", colC);
        QAxObject* cellD = worksheet->querySubObject("Range(QVariant, QVariant)", colD);
        QAxObject* cellE = worksheet->querySubObject("Range(QVariant, QVariant)", colE);
        QAxObject* cellF = worksheet->querySubObject("Range(QVariant, QVariant)", colF);
        QAxObject* cellG = worksheet->querySubObject("Range(QVariant, QVariant)", colG);
        QAxObject* cellH = worksheet->querySubObject("Range(QVariant, QVariant)", colH);
        QAxObject* cellI = worksheet->querySubObject("Range(QVariant, QVariant)", colI);
        QAxObject* cellJ = worksheet->querySubObject("Range(QVariant, QVariant)", colJ);
        QAxObject* cellK = worksheet->querySubObject("Range(QVariant, QVariant)", colK);
        QAxObject* cellL = worksheet->querySubObject("Range(QVariant, QVariant)", colL);
        QAxObject* cellM = worksheet->querySubObject("Range(QVariant, QVariant)", colM);
        QAxObject* cellN = worksheet->querySubObject("Range(QVariant, QVariant)", colN);
        QAxObject* cellO = worksheet->querySubObject("Range(QVariant, QVariant)", colO);
        cellB->dynamicCall("SetValue(conts QVariant&)", value[0]);//写入值
        cellC->dynamicCall("SetValue(conts QVariant&)", value[1]);
        cellD->dynamicCall("SetValue(conts QVariant&)", value[2]);
        cellE->dynamicCall("SetValue(conts QVariant&)", value[3]);
        cellF->dynamicCall("SetValue(conts QVariant&)", value[4]);
        cellG->dynamicCall("SetValue(conts QVariant&)", value[5]);
        cellH->dynamicCall("SetValue(conts QVariant&)", value[6]);
        cellI->dynamicCall("SetValue(conts QVariant&)", value[7]);
        cellJ->dynamicCall("SetValue(conts QVariant&)", value[8]);
        cellK->dynamicCall("SetValue(conts QVariant&)", value[9]);
        cellL->dynamicCall("SetValue(conts QVariant&)", value[10]);
        cellM->dynamicCall("SetValue(conts QVariant&)", value[11]);
        cellN->dynamicCall("SetValue(conts QVariant&)", value[12]);
        cellO->dynamicCall("SetValue(conts QVariant&)", value[13]);

    }
    // 另存为
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/发展对象备案报告.xlsx")));
    // 注意一定要用QDir::toNativeSeparators, 将路径中的"/"转换为"\", 不然一定保存不了
    workbook->dynamicCall("Close (Boolean)", false);  //关闭文件
}

void ForExcel::creatExcel_type3()
{
    // 连接控件
    QAxObject* excel = new QAxObject(this);
    excel->setControl("Excel.Application");  // 连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false);  // 不显示任何警告信息。如果为true, 那么关闭时会出现类似"文件已修改，是否保存"的提示

    // 打开工作簿
    QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    // 打开工作簿方式二：打开现成
    QAxObject* workbook = workbooks->querySubObject("Open(QString)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/qt/InformationManagementSystem/model/党员发展对象预审.xlsx")));

    // 打开sheet
    QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1); // 获取工作表集合的工作表1， 即sheet1

    for(int ind = 0; ind < information.size(); ind++)
    {
        QVariant value[14];
        value[0] = information.at(ind)->getPropertyValue(tr("班级"));
        value[1] = information.at(ind)->getPropertyValue(tr("姓名"));
        value[2] = information.at(ind)->getPropertyValue(tr("性别"));
        value[3] = information.at(ind)->getPropertyValue(tr("申请入党时间"));
        value[4] = information.at(ind)->getPropertyValue(tr("团支部推优时间"));
        value[5] = information.at(ind)->getPropertyValue(tr("列为积极分子时间_支委会"));
        value[6] = information.at(ind)->getPropertyValue(tr("党课结业日期"));
        value[7] = information.at(ind)->getPropertyValue(tr("基层党委备案时间（发展对象）"));
        value[8] = tr("无异议");
        value[9] = tr("合格");

        // 读和写
        QString colB = "B" + QString::number(5+ind); //设置要操作的单元格
        QString colC = "C" + QString::number(5+ind);
        QString colD = "D" + QString::number(5+ind);
        QString colE = "E" + QString::number(5+ind);
        QString colF = "F" + QString::number(5+ind);
        QString colG = "G" + QString::number(5+ind);
        QString colH = "H" + QString::number(5+ind);
        QString colI = "I" + QString::number(5+ind);
        QString colJ = "J" + QString::number(5+ind);
        QString colK = "K" + QString::number(5+ind);
        QString colL = "L" + QString::number(5+ind);
        QString colM = "M" + QString::number(5+ind);
        QString colN = "N" + QString::number(5+ind);
        QString colO = "O" + QString::number(5+ind);
        QAxObject* cellB = worksheet->querySubObject("Range(QVariant, QVariant)", colB); //获取单元格
        QAxObject* cellC = worksheet->querySubObject("Range(QVariant, QVariant)", colC);
        QAxObject* cellD = worksheet->querySubObject("Range(QVariant, QVariant)", colD);
        QAxObject* cellE = worksheet->querySubObject("Range(QVariant, QVariant)", colE);
        QAxObject* cellF = worksheet->querySubObject("Range(QVariant, QVariant)", colF);
        QAxObject* cellG = worksheet->querySubObject("Range(QVariant, QVariant)", colG);
        QAxObject* cellH = worksheet->querySubObject("Range(QVariant, QVariant)", colH);
        QAxObject* cellI = worksheet->querySubObject("Range(QVariant, QVariant)", colI);
        QAxObject* cellJ = worksheet->querySubObject("Range(QVariant, QVariant)", colJ);
        QAxObject* cellK = worksheet->querySubObject("Range(QVariant, QVariant)", colK);
        cellB->dynamicCall("SetValue(conts QVariant&)", value[0]);//写入值
        cellC->dynamicCall("SetValue(conts QVariant&)", value[1]);
        cellD->dynamicCall("SetValue(conts QVariant&)", value[2]);
        cellE->dynamicCall("SetValue(conts QVariant&)", value[3]);
        cellF->dynamicCall("SetValue(conts QVariant&)", value[4]);
        cellG->dynamicCall("SetValue(conts QVariant&)", value[5]);
        cellH->dynamicCall("SetValue(conts QVariant&)", value[6]);
        cellI->dynamicCall("SetValue(conts QVariant&)", value[7]);
        cellJ->dynamicCall("SetValue(conts QVariant&)", value[8]);
        cellK->dynamicCall("SetValue(conts QVariant&)", value[9]);

    }
    // 另存为
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/发展对象预审请示.xlsx")));
    // 注意一定要用QDir::toNativeSeparators, 将路径中的"/"转换为"\", 不然一定保存不了
    workbook->dynamicCall("Close (Boolean)", false);  //关闭文件
}

void ForExcel::creatExcel_type4()
{
    // 连接控件
    QAxObject* excel = new QAxObject(this);
    excel->setControl("Excel.Application");  // 连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false);  // 不显示任何警告信息。如果为true, 那么关闭时会出现类似"文件已修改，是否保存"的提示

    // 打开工作簿
    QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    // 打开工作簿方式二：打开现成
    QAxObject* workbook = workbooks->querySubObject("Open(QString)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/qt/InformationManagementSystem/model/接收预备党员.xlsx")));

    // 打开sheet
    QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1); // 获取工作表集合的工作表1， 即sheet1

    for(int ind = 0; ind < information.size(); ind++)
    {
        QVariant value[11];
        value[0] = information.at(ind)->getPropertyValue(tr("班级"));
        value[1] = information.at(ind)->getPropertyValue(tr("姓名"));
        value[2] = information.at(ind)->getPropertyValue(tr("性别"));
        value[3] = information.at(ind)->getPropertyValue(tr("民族"));
        value[4] = information.at(ind)->getPropertyValue(tr("出生年月日"));
        value[5] = tr("高中");
        value[6] = information.at(ind)->getPropertyValue(tr("申请入党时间"));
        value[7] = information.at(ind)->getPropertyValue(tr("列为积极分子时间_支委会"));
        value[8] = information.at(ind)->getPropertyValue(tr("基层党委备案时间（发展对象）"));
        value[9] = information.at(ind)->getPropertyValue(tr("支部大会讨论接收申请人为预备党员会议时间"));
        value[10] = information.at(ind)->getPropertyValue(tr("基层党委审批意见"));

        // 读和写
        QString colB = "B" + QString::number(5+ind); //设置要操作的单元格
        QString colC = "C" + QString::number(5+ind);
        QString colD = "D" + QString::number(5+ind);
        QString colE = "E" + QString::number(5+ind);
        QString colF = "F" + QString::number(5+ind);
        QString colG = "G" + QString::number(5+ind);
        QString colH = "H" + QString::number(5+ind);
        QString colI = "I" + QString::number(5+ind);
        QString colJ = "J" + QString::number(5+ind);
        QString colK = "K" + QString::number(5+ind);
        QString colL = "L" + QString::number(5+ind);
        QAxObject* cellB = worksheet->querySubObject("Range(QVariant, QVariant)", colB); //获取单元格
        QAxObject* cellC = worksheet->querySubObject("Range(QVariant, QVariant)", colC);
        QAxObject* cellD = worksheet->querySubObject("Range(QVariant, QVariant)", colD);
        QAxObject* cellE = worksheet->querySubObject("Range(QVariant, QVariant)", colE);
        QAxObject* cellF = worksheet->querySubObject("Range(QVariant, QVariant)", colF);
        QAxObject* cellG = worksheet->querySubObject("Range(QVariant, QVariant)", colG);
        QAxObject* cellH = worksheet->querySubObject("Range(QVariant, QVariant)", colH);
        QAxObject* cellI = worksheet->querySubObject("Range(QVariant, QVariant)", colI);
        QAxObject* cellJ = worksheet->querySubObject("Range(QVariant, QVariant)", colJ);
        QAxObject* cellK = worksheet->querySubObject("Range(QVariant, QVariant)", colK);
        QAxObject* cellL = worksheet->querySubObject("Range(QVariant, QVariant)", colL);
        cellB->dynamicCall("SetValue(conts QVariant&)", value[0]);//写入值
        cellC->dynamicCall("SetValue(conts QVariant&)", value[1]);
        cellD->dynamicCall("SetValue(conts QVariant&)", value[2]);
        cellE->dynamicCall("SetValue(conts QVariant&)", value[3]);
        cellF->dynamicCall("SetValue(conts QVariant&)", value[4]);
        cellG->dynamicCall("SetValue(conts QVariant&)", value[5]);
        cellH->dynamicCall("SetValue(conts QVariant&)", value[6]);
        cellI->dynamicCall("SetValue(conts QVariant&)", value[7]);
        cellJ->dynamicCall("SetValue(conts QVariant&)", value[8]);
        cellK->dynamicCall("SetValue(conts QVariant&)", value[9]);
        cellL->dynamicCall("SetValue(conts QVariant&)", value[10]);

    }
    // 另存为
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/接收预备党员.xlsx")));
    // 注意一定要用QDir::toNativeSeparators, 将路径中的"/"转换为"\", 不然一定保存不了
    workbook->dynamicCall("Close (Boolean)", false);  //关闭文件
}

void ForExcel::creatExcel_type5()
{
    // 连接控件
    QAxObject* excel = new QAxObject(this);
    excel->setControl("Excel.Application");  // 连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false);  // 不显示任何警告信息。如果为true, 那么关闭时会出现类似"文件已修改，是否保存"的提示

    // 打开工作簿
    QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    // 打开工作簿方式二：打开现成
    QAxObject* workbook = workbooks->querySubObject("Open(QString)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/qt/InformationManagementSystem/model/预备党员转正.xlsx")));

    // 打开sheet
    QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1); // 获取工作表集合的工作表1， 即sheet1

    for(int ind = 0; ind < information.size(); ind++)
    {
        QVariant value[8];
        value[0] = information.at(ind)->getPropertyValue(tr("班级"));
        value[1] = information.at(ind)->getPropertyValue(tr("姓名"));
        value[2] = information.at(ind)->getPropertyValue(tr("性别"));
        value[3] = information.at(ind)->getPropertyValue(tr("民族"));
        value[4] = information.at(ind)->getPropertyValue(tr("出生年月日"));
        value[5] = tr("高中");
        value[6] = information.at(ind)->getPropertyValue(tr("支部大会讨论接收申请人为预备党员会议时间"));
        value[7] = information.at(ind)->getPropertyValue(tr("支部大会通过预备党员能否转为正式党员的会议时间"));

        // 读和写
        QString colB = "B" + QString::number(5+ind); //设置要操作的单元格
        QString colC = "C" + QString::number(5+ind);
        QString colD = "D" + QString::number(5+ind);
        QString colE = "E" + QString::number(5+ind);
        QString colF = "F" + QString::number(5+ind);
        QString colG = "G" + QString::number(5+ind);
        QString colH = "H" + QString::number(5+ind);
        QString colI = "I" + QString::number(5+ind);
        QAxObject* cellB = worksheet->querySubObject("Range(QVariant, QVariant)", colB); //获取单元格
        QAxObject* cellC = worksheet->querySubObject("Range(QVariant, QVariant)", colC);
        QAxObject* cellD = worksheet->querySubObject("Range(QVariant, QVariant)", colD);
        QAxObject* cellE = worksheet->querySubObject("Range(QVariant, QVariant)", colE);
        QAxObject* cellF = worksheet->querySubObject("Range(QVariant, QVariant)", colF);
        QAxObject* cellG = worksheet->querySubObject("Range(QVariant, QVariant)", colG);
        QAxObject* cellH = worksheet->querySubObject("Range(QVariant, QVariant)", colH);
        QAxObject* cellI = worksheet->querySubObject("Range(QVariant, QVariant)", colI);
        cellB->dynamicCall("SetValue(conts QVariant&)", value[0]);//写入值
        cellC->dynamicCall("SetValue(conts QVariant&)", value[1]);
        cellD->dynamicCall("SetValue(conts QVariant&)", value[2]);
        cellE->dynamicCall("SetValue(conts QVariant&)", value[3]);
        cellF->dynamicCall("SetValue(conts QVariant&)", value[4]);
        cellG->dynamicCall("SetValue(conts QVariant&)", value[5]);
        cellH->dynamicCall("SetValue(conts QVariant&)", value[6]);
        cellI->dynamicCall("SetValue(conts QVariant&)", value[7]);

    }
    // 另存为
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(tr("C:/Users/24270/Desktop/预备党员转正.xlsx")));
    // 注意一定要用QDir::toNativeSeparators, 将路径中的"/"转换为"\", 不然一定保存不了
    workbook->dynamicCall("Close (Boolean)", false);  //关闭文件
}







