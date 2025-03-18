#### m.css.

```sh

git clone git@github.com:mosra/m.css.git
cd m.css/documentation

# You may need sudo here
pip3 install jinja2 Pygments

# latex options
# sudo apt install texlive-base texlive-latex-extra texlive-fonts-extra texlive-fonts-recommended

touch Doxyfile-mcss Doxyfile
vim Doxyfile-mcss
# 填入
@INCLUDE                = Doxyfile
GENERATE_HTML           = NO
GENERATE_XML            = YES
XML_PROGRAMLISTING      = NO

./doxygen.py path/to/your/Doxyfile-mcss

```