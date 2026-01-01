#ifndef ACCOUNTPAGEWINDOW_HPP
#define ACCOUNTPAGEWINDOW_HPP

#include <QWidget>

class AccountPageWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountPageWindow(QWidget *parent = nullptr);

signals:
    void login_page();

private:

};

#endif // ACCOUNTPAGEWINDOW_HPP
