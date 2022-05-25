#!/usr/bin/env python3

from distutils.core import setup, Extension

setup(
	name = "trivial_functions_in_c",
	version = "1.0",
	ext_modules = [Extension("trivial_functions_in_c", ["trivial_functions.cpp", "trivial_functions_pybinder.cpp"])]
	);