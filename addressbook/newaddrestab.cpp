#include "newaddrestab.h"
#include "adddialog.h"

#include <QtWidgets>

NewAddresTab::NewAddresTab(QWidget *parent)
{
    Q_UNUSED (parent);
    descriptionLabel = new QLabel(tr("There are currently no contacts in your address book."
                                     "\nClick Add to add new contacts."));

    addButton = new QPushButton(tr("Add"));

    connect(addButton, &QAbstractButton::clicked, this, &NewAddresTab::addEntry);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget (descriptionLabel);
    mainLayout->addWidget (addButton, 0, Qt::AlignCenter);

    setLayout (mainLayout);
}

//用到addEntry按钮就会关闭addDialog的页面
void NewAddresTab::addEntry()
{
    AddDialog aDialog;

    if(aDialog.exec ()){
        QString name = aDialog.nameText->text ();
        QString address = aDialog.addressText->toPlainText ();

        emit sendDetailes (name, address);
    }
}
