#include "Obstacle.h"
#include "RenderManager.h"

Obstacle::Obstacle(const SDL_FRect dst, bool hasImage, const SDL_Rect src, const char* key)
	:m_hasImage(hasImage), m_pImage(nullptr)
{
	m_pos = { dst.x, dst.y };
	if (m_hasImage)
	{
		//create a new obst based on an image
		//hints in outline
	}
}

Obstacle::~Obstacle()
{
	if (m_hasImage)
	{
		delete m_pImage;
		m_pImage = nullptr;
	}
}

void Obstacle::Update()
{
	m_pos.x -= kScrollSpeed;
	if (m_hasImage)
	{
		//update the images dest rect
	}
}

void Obstacle::Render()
{
	SDL_Rect m_dst = { m_pos.x, m_pos.y, 128, 128 };
	if (m_hasImage)
	{
		//render the image

		//temp ed box
		SDL_SetRenderDrawColor(REMA::GetRenderer(), 255, 102, 94, 255);
		SDL_RenderFillRect(REMA::GetRenderer(), &m_dst );	
	}
	SDL_SetRenderDrawColor(REMA::GetRenderer(), 64, 0, 255, 255);
	SDL_RenderDrawRect(REMA::GetRenderer(), &m_dst);
}
