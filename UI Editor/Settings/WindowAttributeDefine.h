#ifndef WINDOW_ATTRIBUTE_DEFINE_H
#define WINDOW_ATTRIBUTE_DEFINE_H

#include <wx/string.h>
#include <map>

// ������ʶ��xml������ƶ����õ���
const wxString SET_PROPERTY_TYPE = wxS("EditorProperty");
const wxString SET_EDITOR_NAME = wxS("EditorName");
const wxString SET_EDITOR_VALIDATOR = wxS("EditorValidator");
const wxString SET_EDITOR_MAX_LEN = wxS("EditorMaxLength");
const wxString SET_INITIAL_VALUE = wxS("InitialValue");

// ������¼�༭�������ͣ���Ӧ��wxPGProperty�����ﲻ���ִ�Сд
// Ĭ�ϵ��������ͣ���ǰΪwxStringProeprty
const wxString DEFAULT_PROPERTY = "";		// ���������ڣ����ʾ""
// ��Ӧ��wxStringProperty
const wxString STRING_PROPERTY = "string";
// ��Ӧ��wxIntProperty
const wxString INT_PROPERTY = "int";
// ��Ӧ��wxBoolProprety
const wxString BOOL_PROPERTY = "bool";
// ��Ӧ��wxEnumProperty
const wxString ENUM_PROPERTY = "enum";


// ������ʶ�༭���Զ�Ӧ�ڱ༭�����ͣ���Ӧ��wxPGEditor
// ����Ĭ�ϱ༭��
const wxString DEFAULT_EDITOR = "";		// ���������ڣ����ʾ""
// ��Ӧ��wxPGTextCtrlEditor
const wxString TEXTCTRL_EDITOR = "textctrl";
// ��Ӧ��wxPGSpinCtrlEditor
const wxString SPINCTRL_EDITOR = "spinctrl";
// ��Ӧ��wxPGCheckBoxEditor
const wxString CHECKBOX_EDITOR = "checkbox";
// ��Ӧ��wxPGChoiceEditor
const wxString CHOICE_EDITOR = "choice";




// ������ʶ�༭����ʱ��Validator����Ӧ��wxValidator
// Ĭ��ֵ����ǰΪû��Validator
const wxString DEFAULT_VALIDATOR = "";		// ���������ڣ����ʾ""



// ������ʶ�༭�����ܵ��ַ�����󳤶ȣ���Ӧ��wxPGProperty��SetMaxLength����
// Ĭ��ֵ����ǰ��ʾ255
const wxString DEFAULT_MAXLENGTH = "";		// ���������ڣ����ʾ""
// Ĭ��ֵ��Ӧ���ַ�����С
const int DEF_MAX_LENGTH = 255;


// ������ʶProperty��Ӧ�����ԣ���wxPGProperty::SetAttribute����
//
const wxString XML_ATTR_DEFAULT_VALUE = wxS("DefaultValue");
// ��Ӧ��wxPG_ATTR_HINT
const wxString XML_ATTR_HINT = wxS("Hint");
// ��Ӧ��wxPG_ATTR_MAX
const wxString XML_ATTR_MAX = wxS("Max");
// ��Ӧ��wxPG_ATTR_MIN
const wxString XML_ATTR_MIN = wxS("Min");
//// ��Ӧ��wxPG_ATTR_SPINCTRL_MOTIONSPIN
//const wxString XML_ATTR_SPINCTRL_MOTIONSPIN = wxS("MotionSpin");
// ��Ӧ��wxPG_ATTR_SPINCTRL_STEP
const wxString XML_ATTR_SPINCTRL_STEP = wxS("Step");
// ��Ӧ��wxPG_ATTR_SPINCTRL_WRAP
const wxString XML_ATTR_SPINCTRL_WRAP = wxS("Wrap");
// ��Ӧ��wxPG_ATTR_UNITS
const wxString XML_ATTR_UNITS = wxS("Units");
// ��Ӧ��wxPG_BOOL_USE_CHECKBOX
const wxString XML_BOOL_USE_CHECKBOX = wxS("UseCheckbox");
// ��Ӧ��wxPG_BOOL_USE_DOUBLE_CLICK_CYCLING
const wxString XML_BOOL_USE_DOUBLE_CLICK_CYCLING = wxS("UseDClickCycling");
// ��Ӧ��wxPG_DIR_DIALOG_MESSAGE
const wxString XML_DIR_DIALOG_MESSAGE = wxS("DialogMessage");
// ��Ӧ��wxPG_FILE_DIALOG_STYLE
const wxString XML_FILE_DIALOG_STYLE = wxS("DialogStyle");
// ��Ӧ��wxPG_FILE_DIALOG_TITLE
const wxString XML_FILE_DIALOG_TITLE = wxS("DialogTitle");
// ��Ӧ��wxPG_FILE_INITIAL_PATH
const wxString XML_FILE_INITIAL_PATH = wxS("InitialPath");
// ��Ӧ��wxPG_FILE_SHOW_FULL_PATH
const wxString XML_FILE_SHOW_FULL_PATH = wxS("ShowFullPath");
// ��Ӧ��wxPG_FILE_SHOW_RELATIVE_PATH
const wxString XML_FILE_SHOW_RELATIVE_PATH = wxS("ShowRelativePath");
// ��Ӧ��wxPG_FILE_WILDCARD
const wxString XML_FILE_WILDCARD = wxS("Wildcard");
// ��Ӧ��wxPG_FLOAT_PRECISION
const wxString XML_FLOAT_PRECISION = wxS("Precision");
// ��Ӧ��wxPG_UINT_BASE
const wxString XML_UINT_BASE = wxS("Base");
// ��Ӧ��wxPG_UINT_PREFIX
const wxString XML_UINT_PREFIX = wxS("Prefix");


// ���Ե�һЩ������Ϣʹ�õı�ʶ��
// ������ʶö��ʹ�õ�����ֵ
const wxString ENUM_RANGE = wxS("range");
// �ָ�ö��ֵʹ�õķָ���
const wxString ENUM_RANGE_DELIMITER = wxS(",");


// �����洢�������Ա༭��Ϣ
struct AttributeProperty
{
	// ������
	wxString propertyName;
	// ��������
	wxString editorProperty;
	// ���Ա༭��
	wxString editorName;
	// ������֤
	wxString editorValidator;
	// �༭����󳤶�
	int editorMaxLength;
	// ��ʼֵ
	wxString initialValue;
	// �༭������������
	std::map<wxString, wxString> editorAttributeList;
	// �������ԵĶ�����Ϣ
	std::map<wxString, wxString> additionalInfos;

	AttributeProperty()
		: editorMaxLength(0)
	{

	}
};

#endif	// WINDOW_ATTRIBUTE_DEFINE_H
