/**
 * A simple Python module written in C
 *   => Function can accept keyword arguments here
 *     
 *     For keyword arguments there are three things to do :-
 *       1. Make keyword list. A string array.
 *       2. Use PyArg_ParseTupleAndKeywords() instead of PyArg_ParseTuple()
 *       3. In PyMethodDef Method Table, the flag bit should also have 
 *          METH_KEYWORDS flag.
 *
 */

#include <Python.h>

/**
 * NOTE three arguments instead of two.
 * Third argument is for keyword list 
 */
static PyObject*
spam_name_age(PyObject *self, PyObject *args, PyObject *keywords)
{
    const char *name;
    int age;

    /* Keyword list */
    static char *kwlist[] = {"name", "age", NULL};

    /* Similar to PyArg_ParseTuple(), but also takes keywords */
    if (!PyArg_ParseTupleAndKeywords(args, keywords, "si", kwlist, &name, &age))
        return NULL;

    printf("Name: %s, Age: %i\n", name, age);

    return Py_None;
}

static PyMethodDef SpamMethods[] = {
    {
        "name_age", 
        (PyCFunction)spam_name_age, /* to make it a two argument function */
        METH_VARARGS | METH_KEYWORDS, /* to accept keywords arguments */
        "Prints your name and age"
    },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;
}


