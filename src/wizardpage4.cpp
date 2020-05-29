#include "wizardpage4.h"
#include "ui_wizardpage4.h"
#include "wizard.h"
#include <QTimer>
#include <QProcess>
#include <QTextCodec>
#include "helpers.h"

// TODO: Fix no previous extern declaration for non-static variable 'bWorkDone'
bool bWorkDone = false;     // if convert is done, then enable "Next" button

WizardPage4::WizardPage4(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage4) {
  ui->setupUi(this);

  QString szLogoPath;

  // Set Logo to fourth page
  #ifdef Q_OS_LINUX
    szLogoPath = "/usr/share/qscrap2rtf/pixmaps/main.png";

    if (!FileExists(szLogoPath)) {
      szLogoPath = qApp->applicationDirPath() + "/data/pixmaps/main.png";
    }
  #else
  #ifdef Q_OS_WIN32
    szLogoPath = qApp->applicationDirPath()+"\\pixmaps\\main.png";
  #endif
  #endif

  setPixmap(QWizard::LogoPixmap, QPixmap(szLogoPath));
}
//-------------------------------------------------------------------------

WizardPage4::~WizardPage4() {
  delete ui;
}
//-------------------------------------------------------------------------

// The function checks the list. If it is empty, then the "Next" button is inactive
bool WizardPage4::isComplete() const {
  return bWorkDone;
}
//-------------------------------------------------------------------------

void WizardPage4::Convert() {
  // Set maximum to progressBar (files count)
  ui->progressBar->setMaximum(szScrapNames.count());

  for (int i=1; i <= ui->progressBar->maximum(); i++) {
    // Create process
    QProcess proc;

    // Options
    QStringList args;
    args << "-v";

    // if remove original
    if (bRemoveOriginal) {
      args << "-r";
    }

    // if output directory is present
    if (szOutputDir != ".") {
      args << "--output=" + szOutputDir;
    }

    // add scrap name
    args << szScrapNames[i-1];

    // Start process
    #ifdef Q_OS_LINUX
      proc.start("/usr/bin/scrap2rtf", args);
    #else
    #ifdef Q_OS_WIN32
      proc.start(qApp->applicationDirPath() + "\\bin\\scrap2rtf.exe", args);
    #endif
    #endif

    // converting...
    proc.waitForFinished();

    // Convert output to unicode
    #ifdef Q_OS_LINUX
      QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    #else
    #ifdef Q_OS_WIN32
      QTextCodec* codec = QTextCodec::codecForName("Windows-1251");
    #endif
    #endif

    QString output = codec->toUnicode(proc.readAllStandardOutput());

    // Add log to textEdit
    ui->textEdit->append(output);

    ui->progressBar->setValue(i);
    qApp->processEvents();

    ui->label->setText(QString(tr("Process file %1 from %2")).arg(i).arg(ui->progressBar->maximum()));
    qApp->processEvents();
  }

  bWorkDone = true;

  // exec isComplete() function
  emit completeChanged();
}
//-------------------------------------------------------------------------

// Page activated
void WizardPage4::initializePage() {
  // Start convert after 1 second
  QTimer::singleShot(1000, this, SLOT(Convert()));
}
//-------------------------------------------------------------------------
