/**
 * A simple Python module written in C with custom data type
 *
 *  module-name: noddy
 *  data-type-name: Noddy
 *
 */

#include <Python.h>

/* The PyObject child for Noddy */
typedef struct {
    PyObject_HEAD /* brings ref count and pointer to typeobject */
    /* Type-specific fields go here. */
} noddy_NoddyObject;

/* PyTypeObject for defining the Type */
static PyTypeObject noddy_NoddyType = {
    PyObject_HEAD_INIT(NULL) 
    0,                         /*ob_size*/
    "noddy.Noddy",             /*tp_name*/
    sizeof(noddy_NoddyObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Noddy objects",           /* tp_doc */
};

/* Module Method Table */
static PyMethodDef noddy_methods[] = {
    {NULL}  /* Sentinel */
};

/* Initialization function */
PyMODINIT_FUNC
initnoddy(void) 
{
    PyObject* m;

    noddy_NoddyType.tp_new = PyType_GenericNew; /* for object creation */
    /* Initialize Noddy type, filling members we set blank */
    if (PyType_Ready(&noddy_NoddyType) < 0)
        return;

    m = Py_InitModule3("noddy", noddy_methods,
                       "Example module that creates an extension type.");

    Py_INCREF(&noddy_NoddyType);

    /* Add type to module dictionary */
    /* int PyModule_AddObject(module, name, value) */
    PyModule_AddObject(m, "Noddy", (PyObject *)&noddy_NoddyType);
}

