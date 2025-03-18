# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8...3.5)

# doxygen
find_package(Doxygen)

if (DOXYGEN_FOUND)
    # 设置文档输入和输出路径
    set(DOXYGEN_PROJECT_NAME ${PROJECT_NAME})                           # PROJECT_NAME
    set(DOXYGEN_CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../include)    # INPUT_DIRECTORY
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)         # OUTPUT_DIRECTORY

    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # add_custom_command(OUTPUT "html/index.html"
    #                COMMAND "${DOXYGEN_EXECUTABLE}"
    #                WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    #                MAIN_DEPENDENCY Doxyfile
    #             #    DEPENDS ${header_paths} ${source_files} ${extra_files}
    #                COMMENT "Generating HTML documentation"
    #                VERBATIM)
    # # 在make -j16或者其他make指令时doxygen生成文档生效
    # add_custom_target(docs ALL SOURCES "html/index.html")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(py_docqt ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else()
    message(STATUS "Doxygen need to be installed to generate the doxygen documentation")
endif()