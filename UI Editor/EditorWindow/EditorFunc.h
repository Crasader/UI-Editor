#ifndef EDITOR_FUNC_H
#define EDITOR_FUNC_H

/*
 * �ļ�����EditorFunc
 * ���ã�����ʵ�ִ��ڱ༭��صĹ���
 * ˵�����������C++ Programming Language 4th�е�27.4.2: Linearizing Class Hierarchies�е���Ʒ�����
 * �Ż����Դ�����غ�����ʵ��
 */

#include <map>
#include <utility>
#include <functional>
#include <stdexcept>
#include <wx/string.h>
#include <wx/any.h>

namespace inner
{
	template <typename T>
	class SimpleWindow;
}

// �༭���ڵ���ʼID
const int ID_BEG = 10;

class Visitor;

namespace inner
{
	class EditorFunc
	{
	public:
		using WIN_ATTR_MAP = std::map<wxString, wxAny>;
	public:
		EditorFunc();
		virtual ~EditorFunc();

		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		virtual SimpleWindow<EditorFunc>* getConstructWindow() = 0;

		// ��ȡ����ID��������ʶ����
		int getId() const { return m_id; }

		// ���´��ڶ���������Ϣ
		virtual void updateWinAttr(const wxString& attrName, const wxAny& value) { updateAttrValue(attrName, value); }

		// ���������������Ա���ǰֻ������б���Ϣ�������޸�Window�е�����
		template <typename ATTR_MAP_TYPE = WIN_ATTR_MAP>
		void resetWinAttrs(ATTR_MAP_TYPE&& allTypes = ATTR_MAP_TYPE());

	protected:
		// ���崦����Ϣ�����ͣ�����ֵ��ʾ�Ƿ��޸������ԣ�true��ʾ�޸ģ�false��ʾδ�޸�
		using CHANGE_ATTR_FUNC = std::function<bool(EditorFunc*, const wxAny&)>;
		using ATTR_HANDLE_MAP = std::map<const wxString, CHANGE_ATTR_FUNC>;
		// �޸ı༭ʱ�Ƿ���ʾ
		bool ChangeEditShow(const wxAny& value);
		// �޸�X����
		bool ChangePosX(const wxAny& value);
		// �޸�Y����
		bool ChangePosY(const wxAny& value);
		// �޸�sizeX
		bool ChangeSizeX(const wxAny& value);
		// �޸�sizeY
		bool ChangeSizeY(const wxAny& value);

		// ��ȡ���������Դ�����Map
		static const ATTR_HANDLE_MAP& getEditorAttrHandles();

	protected:
		// ���ô����ڱ༭ʱ�Ƿ���ʾ
		void setEditShow(bool editShow) { m_editShow = editShow; }
		bool getEditShow() const { return m_editShow; }

		// �����������Ա��е���Ϣ
		void updateAttrValue(const wxString& name, const wxAny& value);
		// ��ȡ�������Ա��е�ȫ����Ϣ
		const WIN_ATTR_MAP& getWinAttrs() const { return m_allWinAttrs;  }

	private:
		// ���������µĴ���ID
		static int s_id_generator;
		// ��ȡһ������ID����ȡ�Ĵ���ID��ID_BEG��ʼ������µĴ���IDΪ��ֵ������ʾ����
		static int getNewId();
		// ��ʼ�����Դ�����Map
		static ATTR_HANDLE_MAP initEditorAttrHanldes();
		// �޸Ĵ�����һ��T������
		template <typename T>
		bool ChangeWndAttrValue(const wxAny& value, std::function<T(SimpleWindow<EditorFunc>*)> getFunc,
			std::function<void(SimpleWindow<EditorFunc>*, T)> setFunc, const char* funcName);

	private:
		// �ڱ༭ʱ���ô����Ƿ���ʾ
		bool m_editShow;
		// ������¼��ǰ���ڵ�ID
		int m_id;
		// ������¼���ڵ�ȫ������
		WIN_ATTR_MAP m_allWinAttrs;
	};

	// ���������������Ա���ǰֻ������б���Ϣ�������޸�Window�е�����
	template<typename ATTR_MAP_TYPE>
	inline void EditorFunc::resetWinAttrs(ATTR_MAP_TYPE&& allTypes)
	{
		m_allWinAttrs = allTypes;
	}

	// �����������Ա��е���Ϣ
	inline void EditorFunc::updateAttrValue(const wxString & name, const wxAny & value)
	{
		m_allWinAttrs[name] = value;
	}

	// �޸Ĵ�����һ��int������
	template <typename T>
	inline bool EditorFunc::ChangeWndAttrValue(const wxAny& value, std::function<T(SimpleWindow<EditorFunc>*)> getFunc,
		std::function<void(SimpleWindow<EditorFunc>*, T)> setFunc, const char* funcName)
	{
		if (value.CheckType<T>())
		{
			auto v = value.As<T>();
			auto pThis = getConstructWindow();
			if (v != getFunc(pThis))
			{
				setFunc(pThis, v);
			}
			return false;
		}
		else
		{
			throw std::runtime_error(funcName + std::string("'s parameter is not an int."));
		}

		return false;
	}

	// ��ȡһ������ID����ȡ�Ĵ���ID��10��ʼ������µĴ���IDΪ��ֵ������ʾ����
	inline int EditorFunc::getNewId()
	{
		int newId = s_id_generator++;
		if (newId < 0)
		{
			throw std::runtime_error("EditorFunc::getNewId will return negative id");
		}
		return newId;
	}
}


#endif	// EDITOR_FUNC_H
