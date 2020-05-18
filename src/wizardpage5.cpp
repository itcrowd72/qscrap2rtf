#include "wizardpage5.h"
#include "ui_wizardpage5.h"
#include "helpers.h"

WizardPage5::WizardPage5(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage5) {
  ui->setupUi(this);

  QString szWatermarkPath;

  // Set Watermark to last page
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

WizardPage5::~WizardPage5() {
  delete ui;
}
//-------------------------------------------------------------------------
