from setuptools import Extension, setup

# Nome do módulo
module_name = 'sentimetrics'

# Definição do módulo em C
module = Extension(module_name, sources=['sentimetrics.c'])

# Leitura do conteúdo do arquivo README.md
with open('README.md', 'r', encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='sentimetrics',
    version='1.0.0',
    description='Analyze sentiment of text',
    long_description=long_description,
    long_description_content_type='text/markdown',
    author='Emeson Borges',
    author_email='borges2016.leh@gmail.com',
    url='https://github.com/Emeson-Borges/emotions-analysis',
    ext_modules=[module],
)