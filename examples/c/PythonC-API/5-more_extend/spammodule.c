/**
 * A simple Python module written in C
 *
 */

#include <Python.h>

/* Add two integer */
static PyObject*
spam_add(PyObject *self, PyObject *args)
{
    int a;
    int b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;

    return Py_BuildValue("i", a+b); /* Convert C to Python types */
}

/**
 * Just takes a string and an int ie name and age,
 * and prints them
 */
static PyObject*
spam_name_age(PyObject *self, PyObject *args)
{
    int age;
    const char *name;

    if (!PyArg_ParseTuple(args, "si", &name, &age))
        return NULL;

    printf("Name: %s, Age %i\n", name, age);

    return Py_None; /* We return Py_None, not NULL! */
}

/* Module Method Table */
static PyMethodDef SpamMethods[] = {
    {
        "add", 
        spam_add,
        METH_VARARGS,
        "Adds two integer"
    },
    {
        "name_age", 
        spam_name_age,
        METH_VARARGS,
        "Prints name and age"
    },
    { NULL, NULL, 0, NULL }
};

/* Initialization function */
PyMODINIT_FUNC
initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;
}


