#include "General/IDHandler.h"



IDHandler::IDHandler() : m_NrOfIDs(0)
{
}

IDHandler::IDHandler(const size_t size, const size_t startID) : m_NrOfIDs(0)
{
	resize(size, startID);
}

bool IDHandler::remove(const size_t id)
{
	bool removedID = false;

	if (m_UsedIDs.erase(id) != 0)
	{
		removedID = true;
		m_AvailableIDs.push_front(id);
		m_NrOfIDs--;
	}

	return removedID;
}

void IDHandler::resize(const size_t size, const size_t startID)
{
	this->clear();

	if (m_NrOfIDs < size)
	{
		for (size_t i = m_NrOfIDs; i < size; i++)
		{
			m_AvailableIDs.push_back(startID + i);
		}

		m_NrOfIDs = size;
	}
}

void IDHandler::clear()
{
	m_AvailableIDs.clear();
	m_UsedIDs.clear();
	m_NrOfIDs = 0;
}

bool IDHandler::idInUse(const size_t id)
{
	return m_UsedIDs.count(id);
}

bool IDHandler::empty()
{
	return m_UsedIDs.empty();
}

const size_t IDHandler::peekNextID()
{
	size_t id = m_NrOfIDs;
	if (!m_AvailableIDs.empty())
	{
		id = m_AvailableIDs.front();
	}
	return id;
}

const size_t IDHandler::getNewID()
{
	size_t id = -1;
	if (!m_AvailableIDs.empty())
	{
		id = m_AvailableIDs.front();
		m_UsedIDs.insert(m_UsedIDs.end(), std::pair<size_t, size_t>(id, id));
		m_AvailableIDs.pop_front();
	}
	else 
	{
		id = m_NrOfIDs;
		m_UsedIDs.insert(m_UsedIDs.end(), std::pair<size_t, size_t>(id, id));
		m_NrOfIDs++;
	}
	return id;
}

const size_t IDHandler::getNrOfIDs()
{
	return m_NrOfIDs;
}
