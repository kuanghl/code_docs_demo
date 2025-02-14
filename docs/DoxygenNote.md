# Doxygen.

All as list.

## Basically

```sh
@author     作者
@brief      摘要
@bug        被标记的代码会在Bug列表中出现
@class      类名，格式：@class <name> [<header-file>] [<header-name>] eg:@class Test"test/test.h"
@date       日期
@file       文件名，可以默认为空，DoxyGen会自己加
@param      函数参数名及其说明
@return     描述该函数的返回值情况eg: @return 本函数返回执行结果，若成功则返回TRUE，否则返回FLASE
@retval     描述返回值类型 eg: @retval NULL 空字符串。
@retval !NULL 非空字符串。
@note       注解
@attention  注意
@name       分组名
@warning    警告信息
@enum       引用了某个枚举，Doxygen会在该枚举处产生一个链接 eg：@enum CTest::MyEnum
@var        引用了某个变量，Doxygen会在该枚举处产生一个链接 eg：@var CTest::m_FileKey
@exception  可能产生的异常描述 eg: @exception 本函数执行可能会产生超出范围的异常
@todo       对将要做的事情进行注释
@see        see also字段
@relates <name> 通常用做把非成员函数的注释文档包含在类的说明文档中。
@since      从哪个版本后开始有这个函数的
@code       在注释中开始说明一段代码，直到@endcode命令。
@endcode    在注释中代码段的结束。
@remarks    备注
@pre        用来说明代码项的前提条件。
@post       用来说明代码项之后的使用条件。
@deprecated 这个函数可能会在将来的版本中取消。
@defgroup   模块名
@{          模块开始
@}          模块结束
@class      声明一个类 
@enum       声明一个枚举
@struct     声明一个结构体
@name       自定义参数
@version    版本号
@fn         声明一个函数
@par        开始一个段落，段落名称描述由你自己指定，比如可以写一段示例代码
-           一级项目符号
-#          二级项目符号
```

