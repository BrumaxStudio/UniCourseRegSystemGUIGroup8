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

#include <nlohmann/json.hpp>

#include <iostream>

class AccountPageWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountPageWindow(QWidget *parent = nullptr);

signals:
    void login_page();
    void signup_page();

public:
    nlohmann::json dataM;
    void refreshPage();
    void reset();
    QTableWidget* scheTable;

private:
    QLabel* mainText;
    QTableWidget* table;

    QLabel* scheduleLabel;

    QVBoxLayout* mainLayout;

    QPushButton* logOutPB;
    QPushButton* SignInPB;
    QHBoxLayout* LOSI;

};

#endif // ACCOUNTPAGEWINDOW_HPP
