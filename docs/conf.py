# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import subprocess, os

def configureDoxyfile(input_dir, output_dir, project_name):

	with open('Doxyfile.in', 'r') as file :
		filedata = file.read()
  
	filedata = filedata.replace('@DOXYGEN_PROJECT_NAME@', project_name)
	filedata = filedata.replace('@DOXYGEN_INPUT_DIR@', input_dir)
	filedata = filedata.replace('@DOXYGEN_OUTPUT_DIR@', output_dir)
 
	with open('Doxyfile', 'w') as file:
		file.write(filedata)
  
# Check if we're running on Read the Docs' servers
read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

breathe_projects = {}
if read_the_docs_build:
	input_dir = '../include'
	output_dir = 'build'
	project_name = 'code_docs_demo'
	configureDoxyfile(input_dir, output_dir, project_name)
	subprocess.call('doxygen', shell=True)
	breathe_projects['code_docs_demo'] = output_dir + '/xml'

# -- Project information for CMake -----------------------------------------------------
 
project = 'code_docs_demo'
copyright = '2023, Thilina Ratnayaka'
author = 'Thilina Ratnayaka'
release = '0.0.1'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["breathe", 
              "myst_parser"]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# -- Options for myst_parser -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/markdown.html
source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown',
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

# -- Options for breathe -----------------------------------------------------
# -Dbreathe_projects.code_docs_demo
breathe_default_project = "code_docs_demo"
