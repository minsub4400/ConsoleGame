#pragma once

#include "../Common.h"
#include "../Framework/Text.h"

typedef struct tagBullet
{
	bool	IsActive;
	COORD	Position;
	Text	Text;
} Bullet;

void Bullet_Init(Bullet* bullet);
void Bullet_Update(Bullet* bullet);
void Bullet_Render(Bullet* bullet);
