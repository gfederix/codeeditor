#pragma once
// #include <QtWidgets/private/qtwidgetsglobal_p.h>
// #include <QtWidgets/private/qframe_p.h>
#include <QtCore/qglobal.h>
#include "codeframe.hpp"
QT_BEGIN_NAMESPACE

class Q_WIDGETS_EXPORT  CodeFramePrivate : public QFramePrivate
{
  Q_DECLARE_PUBLIC(CodeFrame);
};

QT_END_NAMESPACE
