#pragma once
#include "Component.h"
#include <sfml/Graphics.hpp>

namespace YEngine
{
	class AnimationComponent : public DerivedComponent<AnimationComponent>
	{
	private:
		std::unordered_map<size_t, std::vector<sf::IntRect>> m_Frames;
		size_t m_LastFrameType;
		size_t m_LastFrameNum;
	public:
		AnimationComponent();
		virtual ~AnimationComponent() {};

		void init() override;
		void update(float dt) override;
		void cleanup() override;

		void addFrame(const sf::IntRect& rect, const size_t& type);
		sf::IntRect getFrame(const size_t& type, const size_t& n);
		sf::IntRect getNextFrame();
		size_t getLastFrameType() const;
		size_t getNumFrames(const size_t& type);
	};
}

