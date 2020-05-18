#include "wizardpage1.h"
#include "ui_wizardpage1.h"
#include "helpers.h"

WizardPage1::WizardPage1(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage1) {
  ui->setupUi(this);

  QString szWatermarkPath;

  // Set Watermark to first page
  #ifdef Q_OS_LINUX
    szWatermarkPath = "/usr/share/qscrap2rtf/pixmaps/watermark.png";

    if (!FileExists(szWatermarkPath)) {
      szWatermarkPath = qApp->applicationDirPath() + "/data/pixmaps/watermark.png";
    }
  #else
  #ifdef Q_OS_WIN32
    szWatermarkPath = qApp->applicationDirPath()+"\\pixmaps\\watermark.png";
  #endif
  #endif

  setPixmap(QWizard::WatermarkPixmap, QPixmap(szWatermarkPath));
}
//-------------------------------------------------------------------------

WizardPage1::~WizardPage1() {
  delete ui;
}
//-------------------------------------------------------------------------
