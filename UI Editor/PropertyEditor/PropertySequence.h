#ifndef PROPERTY_SEQUENCE_H
#define PROPERTY_SEQUENCE_H

/*
 * �ļ�����AbstractPropertySequence
 * ���ã����Ա༭������ʾ���Ե�˳��
 * ������ͬһ���͵Ĵ����࣬����ͬһ����������˳�򣬼��̶������ԣ��̶����������У����Կ��ǣ�
 * ����һ�λ�ȡ��ʱ�򣬸��������ļ��л�õ���Ϣ��������֮���ȡ��ֱ�ӷ���ֵ
 */

#include "AbstractPropertySequence.h"
#include <typeinfo>

class PropertySequence : public AbstractPropertySequence
{
public:
	PropertySequence() : AbstractPropertySequence() {}
	~PropertySequence() override {}

protected:
	void sortPropertySequence() override {}

private:

};

#endif	// PROPERTY_SEQUENCE_H
