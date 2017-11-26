#ifndef SELECT_WINDOWS_COMMAND_H
#define SELECT_WINDOWS_COMMAND_H

/*
 * �ļ�����SelectWindowsCommand
 * ���ã����õ�ǰѡ�еĿؼ�
 * ˵�������༭��ʼ�ջ����һ�����߶����ǰѡ�еĿؼ������ֻ����һ����ǰѡ��ؼ�����ô�ÿؼ�Ϊ��ǰ�༭�ؼ���
 * �ÿؼ�Ҫô���û������Ŀؼ���Ҫô�ǹ���ؼ������й���ؼ������Ա༭����
 */

#include <unordered_set>
#include <stdexcept>
#include <wx/cmdproc.h>
#include "../EditorWindow/EditorWindowInterface.h"

namespace Command
{
	template <typename T>
	class SelectWindowsCommand : public wxCommand
	{
	public:
		SelectWindowsCommand(T mgr, std::unordered_set<ID_TYPE> selectIds)
			: m_mgr(mgr), m_selectIds(std::move(selectIds))
		{
			if (mgr == nullptr)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr shouldn't be nullptr"));
			}
		}
		~SelectWindowsCommand() override {}

		// �ع�ִ�к���
		bool Do() override;
		// �ع�ȡ��ִ�к���
		bool Undo() override;


	private:
		T m_mgr;
		// ����ѡ�е����пؼ�ID
		std::unordered_set<ID_TYPE> m_selectIds;
	};


	// �ع�ִ�к���
	template<typename T>
	inline bool SelectWindowsCommand<T>::Do()
	{
		return m_mgr->changeSelectWnds(m_selectIds);
	}

	// �ع�ȡ��ִ�к���
	template<typename T>
	inline bool SelectWindowsCommand<T>::Undo()
	{
		return m_mgr->changeSelectWnds(m_selectIds);
	}
}

#endif	// SELECT_WINDOWS_COMMAND_H