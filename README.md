# UI-Editor
An UI Editor written by wxWidgets and DirectX used for editing game ui xml

progress:
It is working in progress now, and there are a lot of things to do.

contribution:
Welcome to anyone to tell me the unreasonable part and contribute it. Without your help, the project would not be 
that good as it will be.

goal:
Writing a extensible ui xml editor. It should meet some requests, such as adding different widgets easily,
adding attributes to widgets easily, appending different commands easily and others if available.



以下内容引用于EditorProtocol文件夹

/*
 * 作用：说明所在文件夹的用处
 * 说明：该项目会用到各种约定，例如，通过加载xml来创建控件类型选择的功能区时，不同类型控件对应的名字，及其他各种定义。
 * 该文件夹，将会在不同模块使用的约定整合在一起，从而方便查找和修改。
 * 各种约定会分布在该文件夹中的各个文件中，其中，一些与代码无关的约定，会出现在该文件的下方。
 */

/*
 * 添加头文件规范
 * 1. 先添加C++标准库头文件。
 * 2. 然后添加wxWidgets相关头文件，Win32相关头文件，以及d3d相关头文件（尖括号的头文件）。
 * 3. 再添加该项目窗口的头文件。(1)若该文件为.h文件，则添加的第一个头文件应该是该文件中创建的主要类的父类所在的头文件，然后是各种定义文件，
 *    再添加其他头文件。(2)若该文件为.cpp文件，则添加的第一个头文件应该是为了实现的头文件，然后是各种定义文件，然后是其他文件。
 */

/*
 * 注释说明规范：
 * 1.该项目的作用是生成一个表示窗口结构，属性的xml，所以在主工作区，会绘制这种窗口，然后修改窗口的各种属性。
 * 在该项目中，还存在其他含义的窗口，例如该程序运行时，会看到各种窗口。
 * 下面约定：
 * (1) 凡是提到“控件”的地方，都是指在主工作区绘制的，将要写入xml的窗口。
 * (2) 在项目中，存在用于选择窗口类型，显示控件，编辑控件属性等显示区，这些区域成为“工作区”或者“功能区”。
 * (3) 其他涉及窗口的地方，就简单成为“窗口”。
 * (4) 其他需要使用“控件”这个称呼，又不是上述含义的地方，会有额外的说明，例如wxWidgets控件。
 */

/*
 * 命名规范：
 * 1.主工作区绘制的控件，都以Editor作为前缀
 * 2.主工作区和功能区命名，都以Form作为前缀
 */

/*
 * 文件夹模块说明：
 * 1.各种约定的文件位于EditorProtocol文件夹。
 * 2.程序启动时加载的，用来完成程序的初始化，各种设置的文件位于Settings文件夹。
 * 3.控件的类定义的文件，位于EditorWindow文件夹。
 * 4.提供各种简单函数，辅助函数，类等定义的文件，位于Util文件夹。
 * 5.定义各种异常，简单处理异常的文件，位于ErrorHandle文件夹。
 * 6.实现各种功能区的文件，位于Form文件夹
 * 7.处理各种消息，各种命令的文件位于EditMessage文件夹。
 */
