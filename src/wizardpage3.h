#ifndef WIZARDPAGE3_H
#define WIZARDPAGE3_H

#include <QWizardPage>

namespace Ui {
  class WizardPage3;
}

class WizardPage3 : public QWizardPage {
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
