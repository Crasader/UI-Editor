#ifndef ARITHMETIC_UTIL_H
#define ARITHMETIC_UTIL_H

//#include <stdexcept>
//
//// ��� scalar numeric conversion function��ʵ��Դ�� C++ programming language(4th)
//// ������ֹʹ��staticת����ʱ��ֵ�����ı�
//template <class Source, typename Target>
//inline Target narrow_cast(Source v)
//{
//	auto r = static_cast<Target>(v);
//	if (static_cast<Source>(r) != v)
//		throw std::runtime_error("narrow_cast<>() failed");
//	return r;
//}

#include <type_traits>
#include <stdexcept>

// ��� scalar numeric conversion function��ʵ��Դ�� C++ programming language(4th)
// ������ֹʹ��staticת����ʱ��ֵ�����ı�
template <typename Target, typename Source,
	typename = std::enable_if_t<!std::is_same_v<std::remove_reference_t<std::remove_const_t<Target>>,
	std::remove_reference_t<std::remove_const_t<Source>>> && !std::is_reference_v<Target>, int>>
	inline Target narrow_cast(Source v)
{
	// using Target_U = std::remove_reference_t<Target>;
	// using Source_U = std::remove_reference_t<Source>;
	auto r = static_cast<Target>(v);
	if (static_cast<Source>(r) != v)
		throw std::runtime_error("narrow_cast<>() failed");
	return r;
}

template <typename Target, typename Source,
	typename = std::enable_if_t<std::is_same_v<std::remove_reference_t<std::remove_const_t<Target>>,
	std::remove_reference_t<std::remove_const_t<Source>>> && !std::is_reference_v<Target>, int>>
	inline constexpr std::remove_reference_t<Source> narrow_cast(Source v)
{
	return std::remove_reference_t<Source>(v);
}

#endif	// ARITHMETIC_UTIL_H
