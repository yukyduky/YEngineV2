#pragma once

#include <deque>

namespace YEngine
{
	enum class EVENT {
		GAMEOVER, OBJECTDIED
	};
	
	struct Event
	{
		Event() : param(-1) {}
		Event(EVENT event, size_t param) : event(event), param(param) {}
	
		EVENT event;
		size_t param;
	};
	
	class EventHandler
	{
	private:
		std::deque<Event> m_EventQueue;
	public:
		virtual ~EventHandler() {}
		bool pollEvent(Event& event);
		void addEvent(Event event);
	};
}
