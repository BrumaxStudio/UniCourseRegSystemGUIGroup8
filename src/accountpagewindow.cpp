#include "accountpagewindow.hpp"

AccountPageWindow::AccountPageWindow(QWidget *parent)
    : QWidget{parent}
{
    mainText = new QLabel(this);
    mainText->setFont(QFont("Times", 25));
    mainText->setText("Student Course Registration");

    table = new QTableWidget(this);
    table->setColumnCount(10);

    scheduleLabel = new QLabel(this);
    scheduleLabel->setFont(QFont("Times", 18));
    scheduleLabel->setText("Available Schedules");

    scheTable = new QTableWidget(this);
    scheTable->setColumnCount(6);

    logOutPB = new QPushButton(this);
    logOutPB->setFont(QFont("Times"));
    logOutPB->setText("Log Out");

    SignInPB = new QPushButton(this);
    SignInPB->setFont(QFont("Times"));
    SignInPB->setText("Sign In");

    LOSI = new QHBoxLayout;
    LOSI->addWidget(logOutPB);
    LOSI->addWidget(SignInPB);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainText);
    mainLayout->addWidget(table);
    mainLayout->addWidget(scheduleLabel);
    mainLayout->addWidget(scheTable);
    mainLayout->addLayout(LOSI);

    this->setLayout(mainLayout);
}

void AccountPageWindow::refreshPage(){

    if(dataM.contains("data") && !dataM["data"].is_null() && dataM.contains("schedule") && !dataM["schedule"].is_null() && dataM["schedule"].is_array()){
        std::cout << dataM.dump() << std::endl;
        auto data = dataM["data"];
        auto scheDataList = dataM["schedule"];

        QStringList headers = {"Matric No", "First", "Middle Name", "Last Name", "Sex", "Department", "Level", "Email Address", "Phone Number", "School Name"};
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        QStringList scheHeader = {"Schedule ID", "Day of Week", "Time", "Venue", "Lecturer", "Course Code"};
        scheTable->setHorizontalHeaderLabels(scheHeader);
        scheTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        table->setRowCount(1);

        table->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(data.at("mat_no").get<std::string>())));
        table->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(data.at("first_name").get<std::string>())));
        table->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(data.at("middle_name").get<std::string>())));
        table->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(data.at("last_name").get<std::string>())));
        table->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(data.at("sex").get<std::string>())));
        table->setItem(0, 5, new QTableWidgetItem(QString::fromStdString(data.at("dept").get<std::string>())));
        table->setItem(0, 6, new QTableWidgetItem(QString::number(data.at("level").get<int>())));
        table->setItem(0, 7, new QTableWidgetItem(QString::fromStdString(data.at("email").get<std::string>())));
        table->setItem(0, 8, new QTableWidgetItem(QString::number(data.at("phone_no").get<long long>())));
        table->setItem(0, 9, new QTableWidgetItem(QString::fromStdString(data.at("name").get<std::string>())));

        for(size_t x = 0; x < scheDataList.size(); x++){
            scheTable->insertRow(x);
            auto scheData = scheDataList[x];

            scheTable->setItem(x, 0, new QTableWidgetItem(QString::number(scheData["schedule_id"].get<int>())));
            scheTable->setItem(x, 1, new QTableWidgetItem(QString::fromStdString(scheData["day_of_week"].get<std::string>())));
            scheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["time"].get<std::string>())));
            scheTable->setItem(x, 3, new QTableWidgetItem(QString::fromStdString(scheData["venue"].get<std::string>())));
            scheTable->setItem(x, 4, new QTableWidgetItem(QString::fromStdString(scheData["name"].get<std::string>())));
            scheTable->setItem(x, 5, new QTableWidgetItem(QString::fromStdString(scheData["course_code"].get<std::string>())));
        }
    }
    else{
        std::cout << "Empty Record" << std::endl;
    }

    QObject::connect(logOutPB, &QPushButton::clicked, [&](){
        emit login_page();
    });

    QObject::connect(SignInPB, &QPushButton::clicked, [&](){
        emit signup_page();
    });
}

void AccountPageWindow::reset(){
    table->clear();
    scheTable->clear();
}

