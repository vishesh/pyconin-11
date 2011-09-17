/**
 * Embed Python in C
 * Call Python function with arguments from C
 *
 * $main python_module_name function_name arg1 arg2 
 *
 * Note: Error checking not done for sake of simplicity
 *
 */


#include <Python.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs;

    if (argc < 5) {
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

    /* pDict is a borrowed reference */
    /* Equivalent to __dict__ attribute of object */
    pDict = PyModule_GetDict(pModule);

    /* pFunc is also a borrowed reference */
    /* Get value of object with key 'argv[2]' */ 
    /* This is the function we'll execute */
    pFunc = PyDict_GetItemString(pDict, argv[2]);

    /* Prepare a tuple which will contain arguments for our Python function */

    /* Create tuple of size 2 */
    pArgs = PyTuple_New(2);

    /* We set the values at indices as provided by main program arguments */
    PyTuple_SetItem(pArgs, 0, PyInt_FromLong(atoi(argv[3])));
    PyTuple_SetItem(pArgs, 1, PyInt_FromLong(atoi(argv[4])));

    /* First check if the PyObject retrieved is callable */
    if (PyCallable_Check(pFunc)) {
        /* To store return value by the called function */
        PyObject *result;

        /* => PyObject_CallObject(object, arguments) */
        if (result = PyObject_CallObject(pFunc, pArgs)) {
            /* We convery returned PyObject to C's long */
            long resultLong = PyInt_AsLong(result);
            printf("Result is: %ld\n", resultLong);
        }
        else {
            /* Since NULL is returned, and NULL is error */
            printf("Failed\n");
        }
    } 
    else {
        /* What you provided wasnt callable */
        PyErr_Print();
    }

    /* Clean up */
    Py_DECREF(pModule);
    Py_DECREF(pName);
    Py_DECREF(pArgs);

    /* Shutdown Python Interpreter */
    Py_Finalize();

    return 0;
}

