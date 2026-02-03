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
    scheTable->setColumnCount(12);

    SavePB = new QPushButton(this);
    SavePB->setFont(QFont("Times"));
    SavePB->setText("Save");
    SavePB->setFixedSize(QSize(100, 20));

    SaveLayout = new QHBoxLayout;
    SaveLayout->addStretch();
    SaveLayout->addWidget(SavePB);

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

    ReLoadPB = new QPushButton(this);
    ReLoadPB->setFont(QFont("Times"));
    ReLoadPB->setText("Refresh Page");

    LOSI = new QHBoxLayout;
    LOSI->addWidget(logOutPB);
    LOSI->addWidget(SignInPB);
    LOSI->addWidget(ReLoadPB);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainText);
    mainLayout->addWidget(table);
    mainLayout->addWidget(scheduleLabel);
    mainLayout->addWidget(scheTable);
    mainLayout->addLayout(SaveLayout);
    mainLayout->addWidget(enrolledScheduleLabel);
    mainLayout->addWidget(enrolledScheTable);
    mainLayout->addLayout(LOSI);

    this->setLayout(mainLayout);

    QObject::connect(scheTable, &QTableWidget::itemChanged, this, &AccountPageWindow::selectSchedule);
}

void AccountPageWindow::refreshPage(){

    reader_json["enroll"] = nlohmann::json::array();

    if(dataM.contains("data") && !dataM["data"].is_null() && dataM.contains("schedule") && !dataM["schedule"].is_null() && dataM["schedule"].is_array()){
        std::cout << dataM.dump() << std::endl;
        auto data = dataM["data"];
        auto scheDataList = dataM["schedule"];

        QStringList headers = {"Matric No", "First", "Middle Name", "Last Name", "Gender", "Date of Birth", "Department", "Level", "Email Address", "Phone Number", "School Name"};
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        QStringList scheHeader = {"Schedule ID", "Day of Week", "Starting Time", "Closing Time", "Venue", "Lecturer", "Course Code", "Course Title", "Current Enrollments", "Maximum Capacity", "Enrollment Status", "Select"};
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

        scheTable->blockSignals(true);

        for(size_t x = 0; x < scheDataList.size(); x++){
            scheTable->insertRow(x);
            auto scheData = scheDataList[x];
            auto checkBOX = new QTableWidgetItem();
            checkBOX->setFlags(checkBOX->flags() | Qt::ItemIsUserCheckable);
            checkBOX->setCheckState((scheData["enrollment_status"].get<std::string>() == "not active")? Qt::Unchecked: Qt::Checked);

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
            scheTable->setItem(x, 10, new QTableWidgetItem(QString::fromStdString(scheData["enrollment_status"].get<std::string>())));
            scheTable->setItem(x, 11, checkBOX);
        }

        scheTable->blockSignals(false);

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
                enrolledScheTable->setItem(x, 3, new QTableWidgetItem(QString::fromStdString(scheData["end_time"].get<std::string>())));
                enrolledScheTable->setItem(x, 4, new QTableWidgetItem(QString::fromStdString(scheData["venue"].get<std::string>())));
                enrolledScheTable->setItem(x, 5, new QTableWidgetItem(QString::fromStdString(scheData["name"].get<std::string>())));
                enrolledScheTable->setItem(x, 6, new QTableWidgetItem(QString::fromStdString(scheData["course_code"].get<std::string>())));
                enrolledScheTable->setItem(x, 7, new QTableWidgetItem(QString::fromStdString(scheData["course_title"].get<std::string>())));
                enrolledScheTable->setItem(x, 8, new QTableWidgetItem(QString::fromStdString(scheData["current_enrollment"].get<std::string>())));
                enrolledScheTable->setItem(x, 9, new QTableWidgetItem(QString::fromStdString(scheData["max_capacity"].get<std::string>())));
                enrolledScheTable->setItem(x, 10, new QTableWidgetItem(QString::fromStdString(scheData["grade"].get<std::string>())));
                enrolledScheTable->setItem(x, 11, new QTableWidgetItem(QString::fromStdString(scheData["date_enrolled"].get<std::string>())));
                enrolledScheTable->setItem(x, 12, new QTableWidgetItem(QString::fromStdString(scheData["enrollment_status"].get<std::string>())));
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

    saveCount = 0;

    QObject::connect(SavePB, &QPushButton::clicked, [this](){
        reader_json["user_name"] = userName.toStdString();
        QPointer<AccountPageWindow> self(this);
        std::jthread([self](std::stop_token st){
            if(st.stop_requested()) std::exit(0);

            QString Url = QString("http://%1:%2").arg(self->ipAddress, self->portNumber);

            httplib::Client client(Url.toStdString());
            auto response = client.Post("/enrollin/schedules", self->reader_json.dump(), "application/json");
            if(response){
                if(response->status == 200){
                    self->saveCount++;
                    self->dataMMM = nlohmann::json::parse(response->body);
                    std::cout << termcolor::green << "Success: " << self->dataMMM["message"] << termcolor::reset << std::endl;
                    self->reader_json["enroll"].clear();
                    QMetaObject::invokeMethod(self, [self, st](){
                        if(st.stop_requested()) std::exit(0);
                        if(self->saveCount == 1){
                            QMessageBox::information(self, "Success", "Successfully enrolled/unenrolled in schedule(s)!");
                        }
                        emit self->reload_page();
                    }, Qt::QueuedConnection);
                }
                else{
                    self->saveCount++;
                    self->dataMMM = nlohmann::json::parse(response->body);
                    self->reader_json["enroll"].clear();
                    if(self->saveCount == 1){
                        std::cerr << termcolor::red << "Message: " << self->dataMMM["message"] << termcolor::reset << std::endl;
                        QMetaObject::invokeMethod(self, [self, st](){
                            if(st.stop_requested()) std::exit(0);
                            QMessageBox::warning(self, "Error", QString::fromStdString(self->dataMMM["message"]));
                        }, Qt::QueuedConnection);
                    }
                }
            }
            else{
                std::cout << termcolor::red << "Server Error" << termcolor::reset << std::endl;
                self->reader_json["enroll"].clear();
                QMetaObject::invokeMethod(self, [self, st](){
                    if(st.stop_requested()) std::exit(0);
                    QMessageBox::warning(self, "Server Error", "Server is down, contact support or wait");
                }, Qt::QueuedConnection);
            }
        }).detach();
        //emit save_page();
    });

    refreshCount = 0;

    QObject::disconnect(refreshMO);

    refreshMO = QObject::connect(ReLoadPB, &QPushButton::clicked, [this](){
        reader_json["user_name"] = userName.toStdString();

        QPointer<AccountPageWindow> self(this);

        std::jthread([self](std::stop_token st){
            if(st.stop_requested()) std::exit(0);

            QString Url = QString("http://%1:%2").arg(self->ipAddress, self->portNumber);

            httplib::Client client(Url.toStdString());
            auto response = client.Post("/refresh/page", self->reader_json.dump(), "application/json");

            if(response){
                if(response->status == 200){
                    self->refreshCount++;
                    self->dataMMM = nlohmann::json::parse(response->body);
                    std::cout << termcolor::green << "Success: " << self->dataMMM["message"] << termcolor::reset << std::endl;
                    QMetaObject::invokeMethod(self, [self, st](){
                        if(st.stop_requested()) std::exit(0);
                        if(self->refreshCount == 1){
                            QMessageBox::information(self, "Success", "Refreshing page...");
                            emit self->reload_page();
                        }
                    }, Qt::QueuedConnection);
                }
                else{
                    self->refreshCount++;
                    self->dataMMM = nlohmann::json::parse(response->body);
                    if(self->refreshCount == 1){
                        std::cerr << termcolor::red << "Message: " << self->dataMMM["message"] << termcolor::reset << std::endl;
                        QMetaObject::invokeMethod(self, [self, st](){
                            if(st.stop_requested()) std::exit(0);
                            QMessageBox::warning(self, "Error", QString::fromStdString(self->dataMMM["message"]));
                        }, Qt::QueuedConnection);
                    }
                }
            }
            else{
                std::cout << termcolor::red << "Server Error" << termcolor::reset << std::endl;
                QMetaObject::invokeMethod(self, [self, st](){
                    if(st.stop_requested()) std::exit(0);
                    QMessageBox::warning(self, "Server Error", "Server is down, contact support or wait");
                }, Qt::QueuedConnection);
            }

        }).detach();
    });
}

void AccountPageWindow::reset(){
    table->clear();

    scheTable->setRowCount(0);
    scheTable->clear();

    enrolledScheTable->setRowCount(0);
    enrolledScheTable->clear();
}

void AccountPageWindow::selectSchedule(QTableWidgetItem* checkBOX){
    if(checkBOX->column() != 11) return;

    int theRowTheScheduleWasCheckedFrom = checkBOX->row();
    size_t scheduleID = scheTable->item(theRowTheScheduleWasCheckedFrom, 0)->text().toInt();

    if(checkBOX->checkState() == Qt::Checked){
        std::cout << "Row: " << theRowTheScheduleWasCheckedFrom + 1 << " CHECKED" << std::endl;
        std::cout << "Enrolled in schedule " << scheduleID << std::endl;
        reader_json["enroll"].push_back({{"action", "register"}, {"ID", scheduleID}});
    }
    else{
        std::cout << "Row: " << theRowTheScheduleWasCheckedFrom + 1 << " UNCHECKED" << std::endl;
        std::cout << "Deleted enrollment in schedule " << scheduleID << std::endl;
        reader_json["enroll"].push_back({{"action", "unregister"}, {"ID", scheduleID}});
    }
}

