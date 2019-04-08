#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbstruct.h"
#include "personalinformation.h"
#include "calendar.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "personalinformation.h"
#include "forword.h"
#include "forexcel.h"

#include <QSizePolicy>
#include <QToolBox>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QVector>
#include <QDebug>
#include <QTreeWidget>
#include <QLineEdit>
#include <QDialog>
#include <QCalendarWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowNoState);
    DB = new DBStruct("C:/Users/24270/Desktop/accessReadTest/text.accdb");
    createMenu();
    createAction();
    creatTreeWidget();
    creatTabWidget();
    setEditOrNot(false);//初始化，内容不可编辑
    allConnectionFunction();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCheckInfo(QTreeWidgetItem * item, int)
{
    QList<QTreeWidgetItem* > a;
    {
        for(int i = 0; i < pItem->childCount(); i++)
        {
            a.append(pItem->child(i));
        }
    }
    if(a.indexOf(item) != -1)
    {
        if(item->childCount() == 0)
        {
            int index = maps.key(item);
            emit sendCurrentIndex(index);
            PersonalInformation* person = DB->getPersonalDate()->value(index);

            /*第一个tab页面*/
            this->ID_1->setText(person->getPropertyValue(std::move(QString(tr("ID")))).toString());//注：标签ID内容是学号
            this->type_1->setText(person->getPropertyValue(type->text()).toString());
            this->name_1->setText(person->getPropertyValue(name->text()).toString());
            this->sex_1->setText(person->getPropertyValue(sex->text()).toString());
            this->clas_1->setText(person->getPropertyValue(clas->text()).toString());
            this->national_1->setText(person->getPropertyValue(national->text()).toString());
            this->address_1->setText(person->getPropertyValue(address->text()).toString());
            this->personalID_1->setText(person->getPropertyValue(personalID->text()).toString());
            this->phone_1->setText(person->getPropertyValue(phone->text()).toString());
            this->origin_1->setText(person->getPropertyValue(origin->text()).toString());
            this->birthday_1->setText((person->getPropertyValue(birthday->text()).toDate()).toString("yyyy-MM-dd"));
            this->intoCollege_1->setText((person->getPropertyValue(intoCollege->text()).toDate()).toString("yyyy-MM-dd"));

            /*第二个tab页面*/
            this->talkWithApplicant_1->setText((person->getPropertyValue(talkWithApplicant->text()).toDate()).toString("yyyy-MM-dd"));
            this->applyForMembership_1->setText((person->getPropertyValue(applyForMembership->text()).toDate()).toString("yyyy-MM-dd"));
            this->league_1->setText((person->getPropertyValue(league->text()).toDate()).toString("yyyy-MM-dd"));
            this->leagueBranchpush_1->setText((person->getPropertyValue(leagueBranchpush->text()).toDate()).toString("yyyy-MM-dd"));
            this->instructorDrivenOptimization_1->setText((person->getPropertyValue(instructorDrivenOptimization->text()).toDate()).toString("yyyy-MM-dd"));
            this->youthLeagueRecommendation_1->setText((person->getPropertyValue(youthLeagueRecommendation->text()).toDate()).toString("yyyy-MM-dd"));
            this->classifiedAsAPositiveScoremMember_1->setText((person->getPropertyValue(classifiedAsAPositiveScoremMember->text()).toDate()).toString("yyyy-MM-dd"));
            this->classifiedAsAPositiveGrassRootsPartyCommittee_1->setText((person->getPropertyValue(classifiedAsAPositiveGrassRootsPartyCommittee->text()).toDate()).toString("yyyy-MM-dd"));
            this->developContacts1_1->setText(person->getPropertyValue(developContacts1->text()).toString());
            this->developContacts2_1->setText(person->getPropertyValue(developContacts2->text()).toString());
            this->changeDevelopContacts1_1->setText(person->getPropertyValue(changeDevelopContacts1->text()).toString());
            this->changeDevelopContacts2_1->setText(person->getPropertyValue(changeDevelopContacts2->text()).toString());
            this->thoughtReport_1->setText(person->getPropertyValue(thoughtReport->text()).toString());
            this->partyLectureCompletion_1->setText((person->getPropertyValue(partyLectureCompletion->text()).toDate()).toString("yyyy-MM-dd"));
            this->autobiography_1->setText((person->getPropertyValue(autobiography->text()).toDate()).toString("yyyy-MM-dd"));
            this->developcontacts_1->setText((person->getPropertyValue(developcontacts->text()).toDate()).toString("yyyy-MM-dd"));
            this->partyGroup_1->setText((person->getPropertyValue(partyGroup->text()).toDate()).toString("yyyy-MM-dd"));
            this->numberOfPartyMembers_1->setText(person->getPropertyValue(numberOfPartyMembers->text()).toString());
            this->numberOfPublicMembers_1->setText(person->getPropertyValue(numberOfPublicMembers->text()).toString());
            this->memberDiscussion_1->setText((person->getPropertyValue(memberDiscussion->text()).toDate()).toString("yyyy-MM-dd"));
            this->grassrootsPartyCommittee_1->setText((person->getPropertyValue(grassrootsPartyCommittee->text()).toDate()).toString("yyyy-MM-dd"));
            this->municipalities_1->setText((person->getPropertyValue(municipalities->text()).toDate()).toString("yyyy-MM-dd"));
            this->politicsCareful_1->setText((person->getPropertyValue(politicsCareful->text()).toDate()).toString("yyyy-MM-dd"));
            this->preliminary_1->setText((person->getPropertyValue(preliminary->text()).toDate()).toString("yyyy-MM-dd"));


            /*第三个tab页面*/

            this->branchCongressToDiscussBecomingProbationary_1->setText((person->getPropertyValue(memberDiscussion->text()).toDate()).toString("yyyy-MM-dd"));
            this->joiningThePartyIntroducer1_1->setText(person->getPropertyValue(joiningThePartyIntroducer1->text()).toString());
            this->joiningThePartyIntroducer2_1->setText(person->getPropertyValue(joiningThePartyIntroducer2->text()).toString());
            this->approvalOfGrassrootsPartyCommittee_1->setText((person->getPropertyValue(approvalOfGrassrootsPartyCommittee->text()).toDate()).toString("yyyy-MM-dd"));
            this->probationaryThought_1->setText(person->getPropertyValue(probationaryThought->text()).toString());
            this->applicationForRegularization_1->setText((person->getPropertyValue(applicationForRegularization->text()).toDate()).toString("yyyy-MM-dd"));
            this->theBranchCongressRegularization_1->setText((person->getPropertyValue(theBranchCongressRegularization->text()).toDate()).toString("yyyy-MM-dd"));
            this->grassrootsPartyCommitteeApproval_1->setText((person->getPropertyValue(grassrootsPartyCommitteeApproval->text()).toDate()).toString("yyyy-MM-dd"));
        }

    }else{
        emit sendCurrentIndex(-1);
        return;
    }
}

void MainWindow::setEditOrNot(bool state)
{
    qDebug() << state;
    name_1->setEnabled(state);
    ID_1->setEnabled(state);
    type_1->setEnabled(state);
    clas_1->setEnabled(state);
    sex_1->setEnabled(state);
    national_1->setEnabled(state);
    address_1->setEnabled(state);
    personalID_1->setEnabled(state);
    phone_1->setEnabled(state);
    origin_1->setEnabled(state);
    birthday_1->setEnabled(state);
    intoCollege_1->setEnabled(state);
    talkWithApplicant_1->setEnabled(state);
    applyForMembership_1->setEnabled(state);
    league_1->setEnabled(state);
    leagueBranchpush_1->setEnabled(state);
    instructorDrivenOptimization_1->setEnabled(state);
    youthLeagueRecommendation_1->setEnabled(state);
    classifiedAsAPositiveScoremMember_1->setEnabled(state);
    classifiedAsAPositiveGrassRootsPartyCommittee_1->setEnabled(state);
    developContacts1_1->setEnabled(state);
    developContacts2_1->setEnabled(state);
    changeDevelopContacts1_1->setEnabled(state);
    changeDevelopContacts2_1->setEnabled(state);
    thoughtReport_1->setEnabled(state);
    partyLectureCompletion_1->setEnabled(state);
    autobiography_1->setEnabled(state);
    developcontacts_1->setEnabled(state);
    partyGroup_1->setEnabled(state);
    numberOfPartyMembers_1->setEnabled(state);
    numberOfPublicMembers_1->setEnabled(state);
    memberDiscussion_1->setEnabled(state);
    grassrootsPartyCommittee_1->setEnabled(state);
    municipalities_1->setEnabled(state);
    politicsCareful_1->setEnabled(state);
    preliminary_1->setEnabled(state);
    branchCongressToDiscussBecomingProbationary_1->setEnabled(state);
    joiningThePartyIntroducer1_1->setEnabled(state);
    joiningThePartyIntroducer2_1->setEnabled(state);
    approvalOfGrassrootsPartyCommittee_1->setEnabled(state);
    probationaryThought_1->setEnabled(state);
    applicationForRegularization_1->setEnabled(state);
    theBranchCongressRegularization_1->setEnabled(state);
    grassrootsPartyCommitteeApproval_1->setEnabled(state);


    //按钮
    name_2->setChecked(state);
    ID_2->setChecked(state);
    type_2->setChecked(state);
    clas_2->setChecked(state);
    sex_2->setChecked(state);
    national_2->setChecked(state);
    address_2->setChecked(state);
    personalID_2->setChecked(state);
    phone_2->setChecked(state);
    origin_2->setChecked(state);
    birthday_2->setChecked(state);
    intoCollege_2->setChecked(state);
    talkWithApplicant_2->setChecked(state);
    applyForMembership_2->setChecked(state);
    league_2->setChecked(state);
    leagueBranchpush_2->setChecked(state);
    instructorDrivenOptimization_2->setChecked(state);
    youthLeagueRecommendation_2->setChecked(state);
    classifiedAsAPositiveScoremMember_2->setChecked(state);
    classifiedAsAPositiveGrassRootsPartyCommittee_2->setChecked(state);
    developContacts1_2->setChecked(state);
    developContacts2_2->setChecked(state);
    changeDevelopContacts1_2->setChecked(state);
    changeDevelopContacts2_2->setChecked(state);
    thoughtReport_2->setChecked(state);
    partyLectureCompletion_2->setChecked(state);
    autobiography_2->setChecked(state);
    developcontacts_2->setChecked(state);
    partyGroup_2->setChecked(state);
    numberOfPartyMembers_2->setChecked(state);
    numberOfPublicMembers_2->setChecked(state);
    memberDiscussion_2->setChecked(state);
    grassrootsPartyCommittee_2->setChecked(state);
    municipalities_2->setChecked(state);
    politicsCareful_2->setChecked(state);
    preliminary_2->setChecked(state);
    branchCongressToDiscussBecomingProbationary_2->setChecked(state);
    joiningThePartyIntroducer1_2->setChecked(state);
    joiningThePartyIntroducer2_2->setChecked(state);
    approvalOfGrassrootsPartyCommittee_2->setChecked(state);
    probationaryThought_2->setChecked(state);
    applicationForRegularization_2->setChecked(state);
    theBranchCongressRegularization_2->setChecked(state);
    grassrootsPartyCommitteeApproval_2->setChecked(state);
}

void MainWindow::setEdit(bool state)
{
    setEditOrNot(!state);
}

void MainWindow::popMenu(const QPoint &)
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    QList<QTreeWidgetItem* > a;//用于判断子节点
    {
        for(int i = 0; i < pItem->childCount(); i++)
        {
            a.append(pItem->child(i));
        }
    }
    if(currentItem == nullptr)
    {
        emit errorMessage(tr("右击弹出菜单错误，this is a bug"));
        return;
    }

    //判断是根节点还是子节点
    if(currentItem == pItem)//根节点
    {
        QMenu menu(ui->treeWidget);
        QMenu childMenu(tr("人员类别"),&menu);
        QAction allPerson(tr("所有类别"),&childMenu);
        QAction applicant(tr("申请人"),&childMenu);
        QAction Activists(tr("积极分子"),&childMenu);
        QAction developmentTarget(tr("发展对象"),&childMenu);
        QAction probationary(tr("预备党员"),&childMenu);
        QAction officialPartyMembers(tr("正式党员"),&childMenu);
        connect(&allPerson, &QAction::triggered, this, &MainWindow::sortType);
        connect(&applicant, &QAction::triggered, this, &MainWindow::sortType1);
        connect(&Activists, &QAction::triggered, this, &MainWindow::sortType2);
        connect(&developmentTarget, &QAction::triggered, this, &MainWindow::sortType3);
        connect(&probationary, &QAction::triggered, this, &MainWindow::sortType4);
        connect(&officialPartyMembers, &QAction::triggered, this, &MainWindow::sortType5);
        childMenu.addAction(&allPerson);
        childMenu.addAction(&applicant);
        childMenu.addAction(&Activists);
        childMenu.addAction(&developmentTarget);
        childMenu.addAction(&probationary);
        childMenu.addAction(&officialPartyMembers);
        menu.addMenu(&childMenu);
        menu.exec(QCursor::pos());

    }
    if(a.indexOf(currentItem) >= 0)//子节点
    {
        pCurrentPointer = currentItem;
        QAction deleteItem(tr("删除"),this);
        connect(&deleteItem, &QAction::triggered, this, &MainWindow::deleteItem);
        QMenu menu(ui->treeWidget);
        menu.addAction(&deleteItem);
        menu.exec(QCursor::pos());
    }
    if(currentItem == pItem2)
    {
        /*台账的列表右击功能，需要时候可以在这里实现*/
    }
}

void MainWindow::deleteItem(bool)
{
    if(pCurrentPointer != maps.find(current).value())
    {
        emit errorMessage(tr("所选对象和当前对象不同步，请双击选中人员后再进行删除，注：MainWindow::deleteItem"));
    }else{
        emit errorMessage(tr("删除信息"));
        maps.remove(current);
        DB->getPersonalDate()->remove(current);
        pItem->removeChild(pCurrentPointer);
        pItem->setText(0,QString("人员信息[%1]").arg(pItem->childCount()));
        ui->treeWidget->update();
    }
}

void MainWindow::sortType(bool)
{
    emit sendType(tr("所有人"));
}

void MainWindow::sortType1(bool)
{
    emit sendType(tr("申请人"));
}

void MainWindow::sortType2(bool)
{
    emit sendType(tr("积极分子"));
}

void MainWindow::sortType3(bool)
{
    emit sendType(tr("发展对象"));
}

void MainWindow::sortType4(bool)
{
    emit sendType(tr("预备党员"));
}

void MainWindow::sortType5(bool)
{
    emit sendType(tr("正式党员"));
}

void MainWindow::sortItem(QString type)
{
    if(type == tr("所有人")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            pItem->child(indexs)->setHidden(false);
        }
    }else if(type == tr("申请人")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            if(DB->getPersonalDate()->value(indexs)->getPropertyValue(tr("人员类别")).toString() == tr("申请人")){
                pItem->child(indexs)->setHidden(false);
            }else{
                pItem->child(indexs)->setHidden(true);
            }
        }
    }else if(type == tr("积极分子")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            if(DB->getPersonalDate()->value(indexs)->getPropertyValue(tr("人员类别")).toString() == tr("积极分子")){
                pItem->child(indexs)->setHidden(false);
            }else{
                pItem->child(indexs)->setHidden(true);
            }
        }
    }else if(type == tr("发展对象")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            if(DB->getPersonalDate()->value(indexs)->getPropertyValue(tr("人员类别")).toString() == tr("发展对象")){
                pItem->child(indexs)->setHidden(false);
            }else{
                pItem->child(indexs)->setHidden(true);
            }
        }
    }else if(type == tr("预备党员")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            if(DB->getPersonalDate()->value(indexs)->getPropertyValue(tr("人员类别")).toString() == tr("预备党员")){
                pItem->child(indexs)->setHidden(false);
            }else{
                pItem->child(indexs)->setHidden(true);
            }
        }
    }else if(type == tr("正式党员")){
        for(int indexs = 0; indexs < DB->getPersonalDate()->size(); indexs++)
        {
            if(DB->getPersonalDate()->value(indexs)->getPropertyValue(tr("人员类别")).toString() == tr("正式党员")){
                pItem->child(indexs)->setHidden(false);
            }else{
                pItem->child(indexs)->setHidden(true);
            }
        }
    }else{
        emit errorMessage(tr("报告，找到一只bug，MainWindow::sortItem()"));
    }
}

void MainWindow::curtentIndex(int ind)
{
    current = ind;
}

void MainWindow::resetDates(bool)
{
    if(current <0 || current > 100)
    {
        emit errorMessage("你遇上错的人，请重新选择，注：MainWindow：：resetDate");
        return;
    }
    qDebug() << current;
    QVariant info[44];
    info[0] = ID_1->text();
    info[1] = type_1->text();
    info[2] = name_1->text();
    info[3] = clas_1->text();
    info[4] = sex_1->text();
    info[5] = national_1->text();
    info[6] = address_1->text();
    info[7] = personalID_1->text();
    info[8] = phone_1->text();
    info[9] = origin_1->text();
    info[10] = birthday_1->text();
    info[11] = intoCollege_1->text();
    info[12] = talkWithApplicant_1->text();
    info[13] = applyForMembership_1->text();
    info[14] = league_1->text();
    info[15] = leagueBranchpush_1->text();
    info[16] = instructorDrivenOptimization_1->text();
    info[17] = youthLeagueRecommendation_1->text();
    info[18] = classifiedAsAPositiveScoremMember_1->text();
    info[19] = classifiedAsAPositiveGrassRootsPartyCommittee_1->text();
    info[20] = developContacts1_1->text();
    info[21] = developContacts2_1->text();
    info[22] = changeDevelopContacts1_1->text();
    info[23] = changeDevelopContacts2_1->text();
    info[24] = thoughtReport_1->text();
    info[25] = partyLectureCompletion_1->text();
    info[26] = autobiography_1->text();
    info[27] = developcontacts_1->text();
    info[28] = partyGroup_1->text();
    info[29] = numberOfPartyMembers_1->text();
    info[30] = numberOfPublicMembers_1->text();
    info[31] = memberDiscussion_1->text();
    info[32] = grassrootsPartyCommittee_1->text();
    info[33] = municipalities_1->text();
    info[34] = politicsCareful_1->text();
    info[35] = preliminary_1->text();
    info[36] = branchCongressToDiscussBecomingProbationary_1->text();
    info[37] = joiningThePartyIntroducer1_1->text();
    info[38] = joiningThePartyIntroducer2_1->text();
    info[39] = approvalOfGrassrootsPartyCommittee_1->text();
    info[40] = probationaryThought_1->text();
    info[41] = applicationForRegularization_1->text();
    info[42] = theBranchCongressRegularization_1->text();
    info[43] = grassrootsPartyCommitteeApproval_1->text();
    PersonalInformation* changeInfo = new PersonalInformation(info);
    qDebug() <<info[1].toString();
    pItem->child(current)->setText(1,QString("%1").arg(info[2].toString()));
    pItem->child(current)->setText(2,QString("%1").arg(info[1].toString()));
    for(int i = 0; i < DB->getPersonalDate()->size(); i++)
    {
        if(changeInfo == DB->getPersonalDate()->value(i))
        {
            return;
        }
    }
    DB->getPersonalDate()->insert(current, changeInfo);
}

void MainWindow::addNewOneInfo(bool)
{
    //清楚文本框里的所有内容
    ID_1->clear();
    type_1->clear();
    name_1->clear();
    clas_1->clear();
    sex_1->clear();
    national_1->clear();
    address_1->clear();
    personalID_1->clear();
    phone_1->clear();
    origin_1->clear();
    birthday_1->clear();
    intoCollege_1->clear();
    talkWithApplicant_1->clear();
    applyForMembership_1->clear();
    league_1->clear();
    leagueBranchpush_1->clear();
    instructorDrivenOptimization_1->clear();
    youthLeagueRecommendation_1->clear();
    classifiedAsAPositiveScoremMember_1->clear();
    classifiedAsAPositiveGrassRootsPartyCommittee_1->clear();
    developContacts1_1->clear();
    developContacts2_1->clear();
    changeDevelopContacts1_1->clear();
    changeDevelopContacts2_1->clear();
    thoughtReport_1->clear();
    partyLectureCompletion_1->clear();
    autobiography_1->clear();
    developcontacts_1->clear();
    partyGroup_1->clear();
    numberOfPartyMembers_1->clear();
    numberOfPublicMembers_1->clear();
    memberDiscussion_1->clear();
    grassrootsPartyCommittee_1->clear();
    municipalities_1->clear();
    politicsCareful_1->clear();
    preliminary_1->clear();
    branchCongressToDiscussBecomingProbationary_1->clear();
    joiningThePartyIntroducer1_1->clear();
    joiningThePartyIntroducer2_1->clear();
    approvalOfGrassrootsPartyCommittee_1->clear();
    probationaryThought_1->clear();
    applicationForRegularization_1->clear();
    theBranchCongressRegularization_1->clear();
    grassrootsPartyCommitteeApproval_1->clear();


    QVariant info[44];
    info[0] = ID_1->text();
    info[1] = type_1->text();
    info[2] = name_1->text();
    info[3] = clas_1->text();
    info[4] = sex_1->text();
    info[5] = national_1->text();
    info[6] = address_1->text();
    info[7] = personalID_1->text();
    info[8] = phone_1->text();
    info[9] = origin_1->text();
    info[10] = birthday_1->text();
    info[11] = intoCollege_1->text();
    info[12] = talkWithApplicant_1->text();
    info[13] = applyForMembership_1->text();
    info[14] = league_1->text();
    info[15] = leagueBranchpush_1->text();
    info[16] = instructorDrivenOptimization_1->text();
    info[17] = youthLeagueRecommendation_1->text();
    info[18] = classifiedAsAPositiveScoremMember_1->text();
    info[19] = classifiedAsAPositiveGrassRootsPartyCommittee_1->text();
    info[20] = developContacts1_1->text();
    info[21] = developContacts2_1->text();
    info[22] = changeDevelopContacts1_1->text();
    info[23] = changeDevelopContacts2_1->text();
    info[24] = thoughtReport_1->text();
    info[25] = partyLectureCompletion_1->text();
    info[26] = autobiography_1->text();
    info[27] = developcontacts_1->text();
    info[28] = partyGroup_1->text();
    info[29] = numberOfPartyMembers_1->text();
    info[30] = numberOfPublicMembers_1->text();
    info[31] = memberDiscussion_1->text();
    info[32] = grassrootsPartyCommittee_1->text();
    info[33] = municipalities_1->text();
    info[34] = politicsCareful_1->text();
    info[35] = preliminary_1->text();
    info[36] = branchCongressToDiscussBecomingProbationary_1->text();
    info[37] = joiningThePartyIntroducer1_1->text();
    info[38] = joiningThePartyIntroducer2_1->text();
    info[39] = approvalOfGrassrootsPartyCommittee_1->text();
    info[40] = probationaryThought_1->text();
    info[41] = applicationForRegularization_1->text();
    info[42] = theBranchCongressRegularization_1->text();
    info[43] = grassrootsPartyCommitteeApproval_1->text();

    PersonalInformation* insertInfo = new PersonalInformation(info);
    int size = DB->getPersonalDate()->size();
    DB->getPersonalDate()->insert(size, insertInfo);//向QMap容器添加此人的信息

    QTreeWidgetItem* information = new QTreeWidgetItem;
    QString type = info[1].toString();
    QString name = info[2].toString();
    information->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    information->setCheckState(0,Qt::Unchecked);
    information->setTextAlignment(0,Qt::AlignCenter);
    maps.insert(size,information);//必须要把信息加到maps里面，这是用来返回索引值的
    pItem->addChild(information);
    emit sendCurrentIndex(size);
    pItem->setText(0,QString("人员信息[%1]").arg(pItem->childCount()));
    ui->treeWidget->update();
}

void MainWindow::oneClickGeneration_1(bool)
{
    QList<int> indexs;//用来记录选中的下标
    for(int ind = 0; ind < maps.size(); ind++)
    {
        if(maps.value(ind)->checkState(0))
        {
            indexs.append(ind);
        }
    }

    QList<PersonalInformation*> selectPersons;//获取选中人的信息
    foreach(int ind, indexs)
    {

        selectPersons.append(DB->getPersonalDate()->value(ind));
    }
    QString type=tr("积极分子备案报告");
    ForExcel excel(selectPersons, type);
}

void MainWindow::oneClickGeneration_2(bool)
{
    QList<int> indexs;//用来记录选中的下标
    for(int ind = 0; ind < maps.size(); ind++)
    {
        if(maps.value(ind)->checkState(0))
        {
            indexs.append(ind);
        }
    }

    QList<PersonalInformation*> selectPersons;//获取选中人的信息
    foreach(int ind, indexs)
    {

        selectPersons.append(DB->getPersonalDate()->value(ind));
    }
    qDebug() << selectPersons.at(1)->getPropertyValue(tr("姓名"));
    QString type=tr("发展对象备案报告");
    ForExcel excel(selectPersons, type);
}

void MainWindow::oneClickGeneration_3(bool)
{
    QList<int> indexs;//用来记录选中的下标
    for(int ind = 0; ind < maps.size(); ind++)
    {
        if(maps.value(ind)->checkState(0))
        {
            indexs.append(ind);
        }
    }

    QList<PersonalInformation*> selectPersons;//获取选中人的信息
    foreach(int ind, indexs)
    {

        selectPersons.append(DB->getPersonalDate()->value(ind));
    }
    qDebug() << selectPersons.at(1)->getPropertyValue(tr("姓名"));
    QString type=tr("发展对象预审请示");
    ForExcel excel(selectPersons, type);
}

void MainWindow::oneClickGeneration_4(bool)
{
    QList<int> indexs;//用来记录选中的下标
    for(int ind = 0; ind < maps.size(); ind++)
    {
        if(maps.value(ind)->checkState(0))
        {
            indexs.append(ind);
        }
    }

    QList<PersonalInformation*> selectPersons;//获取选中人的信息
    foreach(int ind, indexs)
    {

        selectPersons.append(DB->getPersonalDate()->value(ind));
    }
    qDebug() << selectPersons.at(1)->getPropertyValue(tr("姓名"));
    QString type=tr("接收预备党员");
    ForExcel excel(selectPersons, type);
}

void MainWindow::oneClickGeneration_5(bool)
{
    QList<int> indexs;//用来记录选中的下标
    for(int ind = 0; ind < maps.size(); ind++)
    {
        if(maps.value(ind)->checkState(0))
        {
            indexs.append(ind);
        }
    }

    QList<PersonalInformation*> selectPersons;//获取选中人的信息
    foreach(int ind, indexs)
    {

        selectPersons.append(DB->getPersonalDate()->value(ind));
    }
    qDebug() << selectPersons.at(1)->getPropertyValue(tr("姓名"));
    QString type=tr("预备党员转正");
    ForExcel excel(selectPersons, type);
}

void MainWindow::allConnectionFunction()
{
    connect(this->exitButton, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this, SLOT(showCheckInfo(QTreeWidgetItem *, int)));
    connect(this->readWrite, &QAction::triggered, this, &MainWindow::setEditOrNot);
    connect(this->readOnly, &QAction::triggered, this, &MainWindow::setEdit);
    connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &MainWindow::popMenu);
    connect(this ,&MainWindow::errorMessage, this,&WarningDlg::getErrorMessage);
    connect(this, &MainWindow::sendType, this, &MainWindow::sortItem);
    connect(this, &MainWindow::sendCurrentIndex, this, &MainWindow::curtentIndex);
    connect(this->sureButton, &QAction::triggered, this, &MainWindow::resetDates);
    connect(this->addNewOne, &QAction::triggered, this, &MainWindow::addNewOneInfo);


    /*tab中按键和编辑框的信号和槽联系,连接日历页面*/
//    connect(this->ID_2, &QPushButton::clicked, calendar = new Calendar(this->ID_1),&Calendar::setEditText);
//    connect(this->name_2, &QPushButton::clicked, calendar = new Calendar(this->name_1),&Calendar::setEditText);
//    connect(this->type_2, &QPushButton::clicked, calendar = new Calendar(this->type_1),&Calendar::setEditText);
//    connect(this->clas_2, &QPushButton::clicked, calendar = new Calendar(this->clas_1),&Calendar::setEditText);
//    connect(this->sex_2, &QPushButton::clicked, calendar = new Calendar(this->sex_1),&Calendar::setEditText);
//    connect(this->national_2, &QPushButton::clicked, calendar = new Calendar(this->national_1),&Calendar::setEditText);
//    connect(this->address_2, &QPushButton::clicked, calendar = new Calendar(this->address_1),&Calendar::setEditText);
//    connect(this->personalID_2, &QPushButton::clicked, calendar = new Calendar(this->personalID_1),&Calendar::setEditText);
//    connect(this->phone_2, &QPushButton::clicked, calendar = new Calendar(this->phone_1),&Calendar::setEditText);
//    connect(this->origin_2, &QPushButton::clicked, calendar = new Calendar(this->origin_1),&Calendar::setEditText);
    connect(this->birthday_2, &QPushButton::clicked, calendar = new Calendar(this->birthday_1),&Calendar::setEditText);
    connect(this->intoCollege_2, &QPushButton::clicked, calendar = new Calendar(this->intoCollege_1),&Calendar::setEditText);
    connect(this->talkWithApplicant_2, &QPushButton::clicked, calendar = new Calendar(this->talkWithApplicant_1),&Calendar::setEditText);
    connect(this->applyForMembership_2, &QPushButton::clicked, calendar = new Calendar(this->applyForMembership_1),&Calendar::setEditText);
    connect(this->league_2, &QPushButton::clicked, calendar = new Calendar(this->league_1),&Calendar::setEditText);
    connect(this->leagueBranchpush_2, &QPushButton::clicked, calendar = new Calendar(this->leagueBranchpush_1),&Calendar::setEditText);
    connect(this->instructorDrivenOptimization_2, &QPushButton::clicked, calendar = new Calendar(this->instructorDrivenOptimization_1),&Calendar::setEditText);
    connect(this->youthLeagueRecommendation_2, &QPushButton::clicked, calendar = new Calendar(this->youthLeagueRecommendation_1),&Calendar::setEditText);
    connect(this->classifiedAsAPositiveScoremMember_2, &QPushButton::clicked, calendar = new Calendar(this->classifiedAsAPositiveScoremMember_1),&Calendar::setEditText);
    connect(this->classifiedAsAPositiveGrassRootsPartyCommittee_2, &QPushButton::clicked, calendar = new Calendar(this->classifiedAsAPositiveGrassRootsPartyCommittee_1),&Calendar::setEditText);
    connect(this->developContacts1_2, &QPushButton::clicked, calendar = new Calendar(this->developContacts1_1),&Calendar::setEditText);
    connect(this->developContacts2_2, &QPushButton::clicked, calendar = new Calendar(this->developContacts2_1),&Calendar::setEditText);
    connect(this->changeDevelopContacts1_2, &QPushButton::clicked, calendar = new Calendar(this->changeDevelopContacts1_1),&Calendar::setEditText);
    connect(this->changeDevelopContacts2_2, &QPushButton::clicked, calendar = new Calendar(this->changeDevelopContacts2_1),&Calendar::setEditText);
    connect(this->thoughtReport_2, &QPushButton::clicked, calendar = new Calendar(this->thoughtReport_1),&Calendar::setEditText);
    connect(this->partyLectureCompletion_2, &QPushButton::clicked, calendar = new Calendar(this->partyLectureCompletion_1),&Calendar::setEditText);
    connect(this->autobiography_2, &QPushButton::clicked, calendar = new Calendar(this->autobiography_1),&Calendar::setEditText);
    connect(this->developcontacts_2, &QPushButton::clicked, calendar = new Calendar(this->developcontacts_1),&Calendar::setEditText);
    connect(this->partyGroup_2, &QPushButton::clicked, calendar = new Calendar(this->partyGroup_1),&Calendar::setEditText);
    connect(this->numberOfPartyMembers_2, &QPushButton::clicked, calendar = new Calendar(this->numberOfPartyMembers_1),&Calendar::setEditText);
    connect(this->numberOfPublicMembers_2, &QPushButton::clicked, calendar = new Calendar(this->numberOfPublicMembers_1),&Calendar::setEditText);
    connect(this->memberDiscussion_2, &QPushButton::clicked, calendar = new Calendar(this->grassrootsPartyCommittee_1),&Calendar::setEditText);
    connect(this->grassrootsPartyCommittee_2, &QPushButton::clicked, calendar = new Calendar(this->grassrootsPartyCommittee_1),&Calendar::setEditText);
    connect(this->municipalities_2, &QPushButton::clicked, calendar = new Calendar(this->municipalities_1),&Calendar::setEditText);
    connect(this->politicsCareful_2, &QPushButton::clicked, calendar = new Calendar(this->politicsCareful_1),&Calendar::setEditText);
    connect(this->preliminary_2, &QPushButton::clicked, calendar = new Calendar(this->preliminary_1),&Calendar::setEditText);
    connect(this->branchCongressToDiscussBecomingProbationary_2, &QPushButton::clicked, calendar = new Calendar(this->branchCongressToDiscussBecomingProbationary_1),&Calendar::setEditText);
    connect(this->joiningThePartyIntroducer1_2, &QPushButton::clicked, calendar = new Calendar(this->joiningThePartyIntroducer1_1),&Calendar::setEditText);
    connect(this->joiningThePartyIntroducer2_2, &QPushButton::clicked, calendar = new Calendar(this->joiningThePartyIntroducer2_1),&Calendar::setEditText);
    connect(this->approvalOfGrassrootsPartyCommittee_2, &QPushButton::clicked, calendar = new Calendar(this->approvalOfGrassrootsPartyCommittee_1),&Calendar::setEditText);
    connect(this->probationaryThought_2, &QPushButton::clicked, calendar = new Calendar(this->probationaryThought_1),&Calendar::setEditText);
    connect(this->applicationForRegularization_2, &QPushButton::clicked, calendar = new Calendar(this->applicationForRegularization_1),&Calendar::setEditText);
    connect(this->theBranchCongressRegularization_2, &QPushButton::clicked, calendar = new Calendar(this->theBranchCongressRegularization_1),&Calendar::setEditText);
    connect(this->grassrootsPartyCommitteeApproval_2, &QPushButton::clicked, calendar = new Calendar(this->grassrootsPartyCommitteeApproval_1),&Calendar::setEditText);

    /*一键生成的信号和槽连接*/
    connect(this->activists, &QAction::triggered, this, &MainWindow::oneClickGeneration_1);
    connect(this->developmentTargetRecord, &QAction::triggered, this, &MainWindow::oneClickGeneration_2);
    connect(this->predevelopmentTarget, &QAction::triggered, this, &MainWindow::oneClickGeneration_3);
    connect(this->receiveProbationary, &QAction::triggered, this, &MainWindow::oneClickGeneration_4);
    connect(this->probationaryRegularization, &QAction::triggered, this, &MainWindow::oneClickGeneration_5);
}

void MainWindow::createMenu()
{
        fileMenu = ui->menuBar->addMenu(tr("文件(&F)"));
        editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
        toolMenu = ui->menuBar->addMenu(tr("工具(&T)"));
        helpMenu = ui->menuBar->addMenu(tr("帮助(&H)"));
}

void MainWindow::createAction()
{
        /*菜单栏的文件按钮及其功能*/
        openFile = fileMenu->addAction(tr("打开文件(&O)"));
        saveFile = fileMenu->addAction(tr("保存(&S)"));
        saveFileAs = fileMenu->addAction(tr("另存为(&S)"));
        fileMenu->addSeparator();
        exportAs = fileMenu->addMenu(tr("导出为(&E)"));
        printFlie = fileMenu->addAction(tr("打印(&P)"));
        asExcel = exportAs->addAction(tr("Excel"));
        asWord = exportAs->addAction(tr("Word"));
        asSQLite = exportAs->addAction(tr("SQLite"));
        asAccess = exportAs->addAction(tr("Access"));
        fileMenu->addSeparator();
        exitButton = fileMenu->addAction(tr("退出(&Q)"));

        saveFile->setShortcut(QKeySequence("Ctrl+S"));
        openFile->setShortcut(QKeySequence("Ctrl+O"));
        saveFileAs->setShortcut(QKeySequence("Alt+S"));
        exitButton->setShortcut((QKeySequence("Ctrl+Q")));

        /*菜单栏的编辑按钮及其功能*/

        QActionGroup* editGroup = new QActionGroup(this);
        readOnly = editGroup->addAction(tr("只读"));
        readWrite = editGroup->addAction(tr("读/写"));
        readOnly->setCheckable(true);
        readWrite->setCheckable(true);
        readOnly->setChecked(true);
        editMenu->addAction(readOnly);
        editMenu->addAction(readWrite);


        /*菜单栏的工具按钮及其功能*/
        sureButton = toolMenu->addAction(tr("确定"));
        addNewOne = toolMenu->addAction(tr("添加新人员"));
        oneClickGeneration = toolMenu->addMenu(tr("一键生成"));
        activists = oneClickGeneration->addAction(tr("积极分子备案报告"));
        developmentTargetRecord = oneClickGeneration->addAction(tr("发展对象备案报告"));
        predevelopmentTarget = oneClickGeneration->addAction(tr("发展对象预审请示"));
        receiveProbationary = oneClickGeneration->addAction(tr("接收预备党员"));
        probationaryRegularization = oneClickGeneration->addAction(tr("预备党员转正"));


        /*菜单栏的帮助按钮及其功能*/
}

void MainWindow::creatTreeWidget()
{
    //设置页面布局
    QGridLayout* layout = new QGridLayout(ui->centralWidget);
    layout->addWidget(ui->treeWidget,0,0,1,4);
    layout->addWidget(ui->tabWidget,0,5,1,1);
    layout->sizeHint();

    QStringList nameList;//获取姓名
    QStringList typeList;//获取人员类别

    for(int i = 0; i < DB->getPersonalDate()->size(); i++)
    {
        nameList << DB->getPersonalDate()->value(i)->returnID();
        typeList << DB->getPersonalDate()->value(i)->returnType();
    }
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);//用于右击发送信号的，customContextMenuRequested信号
    ui->treeWidget->setHeaderLabels(QStringList() << " " << "姓名" << "人员类别");
    ui->treeWidget->setColumnWidth(0,100);
    ui->treeWidget->setColumnWidth(1,80);
    ui->treeWidget->setColumnWidth(2,80);
    pItem = new QTreeWidgetItem;//用于人员信息列表
    pItem2 = new QTreeWidgetItem;//用于台账
    for(int i = 0; i < DB->getPersonalDate()->size(); i++)
    {//注： 这里不能直接调用creatToolListItem（）函数，要先创建一个对象，不然没办法实现展开,information不能指定parent
        QTreeWidgetItem* information = new QTreeWidgetItem;
        information = creatToolListItem(typeList.at(i),nameList.at(i));
        maps.insert(i,information);
        listItem.append(information);
    }
    pItem->addChildren(listItem);
    pItem->setText(0,QString("人员信息[%1]").arg(pItem->childCount()));

    pItem2->setText(0,QString("台账"));
    ui->treeWidget->addTopLevelItem(pItem);
    ui->treeWidget->addTopLevelItem(pItem2);

}

void MainWindow::mergeButtonAndLineEdit(QPushButton * bttn, QLineEdit * lned)
{
    lned->setTextMargins(0,0,bttn->sizeHint().width(),0);//设置编辑框能编辑的边界只到按钮之前，即编辑框的宽度减去按钮的宽度
    lned->setFocusPolicy(Qt::NoFocus);//设置它的焦点，当它不可编辑的时候，可以看得到全部的文本
    QHBoxLayout* thisLayout = new QHBoxLayout();
    thisLayout->setContentsMargins(0,0,0,0);
    thisLayout->addWidget(bttn,0,Qt::AlignRight);
    lned->setLayout(thisLayout);
}

QTreeWidgetItem *MainWindow::creatToolListItem(const QString &name,const QString& type)
{
    QTreeWidgetItem* newItem = new QTreeWidgetItem;
    newItem->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    newItem->setCheckState(0,Qt::Unchecked);
    newItem->setText(1,QString("%1").arg(type));
    newItem->setText(2,QString("%2").arg(name));
    newItem->setTextAlignment(0,Qt::AlignCenter);
    return newItem;
}

void MainWindow::creatTabWidget()
{
    /*第一个窗口内容的实现*/
    QGridLayout* partLayout = new QGridLayout;//tab_3是第一个窗口
    /*打算用于创建头像
    QLabel* picture = new QLabel(ui->tab_3);
    QPixmap loadPix(":/picture/1.jpg");
    QPixmap restPix;
    restPix = loadPix.scaled(150,150,Qt::KeepAspectRatioByExpanding);
    restPix.toImage();
    qDebug()<<loadPix.isNull()<<loadPix.size();
    picture->resize(200,100);
    picture->setPixmap(restPix);
    picture->setStyleSheet("border:2px solid yellow;");
    picture->setFrameShape(QFrame::Box);
    partLayout->addWidget(picture,0,0,1,1);
*/
    /*创建第一个tab页面*/
    {
    name = new QLabel(tr("姓名"));
    ID = new QLabel(tr("学号"));
    type = new QLabel(tr("人员类别"));
    clas = new QLabel(tr("班级"));
    sex = new QLabel(tr("性别"));
    national = new QLabel(tr("民族"));
    address = new QLabel(tr("家庭住址"));
    personalID = new QLabel(tr("身份证号"));
    phone = new QLabel(tr("联系方式"));
    origin = new QLabel(tr("籍贯"));
    birthday = new QLabel(tr("出生年月日"));
    intoCollege = new QLabel(tr("入学时间"));
    name_1 = new QLineEdit("");
    ID_1 = new QLineEdit("");
    type_1 = new QLineEdit("");
    clas_1 = new QLineEdit("");
    sex_1 = new QLineEdit("");
    national_1 = new QLineEdit("");
    address_1 = new QLineEdit("");
    personalID_1 = new QLineEdit("");
    phone_1 = new QLineEdit("");
    origin_1 = new QLineEdit("");
    birthday_1 = new QLineEdit("");
    intoCollege_1 = new QLineEdit("");
    name_2 = new QPushButton("");
    ID_2 = new QPushButton("");
    type_2 = new QPushButton("");
    clas_2 = new QPushButton("");
    sex_2 = new QPushButton("");
    national_2 = new QPushButton("");
    address_2 = new QPushButton("");
    personalID_2 = new QPushButton("");
    phone_2 = new QPushButton("");
    origin_2 = new QPushButton("");
    birthday_2 = new QPushButton("日期");
    intoCollege_2 = new QPushButton("日期");
    mergeButtonAndLineEdit(name_2,name_1);
    mergeButtonAndLineEdit(ID_2,ID_1);
    mergeButtonAndLineEdit(type_2,type_1);
    mergeButtonAndLineEdit(clas_2,clas_1);
    mergeButtonAndLineEdit(sex_2,sex_1);
    mergeButtonAndLineEdit(national_2,national_1);
    mergeButtonAndLineEdit(address_2,address_1);
    mergeButtonAndLineEdit(personalID_2,personalID_1);
    mergeButtonAndLineEdit(phone_2,phone_1);
    mergeButtonAndLineEdit(origin_2,origin_1);
    mergeButtonAndLineEdit(birthday_2,birthday_1);
    mergeButtonAndLineEdit(intoCollege_2,intoCollege_1);
    partLayout->addWidget(name,2,0,1,1);
    partLayout->addWidget(name_1,2,1,1,3);
    partLayout->addWidget(ID,2,4,1,1);
    partLayout->addWidget(ID_1,2,5,1,3);

    partLayout->addWidget(type,3,0,1,1);
    partLayout->addWidget(type_1,3,1,1,3);
    partLayout->addWidget(clas,3,4,1,1);
    partLayout->addWidget(clas_1,3,5,1,3);

    partLayout->addWidget(sex,4,0,1,1);
    partLayout->addWidget(sex_1,4,1,1,3);
    partLayout->addWidget(national,4,4,1,1);
    partLayout->addWidget(national_1,4,5,1,3);

    partLayout->addWidget(address,5,0,1,1);
    partLayout->addWidget(address_1,5,1,1,3);
    partLayout->addWidget(personalID,5,4,1,1);
    partLayout->addWidget(personalID_1,5,5,1,3);

    partLayout->addWidget(phone,6,0,1,1);
    partLayout->addWidget(phone_1,6,1,1,3);
    partLayout->addWidget(origin,6,4,1,1);
    partLayout->addWidget(origin_1,6,5,1,3);

    partLayout->addWidget(birthday,7,0,1,1);
    partLayout->addWidget(birthday_1,7,1,1,3);
    partLayout->addWidget(intoCollege,7,4,1,1);
    partLayout->addWidget(intoCollege_1,7,5,1,3);
    ui->tab_3->setLayout(partLayout);
    }

    /*用于创建第二个tab页面*/
    {
    QVBoxLayout* vLayoutTab2 = new QVBoxLayout(ui->tab);
    //申请人阶段
    QGridLayout* gridLayoutTab2_1 = new QGridLayout;
    talkWithApplicant = new QLabel(tr("同申请人谈话时间"));
    applyForMembership = new QLabel(tr("申请入党时间"));
    league = new QLabel(tr("入团时间"));
    leagueBranchpush = new QLabel(tr("团支部推优时间"));
    instructorDrivenOptimization = new QLabel(tr("辅导员推荐时间"));
    youthLeagueRecommendation = new QLabel(tr("团委推荐时间"));
    talkWithApplicant_1 = new QLineEdit("");
    applyForMembership_1 = new QLineEdit("");
    league_1 = new QLineEdit("");
    leagueBranchpush_1 = new QLineEdit("");
    instructorDrivenOptimization_1 = new QLineEdit("");
    youthLeagueRecommendation_1 = new QLineEdit("");
    talkWithApplicant_2 = new QPushButton("日期");
    applyForMembership_2 = new QPushButton("日期");
    league_2 = new QPushButton("日期");
    leagueBranchpush_2 = new QPushButton("日期");
    instructorDrivenOptimization_2 = new QPushButton("日期");
    youthLeagueRecommendation_2 = new QPushButton("日期");

    mergeButtonAndLineEdit(talkWithApplicant_2,talkWithApplicant_1);
    mergeButtonAndLineEdit(applyForMembership_2,applyForMembership_1);
    mergeButtonAndLineEdit(league_2,league_1);
    mergeButtonAndLineEdit(leagueBranchpush_2,leagueBranchpush_1);
    mergeButtonAndLineEdit(instructorDrivenOptimization_2,instructorDrivenOptimization_1);
    mergeButtonAndLineEdit(youthLeagueRecommendation_2,youthLeagueRecommendation_1);

    gridLayoutTab2_1->addWidget(talkWithApplicant,0,0,1,1);
    gridLayoutTab2_1->addWidget(talkWithApplicant_1,0,1,1,3);
    gridLayoutTab2_1->addWidget(applyForMembership,0,4,1,1);
    gridLayoutTab2_1->addWidget(applyForMembership_1,0,5,1,3);

    gridLayoutTab2_1->addWidget(league,1,0,1,1);
    gridLayoutTab2_1->addWidget(league_1,1,1,1,3);
    gridLayoutTab2_1->addWidget(leagueBranchpush,1,4,1,1);
    gridLayoutTab2_1->addWidget(leagueBranchpush_1,1,5,1,3);

    gridLayoutTab2_1->addWidget(instructorDrivenOptimization,2,0,1,1);
    gridLayoutTab2_1->addWidget(instructorDrivenOptimization_1,2,1,1,3);
    gridLayoutTab2_1->addWidget(youthLeagueRecommendation,2,4,1,1);
    gridLayoutTab2_1->addWidget(youthLeagueRecommendation_1,2,5,1,3);

    //积极分子阶段
    QGridLayout* gridLayoutTab2_2 = new QGridLayout;
    classifiedAsAPositiveScoremMember = new QLabel(tr("列为积极分子时间_支委会"));
    classifiedAsAPositiveGrassRootsPartyCommittee = new QLabel(tr("列为积极分子时间_基层备案"));
    developContacts1 = new QLabel(tr("培养联系人1"));
    developContacts2 = new QLabel(tr("培养联系人2"));
    changeDevelopContacts1 = new QLabel(tr("更换后培养联系人"));
    changeDevelopContacts2 = new QLabel(tr("更换后培养联系人2"));
    thoughtReport = new QLabel(tr("思想汇报篇数"));
    partyLectureCompletion = new QLabel(tr("党课结业日期"));
    autobiography = new QLabel(tr("自传时间"));
    developcontacts = new QLabel(tr("培养联系人··列··时间"));
    partyGroup = new QLabel(tr("党小组··列··时间"));
    numberOfPartyMembers = new QLabel(tr("征求党内外党员人数"));
    numberOfPublicMembers = new QLabel(tr("群众人数"));
    memberDiscussion = new QLabel(tr("支委会讨论确定时间"));
    classifiedAsAPositiveScoremMember_1 = new QLineEdit("");
    classifiedAsAPositiveGrassRootsPartyCommittee_1 = new QLineEdit("");
    developContacts1_1 = new QLineEdit("");
    developContacts2_1 = new QLineEdit("");
    changeDevelopContacts1_1 = new QLineEdit("");
    changeDevelopContacts2_1 = new QLineEdit("");
    thoughtReport_1 = new QLineEdit("");
    partyLectureCompletion_1 = new QLineEdit("");
    autobiography_1 = new QLineEdit("");
    developcontacts_1 = new QLineEdit("");
    partyGroup_1 = new QLineEdit("");
    numberOfPartyMembers_1 = new QLineEdit("");
    numberOfPublicMembers_1 = new QLineEdit("");
    memberDiscussion_1 = new QLineEdit("");
    classifiedAsAPositiveScoremMember_2 = new QPushButton("日期");
    classifiedAsAPositiveGrassRootsPartyCommittee_2 = new QPushButton("日期");
    developContacts1_2 = new QPushButton("日期");
    developContacts2_2 = new QPushButton("日期");
    changeDevelopContacts1_2 = new QPushButton("日期");
    changeDevelopContacts2_2 = new QPushButton("日期");
    thoughtReport_2 = new QPushButton("日期");
    partyLectureCompletion_2 = new QPushButton("日期");
    autobiography_2 = new QPushButton("日期");
    developcontacts_2 = new QPushButton("日期");
    partyGroup_2 = new QPushButton("日期");
    numberOfPartyMembers_2 = new QPushButton("日期");
    numberOfPublicMembers_2 = new QPushButton("日期");
    memberDiscussion_2 = new QPushButton("日期");

    mergeButtonAndLineEdit(classifiedAsAPositiveScoremMember_2,classifiedAsAPositiveScoremMember_1);
    mergeButtonAndLineEdit(classifiedAsAPositiveGrassRootsPartyCommittee_2,classifiedAsAPositiveGrassRootsPartyCommittee_1);
    mergeButtonAndLineEdit(developContacts1_2,developContacts1_1);
    mergeButtonAndLineEdit(developContacts2_2,developContacts2_1);
    mergeButtonAndLineEdit(changeDevelopContacts1_2,changeDevelopContacts1_1);
    mergeButtonAndLineEdit(changeDevelopContacts2_2,changeDevelopContacts2_1);
    mergeButtonAndLineEdit(thoughtReport_2,thoughtReport_1);
    mergeButtonAndLineEdit(partyLectureCompletion_2,partyLectureCompletion_1);
    mergeButtonAndLineEdit(autobiography_2,autobiography_1);
    mergeButtonAndLineEdit(developcontacts_2,developcontacts_1);
    mergeButtonAndLineEdit(partyGroup_2,partyGroup_1);
    mergeButtonAndLineEdit(numberOfPartyMembers_2,numberOfPartyMembers_1);
    mergeButtonAndLineEdit(numberOfPublicMembers_2,numberOfPublicMembers_1);
    mergeButtonAndLineEdit(memberDiscussion_2,memberDiscussion_1);

    gridLayoutTab2_2->addWidget(classifiedAsAPositiveScoremMember,0,0,1,1);
    gridLayoutTab2_2->addWidget(classifiedAsAPositiveScoremMember_1,0,1,1,3);
    gridLayoutTab2_2->addWidget(classifiedAsAPositiveGrassRootsPartyCommittee,0,4,1,1);
    gridLayoutTab2_2->addWidget(classifiedAsAPositiveGrassRootsPartyCommittee_1,0,5,1,3);

    gridLayoutTab2_2->addWidget(developContacts1,1,0,1,1);
    gridLayoutTab2_2->addWidget(developContacts1_1,1,1,1,3);
    gridLayoutTab2_2->addWidget(developContacts2,1,4,1,1);
    gridLayoutTab2_2->addWidget(developContacts2_1,1,5,1,3);

    gridLayoutTab2_2->addWidget(changeDevelopContacts1,2,0,1,1);
    gridLayoutTab2_2->addWidget(changeDevelopContacts1_1,2,1,1,3);
    gridLayoutTab2_2->addWidget(changeDevelopContacts2,2,4,1,1);
    gridLayoutTab2_2->addWidget(changeDevelopContacts2_1,2,5,1,3);

    gridLayoutTab2_2->addWidget(thoughtReport,3,0,1,1);
    gridLayoutTab2_2->addWidget(thoughtReport_1,3,1,1,3);
    gridLayoutTab2_2->addWidget(partyLectureCompletion,3,4,1,1);
    gridLayoutTab2_2->addWidget(partyLectureCompletion_1,3,5,1,3);

    gridLayoutTab2_2->addWidget(autobiography,4,0,1,1);
    gridLayoutTab2_2->addWidget(autobiography_1,4,1,1,3);
    gridLayoutTab2_2->addWidget(developcontacts,4,4,1,1);
    gridLayoutTab2_2->addWidget(developcontacts_1,4,5,1,3);

    gridLayoutTab2_2->addWidget(partyGroup,5,0,1,1);
    gridLayoutTab2_2->addWidget(partyGroup_1,5,1,1,3);
    gridLayoutTab2_2->addWidget(numberOfPartyMembers,5,4,1,1);
    gridLayoutTab2_2->addWidget(numberOfPartyMembers_1,5,5,1,3);

    gridLayoutTab2_2->addWidget(numberOfPublicMembers,6,0,1,1);
    gridLayoutTab2_2->addWidget(numberOfPublicMembers_1,6,1,1,3);
    gridLayoutTab2_2->addWidget(memberDiscussion,6,4,1,1);
    gridLayoutTab2_2->addWidget(memberDiscussion_1,6,5,1,3);


    //发展对象阶段
    QGridLayout* gridLayoutTab2_3 = new QGridLayout;
    grassrootsPartyCommittee = new QLabel(tr("基层党委备案时间（发展对象）"));
    municipalities = new QLabel(tr("函调时间"));
    politicsCareful = new QLabel(tr("政审时间"));
    preliminary = new QLabel(tr("基层党委预审意见时间"));
    grassrootsPartyCommittee_1 = new QLineEdit("");
    municipalities_1 = new QLineEdit("");
    politicsCareful_1 = new QLineEdit("");
    preliminary_1 = new QLineEdit("");
    grassrootsPartyCommittee_2 = new QPushButton("日期");
    municipalities_2 = new QPushButton("日期");
    politicsCareful_2 = new QPushButton("日期");
    preliminary_2 = new QPushButton("日期");

    mergeButtonAndLineEdit(grassrootsPartyCommittee_2,grassrootsPartyCommittee_1);
    mergeButtonAndLineEdit(municipalities_2,municipalities_1);
    mergeButtonAndLineEdit(politicsCareful_2,politicsCareful_1);
    mergeButtonAndLineEdit(preliminary_2,preliminary_1);

    gridLayoutTab2_3->addWidget(grassrootsPartyCommittee,0,0,1,1);
    gridLayoutTab2_3->addWidget(grassrootsPartyCommittee_1,0,1,1,3);
    gridLayoutTab2_3->addWidget(municipalities,0,4,1,1);
    gridLayoutTab2_3->addWidget(municipalities_1,0,5,1,3);

    gridLayoutTab2_3->addWidget(politicsCareful,1,0,1,1);
    gridLayoutTab2_3->addWidget(politicsCareful_1,1,1,1,3);
    gridLayoutTab2_3->addWidget(preliminary,1,4,1,1);
    gridLayoutTab2_3->addWidget(preliminary_1,1,5,1,3);

    vLayoutTab2->addLayout(gridLayoutTab2_1);
    vLayoutTab2->addSpacing(100);
    vLayoutTab2->addLayout(gridLayoutTab2_2);
    vLayoutTab2->addSpacing(100);
    vLayoutTab2->addLayout(gridLayoutTab2_3);
    ui->tab->setLayout(vLayoutTab2);
    }

    /*用于第三个页面*/
    {
    /*党员阶段*/
    branchCongressToDiscussBecomingProbationary = new QLabel(tr("支部大会讨论接收申请人为预备党员会议时间"));
    joiningThePartyIntroducer1 = new QLabel(tr("入党介绍人1"));
    joiningThePartyIntroducer2 = new QLabel(tr("入党介绍人2"));
    approvalOfGrassrootsPartyCommittee = new QLabel(tr("基层党委审批意见"));
    probationaryThought = new QLabel(tr("预备党员思想汇报篇数"));
    applicationForRegularization = new QLabel(tr("转正申请书时间"));
    theBranchCongressRegularization = new QLabel(tr("支部大会通过预备党员能否转为正式党员的会议时间"));
    grassrootsPartyCommitteeApproval = new QLabel(tr("基层党委审批时间"));
    branchCongressToDiscussBecomingProbationary_1 = new QLineEdit(tr(""));
    joiningThePartyIntroducer1_1 = new QLineEdit(tr(""));
    joiningThePartyIntroducer2_1 = new QLineEdit(tr(""));
    approvalOfGrassrootsPartyCommittee_1 = new QLineEdit(tr(""));
    probationaryThought_1 = new QLineEdit(tr(""));
    applicationForRegularization_1 = new QLineEdit(tr(""));
    theBranchCongressRegularization_1 = new QLineEdit(tr(""));
    grassrootsPartyCommitteeApproval_1 = new QLineEdit(tr(""));
    branchCongressToDiscussBecomingProbationary_2 = new QPushButton("日期");
    joiningThePartyIntroducer1_2 = new QPushButton("日期");
    joiningThePartyIntroducer2_2 = new QPushButton("日期");
    approvalOfGrassrootsPartyCommittee_2 = new QPushButton("日期");
    probationaryThought_2 = new QPushButton("日期");
    applicationForRegularization_2 = new QPushButton("日期");
    theBranchCongressRegularization_2 = new QPushButton("日期");
    grassrootsPartyCommitteeApproval_2 = new QPushButton("日期");

    mergeButtonAndLineEdit(branchCongressToDiscussBecomingProbationary_2,branchCongressToDiscussBecomingProbationary_1);
    mergeButtonAndLineEdit(joiningThePartyIntroducer1_2,joiningThePartyIntroducer1_1);
    mergeButtonAndLineEdit(joiningThePartyIntroducer2_2,joiningThePartyIntroducer2_1);
    mergeButtonAndLineEdit(approvalOfGrassrootsPartyCommittee_2,approvalOfGrassrootsPartyCommittee_1);
    mergeButtonAndLineEdit(probationaryThought_2,probationaryThought_1);
    mergeButtonAndLineEdit(applicationForRegularization_2,applicationForRegularization_1);
    mergeButtonAndLineEdit(theBranchCongressRegularization_2,theBranchCongressRegularization_1);
    mergeButtonAndLineEdit(grassrootsPartyCommitteeApproval_2,grassrootsPartyCommitteeApproval_1);

    QGridLayout* gridLayoutTab3 = new QGridLayout(ui->tab_2);
    gridLayoutTab3->addWidget(branchCongressToDiscussBecomingProbationary,0,0,1,1);
    gridLayoutTab3->addWidget(branchCongressToDiscussBecomingProbationary_1,0,1,1,3);
    gridLayoutTab3->addWidget(joiningThePartyIntroducer1,0,4,1,1);
    gridLayoutTab3->addWidget(joiningThePartyIntroducer1_1,0,5,1,3);

    gridLayoutTab3->addWidget(joiningThePartyIntroducer2,1,0,1,1);
    gridLayoutTab3->addWidget(joiningThePartyIntroducer2_1,1,1,1,3);
    gridLayoutTab3->addWidget(approvalOfGrassrootsPartyCommittee,1,4,1,1);
    gridLayoutTab3->addWidget(approvalOfGrassrootsPartyCommittee_1,1,5,1,3);

    gridLayoutTab3->addWidget(probationaryThought,2,0,1,1);
    gridLayoutTab3->addWidget(probationaryThought_1,2,1,1,3);
    gridLayoutTab3->addWidget(applicationForRegularization,2,4,1,1);
    gridLayoutTab3->addWidget(applicationForRegularization_1,2,5,1,3);

    gridLayoutTab3->addWidget(theBranchCongressRegularization,3,0,1,1);
    gridLayoutTab3->addWidget(theBranchCongressRegularization_1,3,1,1,3);
    gridLayoutTab3->addWidget(grassrootsPartyCommitteeApproval,3,4,1,1);
    gridLayoutTab3->addWidget(grassrootsPartyCommitteeApproval_1,3,5,1,3);
    }
}
