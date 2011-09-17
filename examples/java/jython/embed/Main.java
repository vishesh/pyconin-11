/**
 * Embed Jython in Java
 *   Use Jython classes
 */

import org.python.core.*;
import org.python.util.PythonInterpreter;

public class Main
{
    public Main()
    {
        PythonInterpreter interpreter = new PythonInterpreter();
        interpreter.exec("from Person import Person");
        personClass = interpreter.get("Person");
    }

    public static void main(String[] args)
    {
        Main foo = new Main();
        PersonInterface javaPerson = foo.createPerson("Bon Jovi", 48);
        System.out.println("Name: " + javaPerson.getName());
        System.out.println("Age : " + javaPerson.getAge());
    }

    public PersonInterface createPerson(String name, int age)
    {
        PyObject personObject = personClass.__call__(new PyString(name), 
                                                     new PyInteger(age));
        return (PersonInterface)personObject.__tojava__(PersonInterface.class);
    }

    private PyObject personClass;
}

