#include "Player.h"
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
}
void Player_Render(Player* player)
{
	Text *text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);
}
void Player_Release(Player* player)
{

}