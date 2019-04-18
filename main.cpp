#include <QtWidgets>
#include <Python.h>
#include <iostream>
#include "codeeditor.hpp"
#include <pybind11/embed.h>

namespace py = pybind11;
int param = 1;
PYBIND11_EMBEDDED_MODULE(fast_calc, m) {
    // `m` is a `py::module` which is used to bind functions and classes
    m.def("add", [](int i, int j) {
                   param ++;
                   return i + j;
    });
}

// PYBIND11_EMBEDDED_MODULE(conf, m) {
//   py::class_<>(m, "")
// }

int main(int argc, char *argv[])
{
  FILE * fp;

  wchar_t *program = Py_DecodeLocale(argv[0], NULL);

  if (program == NULL) {
    fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    exit(1);
  }
  // https://docs.python.org/3/extending/
  // PyRun_SimpleString("from time import time,ctime\n"
  //                    "print(\"Python3 interpreter test:\")\n"
  //                    "print('Today is', ctime(time()))\n"
  //                    "x=\"some value\";\n"
  //                    "print(\"x=\", str(x))\n"
  //                    );

  /*
   *   Qt Window
   */
  py::scoped_interpreter guard{};
  // Evaluate in scope of main module
  py::object scope = py::module::import("__main__").attr("__dict__");
  py::eval_file("codeeditor.py", scope);
  py::eval(R"(
print("x val = ", str(x))
               )");

  std::cout << param << std::endl;
  QApplication app(argc, argv);

  CodeEditor editor;
  editor.setWindowTitle(QObject::tr("Code Editor Example"));
  editor.show();

  return app.exec();
}
