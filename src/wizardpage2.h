#ifndef WIZARDPAGE2_H
#define WIZARDPAGE2_H

#include <QWizardPage>

namespace Ui {
class WizardPage2;
}

class WizardPage2 : public QWizardPage {
  Q_OBJECT

public:
  explicit WizardPage2(QWidget *parent = 0);
  bool isComplete()const;
  ~WizardPage2();

private slots:
  void on_pushButton_4_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

private:
  Ui::WizardPage2 *ui;
};

#endif // WIZARDPAGE2_H
