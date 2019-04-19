#include <QtWidgets>
#include <iostream>
#include "codeframe.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  CodeFrame cframe;
  cframe.setWindowTitle(QObject::tr("Code Frame Tsts"));
  cframe.show();
  return app.exec();
}
