/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: CDescInfo.h
@Time: 2023/2/19 15:56
@Desc: 通用描述信息
***************************/

#ifndef CGRAPH_CDESCINFO_H
#define CGRAPH_CDESCINFO_H

#include <string>

#include "CBasicDefine.h"

CGRAPH_NAMESPACE_BEGIN

class CDescInfo {
public:
    /**
     * 获取名称信息
     * @return
     */
    const std::string& getName() const {
        return name_.empty() ? session_ : name_;
    }

    /**
     * 获取唯一id信息
     * @return
     */
    const std::string& getSession() const {
        return session_;
    }

    /**
     * 获取描述信息
     * @return
     */
    const std::string& getDescription() const {
        return description_;
    }

    /**
     * 设置名称信息
     * @param name
     * @return
     */
#if defined(_MSC_VER) && _MSC_VER <= 1800
	 // 这部分代码在编译器为 Visual Studio 2013 及以上版本时会被编译
	 // 可以在这里放置只在 VS2013 及以上版本编译器下执行的代码
	virtual CDescInfo* setName(const std::string& name)
#else
	virtual auto setName(const std::string& name)
		-> decltype(this)
#endif
    {
        name_ = name;
        return this;
    }

    /**
     * 设置描述信息
     * @param description
     * @return
     */

#if defined(_MSC_VER) && _MSC_VER <= 1800
		// 这部分代码在编译器为 Visual Studio 2013 及以上版本时会被编译
		// 可以在这里放置只在 VS2013 及以上版本编译器下执行的代码
	virtual CDescInfo* setDescription(const std::string& description)
#else
	virtual auto setDescription(const std::string& description)
		-> decltype(this)
#endif
    {
        description_ = description;
        return this;
    }

    virtual ~CDescInfo() = default;

protected:
    std::string name_;                               // 名字
    std::string session_;                            // 唯一id信息
    std::string description_;                        // 描述信息
};

CGRAPH_NAMESPACE_END

#endif //CGRAPH_CDESCINFO_H
