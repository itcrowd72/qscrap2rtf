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

#include "wizardpage2.h"
#include "ui_wizardpage2.h"
#include <QFileDialog>
#include "wizard.h"

WizardPage2::WizardPage2(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPage2)
{
    ui->setupUi(this);

    // Set Logo to second page
    #ifdef Q_OS_LINUX
        setPixmap(QWizard::LogoPixmap, QPixmap("/usr/share/qscrap2rtf/pixmaps/main.png"));
    #else
    #ifdef Q_OS_WIN32
		setPixmap(QWizard::LogoPixmap, QPixmap(qApp->applicationDirPath()+"\\pixmaps\\main.png"));
    #endif
    #endif
}
//-------------------------------------------------------------------------

WizardPage2::~WizardPage2()
{
    delete ui;
}
//-------------------------------------------------------------------------

// The function checks the list. If it is empty, then the "Next" button is inactive
bool WizardPage2::isComplete()const
{
    if (ui->listWidget->count() > 0)
        return true;
    else
        return false;
}
//-------------------------------------------------------------------------

// Clear list button
void WizardPage2::on_pushButton_4_clicked()
{
    // Clear list
    szScrapNames.clear();

    // Clear listWidget
    ui->listWidget->clear();

    // exec isComplete() function
    emit completeChanged();
}
//-------------------------------------------------------------------------

// Remove file button
void WizardPage2::on_pushButton_3_clicked()
{
    // Remove selected item from list
    szScrapNames.removeAt(ui->listWidget->row(ui->listWidget->currentItem()));

    // Remove selected item from listWidget
    ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));

    // exec isComplete() function
    emit completeChanged();
}
//-------------------------------------------------------------------------

// Add file button
void WizardPage2::on_pushButton_clicked()
{
    // Get selected file names
    QStringList templist = QFileDialog::getOpenFileNames(this,tr("Add scraps"),"", tr("Scrap Files (*.shs)"));

    // Append file names to list
    szScrapNames += templist;

    // Append file names to listWidget
    ui->listWidget->addItems(templist);

    // exec isComplete() function
    emit completeChanged();
}
//-------------------------------------------------------------------------

// Add directory button
void WizardPage2::on_pushButton_2_clicked()
{
    // Select the directory to search for scraps
    QString szOpenDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"",
                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // To search for files will use QDir
    QDir qdirOpenDir (szOpenDir);
    // Adding to the list only files with the extension .shs
    QStringList templist = qdirOpenDir.entryList(QStringList("*.shs"));

    // Why is QDir adds to the list the names of files with relative paths,
    // and we need the absolute
    for (int i=0; i<templist.count(); i++)
    {
        // Set the absolute paths and add them to the list
        templist[i] = szOpenDir + "/" + templist[i];
    }

    // Append file names to list
    szScrapNames += templist;

    // Append file names to listWidget
    ui->listWidget->addItems(templist);

    // exec isComplete() function
    emit completeChanged();
}
//-------------------------------------------------------------------------
