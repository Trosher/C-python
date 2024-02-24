from setuptools import setup, Extension

module = Extension('calculator', sources=['calculator.c'])

setup(name='calculator',
      version='1.0',
      description='A simple calculator module for Python C API',
      ext_modules=[module])