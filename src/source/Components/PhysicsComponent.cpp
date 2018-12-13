#include "Components/PhysicsComponent.h"

namespace YEngine
{
	PhysicsComponent::PhysicsComponent()
	{
		m_Velocity = vec3(0.0f, 0.0f, 0.0f);
		m_Acceleration = vec3(0.0f, 0.0f, 0.0f);
	}
	
	void PhysicsComponent::init()
	{
	}
	
	void PhysicsComponent::update(float dt)
	{
		m_Velocity += m_Acceleration * dt;
	}
	
	void PhysicsComponent::cleanup()
	{
	}
	
	vec3 PhysicsComponent::getVelocity() const
	{
		return m_Velocity;
	}
	
	void PhysicsComponent::setVelocity(vec3 val)
	{
		m_Velocity = val;
	}
	
	vec3 PhysicsComponent::getAcceleration() const
	{
		return m_Acceleration;
	}
	
	void PhysicsComponent::setAcceleration(vec3 val)
	{
		m_Acceleration = val;
	}

	float PhysicsComponent::getMass() const
	{
		return m_Mass;
	}

	void PhysicsComponent::setMass(float val)
	{
		m_Mass = val;
	}
}