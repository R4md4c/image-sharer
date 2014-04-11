#include "ktp-test.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>

#include <QMessageBox>


#include "image-sharer/shareprovider.h"

ktp_test::ktp_test()
{
    QLabel* l = new QLabel( this );
    l->setText( QLatin1String("Hello World!") );
    setCentralWidget( l );
    QAction* a = new QAction(this);
    a->setText( QLatin1String("Quit") );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( QLatin1String("File") )->addAction( a );
    ShareProvider *provider = new ShareProvider(ShareProvider::availableShareServices().value(QLatin1String("Image Bin")), this);
    connect(provider, SIGNAL(finishedError(ShareProvider*,QString)), this, SLOT(slotShareProviderFinishedFailure(ShareProvider*,QString)));
    connect(provider, SIGNAL(finishedSuccess(ShareProvider*,QString)), this, SLOT(slotShareProviderFinishedSuccess(ShareProvider*,QString)));

    // Put the image path here
    provider->publish(QLatin1String("/home/ramdac/1975269_620119998057124_1889819789_n.jpg"));

}

ktp_test::~ktp_test()
{}

void ktp_test::slotShareProviderFinishedFailure(ShareProvider* provider, const QString& result)
{
    QMessageBox::critical(this, QLatin1String("Failure"), result);
    provider->deleteLater();
}

void ktp_test::slotShareProviderFinishedSuccess(ShareProvider* provider, const QString& result)
{
    QMessageBox::information(this, QLatin1String("Success"), result);
    provider->deleteLater();
}

#include "ktp-test.moc"
