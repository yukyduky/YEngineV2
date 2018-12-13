#pragma once

#include "Component.h"
#include <unordered_map>
#include <bitset>
#include <sfml/Graphics.hpp>

namespace YEngine
{
	namespace GRAPHICS
	{
		enum TYPE {
			DIFFUSE, NORMAL, SPECTRAL, EMISSION, SHADER, SIZE
		};
	};

	class GraphicsComponent : public DerivedComponent<GraphicsComponent>, public sf::Drawable
	{
	private:
		std::bitset<GRAPHICS::SIZE> m_ResourceBitmask;
		std::unordered_map<GRAPHICS::TYPE, size_t> m_ResourceIDs;
		sf::Vertex m_Vertices[4];
		sf::Vector2f m_Origin;
		sf::IntRect m_Rect;
		float m_RenderDepth;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		GraphicsComponent(sf::IntRect rect);
		virtual ~GraphicsComponent() {}
	
		void init() override;
		void update(float dt) override;
		void cleanup() override;
		
		void removeGraphics(GRAPHICS::TYPE graphics);
		void addGraphics(GRAPHICS::TYPE type, size_t id);

		const size_t getResourceID(GRAPHICS::TYPE type) const;
		const std::bitset<GRAPHICS::SIZE> getResourceBitmask() const;
		void setRect(sf::IntRect rect);
		void setPosition(sf::Vector2f pos);
		void setOrigin(sf::Vector2f origin);
		void setColor(sf::Color color);
		float getRenderDepth() const;
		void setRenderDepth(float val);
	};
}
