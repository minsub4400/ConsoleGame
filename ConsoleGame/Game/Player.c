#include "Player.h"
#include "Bullet.h"
#include "../Framework/Input.h"
#include "../Framework/Renderer.h"

void Player_Init(Player* player)
{
	TextCopy(&player->Text, L"P", TEXT_COLOR_GREEN | TEXT_COLOR_STRONG);
	//Player player;
	//player->Coord;
	//player->Coord.X = 0;
	//player->Coord.Y = 0;
	SetCoord(player->Coord, 0, 0);
	Bullet_Init(&player->bullet);
}

void Player_Update(Player* player)
{
	if (Input_GetKey(VK_DOWN))
	{
		player->Coord.Y++;
	}

	if (Input_GetKey(VK_UP))
	{
		player->Coord.Y--;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		player->Coord.X++;
	}

	if (Input_GetKey(VK_LEFT))
	{
		player->Coord.X--;
	}

	if (Input_GetKey(VK_SPACE))
	{
		player->bullet.Position.X = player->Coord.X;
		player->bullet.Position.Y = player->Coord.Y;
		player->bullet.IsActive = true;
	}

	Bullet_Update(&player->bullet);
}
void Player_Render(Player* player)
{
	Text *text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);

	Bullet_Render(&player->bullet);

}
void Player_Release(Player* player)
{

}