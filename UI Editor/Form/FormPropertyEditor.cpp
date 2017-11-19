#include <wx/propgrid/propgrid.h>
#include <wx/log.h>
#include "FormPropertyEditor.h"
#include "../Property/ImageProperty.h"
#include "../ErrorHandle/ErrorHandle.h"
#include "../EditMessage/CommandFactory.h"
#include "../EditMessage/ChangeManager.h"

const int PROPERTY_EDITOR_WIDTH = 300;
const int PROPERTY_EDITOR_HEIGHT = 600;

FormPropertyEditor::FormPropertyEditor(wxAuiManager & manager, wxWindow * parent, int direction, const wxString & paneName)
	: FormToolWindow(manager, parent, direction, paneName)
{
	
}

FormPropertyEditor::~FormPropertyEditor()
{
}

// ��ʾ��Ӧ���͵ı༭��
void FormPropertyEditor::resetAttrs(const wxString& winTypeName)
{
	// �����ǰ�򿪵ĺ�֮ǰ��һ�£��򲻲���
	if (winTypeName == m_curEditWinType)
	{
		return;
	}
	// ��ʾ��Ӧ�ؼ��ı༭��
	m_curPropertyGrid->Hide();
	auto it = m_propertyGrids.find(winTypeName);
	if (it != m_propertyGrids.cend())
	{
		it->second->Show();
		m_curPropertyGrid = it->second;
		m_curEditWinType = winTypeName;
		m_sizer->Layout();

		return;
	}

	// û�в��ҵ����쳣
	throw ExtraExcept::unexpected_situation("FormPropertyEditor::resetAttrs: can't find winTypeName in m_propertyGrids");
	return;
}

// ���������б��ֵ
void FormPropertyEditor::updateAttrs(const std::map<wxString, wxAny>& propAttrs)
{
	const char* const PRE_FUNC_NAME = "FormPropertyEditor::resetAttrs";
	const char* const CUR_FUNC_NAME = "FormPropertyEditor::updateAttrs";

	if (m_curPropertyGrid == nullptr)
	{
		throw ExtraExcept::wrong_invoke_seq(PRE_FUNC_NAME, CUR_FUNC_NAME);
	}

	for (const auto& attr : propAttrs)
	{
		auto prop = m_curPropertyGrid->GetProperty(attr.first);
		if (prop == nullptr)
		{
			throw ExtraExcept::wrong_invoke_seq(PRE_FUNC_NAME, CUR_FUNC_NAME);
		}
		// �޸�����ֵ
		prop->SetValue(attr.second);
	}
	// ˢ�������б�
	m_curPropertyGrid->Update();
}

// �����������Ըı�
void FormPropertyEditor::OnPropertyGridChanged(wxPropertyGridEvent & event)
{
	wxPGProperty* prop = event.GetProperty();

	if (prop->GetGrid() != m_curPropertyGrid)
	{
		throw ExtraExcept::unexpected_situation("The wxPGProperty changed is not in current wxPropertyGrid");
	}
	using namespace Command;
	auto changeWinAttrCmd = CommandFactory::instance()->createChangeWinAttrCommand(
		event.GetPropertyName(), event.GetPropertyValue());
	ChangeManager::instance()->getCommandStack().Submit(changeWinAttrCmd);
}

// ��ʼ���༭���Դ���
void FormPropertyEditor::initSubWindows(const std::vector<wxString>& windowTypes)
{
	wxBoxSizer* vBoxSizer = new wxBoxSizer(wxVERTICAL);
	m_sizer = vBoxSizer;

	for (auto const& winType : windowTypes)
	{
		auto propertyGrid = new wxPropertyGrid(getBench(), wxID_ANY, wxPoint(0, 0), 
			wxSize(PROPERTY_EDITOR_WIDTH, PROPERTY_EDITOR_HEIGHT), 
			wxPG_DEFAULT_STYLE | wxPG_SPLITTER_AUTO_CENTER |wxPG_HIDE_MARGIN);
		propertyGrid->SetColumnProportion(0, 4);
		propertyGrid->SetColumnProportion(1, 6);
		propertyGrid->Hide();
		//ImageProperty* imgProp = new ImageProperty("NormalImage", wxPG_LABEL);
		//propertyGrid->Append(imgProp);

		vBoxSizer->Add(propertyGrid, 1, wxALL, 5);
		// ��ӿؼ����ͱ༭�����map
		m_propertyGrids.insert(std::make_pair(winType, propertyGrid));

		propertyGrid->Bind(wxEVT_PG_CHANGED, &FormPropertyEditor::OnPropertyGridChanged, this);
	}
	// �鿴�Ƿ���ڿ��Ա༭�Ŀؼ�����
	if (m_propertyGrids.empty())
	{
		throw ExtraExcept::unexpected_situation("FormPropertyEditor::initSubWindows: m_propertyGrids can't be empty");
	}
	// ��ʼ��ֵ
	m_curEditWinType = m_propertyGrids.begin()->first;
	m_curPropertyGrid = m_propertyGrids.begin()->second;
	m_curPropertyGrid->Show();
	getBench()->SetSizerAndFit(vBoxSizer);
}

// �޸Ķ�Ӧ�ؼ��������б�
void FormPropertyEditor::insertWindowTypeAttrs(const wxString& winType, const std::vector<wxPGProperty*>& attrs)
{
	auto it = m_propertyGrids.find(winType);

	if (it == m_propertyGrids.cend())
	{
		throw std::runtime_error("FormPropertyEditor::insertWindowTypeAttrs: m_properGrids can't find " + winType);
	}

	auto propertyGrid = it->second;
	for (auto prop : attrs)
	{
		propertyGrid->Append(prop);
	}
	propertyGrid->ResetColumnSizes();
	getBench()->SetSizerAndFit(m_sizer);
}
