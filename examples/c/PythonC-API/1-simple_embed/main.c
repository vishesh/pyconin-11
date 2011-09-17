/**
 * Simple High Level Embedding of Python in C
 *
 */

#include <Python.h>

int main(int argc, char **argv)
{
    /* Start Python interpretor */
    Py_Initialize();
    
    /* Run python script here */
    PyRun_SimpleString("print 'Hello World'");

    /* Shutdown Python interpretor */
    Py_Finalize();

    return 0;
}

