English description is below.

**QScrap2rtf** - простая программа для преобразования фрагментов файлов 
(Shell Scrap Object File) в Rich Text Format

**QScrap2rtf** - это графическая оболочка для консольной утилиты [scrap2rtf](https://github.com/ivnish/scrap2rtf).
В GNU/Linux версии scrap2rtf распространяется как отдельный пакет и идет как 
зависимость. В Windows версии scrap2rtf включен в архив с графической оболочкой

Начиная с версии 0.2 будет использоваться Qt5 вместо Qt4

Если вы хотите собрать сами из исходников:

* qmake QScrap2rtf.pro -r -spec linux-g++-64
* make
* sudo make install

English description:

**QScrap2rtf** is a simple program to convert Shell Scrap Object File to Rich 
Text Format

**QScrap2rtf** is a GUI to console utility [scrap2rtf](https://github.com/ivnish/scrap2rtf).
GNU/Linux version doesn't contain scrap2rtf. It is an another package and should
be installed with QScrap2rtf as dependency. Windows version contains scrap2rtf

Since version 0.2 will be used Qt5 instead of Qt4

If you want to install from sources:

* qmake QScrap2rtf.pro -r -spec linux-g++-64
* make
* sudo make install

Copyright (C) 2012-2020 Andrei Ivnitskii <ivnish.dev@gmail.com>
