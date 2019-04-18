#pragma once
#include <QWidget>
#include <QPainter>

class CodeFrame : public QWidget
{
public:
  CodeFrame(QWidget *parent=nullptr);
protected:
  void paint(QPainter *painter);
  void paintEvent(QPaintEvent *event) override;
  int i{0};
};
