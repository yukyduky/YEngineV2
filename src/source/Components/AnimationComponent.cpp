#include "Components/AnimationComponent.h"

YEngine::AnimationComponent::AnimationComponent()
{
}

void YEngine::AnimationComponent::init()
{

}

void YEngine::AnimationComponent::update(float dt)
{

}

void YEngine::AnimationComponent::cleanup()
{

}

void YEngine::AnimationComponent::addFrame(const sf::IntRect& rect, const size_t& type)
{
	m_Frames[type].push_back(rect);
}

sf::IntRect YEngine::AnimationComponent::getFrame(const size_t& type, const size_t& n)
{
	m_LastFrameType = type;
	m_LastFrameNum = n;
	return m_Frames.at(type).at(n);
}

sf::IntRect YEngine::AnimationComponent::getNextFrame()
{
	sf::IntRect nextFrame;

	m_LastFrameNum++;

	if (m_Frames.at(m_LastFrameType).size() > m_LastFrameNum)
	{
		nextFrame = m_Frames.at(m_LastFrameType).at(m_LastFrameNum);
	}
	else
	{
		m_LastFrameNum = 0;
		nextFrame = m_Frames.at(m_LastFrameType).at(m_LastFrameNum);
	}

	return nextFrame;
}

size_t YEngine::AnimationComponent::getLastFrameType() const
{
	return m_LastFrameType;
}

size_t YEngine::AnimationComponent::getNumFrames(const size_t& type)
{
	return m_Frames[type].size();
}
