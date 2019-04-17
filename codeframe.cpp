#include <iostream>
#include <QtWidgets>
// #include <QtWidgets/private/qapplication_p.h>

#include <QtCore/qglobal.h>

#include "codeframe.hpp"

CodeFrame::CodeFrame(QWidget *parent): QFrame(parent)
{
  Q_Q(CodeFrame);
  viewport = new QWidget(q);
  // viewport->setObjectName(QLatin1String("qt_scrollarea_viewport"));
  // viewport->setBackgroundRole(QPalette::Base);
  // viewport->setAutoFillBackground(true);
}
void CodeFrame::init()
{
}
void CodeFrame::paintEvent(QPaintEvent *e)
{
  // Q_D(CodeFrame);
  QPainter painter(viewport());
}
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  CodeFrame cframe;
  cframe.show();
  return app.exec();
}
