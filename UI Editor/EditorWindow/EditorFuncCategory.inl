#ifndef EDITOR_FUNC_CATEGORY_INL
#define EDITOR_FUNC_CATEGORY_INL

/*
 * �ļ�����EditorFuncCategory.inl
 * ���ã�����һϵ����EditorFunc�йص��࣬��ʽ����Щ����ΪEditorFunc��������
 * ˵������Щ��ֻ����ʽ�ϵ����ã������Ķ�EditorFunc���麯�����ع�������SimpleWindow��
 * ���������͵��������У������������͵�ʵ�֣�����������û��ʵ�ʵ����ã���������SimpleWindow
 * ���������У���������µ���ļ̳нṹ
 */

namespace inner
{
	// ����SimpleWindow����������
	class EditorEditableFunc : public EditorFunc
	{
	public:
		using FuncBaseType = EditorFunc;
	public:
		using EditorFunc::EditorFunc;
		~EditorEditableFunc() override = default;
	};

	// ����ContainerWindow����������
	class EditorContainerFunc : public EditorEditableFunc
	{
	public:
		using FuncBaseType = EditorFunc;
	public:
		using EditorEditableFunc::EditorEditableFunc;
		~EditorContainerFunc() override = default;

	};
}

#endif	// EDITOR_FUNC_CATEGORY_INL
