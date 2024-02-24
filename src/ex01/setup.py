from setuptools import setup, Extension
from Cython.Build import cythonize

setup(name='matrix',
      version='1.0',
      description='A simple matrix module for Python C API',
      ext_modules=cythonize("multiply.pyx"))