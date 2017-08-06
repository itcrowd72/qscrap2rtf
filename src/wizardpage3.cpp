/* QScrap2rtf - a simple program to convert Shell Scrap Object File to Rich Text Format
   Copyright (C) 2012 Andrey Ivnitsky.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Andrey Ivnitsky <ivnitsky.a@gmail.com> */

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
