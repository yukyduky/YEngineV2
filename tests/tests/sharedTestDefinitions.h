#pragma once
#include "Components/Component.h"

class TestComponent : public YEngine::DerivedComponent<TestComponent>
{
public:
	virtual void init();
	virtual void update(float dt);
	virtual void cleanup();
};

inline void TestComponent::init()
{
}

inline void TestComponent::update(float dt)
{
}

inline void TestComponent::cleanup()
{
}