#include "Components/PositionalComponent.h"



namespace YEngine
{
	PositionalComponent::PositionalComponent()
	{
		setPosition(sf::Vector3f(0.0f, 0.0f, 0.0f));
	}
	
	void PositionalComponent::init()
	{
	}
	
	void PositionalComponent::update(float dt)
	{
	
	}
	
	void PositionalComponent::cleanup()
	{
	
	}
	
	sf::Vector3f PositionalComponent::getPosition() const
	{
		return m_Position;
	}
	
	void PositionalComponent::setPosition(sf::Vector3f val)
	{
		m_Position = val;
	}
}
