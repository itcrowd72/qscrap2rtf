#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent) :
  QWizard(parent),
  ui(new Ui::Wizard) {
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

Wizard::~Wizard() {
  delete ui;
}
//-------------------------------------------------------------------------
