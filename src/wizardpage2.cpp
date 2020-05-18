#include "wizardpage2.h"
#include "ui_wizardpage2.h"
#include <QFileDialog>
#include "wizard.h"
#include "helpers.h"

WizardPage2::WizardPage2(QWidget *parent): QWizardPage(parent), ui(new Ui::WizardPage2) {
  ui->setupUi(this);

  QString szLogoPath;

  // Set Logo to second page
  #ifdef Q_OS_LINUX
    szLogoPath = "/usr/share/qscrap2rtf/pixmaps/main.png";

    if (!FileExists(szLogoPath)) {
      szLogoPath = qApp->applicationDirPath() + "/data/pixmaps/main.png";
    }
  #else
  #ifdef Q_OS_WIN32
    szLogoPath = qApp->applicationDirPath()+"\\pixmaps\\main.png");
  #endif
  #endif

  setPixmap(QWizard::LogoPixmap, QPixmap(szLogoPath));
}
//-------------------------------------------------------------------------

WizardPage2::~WizardPage2() {
  delete ui;
}
//-------------------------------------------------------------------------

// The function checks the list. If it is empty, then the "Next" button is inactive
bool WizardPage2::isComplete() const {
  bool bIsListEmpty = (ui->listWidget->count() > 0);

  ui->pushButton_3->setEnabled(bIsListEmpty);
  ui->pushButton_4->setEnabled(bIsListEmpty);

  return bIsListEmpty;
}
//-------------------------------------------------------------------------

// Clear list button
void WizardPage2::on_pushButton_4_clicked() {
  // Clear list
  szScrapNames.clear();

  // Clear listWidget
  ui->listWidget->clear();

  // exec isComplete() function
  emit completeChanged();
}
//-------------------------------------------------------------------------

// Remove file button
void WizardPage2::on_pushButton_3_clicked() {
  int currentItem = ui->listWidget->row(ui->listWidget->currentItem());

  // Remove selected item from list
  szScrapNames.removeAt(currentItem);

  // Remove selected item from listWidget
  ui->listWidget->takeItem(currentItem);

  // exec isComplete() function
  emit completeChanged();
}
//-------------------------------------------------------------------------

// Add file button
void WizardPage2::on_pushButton_clicked() {
  // Get selected file names
  QStringList templist = QFileDialog::getOpenFileNames(this,tr("Add scraps"),"", tr("Scrap Files (*.shs)"));

  // Append file names to list
  szScrapNames += templist;

  // Remove duplicates from list before render to listWidget
  szScrapNames.removeDuplicates();

  // Clear listWidget
  ui->listWidget->clear();

  // Append file names to listWidget
  ui->listWidget->addItems(szScrapNames);

  // Set first row after adding elements
  ui->listWidget->setCurrentRow(0);

  // exec isComplete() function
  emit completeChanged();
}
//-------------------------------------------------------------------------

// Add directory button
void WizardPage2::on_pushButton_2_clicked() {
  // Select the directory to search for scraps
  QString szOpenDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"",
    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  // To search for files will use QDir
  QDir qdirOpenDir (szOpenDir);

  // Adding to the list only files with the extension .shs
  QStringList templist = qdirOpenDir.entryList(QStringList("*.shs"));

  // Why is QDir adds to the list the names of files with relative paths,
  // and we need the absolute
  for (int i = 0; i < templist.count(); i++) {
    // Set the absolute paths and add them to the list
    templist[i] = szOpenDir + "/" + templist[i];
  }

  // Append file names to list
  szScrapNames += templist;

  // Remove duplicates from list before render to listWidget
  szScrapNames.removeDuplicates();

  // Clear listWidget
  ui->listWidget->clear();

  // Append file names to listWidget
  ui->listWidget->addItems(szScrapNames);

  // Set first row after adding elements
  ui->listWidget->setCurrentRow(0);

  // exec isComplete() function
  emit completeChanged();
}
//-------------------------------------------------------------------------
