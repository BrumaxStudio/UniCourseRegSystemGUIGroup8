#include "accountpagewindow.hpp"

AccountPageWindow::AccountPageWindow(QWidget *parent)
    : QWidget{parent}
{
    mainText = new QLabel(this);
    mainText->setFont(QFont("Times", 25));
    mainText->setText("Student Course Registration");
    table = new QTableWidget(this);
    table->setColumnCount(11);

    scheduleLabel = new QLabel(this);
    scheduleLabel->setFont(QFont("Times", 18));
    scheduleLabel->setText("Available Schedules");
    scheTable = new QTableWidget(this);
    scheTable->setColumnCount(10);

    enrolledScheduleLabel = new QLabel(this);
    enrolledScheduleLabel->setFont(QFont("Times", 18));
    enrolledScheduleLabel->setText("Enrolled Schedules");
    enrolledScheTable = new QTableWidget(this);
    enrolledScheTable->setColumnCount(13);

    logOutPB = new QPushButton(this);
    logOutPB->setFont(QFont("Times"));
    logOutPB->setText("Log Out");

    SignInPB = new QPushButton(this);
    SignInPB->setFont(QFont("Times"));
    SignInPB->setText("Sign Up");

    LOSI = new QHBoxLayout;
    LOSI->addWidget(logOutPB);
    LOSI->addWidget(SignInPB);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainText);
    mainLayout->addWidget(table);
    mainLayout->addWidget(scheduleLabel);
    mainLayout->addWidget(scheTable);
    mainLayout->addWidget(enrolledScheduleLabel);
    mainLayout->addWidget(enrolledScheTable);
    mainLayout->addLayout(LOSI);

    this->setLayout(mainLayout);
}

void AccountPageWindow::refreshPage(){

    if(dataM.contains("data") && !dataM["data"].is_null() && dataM.contains("schedule") && !dataM["schedule"].is_null() && dataM["schedule"].is_array()){
        std::cout << dataM.dump() << std::endl;
        auto data = dataM["data"];
        auto scheDataList = dataM["schedule"];

        QStringList headers = {"Matric No", "First", "Middle Name", "Last Name", "Gender", "Date of Birth", "Department", "Level", "Email Address", "Phone Number", "School Name"};
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        QStringList scheHeader = {"Schedule ID", "Day of Week", "Starting Time", "Closing Time", "Venue", "Lecturer", "Course Code", "Course Title", "Current Enrollments", "Maximum Capacity"};
        scheTable->setHorizontalHeaderLabels(scheHeader);
        scheTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        for(int i = 0; i < table->columnCount(); i++){
            auto* item = table->horizontalHeaderItem(i);
            if(item){
                item->setBackground((i % 2)? Qt::white: Qt::gray);
            }
        }

        table->setRowCount(1);

        table->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(data.at("mat_no").get<std::string>())));
        table->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(data.at("first_name").get<std::string>())));
        table->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(data.at("middle_name").get<std::string>())));
        table->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(data.at("last_name").get<std::string>())));
        table->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(data.at("gender").get<std::string>())));
        table->setItem(0, 5, new QTableWidgetItem(QString::fromStdString(data.at("date_of_birth").get<std::string>())));
        table->setItem(0, 6, new QTableWidgetItem(QString::fromStdString(data.at("dept").get<std::string>())));
        table->setItem(0, 7, new QTableWidgetItem(QString::number(data.at("level").get<int>())));
        table->setItem(0, 8, new QTableWidgetItem(QString::fromStdString(data.at("email").get<std::string>())));
        table->setItem(0, 9, new QTableWidgetItem("0" + QString::number(data.at("phone_no").get<long long>())));
        table->setItem(0, 10, new QTableWidgetItem(QString::fromStdString(data.at("school_name").get<std::string>())));

        for(int i = 0; i < scheTable->columnCount(); i++){
            auto* item = scheTable->horizontalHeaderItem(i);
            if(item){
                item->setBackground((i % 2)? Qt::white: Qt::gray);
            }
        }

        for(size_t x = 0; x < scheDataList.size(); x++){
            scheTable->insertRow(x);
            auto scheData = scheDataList[x];

            scheTable->setItem(x, 0, new QTableWidgetItem(QString::number(scheData["schedule_id"].get<int>())));
            scheTable->setItem(x, 1, new QTableWidgetItem(QString::fromStdString(scheData["day_of_week"].get<std::string>())));
            scheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["start_time"].get<std::string>())));
            scheTable->setItem(x, 3, new QTableWidgetItem(QString::fromStdString(scheData["end_time"].get<std::string>())));
            scheTable->setItem(x, 4, new QTableWidgetItem(QString::fromStdString(scheData["venue"].get<std::string>())));
            scheTable->setItem(x, 5, new QTableWidgetItem(QString::fromStdString(scheData["name"].get<std::string>())));
            scheTable->setItem(x, 6, new QTableWidgetItem(QString::fromStdString(scheData["course_code"].get<std::string>())));
            scheTable->setItem(x, 7, new QTableWidgetItem(QString::fromStdString(scheData["course_title"].get<std::string>())));
            scheTable->setItem(x, 8, new QTableWidgetItem(QString::fromStdString(scheData["current_enrollment"].get<std::string>())));
            scheTable->setItem(x, 9, new QTableWidgetItem(QString::fromStdString(scheData["max_capacity"].get<std::string>())));
        }

        QStringList enrolledScheHeader = {"Schedule ID", "Day of Week", "Starting Time", "Closing Time", "Venue", "Lecturer", "Course Code", "Course Title", "Current Enrollments", "Max Capacity", "Grade", "Date Enrolled", "Enrollment Status"};
        enrolledScheTable->setHorizontalHeaderLabels(enrolledScheHeader);
        enrolledScheTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        for(int i = 0; i < enrolledScheTable->columnCount(); i++){
            auto* item = enrolledScheTable->horizontalHeaderItem(i);
            if(item){
                item->setBackground((i % 2)? Qt::white: Qt::gray);
            }
        }

        if(!dataM["enrolled_schedule"].is_null() && dataM["enrolled_schedule"].is_array()){
            auto enrolledScheDataList = dataM["enrolled_schedule"];
            for(size_t x = 0; x < enrolledScheDataList.size(); x++){
                enrolledScheTable->insertRow(x);
                auto scheData = enrolledScheDataList[x];

                enrolledScheTable->setItem(x, 0, new QTableWidgetItem(QString::number(scheData["schedule_id"].get<int>())));
                enrolledScheTable->setItem(x, 1, new QTableWidgetItem(QString::fromStdString(scheData["day_of_week"].get<std::string>())));
                enrolledScheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["start_time"].get<std::string>())));
                enrolledScheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["end_time"].get<std::string>())));
                enrolledScheTable->setItem(x, 3, new QTableWidgetItem(QString::fromStdString(scheData["venue"].get<std::string>())));
                enrolledScheTable->setItem(x, 4, new QTableWidgetItem(QString::fromStdString(scheData["name"].get<std::string>())));
                enrolledScheTable->setItem(x, 5, new QTableWidgetItem(QString::fromStdString(scheData["course_code"].get<std::string>())));
                enrolledScheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["course_title"].get<std::string>())));
                enrolledScheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["current_enrollment"].get<std::string>())));
                enrolledScheTable->setItem(x, 2, new QTableWidgetItem(QString::fromStdString(scheData["max_capacity"].get<std::string>())));
                enrolledScheTable->setItem(x, 6, new QTableWidgetItem(QString::fromStdString(scheData["grade"].get<std::string>())));
                enrolledScheTable->setItem(x, 7, new QTableWidgetItem(QString::fromStdString(scheData["date_enrolled"].get<std::string>())));
                enrolledScheTable->setItem(x, 8, new QTableWidgetItem(QString::fromStdString(scheData["enrollment_status"].get<std::string>())));
            }
        }

    }
    else{
        std::cout << "Empty Record" << std::endl;
    }

    QObject::connect(logOutPB, &QPushButton::clicked, [this](){
        emit login_page();
    });

    QObject::connect(SignInPB, &QPushButton::clicked, [this](){
        emit signup_page();
    });
}

void AccountPageWindow::reset(){
    table->clear();
    scheTable->setRowCount(0);
    scheTable->clear();

    enrolledScheTable->setRowCount(0);
    enrolledScheTable->clear();
}

