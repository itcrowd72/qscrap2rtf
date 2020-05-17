#include "wizardpage1.h"
#include "ui_wizardpage1.h"

WizardPage1::WizardPage1(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage1) {
  ui->setupUi(this);

  // Set Watermark to first page
  #ifdef Q_OS_LINUX
    setPixmap(QWizard::WatermarkPixmap, QPixmap("/usr/share/qscrap2rtf/pixmaps/watermark.png"));
  #else
  #ifdef Q_OS_WIN32
    setPixmap(QWizard::WatermarkPixmap, QPixmap(qApp->applicationDirPath()+"\\pixmaps\\watermark.png"));
  #endif
  #endif
}
//-------------------------------------------------------------------------

WizardPage1::~WizardPage1() {
  delete ui;
}
//-------------------------------------------------------------------------
