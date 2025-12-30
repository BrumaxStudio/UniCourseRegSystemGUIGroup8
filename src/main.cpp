#include <QApplication>
#include "loginwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug() << "hi";

    LoginWindow log;
    log.show();

    return app.exec();
}
