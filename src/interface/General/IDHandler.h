#pragma once

#include <list>
#include <unordered_map>

class IDHandler
{
private:
	size_t m_NrOfIDs;
	std::list<size_t> m_AvailableIDs;
	std::unordered_map<size_t, size_t> m_UsedIDs;
public:
	IDHandler();
	IDHandler(const size_t size, const size_t startID);

	bool remove(const size_t id);
	void resize(const size_t size, const size_t startID);
	void clear();
	bool idInUse(const size_t id);
	bool empty();
	const size_t peekNextID();

	const size_t getNewID();
	const size_t getNrOfIDs();
};
