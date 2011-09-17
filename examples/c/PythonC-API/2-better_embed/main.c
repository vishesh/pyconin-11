/**
 * Embed Python in C
 * Call Python function from C
 *
 * $main python_module_name function_name 
 *
 * Note: Error checking not done for sake of simplicity
 *
 */

#include <Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3) {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    /* Initialize the Python Interpreter */
    Py_Initialize();
    PySys_SetArgv(argc, argv);

    /* Build the name object */
    /* Convery C-String to PyString */
    pName = PyString_FromString(argv[1]);

    /* Load the module object */
    pModule = PyImport_Import(pName);
    if (pModule == 0) {
        printf("Module not found: %s, %p \n", argv[1], pName);
    }

    /* pDict is a borrowed reference */
    /* Equivalent to __dict__ attribute of object */
    pDict = PyModule_GetDict(pModule);

    /* pFunc is also a borrowed reference */
    /* Get value of object with key 'argv[2]' */ 
    /* This is the function we'll execute */
    pFunc = PyDict_GetItemString(pDict, argv[2]);

    /* First check if the PyObject retrieved is callable */
    if (PyCallable_Check(pFunc)) {
        /* => PyObject_CallObject(object, arguments) */
        PyObject_CallObject(pFunc, NULL);
    } 
    else {
        PyErr_Print();
    }

    /* Clean up */
    Py_DECREF(pModule);
    Py_DECREF(pName);

    /* Shutdown Python Interpreter */
    Py_Finalize();

    return 0;
}

