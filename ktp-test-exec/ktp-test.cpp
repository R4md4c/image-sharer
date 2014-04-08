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
    l->setText( "Hello World!" );
    setCentralWidget( l );
    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( a );
    ShareProvider *provider = new ShareProvider(ShareProvider::Imgur, this);
    connect(provider, SIGNAL(finishedSuccess(QString)), this, SLOT(slotShareProviderFinishedSuccess(QString)));
    connect(provider, SIGNAL(finishedError(QString)), this, SLOT(slotShareProviderFinishedFailure(QString)));

    // Put the image paath here
    provider->publish("/home/ramdac/1975269_620119998057124_1889819789_n.jpg");

}

ktp_test::~ktp_test()
{}

void ktp_test::slotShareProviderFinishedFailure(const QString& result)
{
    QMessageBox::critical(this, "Failure", result);
}

void ktp_test::slotShareProviderFinishedSuccess(const QString& result)
{
    QMessageBox::information(this, "Success", result);
}


#include "ktp-test.moc"
