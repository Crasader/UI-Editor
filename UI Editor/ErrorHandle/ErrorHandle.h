#ifndef ERROR_HANDLE_H
#define ERROR_HANDLE_H

#include <exception>
#include <stdexcept>

namespace ExtraExcept
{

/*
 * ������unexpected_situation
 * ʹ�ã�������Ƶ��뷨����Ԥ�ϲ����ߵ��ķ�֧���׳�����쳣
 */

class unexpected_situation : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit unexpected_situation(const std::string& msg)
		: std::logic_error(msg)
	{

	}

	explicit unexpected_situation(const char* const msg)
		: std::logic_error(msg)
	{

	}
};

/*
 * ������invoke_too_early
 * ʹ�ã�����س�ʼ����δ��ɾ͵����˸ú���
 */

class invoke_too_early : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit invoke_too_early(const std::string& msg)
		: std::logic_error(msg)

	{

	}

	explicit invoke_too_early(const char* const msg)
		: std::logic_error(msg)
	{

	}
};

/*
 * ����: wrong_invoke_seq
 * ʹ�ã���Ҫ�ڵ��øú���ǰ��������ĺ���
 */

class wrong_invoke_seq : public std::logic_error
{
public:
	using _Mybase = std::logic_error;

	explicit wrong_invoke_seq(std::string preReqFunc, std::string curFunc)
		: std::logic_error("You should invoke " + std::move(preReqFunc) + " before invoking " + std::move(curFunc))
	{

	}

	explicit wrong_invoke_seq(const char* preReqFunc, const char* curFunc)
		: std::logic_error(std::string().append("You should invoke ").append(preReqFunc)
			.append(" before invoking ").append(curFunc))
	{

	}
};

}


#endif	// ERROR_HANDLE_H