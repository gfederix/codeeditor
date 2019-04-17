#pragma once
#include <QObject>
#include <QFrame>

// class QWidget;

class CodeFrame : public QFrame
{
  Q_OBJECT
public:
  CodeFrame(QWidget *parent = 0);
};
