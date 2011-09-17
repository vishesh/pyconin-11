#ifndef __PYTHON_EXPOSED_H__
#define __PYTHON_EXPOSED_H__

#include <Python.h>
#include "mainwindow.h"
#include "canvas.h"

static PyObject *interface_set_pixel(PyObject *self, PyObject *args)
{
    int x, y, set;

    if (!PyArg_ParseTuple(args, "iii", &x, &y, &set))
        return NULL;

    Canvas::instance()->setPixel(x, y, set);    

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef InterfaceMethods[] = {
    {
        "set_pixel", 
        interface_set_pixel,
        METH_VARARGS,
        "Set pixel at given position"
    },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC init_python_interface(void)
{
    PyObject *m;

    m = Py_InitModule("canvas_interface", InterfaceMethods);
    if (m == NULL)
        return;
}


#endif

