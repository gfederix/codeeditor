#include <Python.h>
#include <iostream>
#include <pybind11/embed.h>

#include <QtWidgets>

#include "codeframe/codeframe.hpp"
#include "config.h"

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
  // https://docs.python.org/3/extending/

  py::scoped_interpreter guard{};
  // Evaluate in scope of main module
  py::object scope = py::module::import("__main__").attr("__dict__");
  py::eval_file(PY_CONFIG, scope);
  py::eval(R"(
print("x val = ", str(x))
               )");

  std::cout << param << std::endl;
  /*
   *   Qt Window
   */
  QApplication app(argc, argv);

  CodeFrame editor;
  editor.setWindowTitle(QObject::tr("Code Editor Tsts"));
  editor.show();

  return app.exec();
}
