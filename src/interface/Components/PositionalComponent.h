#pragma once

#include "Component.h"

namespace YEngine
{
	class PositionalComponent : public DerivedComponent<PositionalComponent>
	{
	private:
		sf::Vector3f m_Position;
	public:
		PositionalComponent();
		virtual ~PositionalComponent() {}
	
		virtual void init() override;
		virtual void update(float dt) override;
		virtual void cleanup() override;
	
		sf::Vector3f getPosition() const;
		void setPosition(sf::Vector3f val);
	};
}
