#include <QtWidgets>
#include <Python.h>
#include "codeeditor.hpp"

int main(int argc, char *argv[])
{
  const int first = 0;
  wchar_t *program = Py_DecodeLocale(argv[0], NULL);
  if (program == NULL) {
    fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    exit(1);
  }
  // https://docs.python.org/3/extending/
  Py_SetProgramName(program);
  /* optional but recommended */
  Py_Initialize();
  PyRun_SimpleString("from time import time,ctime\n"
                     "print(\"Python3 interpreter test:\")\n"
                     "print('Today is', ctime(time()))\n");
  if (Py_FinalizeEx() < 0) {
    exit(120);
  }
  PyMem_RawFree(program);

  /*
   *   Qt Window
   */

  QApplication app(argc, argv);

  CodeEditor editor;
  editor.setWindowTitle(QObject::tr("Code Editor Example"));
  editor.show();

  return app.exec();
}
