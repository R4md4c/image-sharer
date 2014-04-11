#ifndef ktp_test_H
#define ktp_test_H

#include <QtGui/QMainWindow>

class ShareProvider;

class ktp_test : public QMainWindow
{
    Q_OBJECT
public:
    ktp_test();
    virtual ~ktp_test();

private Q_SLOTS:
    void slotShareProviderFinishedSuccess(ShareProvider *provider, const QString &result);
    void slotShareProviderFinishedFailure(ShareProvider *provider, const QString &result);

};

#endif // ktp_test_H
