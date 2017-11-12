#ifndef ARITHMETIC_UTIL_H
#define ARITHMETIC_UTIL_H

#include <stdexcept>

// 添加 scalar numeric conversion function，实现源自 C++ programming language(4th)
// 用来防止使用static转换的时候，值发生改变
template <class Source, typename Target>
inline Target narrow_cast(Source v)
{
	auto r = static_cast<Target>(v);
	if (static_cast<Source>(r) != v)
		throw std::runtime_error("narrow_cast<>() failed");
	return r;
}

template <class Source>
inline Source narrow_cast(Source v)
{
	return v;
}

#endif	// ARITHMETIC_UTIL_H
