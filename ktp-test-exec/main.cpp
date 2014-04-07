#include <QtGui/QApplication>
#include "ktp-test.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ktp_test foo;
    foo.show();
    return app.exec();
}
