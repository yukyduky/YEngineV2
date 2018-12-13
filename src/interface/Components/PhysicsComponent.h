#pragma once

#include "Component.h"

namespace YEngine
{
	class PhysicsComponent : public DerivedComponent<PhysicsComponent>
	{
	private:
		vec3 m_Velocity;
		vec3 m_Acceleration;
		float m_Mass;
	public:
		PhysicsComponent();
		virtual ~PhysicsComponent() {}
	
		void init() override;
		void update(float dt) override;
		void cleanup() override;
	
		vec3 getVelocity() const;
		void setVelocity(vec3 val);
		vec3 getAcceleration() const;
		void setAcceleration(vec3 val);
		float getMass() const;
		void setMass(float val);
	};
}
