from setuptools import setup, Extension
from glob import glob

setup(
    name='c_lib',
    version='1.0',
    ext_modules=[Extension('c_lib', glob('src/wrapper.c') + glob('src/impl/*.c'))]
)
