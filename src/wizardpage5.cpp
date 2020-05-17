#include "wizardpage5.h"
#include "ui_wizardpage5.h"

WizardPage5::WizardPage5(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage5) {
  ui->setupUi(this);

  // Set Watermark to last page
  #ifdef Q_OS_LINUX
    setPixmap(QWizard::WatermarkPixmap, QPixmap("/usr/share/qscrap2rtf/pixmaps/watermark.png"));
  #else
  #ifdef Q_OS_WIN32
    setPixmap(QWizard::WatermarkPixmap, QPixmap(qApp->applicationDirPath()+"\\pixmaps\\watermark.png"));
  #endif
  #endif
}
//-------------------------------------------------------------------------

WizardPage5::~WizardPage5() {
  delete ui;
}
//-------------------------------------------------------------------------
