#pragma once

#include "General/Resource.h"

namespace YEngine
{
	class Shader : public Resource
	{
	private:
		sf::Shader* m_Shader;
		std::string m_FileVertex;
		std::string m_FileGeometry;
		std::string m_FileFragment;
		bool m_LoadGeometry;
	public:
		enum class SHADER {
			VERTEX, GEOMETRY, FRAGMENT
		};

		Shader(std::string fileVertex, std::string fileFragment);
		Shader(std::string fileVertex, std::string fileGeometry, std::string fileFragment);
		virtual ~Shader();

		bool load() override;
		void unload() override;

		sf::Shader* getData() const;
	};
}

