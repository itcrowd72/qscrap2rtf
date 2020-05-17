#include <QtWidgets/QApplication>
#include "wizard.h"
#include <QTranslator>
#include <QLocale>
#include <unistd.h>

#ifdef Q_OS_WIN32
#include <io.h>					// for windows _access function
#endif

QStringList szScrapNames;       // List of scrap names to convert (Global variable)
bool bRemoveOriginal;           // Remove original scrap? (Global variable)
QString szOutputDir;            // Output directory (Global variable)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Translate application
    QTranslator translator;

    // Path to translate file
    QString szTranslateName;

    #ifdef Q_OS_LINUX
        szTranslateName = "/usr/share/locale/" + QLocale::system().name() + "/LC_MESSAGES/qscrap2rtf.qm";

        // If translate not found try "QLocale::system().name().left(2)"
        if (access(szTranslateName.toStdString().c_str(), 0) != 0)
            szTranslateName = "/usr/share/locale/" + QLocale::system().name().left(2) + "/LC_MESSAGES/qscrap2rtf.qm";
    #else
    #ifdef Q_OS_WIN32
		szTranslateName = qApp->applicationDirPath()+"\\locales\\" + QLocale::system().name() + "\\qscrap2rtf.qm";

		// If translate not found try "QLocale::system().name().left(2)"
		if (_access(szTranslateName.toStdString().c_str(), 0) != -1)
			szTranslateName = qApp->applicationDirPath()+"\\locales\\" + QLocale::system().name().left(2) + "\\qscrap2rtf.qm";
    #endif
    #endif

    // Load translate
    translator.load(szTranslateName);
    // Apply translate
    a.installTranslator(&translator);

    Wizard w;
    w.show();
    
    return a.exec();
}
