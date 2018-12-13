#include "Resource.h"

namespace YEngine
{
	class Texture : public Resource
	{
	private:
		sf::Texture* m_Texture;
		std::string m_Filename;
	public:
		Texture(std::string filename);
		virtual ~Texture();

		bool load() override;
		void unload() override;

		sf::Texture* getData() const;
	};
}
