#include "wizardpage3.h"
#include "ui_wizardpage3.h"
#include <QFileDialog>
#include "wizard.h"
#include "helpers.h"

WizardPage3::WizardPage3(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage3) {
  ui->setupUi(this);

  QString szLogoPath;

  // Set Logo to third page
  #ifdef Q_OS_LINUX
    szLogoPath = "/usr/share/qscrap2rtf/pixmaps/main.png";

    if (!FileExists(szLogoPath)) {
      szLogoPath = qApp->applicationDirPath() + "/data/pixmaps/main.png";
    }
  #else
  #ifdef Q_OS_WIN32
    szLogoPath = qApp->applicationDirPath() + "\\pixmaps\\main.png");
  #endif
  #endif

  setPixmap(QWizard::LogoPixmap, QPixmap(szLogoPath));

  bRemoveOriginal = false;        // initialize global variable
  szOutputDir = ".";              // initialize global variable

  setCommitPage(true);            // Disable Back button on next page
}
//-------------------------------------------------------------------------

WizardPage3::~WizardPage3() {
  delete ui;
}
//-------------------------------------------------------------------------

// "Remove original" CheckBox clicked
void WizardPage3::on_checkBox_stateChanged(int arg1) {
  // if checked
  bRemoveOriginal = (arg1 == 2);
}
//-------------------------------------------------------------------------

// Browse button clicked
void WizardPage3::on_pushButton_clicked() {
  // Select the output directory
  szOutputDir = QFileDialog::getExistingDirectory(this, tr("Output Directory"),"",
    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  // set text to lineEdit
  ui->lineEdit->setText(szOutputDir);

  // if szOutputDir is empty then szOutputDir = current directory (.)
  if (szOutputDir.isEmpty()) {
    szOutputDir = ".";
  }
}
//-------------------------------------------------------------------------
