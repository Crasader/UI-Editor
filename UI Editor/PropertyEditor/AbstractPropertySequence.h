#ifndef ABSTRACT_PROPERTY_SEQUENCE_H
#define ABSTRACT_PROPERTY_SEQUENCE_H

/*
 * �ļ�����AbstractPropertySequence
 * ���ã����Ա༭������ʾ���Ե�˳��
 */

class AbstractPropertySequence
{
public:
	AbstractPropertySequence() {}
	virtual ~AbstractPropertySequence() {}

protected:
	virtual void sortPropertySequence();

};

#endif	// ABSTRACT_PROPERTY_SEQUENCE_H
