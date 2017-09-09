#ifndef ERROR_HANDLE_H
#define ERROR_HANDLE_H

#include <exception>
#include <stdexcept>

namespace ExtraException
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

}


#endif	// ERROR_HANDLE_H