#pragma once

#include "../Common.h"
#include "../Framework/Text.h"
#include "Bullet.h"

typedef struct tagPlayer
{
	Text Text;
	COORD Coord;
	Bullet bullet;
} Player;

void Player_Init(Player* player);
void Player_Update(Player* player);
void Player_Render(Player* player);
void Player_Release(Player* player);