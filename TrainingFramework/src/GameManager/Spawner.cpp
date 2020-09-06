#include "../FallingObject.h"
#include "Spawner.h"
#include <stdlib.h>
#include <time.h>

Spawner::Spawner() : m_lastSpawnTime(0)
{

}

Spawner::~Spawner()
{

}

std::shared_ptr<FallingObject> Spawner::SpawnSingleObject()
{
	srand(time(NULL));
	FallingObject::COLOR objectColor = static_cast<FallingObject::COLOR>(rand() % FallingObject::COLOR::NUM_COLOR);
	return std::make_shared<FallingObject>(objectColor);
}

std::shared_ptr<FallingObject> Spawner::Spawn(float deltaTime)
{
	static float currentTime = 0.0f;
	const static float timeGenerate = 1.0f;
	currentTime += deltaTime;
	if (currentTime >= timeGenerate) 
	{
		srand(time(NULL));
		int spawnType = rand() % SPAWN_TYPE::SPAWN_TYPE_COUNT;

		switch (spawnType)
		{
		case SPAWN_TYPE::LEFT:
			return Spawner::GetInstance()->SpawnSingleObject();
			break;
		case SPAWN_TYPE::RIGHT:
			return Spawner::GetInstance()->SpawnSingleObject();
			break;
		case SPAWN_TYPE::BOTH:
			break;
		default:
			break;
		}

		currentTime -= timeGenerate;
	}

	return nullptr;
	
}