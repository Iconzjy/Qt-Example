#include "forword.h"
#include <QAxObject>
#include <QFileDialog>
#include <QtDebug>
ForWord::ForWord(QObject *parent) : QObject(parent = nullptr)
{
}

void ForWord::creatWord()
{
    QAxObject *word = new QAxObject("Word.Application");
    word->setProperty("Visible",true);
    QAxObject *doc = word->querySubObject("Documents");
    doc->dynamicCall("Open(QString)",QDir::toNativeSeparators(tr(":/new/prefix1/model/1.doc")));
    QAxObject *document = word->querySubObject("ActiveDocument");
    if(document == nullptr)
    {
        qDebug() << "cant open";
    }else{
        QString text;
        QAxObject *pRange = document->querySubObject("Range()");
        if(pRange != nullptr)
        {
            text = pRange->property("Text").toString();
            delete  pRange;
            pRange = nullptr;
        }
        qDebug() <<text;
    }
    QAxObject *bookmark_code = document->querySubObject("Bookmarks(QVariant)","name");
    if(!bookmark_code->isNull())
    {
        bookmark_code->dynamicCall("Select(void)");
        bookmark_code->querySubObject("Range")->setProperty("Text","testg");
    }
    document->dynamicCall("SaveAs (const QString&)",QString("./t.docx"));
    document->dynamicCall("Close (boolean)",false);
    word->dynamicCall("Quit()");
}
