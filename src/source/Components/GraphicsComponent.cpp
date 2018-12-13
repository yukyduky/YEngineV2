#include "Components/GraphicsComponent.h"
#include "General/Locator.h"

namespace YEngine
{	

	void GraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::Shader* shader = nullptr;
		sf::Texture* texDiffuse = nullptr;
		sf::Texture* texNormal = nullptr;
		sf::Texture* texSpectral = nullptr;
		sf::Texture* texEmission = nullptr;

		if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::SHADER)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::SHADER))
		{
			if (Locator::getResourceManager()->getResourceData(shader, m_ResourceIDs.at(GRAPHICS::SHADER)))
			{
				states.shader = shader;
			}
		}

		if (shader)
		{
			if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::DIFFUSE)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::DIFFUSE))
			{
				if (Locator::getResourceManager()->getResourceData(texDiffuse, m_ResourceIDs.at(GRAPHICS::DIFFUSE)))
				{
					shader->setUniform("texDiffuse", texDiffuse);
				}
			}
			if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::NORMAL)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::NORMAL))
			{
				if (Locator::getResourceManager()->getResourceData(texDiffuse, m_ResourceIDs.at(GRAPHICS::NORMAL)))
				{
					shader->setUniform("texNormal", texNormal);
				}
			}
			if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::SPECTRAL)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::SPECTRAL))
			{
				if (Locator::getResourceManager()->getResourceData(texDiffuse, m_ResourceIDs.at(GRAPHICS::SPECTRAL)))
				{
					shader->setUniform("texSpectral", texSpectral);
				}
			}
			if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::EMISSION)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::EMISSION))
			{
				if (Locator::getResourceManager()->getResourceData(texDiffuse, m_ResourceIDs.at(GRAPHICS::EMISSION)))
				{
					shader->setUniform("texEmission", texEmission);
				}
			}

			target.draw(m_Vertices, 4, sf::Quads);
		}
		else
		{
			if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(GRAPHICS::DIFFUSE)) == std::bitset<GRAPHICS::SIZE>(GRAPHICS::DIFFUSE))
			{
				if (Locator::getResourceManager()->getResourceData(texDiffuse, m_ResourceIDs.at(GRAPHICS::DIFFUSE)))
				{
					states.texture = texDiffuse;
					target.draw(m_Vertices, 4, sf::Quads);
				}
			}
		}
	}

	GraphicsComponent::GraphicsComponent(sf::IntRect rect) : m_Origin(0.0f, 0.0f), m_Rect(rect)
	{
		m_ResourceBitmask.reset();

		this->setPosition(sf::Vector2f(0.0f, 0.0f));
		this->setColor(sf::Color(255, 0, 255, 255));
		this->setRenderDepth(-10000.0f);
	}

	void GraphicsComponent::init()
	{
	}
	
	void GraphicsComponent::update(float dt)
	{
	}
	
	void GraphicsComponent::cleanup()
	{
		m_ResourceBitmask.reset();
		m_ResourceIDs.clear();
	}
	
	void GraphicsComponent::addGraphics(GRAPHICS::TYPE type, size_t id)
	{
		m_ResourceIDs.insert(m_ResourceIDs.end(), std::pair<GRAPHICS::TYPE, size_t>(type, id));
	
		m_ResourceBitmask |= std::bitset<GRAPHICS::SIZE>(type);
	}
	
	void GraphicsComponent::removeGraphics(GRAPHICS::TYPE graphics)
	{
		m_ResourceIDs.erase(graphics);
	}
	
	const glm::size_t GraphicsComponent::getResourceID(GRAPHICS::TYPE type) const
	{
		size_t id = -1;

		if ((m_ResourceBitmask & std::bitset<GRAPHICS::SIZE>(type)) == std::bitset<GRAPHICS::SIZE>(type))
		{
			id = m_ResourceIDs.at(type);
		}

		return id;
	}
	
	const std::bitset<YEngine::GRAPHICS::SIZE> GraphicsComponent::getResourceBitmask() const
{
		return m_ResourceBitmask;
	}

	void GraphicsComponent::setRect(sf::IntRect rect)
	{
		m_Rect = rect;

		m_Vertices[1].position = m_Vertices[0].position + sf::Vector2f(static_cast<float>(m_Rect.width), 0.0f);
		m_Vertices[2].position = m_Vertices[0].position + sf::Vector2f(0.0f, static_cast<float>(m_Rect.height));
		m_Vertices[3].position = m_Vertices[0].position + sf::Vector2f(static_cast<float>(m_Rect.width), static_cast<float>(m_Rect.height));

		m_Vertices[0].texCoords = sf::Vector2f(static_cast<float>(m_Rect.left), static_cast<float>(m_Rect.top));
		m_Vertices[1].texCoords = sf::Vector2f(static_cast<float>(m_Rect.left) + static_cast<float>(m_Rect.width), static_cast<float>(m_Rect.top));
		m_Vertices[2].texCoords = sf::Vector2f(static_cast<float>(m_Rect.left), static_cast<float>(m_Rect.top) + static_cast<float>(m_Rect.height));
		m_Vertices[3].texCoords = sf::Vector2f(static_cast<float>(m_Rect.left) + static_cast<float>(m_Rect.width), static_cast<float>(m_Rect.top) + static_cast<float>(m_Rect.height));
	}

	void GraphicsComponent::setPosition(sf::Vector2f pos)
	{
		m_Vertices[0].position = pos + sf::Vector2f(0.0f, 0.0f) - m_Origin;
		m_Vertices[1].position = pos + sf::Vector2f(static_cast<float>(m_Rect.width), 0.0f) - m_Origin;
		m_Vertices[2].position = pos + sf::Vector2f(0.0f, static_cast<float>(m_Rect.height)) - m_Origin;
		m_Vertices[3].position = pos + sf::Vector2f(static_cast<float>(m_Rect.width), static_cast<float>(m_Rect.height)) - m_Origin;
	}

	void GraphicsComponent::setOrigin(sf::Vector2f origin)
	{
		m_Origin = origin;
	}

	void GraphicsComponent::setColor(sf::Color color)
	{
		for (size_t i = 0; i < 4; i++)
		{
			m_Vertices[i].color = color;
		}
	}

	float GraphicsComponent::getRenderDepth() const
	{
		return m_RenderDepth;
	}

	void GraphicsComponent::setRenderDepth(float val)
	{
		m_RenderDepth = val;
	}

}
