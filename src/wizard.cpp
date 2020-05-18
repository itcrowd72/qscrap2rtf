#include "wizard.h"
#include "ui_wizard.h"
#include <QMessageBox>

Wizard::Wizard(QWidget *parent) :
  QWizard(parent),
  ui(new Ui::Wizard) {
  ui->setupUi(this);

  // Disable Back button on last page
  setOption(QWizard::DisabledBackButtonOnLastPage, true);

  // Hide Cancel button on last page
  setOption(QWizard::NoCancelButtonOnLastPage, true);

  // Set buttons namef for translate
  setButtonText(QWizard::BackButton,tr("< Back"));
  setButtonText(QWizard::NextButton,tr("Next >"));
  setButtonText(QWizard::CommitButton,tr("Next >"));
  setButtonText(QWizard::FinishButton,tr("Finish"));
  setButtonText(QWizard::CancelButton,tr("Cancel"));
}
//-------------------------------------------------------------------------

void Wizard::reject() {
  QMessageBox::StandardButton resBtn = QMessageBox::Yes;

  resBtn = QMessageBox::question(this, "Quit",
    tr("Do you want to quit the application?"),
    QMessageBox::No | QMessageBox::Yes,
    QMessageBox::Yes);

  if (resBtn == QMessageBox::Yes) {
    QWizard::reject();
  }
}

Wizard::~Wizard() {
  delete ui;
}
//-------------------------------------------------------------------------
