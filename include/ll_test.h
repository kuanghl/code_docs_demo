#ifndef __LL_TEST_H__
#define __LL_TEST_H__

/** @brief  	摘要
 *  @file   	文件名
 *  @author 	作者
 *  @version	版本
 *  @date  	日期
 *  @note    注解(写一些功能及注意事项等...)
 */

/** @defgroup group1 第一个组
 * 这是第一个组
 *  @{
 */

/**
 * @def 这是一个宏
 */
#define WORKING_MODE 0x0    /**< 宏的行注释 */

/** @brief 组 1 中的类 C1 */
class C1 {};
 
/** @brief 组 1 中的类 C2 */
class C2 {};
 
/** 组 1 中的函数 */
void func() {}
 
/** @} */ // group1 结束
 
/**
 * @defgroup group2 第二个组
 * 这是第二个组
 */
 
/** @defgroup group3 第三个组
 * 这是第三个组
 */
 
/** @defgroup group4 第四个组
 * @ingroup group3
 * 组 4 是组 3 的子组
 */
 
/**
 * @ingroup group2
 * @brief 组 2 中的类 C3
 */
class C3 {};
 
/** @ingroup group2
 * @brief 组 2 中的类 C4
 */
class C4 {};
 
/** @ingroup group3
 * @brief @link group3 第三个组@endlink 中的类 C5。
 */
class C5 {};
 
/** @ingroup group1 group2 group3 group4
 * 命名空间 N1 在四个组中
 * @sa @link group1 第一个组@endlink、group2、group3、group4
 *
 * 另请参阅 @ref mypage2
 */
namespace N1 {};
 
/** @file
 * @ingroup group3
 * @brief 此文件在组 3 中
 */
 
/** @defgroup group5 第五个组
 * 这是第五个组
 *  @{
 */
 
/** @page mypage1 这是组 5 中的一个部分
 * 第一个部分的文本
 */
 
/** @page mypage2 这是组 5 中的另一个部分
 * 第二个部分的文本
 */
 
/** @} */ // group5 结束
 
/** @addtogroup group1
 *  
 * 第一个组的更多文档。
 *  @{
 */
 
/** 组 1 中的另一个函数 */
void func2() {}
 
/** 组 1 中的又一个函数 */
void func3() {}

/** 组 1 中的另一个函数
 * @brief A class that represents
 *        a circle.
 *
 * This toy class will be used to demonstrate the usage of Doxygen
 *
 * List of functionalities:
 * -# initialize a Circle object with a given radius
 *   - a unit circle is assumed by default
 * -# get the radius of the current Circle object
 * -# get the area of the current Circle object
 * -# get the circumference of the current Circle object
 * -# rescale a Circle object by a factor
 * 
 * @n
 * 
 * The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
 * 
 * @n
 * 
 * The LaTeX and Tex logos are: \f(\LaTeX \f) and \f(\TeX \f).
 * 
 * The area of the a circle is given by
 * 
 * \f[
 *   |I_2|=\left| \int_{0}^T \psi(t) 
 *            \left\{ 
 *               u(a,t)-
 *               \int_{\gamma(t)}^a 
 *               \frac{d\theta}{k(\theta,t)}
 *               \int_{a}^\theta c(\xi)u_t(\xi,t)\,d\xi
 *            \right\} dt
 *         \right|
 * \f]
 * 
 * The circumference of the a circle is given by
 * 
 * \f{eqnarray*}{
 *       g &=& \frac{Gm_2}{r^2} \\ 
 *         &=& \frac{(6.673 \times 10^{-11}\,\mbox{m}^3\,\mbox{kg}^{-1}\,
 *             \mbox{s}^{-2})(5.9736 \times 10^{24}\,\mbox{kg})}{(6371.01\,\mbox{km})^2} \\ 
 *         &=& 9.82066032\,\mbox{m/s}^2
 *  \f}
 * 
 * @n
 * 
 *  A list of events:
 *    - mouse events
 *         -# mouse move event
 *         -# mouse click event\n
 *            More info about the click event.
 *         -# mouse double click event
 *    - keyboard events
 *         1. key down event
 *         2. key up event
 *    - checkbox list
 *         - [ ] unchecked
 *         - [x] checked
 *
 *  More text here.
 * 
 * @n
 * 
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>wanghuan  <td>创建初始版本
 * </table>
 * 
 * @n
 * 
 * @link https://mcresearch.github.io/abacus-user-guide/develop-dox.html
 */
void func4() {}

/**  
 * @brief 函数摘要
 * @param[in, out]  a 参数1
 * @param[in]       b 参数2
 * @param[out]      c 参数3
 * @retval  -1 返回值类型
 * @return  返回值
 * @warning 警告: 例如: 参数不能为空
 * @note    注解
 */
void fun5(int *a, int *b, int *c) {}

/**
 * @brief 打开文件 
 * 
 * @n
 * 
 * 文件打开成功后，必须使用::CloseFile函数关闭
 * @param[in] fileName    文件名
 * @param[in] fileMode    文件模式，可以由以下几个模块组合而成：
 *     -r读取
 *     -w 可写
 *     -a 添加
 *     -t 文本模式(不能与b联用)
 *     -b 二进制模式(不能与t联用)
 * @return 返回文件编号
 * @retval -1表示打开文件失败(生成时:.-1)
 * @note 文件打开成功后，必须使用::CloseFile函数关闭
 * @par 示例:
 * @code
 *        //用文本只读方式打开文件
 *        int ret = OpenFile("test.txt", "a");
 * @endcode
 * @see 函数::ReadFile::CloseFile (“::”是指定有连接功能,可以看文档里的CloseFile变成绿,点击它可以跳转到CloseFile.)
 * @deprecated 由于特殊的原因，这个函数可能会在将来的版本中取消
 */
int OpenFile(const char* fileName, const char* fileMode);
 
/** @} */ // group1 结束



#endif