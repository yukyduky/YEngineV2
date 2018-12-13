#include "Renderer.h"
#include "ResourceManager.h"
#include "ComponentManager.h"
#include "Locator.h"
#include "Components/PositionalComponent.h"
#include "Components/GraphicsComponent.h"


void YEngine::Renderer::sort(idlist<Component*>& components)
{
	bool sorted = false;
	size_t i = 0;

	while (!sorted)
	{
		sorted = true;

		while (i + 1 < components.size())
		{
			GraphicsComponent* graphics0 = static_cast<GraphicsComponent*>(components[i]);
			GraphicsComponent* graphics1 = static_cast<GraphicsComponent*>(components[i + 1]);

			if (graphics0->getRenderDepth() < graphics1->getRenderDepth())
			{
				sorted = false;
				components.swap(i, i + 1);
			}

			i++;
		}
	}
}

YEngine::Renderer::~Renderer()
{
	delete m_CM;
	delete m_RM;
}

void YEngine::Renderer::init(sf::Vector2u windowSize, bool fullscreen, std::string title)
{
	m_CM = new ComponentManager();
	Locator::supply(m_CM);

	m_RM = new ResourceManager();
	Locator::supply(m_RM);

	if (fullscreen)
	{
		m_Window.create(sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Fullscreen);
	}
	else
	{
		m_Window.create(sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Default);
	}
}

bool YEngine::Renderer::pollEvent(sf::Event& event)
{
	return m_Window.pollEvent(event);
}

void YEngine::Renderer::draw()
{
	idlist<Component*>* graphicsComponents;

	Locator::getComponentManager()->getAllComponentsOfType(GraphicsComponent::getComponentBitmask(), graphicsComponents);

	static_cast<GraphicsComponent*>(graphicsComponents->operator[](0));
	static_cast<GraphicsComponent*>((*graphicsComponents)[0]);


	for (size_t i = 0; i < graphicsComponents->size(); i++)
	{
		Component* component = nullptr;
		GraphicsComponent* graphics = static_cast<GraphicsComponent*>((*graphicsComponents)[i]);

		if (Locator::getComponentManager()->getComponentFromEntity((*graphicsComponents)[i]->getEntityID(), PositionalComponent::getComponentBitmask(), component))
		{
			PositionalComponent* positional = static_cast<PositionalComponent*>(component);
			sf::Vector3f pos = positional->getPosition();

			graphics->setPosition(sf::Vector2f(pos.x, pos.y));
			graphics->setRenderDepth(pos.z);
		}
	}

	this->sort(*graphicsComponents);

	for (size_t i = 0; i < graphicsComponents->size(); i++)
	{
		m_Window.draw(*(static_cast<GraphicsComponent*>((*graphicsComponents)[i])));
	}

	m_Window.display();
}
