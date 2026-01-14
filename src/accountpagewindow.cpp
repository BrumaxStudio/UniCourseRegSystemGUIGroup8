#include "accountpagewindow.hpp"

AccountPageWindow::AccountPageWindow(QWidget *parent)
    : QWidget{parent}
{
    mainText = new QLabel(this);
    mainText->setFont(QFont("Times", 25));
    mainText->setText("Student");

    int row = 10;

    table = new QTableWidget(this);
    table->setColumnCount(11);
    table->setRowCount(row);

    QStringList headers = {"Matric No", "First", "Middle Name", "Last Name", "Sex", "Date of Birth", "Department", "Level", "Email Address", "Phone Number", "School"};
    table->setHorizontalHeaderLabels(headers);
    for(size_t x = 0; x < 10; x++){
        table->setItem(x, 0, new QTableWidgetItem("DE.2067"));
        table->setItem(x, 1, new QTableWidgetItem("Tamaratare"));
        table->setItem(x, 2, new QTableWidgetItem("Oghenebrume"));
        table->setItem(x, 3, new QTableWidgetItem("David"));
        table->setItem(x, 4, new QTableWidgetItem("Male"));
        table->setItem(x, 5, new QTableWidgetItem("2345-01-03"));
        table->setItem(x, 6, new QTableWidgetItem("Computer Engineering"));
        table->setItem(x, 7, new QTableWidgetItem("300"));
        table->setItem(x, 8, new QTableWidgetItem("creg8@gmail.com"));
        table->setItem(x, 9, new QTableWidgetItem("+23467"));
        table->setItem(x, 10, new QTableWidgetItem("Rivers State University"));
    }


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainText);
    mainLayout->addWidget(table);

    this->setLayout(mainLayout);
}
