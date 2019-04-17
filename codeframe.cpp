#include <iostream>
#include <QtWidgets>

#include "codeframe.hpp"
CodeFrame::CodeFrame(QWidget *parent): QFrame(parent)
{
  
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  CodeFrame cframe;
  cframe.show();
  return app.exec();
}
