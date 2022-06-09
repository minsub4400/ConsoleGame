#include "Bullet.h"
#include "../Framework/Renderer.h"
#include "../Framework/Timer.h"

float ActiveTime = 0.0f;

void Bullet_Init(Bullet* bullet)
{
	bullet->Position.X = 0;
	bullet->Position.Y = 0;
	bullet->IsActive = false;
	TextCopy(&bullet->Text, L"¡Û", TEXT_COLOR_YELLOW | TEXT_COLOR_STRONG);
}


void Bullet_Update(Bullet* bullet)
{
	if (false == bullet->IsActive)
	{
		return;
	}

	bullet->Position.X++;
	
	ActiveTime += Timer_GetDeltaTime();
	if (ActiveTime >= 1.0f)
	{
		ActiveTime = 0.0f;
		bullet->IsActive = false;
	}
}

void Bullet_Render(Bullet* bullet)
{
	if (false == bullet->IsActive)
	{
		return;
	}

	Text* text = &bullet->Text;
	Renderer_DrawText(text, 1, bullet->Position.X, bullet->Position.Y);
}
