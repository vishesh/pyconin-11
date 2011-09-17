from distutils.core import setup, Extension

m = Extension('noddy2',
                sources = ['main.c'])

setup (name = 'noddy2',
        version = '1.0',
        description = 'Demo extenstion',
        ext_modules = [m]
        )

