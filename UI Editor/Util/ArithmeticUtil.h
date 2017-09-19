#ifndef ARITHMETIC_UTIL_H
#define ARITHMETIC_UTIL_H

#include <stdexcept>

// ��� scalar numeric conversion function��ʵ��Դ�� C++ programming language(4th)
// ������ֹʹ��staticת����ʱ��ֵ�����ı�
template <typename Target, class Source>
Target narrow_cast(Source v)
{
	auto r = static_cast<Target>(v);
	if (static_cast<Source>(r) != v)
		throw std::runtime_error("narrow_cast<>() failed");
	return r;
}

#endif	// ARITHMETIC_UTIL_H
