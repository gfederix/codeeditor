#pragma once
#include <QObject>
#include <QFrame>
#include <QtCore/qglobal.h>
#include "codeframe_p.hpp"

// class QWidget;
class CodeFrame : public QFrame
{
  Q_OBJECT
public:
  CodeFrame(QWidget *parent = 0);

  QWidget *viewport() const;
  // void setViewport(QWidget *widget);
  // QSize maximumViewportSize() const;
  void init();
private:
  Q_DECLARE_PRIVATE(CodeFrame)

protected:
  virtual void paintEvent(QPaintEvent *e) override;
};
