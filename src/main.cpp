#include <QtWidgets/QApplication>
#include "wizard.h"
#include <QTranslator>
#include <QLocale>
#include "helpers.h"
#include <QMessageBox>

QStringList szScrapNames;       // List of scrap names to convert (Global variable)
bool bRemoveOriginal;           // Remove original scrap? (Global variable)
QString szOutputDir;            // Output directory (Global variable)

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  // Translate application
  QTranslator translator;

  // Path to translate file
  QString szTranslateName;

  #ifdef Q_OS_LINUX
    szTranslateName = "/usr/share/locale/" + QLocale::system().name() + "/LC_MESSAGES/qscrap2rtf.qm";

    // If translate not found try "QLocale::system().name().left(2)"
    if (!FileExists(szTranslateName)) {
      szTranslateName = "/usr/share/locale/" + QLocale::system().name().left(2) + "/LC_MESSAGES/qscrap2rtf.qm";
    }
  #else
  #ifdef Q_OS_WIN32
    szTranslateName = qApp->applicationDirPath() + "\\locales\\" + QLocale::system().name() + "\\qscrap2rtf.qm";

    // If translate not found try "QLocale::system().name().left(2)"
    if (!FileExists(szTranslateName)) {
      szTranslateName = qApp->applicationDirPath() + "\\locales\\" + QLocale::system().name().left(2) + "\\qscrap2rtf.qm";
    }
  #endif
  #endif

  // Load translate
  translator.load(szTranslateName);
  // Apply translate
  a.installTranslator(&translator);

  Wizard w;
  w.show();

  #ifdef Q_OS_LINUX
    // Check scrap2rtf
    if (!FileExists("/usr/bin/scrap2rtf")) {
      QMessageBox msgBox;
      msgBox.setText(QObject::tr("scrap2rtf not found. Please install scrap2rtf first."));
      msgBox.setIcon(QMessageBox::Critical);

      if (msgBox.exec() == QMessageBox::Ok) {
        return 1;
      }
    }
  #else
  #ifdef Q_OS_WIN32
    // Check scrap2rtf
    if (!FileExists(qApp->applicationDirPath() + "\\bin\\scrap2rtf.exe")) {
      QMessageBox msgBox;
      msgBox.setText(QObject::tr("scrap2rtf not found. Please reinstall application."));
      msgBox.setIcon(QMessageBox::Critical);

      if (msgBox.exec() == QMessageBox::Ok) {
        return 1;
      }
    }
  #endif
  #endif

  return a.exec();
}
