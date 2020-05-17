#include "helpers.h"

bool FileExists(QString path) {
  return QFile::exists(path);
}
