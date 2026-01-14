#ifndef ACCOUNTPAGEWINDOW_HPP
#define ACCOUNTPAGEWINDOW_HPP

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QStringList>
#include <QLabel>

class AccountPageWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountPageWindow(QWidget *parent = nullptr);

signals:
    void login_page();

private:
    QLabel* mainText;
    QTableWidget* table;

    QVBoxLayout* mainLayout;
};

#endif // ACCOUNTPAGEWINDOW_HPP
