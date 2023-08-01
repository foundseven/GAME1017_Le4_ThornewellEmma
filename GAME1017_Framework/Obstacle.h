#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__
#include "Primitives.h"

constexpr int kScrollSpeed = 2;

class Obstacle // Not a GameObject.
{
public:
	Obstacle(const SDL_FRect dst, bool hasImage = false, const SDL_Rect src = { 0,0,0,0 }, const char* key = "");
	~Obstacle();
	void Update();
	void Render();


	bool HasImage() const { return m_hasImage; }
	const SDL_FPoint GetPos() { return m_pos; }

	Image* GetImage() { return m_pImage; }
private:
	bool m_hasImage;
	Image* m_pImage; // Pointer to visual component.
	Image* m_pImage2; // Pointer to visual component.
	Image* m_pImage3; // Pointer to visual component.

	SDL_FPoint m_pos; // Position on screen.

	SDL_Rect m_srcRect; // Source rectangle for texture.
	SDL_FRect m_dstRect;
};

#endif