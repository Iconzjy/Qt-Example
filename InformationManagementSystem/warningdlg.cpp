#include "warningdlg.h"

#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QDebug>
WarningDlg::WarningDlg() : QWidget(nullptr)
{

}

void WarningDlg::getErrorMessage(QString message)
{
    QWidget *Dlg;
    QLabel *label;
    QBoxLayout *layout;
    QPushButton *exitButton;
    Dlg = new QWidget;
    label = new QLabel;
    layout = new QVBoxLayout(Dlg);
    exitButton = new QPushButton(tr("确定"),Dlg);
    connect(exitButton, &QPushButton::clicked, Dlg, &QWidget::close);//关闭窗口

    layout->setContentsMargins(10,10,10,10);//设置布局管理器到边界的距离都为10
    layout->addWidget(label,QSizePolicy::Preferred,Qt::AlignHCenter);//伸缩因子参数,居中
    layout->addWidget(exitButton,QSizePolicy::Preferred,Qt::AlignHCenter);

    QFont font;
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    font.setPointSize(20);
    label->setText(message.toUtf8());
    label->setFont(font);
    label->setPalette(palette);

    Dlg->setFixedSize(QSize(300,100));//对话框的最小大小，默认大小
    Dlg->setWindowTitle(tr("提示"));
    Dlg->setWindowFlag(Qt::WindowStaysOnTopHint,true);
    Dlg->setLayout(layout);
    Dlg->show();

}
