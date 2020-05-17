#ifndef WIZARDPAGE4_H
#define WIZARDPAGE4_H

#include <QWizardPage>

namespace Ui {
class WizardPage4;
}

class WizardPage4 : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPage4(QWidget *parent = 0);
    ~WizardPage4();
    void initializePage();
    bool isComplete()const;

private slots:
    void Convert();
    
private:
    Ui::WizardPage4 *ui;
};

#endif // WIZARDPAGE4_H
