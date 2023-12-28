/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: USpinLock.h
@Time: 2023/2/21 22:17
@Desc: 
***************************/

#ifndef CGRAPH_USPINLOCK_H
#define CGRAPH_USPINLOCK_H

#include <atomic>

#include "../UThreadObject.h"

CGRAPH_NAMESPACE_BEGIN

class USpinLock : public UThreadObject {
public:
#if defined(_MSC_VER) && _MSC_VER <= 1800
	// 这部分代码在编译器为 Visual Studio 2013 及以下版本时会被编译
	// 可以在这里放置只在 VS2013 及以下版本编译器下执行的代码
    USpinLock()
    {
        flag_.clear(); // 初始化标志
    }
#endif
	
    /**
     * 加锁
     */
    CVoid lock() {
        // memory_order_acquire 后面访存指令勿重排至此条指令之前
        while (flag_.test_and_set(std::memory_order_acquire)) {
        }
    }

    /**
     * 解锁
     */
    CVoid unlock() {
        // memory_order_release 前面访存指令勿重排到此条指令之后
        flag_.clear(std::memory_order_release);
    }

    /**
     * 尝试加锁。若未加锁，会上锁
     * @return
     */
    CBool tryLock() {
        return !flag_.test_and_set();
    }

private:
#if defined(_MSC_VER) && _MSC_VER <= 1800
    std::atomic_flag flag_;
#else
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;         // 标志位
#endif
   
};

CGRAPH_NAMESPACE_END

#endif //CGRAPH_USPINLOCK_H
