#ifndef ACCOUNTPAGEWINDOW_HPP
#define ACCOUNTPAGEWINDOW_HPP

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QStringList>
#include <QLabel>
#include <QHeaderView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPointer>

#include <termcolor/termcolor.hpp>
#include <nlohmann/json.hpp>
#include <httplib.h>

#include <thread>
#include <iostream>

class AccountPageWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountPageWindow(QWidget *parent = nullptr);

signals:
    void login_page();
    void signup_page();
    void reload_page();
    void save_page();

public:
    nlohmann::json dataM;
    nlohmann::json dataMMM;
    nlohmann::json reader_json;
    void refreshPage();
    void reset();
    QTableWidget* scheTable;
    QTableWidget* enrolledScheTable;

    QString ipAddress;
    QString portNumber;
    QString userName;

    void selectSchedule(QTableWidgetItem* checkBOX);

private:
    int refreshCount;
    int saveCount;

    QMetaObject::Connection refreshMO;

    QLabel* mainText;
    QTableWidget* table;

    QLabel* scheduleLabel;
    QLabel* enrolledScheduleLabel;

    QVBoxLayout* mainLayout;

    QPushButton* logOutPB;
    QPushButton* SignInPB;
    QPushButton* ReLoadPB;

    QPushButton* SavePB;
    QHBoxLayout* SaveLayout;

    QHBoxLayout* LOSI;

};

#endif // ACCOUNTPAGEWINDOW_HPP
