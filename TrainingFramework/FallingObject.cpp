#include "FallingObject.h"



std::shared_ptr<Texture> FallingObject::m_textureVector[4] = {};

FallingObject::FallingObject(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader/*, std::shared_ptr<Texture> texture*/, float frameTime, int numFrame) : AnimationSprite(model, shader, m_textureVector[2], frameTime, numFrame)
{
	
}

void FallingObject::Init() 
{
	m_textureVector[0] = ResourceManagers::GetInstance()->GetTexture("circle_animation_yellow");
	m_textureVector[1] = ResourceManagers::GetInstance()->GetTexture("circle_animation_purple");
	m_textureVector[2] = ResourceManagers::GetInstance()->GetTexture("circle_animation_pink");
	m_textureVector[3] = ResourceManagers::GetInstance()->GetTexture("circle_animation_green");
}

FallingObject::FallingObject(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, float frameTime, int numFrame) : AnimationSprite(model, shader, texture, frameTime, numFrame)
{

}

void FallingObject::Update(GLfloat deltatime)
{
	AnimationSprite::Update(deltatime);
	//this->m_Vec2DPos.y += 5;
}

void FallingObject::ChangeNextColor() 
{
	m_currentColor = static_cast<COLOR>((static_cast<int> (m_currentColor) + 1));
	if (m_currentColor == COLOR::NUM_COLOR) m_currentColor = YELLOW;
	this->SetTexture(m_textureVector[m_currentColor]);
}

void FallingObject::ChangeRandomColor()
{

}