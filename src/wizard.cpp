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

#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);

    // Disable Back button on last page
    setOption( QWizard::DisabledBackButtonOnLastPage, true );

    // Set buttons namef for translate
    setButtonText(QWizard::BackButton,tr("< Back"));
    setButtonText(QWizard::NextButton,tr("Next >"));
    setButtonText(QWizard::CommitButton,tr("Next >"));
    setButtonText(QWizard::FinishButton,tr("Finish"));
    setButtonText(QWizard::CancelButton,tr("Cancel"));
}
//-------------------------------------------------------------------------

Wizard::~Wizard()
{
    delete ui;
}
//-------------------------------------------------------------------------
