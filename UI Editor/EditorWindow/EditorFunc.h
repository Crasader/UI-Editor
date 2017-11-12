#ifndef EDITOR_FUNC_H
#define EDITOR_FUNC_H

/*
 * �ļ�����EditorFunc
 * ���ã�����ʵ�ִ��ڱ༭��صĹ���
 * ˵����
 * 1.�������C++ Programming Language 4th�е�27.4.2: Linearizing Class Hierarchies�е���Ʒ�����
 * �Ż����Դ�����غ�����ʵ��
 * 2.�޸ĸ�����������ԣ���Ҫ��Ӧ���updateWinAttr���������������б��е�ֵ���������Ա���һ��
 */

#include <map>
#include <utility>
#include <functional>
#include <wx/string.h>
#include <wx/any.h>
#include "../EditorFuncDefine.h"
#include "../Form/EditorToolWidgetSelectDefine.h"
#include "../ErrorHandle/ErrorHandle.h"

namespace inner
{
	template <typename T>
	class SimpleWindow;
}

class Visitor;
class DrawControlManager;

namespace inner
{
	class EditorFunc
	{
	public:
		using FuncBaseType = EditorFunc;
		using WIN_ATTR_MAP = std::map<wxString, wxAny>;
	public:
		EditorFunc();
		virtual ~EditorFunc();

		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		virtual SimpleWindow<EditorFunc>* getConstructWindow() = 0;

		// ������ȡ����������
		virtual wxString getWindowClassName() const { return EDITOR_WINDOW_TYPE; }
		// ��ȡ����ID��������ʶ����
		ID_TYPE getId() const { return m_id; }
		// �����жϴ����ڱ༭���Ƿ���Ա༭
		bool isUiEditable() const { return m_editShow; }
		// ������ȡ�����Ƿ���Ա༭�����ڴ��ڹ����࣬���Բ����Ա༭
		virtual bool isAttrEditable() { return true; }
		// �����鿴��ӦID�Ĵ���
		virtual SimpleWindow<EditorFunc>* findMatchWnd(ID_TYPE findId);

		// ���´��ڶ���������Ϣ
		virtual void updateWinAttr(const wxString& attrName, const wxAny& value) { updateAttrValue(attrName, value); }
		// ��ȡ���ڶ��������б��е���Ϣ
		const wxAny& getWinAttr(const wxString& attrName) const;
		// ���������������Ա���ǰֻ������б���Ϣ�������޸�Window�е�����
		template <typename ATTR_MAP_TYPE = WIN_ATTR_MAP>
		void resetWinAttrs(ATTR_MAP_TYPE&& allTypes = ATTR_MAP_TYPE());
		// ��ȡ�������Ա��е�ȫ����Ϣ
		const WIN_ATTR_MAP& getWinAttrs() const 
		{ 
			return m_allWinAttrs; 
		}

		// ���ô����ڱ༭ʱ�Ƿ���ʾ
		virtual void setEditShow(bool editShow) { m_editShow = editShow; }

		//�ڱ༭�����ϻ���
		virtual void editDraw(int absX, int absY, DrawControlManager* drawManager) {}

	protected:
		// ���崦����Ϣ�����ͣ�����ֵ��ʾ�Ƿ��޸������ԣ�true��ʾ�޸ģ�false��ʾδ�޸�
		using CHANGE_ATTR_FUNC = std::function<bool(EditorFunc*, const wxAny&)>;
		using ATTR_HANDLE_MAP = std::map<const wxString, CHANGE_ATTR_FUNC>;
		// �޸ı༭ʱ�Ƿ���ʾ
		bool changeEditShow(const wxAny& value);
		// �޸�X����
		bool changePosX(const wxAny& value);
		// �޸�Y����
		bool changePosY(const wxAny& value);
		// �޸�sizeX
		bool changeSizeX(const wxAny& value);
		// �޸�sizeY
		bool changeSizeY(const wxAny& value);

		// ��ȡ���������Դ�����Map
		static const ATTR_HANDLE_MAP& getEditorAttrHandles();

	protected:
		bool getEditShow() const { return m_editShow; }
		// ���ô���ID
		void setId(ID_TYPE id) { m_id = id; }

		// �����������Ա��е���Ϣ
		void updateAttrValue(const wxString& name, const wxAny& value);

	private:
		// ���������µĴ���ID
		static ID_TYPE s_id_generator;
		// ��ȡһ������ID����ȡ�Ĵ���ID��ID_BEG��ʼ������µĴ���IDΪ��ֵ������ʾ����
		static ID_TYPE getNewId();
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
		ID_TYPE m_id;
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

	// ��ȡ���ڶ��������б��е���Ϣ
	inline const wxAny& EditorFunc::getWinAttr(const wxString & attrName) const
	{
		auto it = m_allWinAttrs.find(attrName);
		if (it != m_allWinAttrs.cend())
		{
			return it->second;
		}

		// �����߼���Ӧ�ó��ֵ����
		throw ExtraExcept::unexpected_situation("EditorFunc::getWinAttr can't find " + attrName.ToStdString());

		static wxAny value;
		return value;
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
				return true;
			}
		}
		else
		{
			throw std::runtime_error(funcName + std::string("'s parameter is not ") + typeid(T).name());
		}

		return false;
	}

	// ��ȡһ������ID����ȡ�Ĵ���ID��10��ʼ������µĴ���IDΪ��ֵ������ʾ����
	inline int EditorFunc::getNewId()
	{
		auto newId = ++s_id_generator;
		if (newId < 0)
		{
			throw std::runtime_error("EditorFunc::getNewId will return negative id");
		}
		return newId;
	}
}

#include "EditorFuncCategory.inl"


#endif	// EDITOR_FUNC_H
