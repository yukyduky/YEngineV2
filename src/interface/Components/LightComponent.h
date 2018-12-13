#pragma once

#include "Component.h"

namespace YEngine
{
	enum class LIGHT {
		POINT, SPOT, DIRECTIONAL
	};
	
	struct LightData
	{
		vec3 position;
		float specPower;
		vec3 diffuse;
		vec3 ambient;
	
		LightData() : position(0.0f, 0.0f, 0.0f), diffuse(0.0f, 0.0f, 0.0f), ambient(0.0f, 0.0f, 0.0f), specPower(0.0f) {}
		LightData(vec3 position, vec3 diffuse, vec3 ambient, float specPower) : position(position), diffuse(diffuse), ambient(ambient), specPower(specPower) {}
	};
	
	class LightComponent : public DerivedComponent<LightComponent>
	{
	protected:
		LIGHT m_Type;
		LightData m_Light;
		bool m_IsPoweredOn;
		float m_Dimmer;
	public:
		LightComponent();
		virtual ~LightComponent() {}
	
		virtual void init() override;
		virtual void update(float dt) override;
		virtual void cleanup() override;
	
		LIGHT getType() const;
		bool getIsPoweredOn() const;
		void setIsPoweredOn(bool val);
		LightData getLight() const;
		void setLight(LightData val);
		float getDimmer() const;
		void setDimmer(float val);
	};
}
