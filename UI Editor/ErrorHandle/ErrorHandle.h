#ifndef ERROR_HANDLE_H
#define ERROR_HANDLE_H

#include <exception>
#include <stdexcept>

namespace ExtraExcept
{

/*
 * 类名：unexpected_situation
 * 使用：根据设计的想法，在预料不会走到的分支，抛出这个异常
 */

class unexpected_situation : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit unexpected_situation(const std::string& msg)
		: _Mybase(msg)
	{

	}

	explicit unexpected_situation(const char* const msg)
		: _Mybase(msg)
	{

	}
};

/*
 * 类名：invoke_too_early
 * 使用：在相关初始化还未完成就调用了该函数
 */

class invoke_too_early : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit invoke_too_early(const std::string& msg)
		: _Mybase(msg)

	{

	}

	explicit invoke_too_early(const char* const msg)
		: _Mybase(msg)
	{

	}
};

/*
 * 类名: wrong_invoke_seq
 * 使用：需要在调用该函数前调用另外的函数
 */

class wrong_invoke_seq : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit wrong_invoke_seq(std::string preReqFunc, std::string curFunc)
		: _Mybase("You should invoke " + std::move(preReqFunc) + " before invoking " + std::move(curFunc))
	{

	}

	explicit wrong_invoke_seq(const char* preReqFunc, const char* curFunc)
		: _Mybase(std::string().append("You should invoke ").append(preReqFunc)
			.append(" before invoking ").append(curFunc))
	{

	}
};

/*
 * 类名：under_requirement
 * 使用：用来表达不满足类，函数等的要求
 */

class under_requirement : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit under_requirement(const std::string& msg)
		: _Mybase(msg)
	{

	}

	explicit under_requirement(const char* const msg)
		: _Mybase(msg)
	{

	}
};

}


#endif	// ERROR_HANDLE_H