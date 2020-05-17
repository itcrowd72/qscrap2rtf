#ifndef WIZARDPAGE5_H
#define WIZARDPAGE5_H

#include <QWizardPage>

namespace Ui {
  class WizardPage5;
}

class WizardPage5 : public QWizardPage {
  Q_OBJECT

public:
  explicit WizardPage5(QWidget *parent = 0);
  ~WizardPage5();

private:
  Ui::WizardPage5 *ui;
};

#endif // WIZARDPAGE5_H
