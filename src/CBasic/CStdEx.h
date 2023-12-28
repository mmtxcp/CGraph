/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: CStdEx.h
@Time: 2023/1/31 23:15
@Desc: 
***************************/

#ifndef CGRAPH_CSTDEX_H
#define CGRAPH_CSTDEX_H

#include <memory>
#include <type_traits>

CGRAPH_NAMESPACE_BEGIN

// 兼容 std::enable_if_t 的语法
template<bool B, typename T = void>
using c_enable_if_t = typename std::enable_if<B, T>::type;

// 兼容 std::make_unique 的语法
template<typename T, typename... Args>
typename std::unique_ptr<T> c_make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


#if defined(_MSC_VER) && _MSC_VER <= 1800
// 这部分代码在编译器为 Visual Studio 2013 及以上版本时会被编译
// 可以在这里放置只在 VS2013 及以上版本编译器下执行的代码
#define NOEXCEPT 
#else
#define NOEXCEPT noexcept
#endif
CGRAPH_NAMESPACE_END

#endif //CGRAPH_CSTDEX_H
