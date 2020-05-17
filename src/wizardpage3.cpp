#include "wizardpage3.h"
#include "ui_wizardpage3.h"
#include <QFileDialog>
#include "wizard.h"

WizardPage3::WizardPage3(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPage3)
{
    ui->setupUi(this);

    // Set Logo to third page
    #ifdef Q_OS_LINUX
        setPixmap(QWizard::LogoPixmap, QPixmap("/usr/share/qscrap2rtf/pixmaps/main.png"));
    #else
    #ifdef Q_OS_WIN32
		setPixmap(QWizard::LogoPixmap, QPixmap(qApp->applicationDirPath()+"\\pixmaps\\main.png"));
    #endif
    #endif

    bRemoveOriginal = false;        // initialize global variable
    szOutputDir = ".";              // initialize global variable

    setCommitPage(true);                            // Disable Back button on next page
}
//-------------------------------------------------------------------------

WizardPage3::~WizardPage3()
{
    delete ui;
}
//-------------------------------------------------------------------------

// "Remove original" CheckBox clicked
void WizardPage3::on_checkBox_stateChanged(int arg1)
{
    // if checked
    if ( arg1 == 2 )
        bRemoveOriginal = true;
    else
        bRemoveOriginal = false;
}
//-------------------------------------------------------------------------

// Browse button clicked
void WizardPage3::on_pushButton_clicked()
{
    // Select the output directory
    szOutputDir = QFileDialog::getExistingDirectory(this, tr("Output Directory"),"",
                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // set text to lineEdit
    ui->lineEdit->setText(szOutputDir);

    // if szOutputDir is empty then szOutputDir = current directory (.)
    if (szOutputDir.isEmpty())
        szOutputDir = ".";
}
//-------------------------------------------------------------------------
