#pragma once

#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include <vector>

class FallingObject : public AnimationSprite
{
public:
	enum COLOR {
		YELLOW = 0,
		PURPLE,
		PINK,
		GREEN,
		NUM_COLOR
	};


	FallingObject(COLOR color);
	FallingObject(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader/*, std::shared_ptr<Texture> texture*/, float frameTime, int numFrame);


	static void	Init();

	void		Update(GLfloat deltatime);

	void		ChangeNextColor();

	void		ChangeRandomColor();

private:
	COLOR m_currentColor;
	static std::shared_ptr<Texture> m_textureVector[4];
	static std::shared_ptr<Shaders> m_shaders;
	static std::shared_ptr<Models> m_model;
};