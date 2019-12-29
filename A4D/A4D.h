#pragma once
#include <QtWidgets/QMainWindow>
#include <QtGui/qevent.h>
#include "ui_A4D.h"
#include "Engine/EventDispatcher.h"
class Scene;
class Camera;
class WGraphics;
class GameWorld;
class TexturePool;
class InputMgr;
class Console;
class Time;
class MouseMgr;
class A4D : public QMainWindow, public EventDispatcher
{
	Q_OBJECT
public:
	A4D(QWidget *parent = Q_NULLPTR);
	~A4D();
	static A4D * _Instance;
	static A4D * getInstance()
	{
		return _Instance;
	}
	static int width() {
		return A4D::_Instance->ui.editorWindow->width();
	}
	static int height()
	{
		return A4D::_Instance->ui.editorWindow->height();
	}
	static HWND window()
	{
		return (HWND)A4D::_Instance->ui.editorWindow->winId();
	}
	//ID3DXSprite * pSprite;
	//IDirect3D9 * pD3d9;
	//IDirect3DDevice9 * pDevice;//编辑器设备
	//IDirect3DDevice9 * pGameDevice;//正式游戏环境设备
	unsigned long frameCnt;
	Scene * pEditScene;
	Camera * pEditCamera;
	WGraphics * Graphics() { return pGraphs; };
	WGraphics * pGraphs;
	GameWorld * pWorld;
	TexturePool * pTexturePool;
	InputMgr * pInput;
	Console * pConsole;
	Time * pTime;
	MouseMgr * pMouse;
	bool EditorPlaying;
	void EditorUpdate();
	void ChangePlaying(bool play);
	void EngineRender();
	void InitHandler();
	void WireFrame(bool b);
	void Shaded(bool trigger);
	bool event(QEvent *);
	void paintEvent(QPaintEvent *event);
	void InitListener();
	map<int, Transform*> TransformHash;
	map<int, QTreeWidgetItem *> TreeItemHash;
	//dispatcher
	void OnHierarchyChanged(AEvent * evt);

	void OnEnable(AEvent * context);
	void OnDisable(AEvent * context);
private:
	Ui::A4DClass ui;
};
