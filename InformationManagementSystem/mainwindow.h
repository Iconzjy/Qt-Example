#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbstruct.h"
#include <QDate>
namespace Ui {
class MainWindow;
}


class QMenu;
class QAction;
class QLayout;
class QToolBox;
class QGroupBox;
class QTreeWidgetItem;
class QLineEdit;
class QLabel;
class QCalendarWidget;
class Calendar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showCheckInfo(QTreeWidgetItem*,int);//用来映射个人信息的基本内容
    void setEditOrNot(bool);//设置是否可以编辑
    void setEdit(bool);//设置可以编辑，即setEditOrNot值的非
    void popMenu(const QPoint& );//创建右击菜单弹出窗口
    void deleteItem(bool);//用于右击菜单中的删除操作,注：这里只是删除副本，最终还是要到数据库中删除
    void sortType(bool);//用于选择人员类别,所有人
    void sortType1(bool);//用于选择人员类别,申请人
    void sortType2(bool);//用于选择人员类别，积极分子
    void sortType3(bool);//用于选择人员类别，发展对象
    void sortType4(bool);//用于选择人员类别，预备党员
    void sortType5(bool);//用于选择人员类别，正式党员
    void sortItem(QString type);//用于选择人员类别，选择类别
    void curtentIndex(int);//用来初始化当前的索引下标,private中的current变量
    void resetDates(bool);//更改容器里此人的某个时间
    void addNewOneInfo(bool);//用于添加新的人员信息，即创建一个新的窗口
    void oneClickGeneration_1(bool);//自动生成积极分子备案报告
    void oneClickGeneration_2(bool);//自动生成发展对象备案报告
    void oneClickGeneration_3(bool);//自动生成发展对象预审请示
    void oneClickGeneration_4(bool);//自动生成接收预备党员
    void oneClickGeneration_5(bool);//自动生成预备党员转正

signals:
    void errorMessage(QString);
    void sendType(QString);//用于选择人员类别，发送类别
    void setDateLast(QString);//用于发送修改的日期，将其转化为QString
    void sendCurrentIndex(int);//返回某个人的索引，用QMap容器的功能
//    void sendItemPoint(QTreeWidgetItem*);//发送当前的Item的指针

private:
    Ui::MainWindow *ui;
    DBStruct* DB;

/**************************************************************************************
 * 用来创建主窗口的所有按钮*
 * allConnectionFunction()把所有的信号和槽之间的封装在同一个函数里面
 * createMenu()和createAction();创建按钮
***************************************************************************************/
    void allConnectionFunction();
    void createMenu();
    void createAction();
    /*菜单栏的文件按钮及其功能键*/
    QMenu* fileMenu;//文件，注：用于获取Access数据库的文件路径
    QMenu* exportAs;//导出为
    QAction* asExcel;//导出为excel
    QAction* asWord;//导出为word
    QAction* asSQLite;//导出为SQLit
    QAction* asAccess;//导出为Access
    QAction* openFile;//打开文件
    QAction* saveFile;//保存文件
    QAction* saveFileAs;//另存为
    QAction* printFlie;//打印
    QAction* exitButton;//退出

    /*菜单栏的编辑按钮及其功能*/
    QMenu* editMenu;//编辑
    QAction* readOnly;//只读
    QAction* readWrite;//读写



    /*菜单栏的工具按钮及其功能*/
    QMenu* toolMenu;//工具
    QAction* sureButton;//用于修改信息的确定按钮
    QAction* addNewOne;//添加新的人员
    QMenu* oneClickGeneration;//一键生成
    QAction* activists;//积极分子备案报告
    QAction* developmentTargetRecord;//发展对象备案报告
    QAction* predevelopmentTarget;//发展对象预审请示
    QAction* receiveProbationary;//接收预备党员
    QAction* probationaryRegularization;//预备党员转正

    /*菜单栏的帮助按钮及其功能*/
    QMenu* helpMenu;//帮助


    /*****************************************************************************
     *用来创建主窗口的布局以及相应的子窗口 *
     * 其中关于tab窗口部件的信号和槽的连接全部放在mergeButtonAndLineEdit()函数当中，节省代码量*
    ******************************************************************************/
    QTreeWidgetItem* creatToolListItem(const QString& name, const QString & type);
    QGroupBox* personalGroup;
    void creatTabWidget();//用于初始化右边窗口显示基本信息内容
    void creatTreeWidget();//创建左边列表的信息
    QList<QTreeWidgetItem*> listItem;//存储左边信息列表的指针
    QMap<int,QTreeWidgetItem*> maps;//用来获取索引值
    int current;//在整个应用还在运行时，记录当前选中人员的索引值
    QTreeWidgetItem* pCurrentPointer;//某个指针，这里用于记录选中的pItem子节点的某个指针，主要用于删除某个人员信息
    QTreeWidgetItem* pItem;
    QTreeWidgetItem* pItem2;
    Calendar* calendar;
    void mergeButtonAndLineEdit(QPushButton*, QLineEdit*);
    /*用于第一个tab页面*/
    QLabel* name;
    QLabel* ID;
    QLabel* type;
    QLabel* clas;
    QLabel* sex;
    QLabel* national;
    QLabel* address;
    QLabel* personalID;
    QLabel* phone;
    QLabel* origin;
    QLabel* birthday;
    QLabel* intoCollege;
    QLineEdit* name_1;
    QLineEdit* ID_1;
    QLineEdit* type_1;
    QLineEdit* clas_1;
    QLineEdit* sex_1;
    QLineEdit* national_1;
    QLineEdit* address_1;
    QLineEdit* personalID_1;
    QLineEdit* phone_1;
    QLineEdit* origin_1;
    QLineEdit* birthday_1;
    QLineEdit* intoCollege_1;
    QPushButton* name_2;
    QPushButton* ID_2;
    QPushButton* type_2;
    QPushButton* clas_2;
    QPushButton* sex_2;
    QPushButton* national_2;
    QPushButton* address_2;
    QPushButton* personalID_2;
    QPushButton* phone_2;
    QPushButton* origin_2;
    QPushButton* birthday_2;
    QPushButton* intoCollege_2;

    /*用于创建第二个tab页面*/
    //申请人阶段
    QLabel* talkWithApplicant;
    QLabel* applyForMembership;
    QLabel* league;
    QLabel* leagueBranchpush;
    QLabel* instructorDrivenOptimization;
    QLabel* youthLeagueRecommendation;
    QLineEdit* talkWithApplicant_1;
    QLineEdit* applyForMembership_1;
    QLineEdit* league_1;
    QLineEdit* leagueBranchpush_1;
    QLineEdit* instructorDrivenOptimization_1;
    QLineEdit* youthLeagueRecommendation_1;
    QPushButton* talkWithApplicant_2;
    QPushButton* applyForMembership_2;
    QPushButton* league_2;
    QPushButton* leagueBranchpush_2;
    QPushButton* instructorDrivenOptimization_2;
    QPushButton* youthLeagueRecommendation_2;
    //积极分子阶段
    QLabel* classifiedAsAPositiveScoremMember;//列为积极分子时间
    QLabel* classifiedAsAPositiveGrassRootsPartyCommittee;
    QLabel* developContacts1;
    QLabel* developContacts2;
    QLabel* changeDevelopContacts1;
    QLabel* changeDevelopContacts2;
    QLabel* thoughtReport;
    QLabel* partyLectureCompletion;//党课结业日期
    QLabel* autobiography;
    QLabel* developcontacts;//培养联系人..列..时间
    QLabel* partyGroup;
    QLabel* numberOfPartyMembers;//征求党内外党员人数
    QLabel* numberOfPublicMembers;
    QLabel* memberDiscussion;
    QLineEdit* classifiedAsAPositiveScoremMember_1;//列为积极分子时间
    QLineEdit* classifiedAsAPositiveGrassRootsPartyCommittee_1;
    QLineEdit* developContacts1_1;
    QLineEdit* developContacts2_1;
    QLineEdit* changeDevelopContacts1_1;
    QLineEdit* changeDevelopContacts2_1;
    QLineEdit* thoughtReport_1;
    QLineEdit* partyLectureCompletion_1;//党课结业日期
    QLineEdit* autobiography_1;
    QLineEdit* developcontacts_1;//培养联系人..列..时间
    QLineEdit* partyGroup_1;
    QLineEdit* numberOfPartyMembers_1;//征求党内外党员人数
    QLineEdit* numberOfPublicMembers_1;
    QLineEdit* memberDiscussion_1;
    QPushButton* classifiedAsAPositiveScoremMember_2;//列为积极分子时间
    QPushButton* classifiedAsAPositiveGrassRootsPartyCommittee_2;
    QPushButton* developContacts1_2;
    QPushButton* developContacts2_2;
    QPushButton* changeDevelopContacts1_2;
    QPushButton* changeDevelopContacts2_2;
    QPushButton* thoughtReport_2;
    QPushButton* partyLectureCompletion_2;//党课结业日期
    QPushButton* autobiography_2;
    QPushButton* developcontacts_2;//培养联系人..列..时间
    QPushButton* partyGroup_2;
    QPushButton* numberOfPartyMembers_2;//征求党内外党员人数
    QPushButton* numberOfPublicMembers_2;
    QPushButton* memberDiscussion_2;
    //发展对象阶段
    QLabel* grassrootsPartyCommittee;//基层党委备案时间
    QLabel* municipalities;
    QLabel* politicsCareful;
    QLabel* preliminary;
    QLineEdit* grassrootsPartyCommittee_1;//基层党委备案时间
    QLineEdit* municipalities_1;
    QLineEdit* politicsCareful_1;
    QLineEdit* preliminary_1;
    QPushButton* grassrootsPartyCommittee_2;//基层党委备案时间
    QPushButton* municipalities_2;
    QPushButton* politicsCareful_2;
    QPushButton* preliminary_2;

    /*用于第三个页面*/
    /*党员阶段*/
    QLabel* branchCongressToDiscussBecomingProbationary;//支部大会讨论成为预备党员时间
    QLabel* joiningThePartyIntroducer1;
    QLabel* joiningThePartyIntroducer2;
    QLabel* approvalOfGrassrootsPartyCommittee;//基层党委审批
    QLabel* probationaryThought;
    QLabel* applicationForRegularization;
    QLabel* theBranchCongressRegularization;//支部大会转正会议日期
    QLabel* grassrootsPartyCommitteeApproval;
    QLineEdit* branchCongressToDiscussBecomingProbationary_1;//支部大会讨论成为预备党员时间
    QLineEdit* joiningThePartyIntroducer1_1;
    QLineEdit* joiningThePartyIntroducer2_1;
    QLineEdit* approvalOfGrassrootsPartyCommittee_1;//基层党委审批
    QLineEdit* probationaryThought_1;
    QLineEdit* applicationForRegularization_1;
    QLineEdit* theBranchCongressRegularization_1;//支部大会转正会议日期
    QLineEdit* grassrootsPartyCommitteeApproval_1;
    QPushButton* branchCongressToDiscussBecomingProbationary_2;//支部大会讨论成为预备党员时间
    QPushButton* joiningThePartyIntroducer1_2;
    QPushButton* joiningThePartyIntroducer2_2;
    QPushButton* approvalOfGrassrootsPartyCommittee_2;//基层党委审批
    QPushButton* probationaryThought_2;
    QPushButton* applicationForRegularization_2;
    QPushButton* theBranchCongressRegularization_2;//支部大会转正会议日期
    QPushButton* grassrootsPartyCommitteeApproval_2;

};


#endif // MAINWINDOW_H
