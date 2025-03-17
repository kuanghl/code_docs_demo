# Overview.
An example of setting up Sphinx for C/C++ and building with CMake and Read the Docs

See the documentation [here](https://cpp-documentation-example.readthedocs.io/en/latest/)

[refer blog](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)
[refer repository](https://github.com/TartanLlama/cpp-documentation-example.git)

## Dependencies.

- [CMake](https://cmake.org/download/)
- [Doxygen](http://www.doxygen.nl/download.html)
- [Sphinx](https://www.sphinx-doc.org/en/master/usage/installation.html)
- [Breathe](https://pypi.org/project/breathe/)
- [sphinx_rtd_theme](https://github.com/rtfd/sphinx_rtd_theme)

```sh
# Windows
# https://github.com/doxygen/doxygen/releases
doxygen.exe -v
doxygen -g Doxyfile.in # 生成Doxyfile模板文件

# linux
git clone -b Release_1_12_0 https://github.com/doxygen/doxygen.git
cd doxygen
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make -j16
sudo make install
doxygen -v

# Python 3.12.8
# basical
pip install sphinx_rtd_theme breathe Sphinx myst_parser -i https://pypi.tuna.tsinghua.edu.cn/simple

# other
# https://www.osgeo.cn/sphinx-note/extenstion-plantuml.html
# https://github.com/thilinarmtb/ttt.git
```

## Sphinx And Doxygen.

```sh
# Sphinx默认的解析文档是reStructureText,你可以认为是高级版本的 Markdown,也就是比它功能更强大。并生成html文件,托管到Read the Docs.
# Doxygen解析源码文件中的comments生成html/latex/xml文档素材.
# Sphinx使用Breathe插件解析的xml文档素材,以及解析现成的reStructureText文档,生成最后的HTML或者其他文档类型.
```

## Read the Docs.

```sh
# 配置.readthedocs.yaml并推送到github
# 打开https://readthedocs.org/dashboard/托管github项目即可
```

## KeyWords.

```sh
# breathe_default_project = "code_docs_demo"

# .. doxygenfile:: ll_dev.h
#    :project: code_docs_demo

# .. doxygenstruct:: 
#    :members:

# enum

# 
```

![Read The Docs Building](https://cdn.jsdelivr.net/gh/kuanghl/pictures_bed/images/20250214124513.png)