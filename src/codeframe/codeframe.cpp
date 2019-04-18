#include <string>
#include <QWidget>
#include <QString>
#include <QPainter>

#include "codeframe.hpp"

using namespace std;

CodeFrame::CodeFrame(QWidget *parent): QWidget(parent)
{
}
void CodeFrame::paint(QPainter *painter) {
  // QPainter painter(this);
  painter->setPen(Qt::blue);
  painter->setFont(QFont("Arial", 30));
  painter->drawText(rect(), Qt::AlignCenter, "Qt");
}

void CodeFrame::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  string count = to_string(i);
  i++;
  painter.drawText(rect(), Qt::AlignCenter, "Qt paint test" + QString::number(i));
  painter.setPen(Qt::red);
  painter.drawText(rect(), Qt::AlignCenter, "Qt paint test" + QString::number(i));
}
