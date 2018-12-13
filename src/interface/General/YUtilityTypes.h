#pragma once

#include <glm/glm.hpp>

namespace YEngine
{
	using glm::vec2;
	using glm::vec3;
	using glm::vec4;
	//typedef char Byte;

	const size_t BITMASK_SIZE = 32;

	namespace RESOURCE
	{
		enum TYPE {
			TEXTURE, FONT, SOUND, SHADER, SIZE
		};
	}
	
	enum class RENDERER {
		DEFERRED, FORWARD
	};
}
