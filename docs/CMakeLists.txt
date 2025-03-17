# find tools module
find_package(Doxygen REQUIRED)

if (DOXYGEN_FOUND)
    # 1. doxygen
    # set doxygen variables

    # for Doxyfile
    set(DOXYGEN_PROJECT_NAME ${PROJECT_NAME})                       # PROJECT_NAME
    set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)   # INPUT
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)     # OUTPUT_DIRECTORY

    # for cmake
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    set(DOXYGEN_INDEX_XML_FILE ${DOXYGEN_OUTPUT_DIR}/xml/index.xml)

    # Doxygen won't create this for us
    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) 

    # Set the Doxygen input and output directories in the Doxyfile
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    # code .h file to generate html, latex and xml
    file(GLOB_RECURSE GDOC_CODE_FILES ${DOXYGEN_INPUT_DIR}/*.h)

    # Only regenerate Doxygen when the Doxyfile or public headers change
    add_custom_command(
            OUTPUT ${DOXYGEN_INDEX_XML_FILE}
            DEPENDS ${GDOC_CODE_FILES}
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
            MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                COMMENT "Generating documentation with Doxygen"
            VERBATIM)

    # Nice named target so we can run the job easily
    add_custom_target(Doxygen ALL DEPENDS ${DOXYGEN_INDEX_XML_FILE})

    # 2. sphinx
    # find tools module
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
    find_package(Sphinx REQUIRED)

    # set sphinx variables
    set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
    set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx)
    set(SPHINX_PDF_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx/pdf)
    set(SPHINX_INDEX_HTML_FILE ${SPHINX_BUILD}/index.html)

    # Sphinx won't create this for us
    file(MAKE_DIRECTORY ${SPHINX_PDF_BUILD}) 

    # Only regenerate Sphinx when:
    # - Doxygen has rerun
    # - Our doc files have been updated
    # - The Sphinx config has been updated
    add_custom_command(
        OUTPUT ${SPHINX_INDEX_HTML_FILE}
        COMMAND 
            ${SPHINX_EXECUTABLE} -b html
            # Tell Breathe where to find the Doxygen output
            # breathe_default_project
            -Dbreathe_projects.code_docs_demo=${DOXYGEN_OUTPUT_DIR}/xml
            ${SPHINX_SOURCE} ${SPHINX_BUILD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS
            # Other docs files you want to track should go here (or in some variable)
            ${CMAKE_CURRENT_SOURCE_DIR}/index.rst
            ${DOXYGEN_INDEX_XML_FILE}
        MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
        COMMENT "Generating documentation with Sphinx")

    # Nice named target so we can run the job easily
    add_custom_target(Sphinx ALL DEPENDS ${SPHINX_INDEX_HTML_FILE})
else()
    message("Doxygen need to be installed to generate the doxygen documentation")
endif()


