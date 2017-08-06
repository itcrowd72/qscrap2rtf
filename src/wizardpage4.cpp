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

#include "wizardpage4.h"
#include "ui_wizardpage4.h"
#include "wizard.h"
#include <QTimer>
#include <QProcess>
#include <QTextCodec>

bool bWorkDone = false;     // if convert is done, then enable "Next" button

WizardPage4::WizardPage4(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPage4)
{
    ui->setupUi(this);

    // Set Logo to fourth page
    #ifdef Q_OS_LINUX
        setPixmap(QWizard::LogoPixmap, QPixmap("/usr/share/qscrap2rtf/pixmaps/main.png"));
    #else
    #ifdef Q_OS_WIN32
		setPixmap(QWizard::LogoPixmap, QPixmap(qApp->applicationDirPath()+"\\pixmaps\\main.png"));
    #endif
    #endif
}
//-------------------------------------------------------------------------

WizardPage4::~WizardPage4()
{
    delete ui;
}
//-------------------------------------------------------------------------

// The function checks the list. If it is empty, then the "Next" button is inactive
bool WizardPage4::isComplete()const
{
    if (bWorkDone)
        return true;
    else
        return false;
}
//-------------------------------------------------------------------------

void WizardPage4::Convert()
{
    // Set maximum to progressBar (files count)
    ui->progressBar->setMaximum(szScrapNames.count());

    for (int i=1; i <= ui->progressBar->maximum(); i++)
    {
        // Create process
        QProcess proc;

        // Options
        QStringList args;
        args << "-v";

        // if remove original
        if (bRemoveOriginal)
            args << "-r";

        // if output directory is present
        if (szOutputDir != ".")
             args << "--output="+szOutputDir;

        // add scrap name
        args << szScrapNames[i-1];

        // Start process
		#ifdef Q_OS_LINUX
			proc.start("scrap2rtf",args);
		#else
		#ifdef Q_OS_WIN32
			proc.start(qApp->applicationDirPath()+"\\scrap2rtf",args);
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

        ui->label->setText( QString(tr("Process file %1 from %2")).arg(i).arg(ui->progressBar->maximum()));
        qApp->processEvents();
    }

    bWorkDone = true;
    // exec isComplete() function
    emit completeChanged();
}
//-------------------------------------------------------------------------

// Page activated
void WizardPage4::initializePage()
{
    // Start convert after 1 second
    QTimer::singleShot(1000, this, SLOT(Convert()));
}
//-------------------------------------------------------------------------
