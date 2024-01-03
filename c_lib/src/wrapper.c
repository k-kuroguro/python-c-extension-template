#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "impl/add.h"

static PyObject *c_lib_add(PyObject *self, PyObject *args) {
   int x, y, g;

   if (!PyArg_ParseTuple(args, "ii", &x, &y))
      return NULL;
   g = add(x, y);
   return Py_BuildValue("i", g);
}

static PyMethodDef methods[] = {
   {"add", (PyCFunction)c_lib_add, METH_VARARGS, "calculate the sum of two integers."},
   {NULL, NULL, 0, NULL},
};

static struct PyModuleDef c_lib = {
   PyModuleDef_HEAD_INIT,
   "c_lib",
   "module by c.",
   -1,
   methods,
};

PyMODINIT_FUNC PyInit_c_lib(void) {
   return PyModule_Create(&c_lib);
}
