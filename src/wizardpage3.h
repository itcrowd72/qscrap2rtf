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

#ifndef WIZARDPAGE3_H
#define WIZARDPAGE3_H

#include <QWizardPage>

namespace Ui {
class WizardPage3;
}

class WizardPage3 : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPage3(QWidget *parent = 0);
    ~WizardPage3();
    
private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::WizardPage3 *ui;
};

#endif // WIZARDPAGE3_H
