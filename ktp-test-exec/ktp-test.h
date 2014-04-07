#ifndef ktp_test_H
#define ktp_test_H

#include <QtGui/QMainWindow>

class ktp_test : public QMainWindow
{
    Q_OBJECT
public:
    ktp_test();
    virtual ~ktp_test();

private Q_SLOTS:
    void slotShareProviderFinishedSuccess(const QString &result);
    void slotShareProviderFinishedFailure(const QString &result);

};

#endif // ktp_test_H
