#include "dbstruct.h"

#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QFile>
#include <QVariant>

DBStruct::DBStruct(const QString &path)
    :QObject(nullptr)
{
    connect(this, &DBStruct::sendErrorMessage, this, &WarningDlg::getErrorMessage);
    connectToDB (path);
}

DBStruct::DBStruct(QString &&path)
{
    connect(this, &DBStruct::sendErrorMessage, this, &WarningDlg::getErrorMessage);
    connectToDB (std::move(path));
}

QMap<int, PersonalInformation *>* DBStruct::getPersonalDate()
{
    return &allPersonInDB;
}

QStringList DBStruct::getProperty() const
{
    QStringList property;
    for(int i=0; i<44; i++)
    {
        property << propertyName->at(i).toString();
    }
    return property;
}


bool DBStruct::connectToDB(const QString &path)
{
    QSqlDatabase db = QSqlDatabase::addDatabase ("QODBC");
    QString DR = QObject::tr("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};"
                 "DBQ=%1").arg (path);
    db.setDatabaseName(DR);

    QString out_str;
    QSqlError err;
    QSqlRecord record;
    bool ok = db.open ();
    if(ok){
        QStringList tables;
        QString tabName,sqlString;
        tables = db.tables (QSql::Tables);
        //读取数据库里的表名,这里只选用第一个表
//        for(int i = 0; i < tables.size (); ++i){
//            tabName = tables.at (i);
//            qDebug() << tabName;
//        }
//        //读表中记录
//        for (int i = 0; i < tables.size(); ++i){
            tabName = tables.at(0);
            qDebug()<<tabName;
            sqlString = "select * from " + tabName;
            QSqlQuery q(sqlString);
            QSqlRecord rec = q.record();
            int fieldCount = rec.count();//fieldCount=44,depend on my own file information;
            qDebug() << "Number of columns: " << fieldCount;
            int p;
            QVariant fieldName[44];
            for(p=0;p<fieldCount;p++){
                fieldName[p] = rec.fieldName(p);
            }
//            emit this->getDBPropertyName(std::move(fieldName));//将属性名用信号发送出去
            propertyName = new PersonalInformation(fieldName);

//            for(int i = 0; i<44; i++)
//            {
//                qDebug() << fieldName[i]<<"  ";
//            }
            int j = 0;
            while(q.next()){
                QVariant record[44];
                for(int i=0;i<fieldCount;i++){
                    record[i] = q.value(i);
                }
                PersonalInformation *person = new PersonalInformation(record);
                allPersonInDB.insert(j,person);
                ++j;
            }
//        }
        return true;
    }else{
        emit sendErrorMessage(QObject::tr("连接数据库出错"));
        return false;
    }
}


