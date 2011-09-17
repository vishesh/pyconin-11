/**
 * A simple Python module written in C
 *   Interface C's system() function into Python
 *
 */

#include <Python.h>

/**
 * C function that will be called when when Python expression
 * spam.system(string) will be evaluated.
 *
 * Note that every Python function in has following format -
 *  
 *  => PyObject* function_name(PyObject *self, PyObject *args)
 *
 */
static PyObject*
spam_system(PyObject *self, PyObject *args)
{ 
    const char *command;
    int sts;

    /** 
     * Like sscanf(). Would take a format string a variable
     * number of pointer variables as arguments. We are basically
     * converting PyObject to C-datatypes
     */
    if (!PyArg_ParseTuple(args, "s", &command)) {
         /* Arguments provided were not valid. */
         /* Returning NULL means exception in Python */
        return NULL;
    }

    /* Do the stuff. Here we call system() */
    sts = system(command);

    /* Convert return value to PyObject and return to Python */
    return Py_BuildValue("i", sts);
}

/**
 * The Module Method Table. An array of structures.
 */
static PyMethodDef SpamMethods[] = {
    {
        "system",                   /* name of the method */
        spam_system,                /* pointer to function implementing it */
        METH_VARARGS,      /* flag bits indicating how call be constructed */
        "Execute a shell command"   /* docstring */
    },
    { NULL, NULL, 0, NULL } /* Sentinel */
};

/** 
 * Initialization function.
 * => The only non-static item in module
 *
 * PyMODINIT_FUNC declares function as void return type, declares any
 * special linkage declaration required by the platform and for C++ declares
 * the function as extern "C"
 *
 * => Should be named initname() where name is the name of module.
 */
PyMODINIT_FUNC 
initspam(void)
{
    PyObject *m;

    /* Creates a module with methods defined by SpamMethods */
    /* Borrowed reference */
    m = Py_InitModule3("spam", SpamMethods, "Our Demo SPAM module");

    /* Exception */
    if (m == NULL)
        return;
}


