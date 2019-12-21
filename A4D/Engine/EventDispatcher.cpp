#include "stdafx.h"
#include "EventDispatcher.h"
#include <iostream>
#include <functional>
using namespace std;

EventDispatcher::EventDispatcher()
{
}


EventDispatcher::~EventDispatcher()
{
}

void EventDispatcher::onevent(EventId evtId, Event * context)
{
	map<int, vector<EventHandler*>*>::iterator listeners = _events.find(evtId);
	if (listeners != _events.end())
	{
		vector<EventHandler*>::iterator listener = listeners->second->begin();
		while (listener != listeners->second->end())
		{
			EventHandler * pHandler = *listener;
			invoke(pHandler->caller, pHandler->listener, context);
			if (pHandler->once)
			{
				listener = listeners->second->erase(listener);
				continue;
			}
			listener++;
		}
	}
	else
	{

	}
}

void EventDispatcher::offAll(EventId evt)
{
	//�ڴ���ʱ������.
	OutputDebugString(_T("memory leak"));
	if (evt == EventId::All)
	{
		_events.clear();
	}
	else
	{
		map<int, vector<EventHandler*>*>::iterator it = _events.find(evt);
		if (it != _events.end())
		{
			_events.erase(it);
		}
	}
}

void EventDispatcher::on(EventId evtId, EventDispatcher* caller, LPHandler listener, Event * context, bool once)
{
	map<int, vector<EventHandler*>*>::iterator it = _events.find(evtId);
	if (it != _events.end())
	{
		//�ҵ�ͬһ��������
		vector<EventHandler*>::iterator listeners = it->second->begin();
		while (listeners != it->second->end())
		{
			if ((*listeners)->caller == caller)
			{
				//����Ѿ��������¼�������
				(*listeners)->listener = listener;
				(*listeners)->once = once;
				return;
			}
			listeners++;
		}

		//û���ҵ�ͬһ��������
		EventHandler * handler = new EventHandler();
		handler->caller = caller;
		handler->listener = listener;
		handler->once = once;
		it->second->push_back(handler);
	}
	else
	{
		vector<EventHandler*> * msgQueue = new vector<EventHandler*>();
		EventHandler * handler = new EventHandler();
		handler->caller = caller;
		handler->listener = listener;
		handler->once = once;
		msgQueue->push_back(handler);
		_events.insert(pair<int, vector<EventHandler*>*>(evtId, msgQueue));
	}
}

void EventDispatcher::once(EventId evt, EventDispatcher* caller, LPHandler listener, Event * context)
{

}

void EventDispatcher::off(EventId evt, EventDispatcher* caller, LPHandler listener, bool onceonly)
{

}

void EventDispatcher::invoke(EventDispatcher * pDispatch, LPHandler method, Event * context)
{
	auto b = std::bind(method, pDispatch, context);
	b();
}

void EventDispatcher::OnEnable(Event * context)
{

}

void EventDispatcher::OnDisable(Event * context)
{

}

void EventDispatcher::OnMeshChanged(Event * context)
{

}

void EventDispatcher::_activeHierarchy(Event * context)
{

}

void EventDispatcher::_inActiveHierarchy(Event * context)
{

}

void EventDispatcher::OnKeyDown(KeyEvent * context)
{

}

void EventDispatcher::OnKeyUp(KeyEvent * context)
{

}

void EventDispatcher::OnMouseDown(MouseEvent * context)
{

}

void EventDispatcher::OnMouseUp(MouseEvent * context)
{

}

void EventDispatcher::OnMouseMove(MouseEvent * context)
{

}