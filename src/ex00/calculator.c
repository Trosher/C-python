#include <Python.h>

static PyObject* add(PyObject* self, PyObject* args) {
    double a, b, res;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    res = a + b;
	return res == (int)res ? Py_BuildValue("i", (int)res) : Py_BuildValue("d", res);
}

static PyObject* sub(PyObject* self, PyObject* args) {
    double a, b, res;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    res = a - b;
    return res == (int)res ? Py_BuildValue("i", (int)res) : Py_BuildValue("d", res);
}

static PyObject* mul(PyObject* self, PyObject* args) {
    double a, b, res;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    res = a * b;
    return res == (int)res ? Py_BuildValue("i", (int)res) : Py_BuildValue("d", res);
}

static PyObject* divv(PyObject* self, PyObject* args) {
    double a, b, res;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    if (b == 0.0) {
        PyErr_SetString(PyExc_ZeroDivisionError, "Cannot divide by zero");
        return NULL;
    }
    res = a / b;
    return res == (int)res ? Py_BuildValue("i", (int)res) : Py_BuildValue("d", res);
}

static PyMethodDef CalculatorMethods[] = {
    {"add", add, METH_VARARGS, "Summ two numbers"},
    {"sub", sub, METH_VARARGS, "Sub two numbers"},
    {"mul", mul, METH_VARARGS, "Mult two numbers"},
    {"div", divv, METH_VARARGS, "Div two numbers"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef calculatirmodule = {
    PyModuleDef_HEAD_INIT,
    "calculator",
    "A simple calculator module",
    -1,
    CalculatorMethods
};

PyMODINIT_FUNC PyInit_calculator(void) {
    return PyModule_Create(&calculatirmodule);
}