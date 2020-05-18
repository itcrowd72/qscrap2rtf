#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>

extern QStringList szScrapNames;    // List of scrap names to convert (Global variable)
extern bool bRemoveOriginal;        // Remove original scrap? (Global variable)
extern QString szOutputDir;         // Output directory (Global variable)

namespace Ui {
  class Wizard;
}

class Wizard : public QWizard {
  Q_OBJECT

public:
  explicit Wizard(QWidget *parent = 0);
  void reject();
  ~Wizard();

private:
  Ui::Wizard *ui;
};

#endif // WIZARD_H
