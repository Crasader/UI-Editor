#ifndef CHANGE_WIN_ATTR_COMMAND_H
#define CHANGE_WIN_ATTR_COMMAND_H

/*
 * �ļ�����ChangeWinAttrCommand
 * ���ã��޸ĵ�ǰ����(EditorAbstractWindowϵ��)������ֵ
 * ˵��������ǰ���ڵ�����ֵ�޸�ΪnewValue��ͬʱ��֮ǰ��ֵ���棬����ʵ��Undo����
 */

#include <wx/cmdproc.h>
#include <stdexcept>
#include "../EditorWindow/EditorWindowInterface.h"

namespace Command
{
	template <typename T>
	class ChangeWinAttrCommand : public wxCommand
	{
	public:
		ChangeWinAttrCommand(T mgr, wxString attrName, wxAny newValue)
			: wxCommand(true),
			m_mgr(mgr),
			m_attrName(attrName),
			m_toSetValue(newValue)
		{
			if (mgr == nullptr)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr, lastCurWnd and newCurWnd shouldn't be nullptr"));
			}
		}
		~ChangeWinAttrCommand() {}

		// �ع�ִ�к���
		bool Do() override;
		// �ع�ȡ��ִ�к���
		bool Undo() override;

	private:
		T m_mgr;
		// ��ǰ����Ҫ�����õ�����
		wxString m_attrName;
		// ��ǰ����Ҫ�����õ�ֵ
		wxAny m_toSetValue;
	};

	// �ع�ִ�к���
	template<typename T>
	inline bool ChangeWinAttrCommand<T>::Do()
	{
		m_mgr->changeSelectWndAttr(m_attrName, m_toSetValue);
		return true;
	}

	// �ع�ȡ��ִ�к���
	template<typename T>
	inline bool ChangeWinAttrCommand<T>::Undo()
	{
		m_mgr->changeSelectWndAttr(m_attrName, m_toSetValue);
		return true;
	}
}

#endif	// CHANGE_WIN_ATTR_COMMAND_H