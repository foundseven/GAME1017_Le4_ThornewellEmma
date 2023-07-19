#include "ObstacleRow.h"
#include "RenderManager.h"
#include "TextureManager.h"

ObstacleRow::ObstacleRow():m_gapCtr(0), m_gapMax(3)
{
	for (int i = 0; i < 9; i++)
	{
		m_obstacles.push_back(new Obstacle({128.0f * i, 384.0f, 128.0f, 128.0f })); //vector for boxes
		//m_obstacles.push_back(new ______("obstacle.png", { 128.0f * i, 384.0f, 128.0f, 128.0f })); // Replace "obstacle.png" with the path to your obstacle image file
		TextureManager::Load("Assets/rock.png", "rock");
		SDL_Texture* texture = TextureManager::GetTexture("rock");
		//m_obstacles.push_back(new Image(texture, { 128.0f * i, 384.0f, 128.0f, 128.0f }));
	}
}

void ObstacleRow::Update()
{
	//check for conveyor effect... or check if first obst goes off screen
	if (m_obstacles[0]->GetPos().x <= -128.0f)
	{
		delete m_obstacles[0]; 
		m_obstacles[0] = nullptr;
		m_obstacles.erase(m_obstacles.begin());
		//add a new element to the end
		if (m_gapCtr++ % m_gapMax == 0) //need to render the image here
		
			m_obstacles.push_back(new Obstacle({ 1024.0f, 384.0f, 128.0f, 128.0f }, true));
		
		else 
			m_obstacles.push_back(new Obstacle({ 1024.0f, 384.0f, 128.0f, 128.0f }));

	}
	// scroll boxes
	for (const auto obstacle : m_obstacles)
	{
		obstacle->Update();
	}
}

void ObstacleRow::Render()
{
	// Blue line under obstacles.
	SDL_SetRenderDrawColor(REMA::GetRenderer(), 0, 0, 255, 255);
	SDL_RenderDrawLine(REMA::GetRenderer(), 0, 512, 1024, 512);
	// Render the obstacles.
	for (const auto obstacle : m_obstacles)
	{
		obstacle->Render();
	}
}
