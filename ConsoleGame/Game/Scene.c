#include "Scene.h"
#include "../Common.h"
#include "../Framework/Input.h"
#include "../Framework/Text.h"
#include "../Framework/Timer.h"
#include "../Framework/Renderer.h"
#include "../Framework/Random.h"
#include "../Macro.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

bool Scene_IsSetNextScene(void)
{
	if (SCENE_NULL == s_nextScene) // s_nextScene이 0이면 씬이 초기화 상태이기 때문에 false 리턴
	{
		return false;
	}
	else
	{
		return true;
	}
}

#pragma region Title Scene

typedef struct tagTitleSceneData
{
	Text TitleText[3][128];
	COORD TitleCoords[3];
} TitleSceneData;

void init_title(void)
{
	// 동적 공간 할당 - Data공간에 주소할당
	g_Scene.Data = malloc(sizeof(TitleSceneData));
	// void에서 형 변환
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;
}
void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}
	if (Input_GetKeyDown('Q')) // Q를 눌으면 MINSUB 씬으로 넘어감
	{
		Scene_SetNextScene(SCENE_MINSUB);
	}

}
void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;
	TextCopyWithWhite(data->TitleText[0], L"스페이스키를 누르면 다음으로 넘어갑니다.");
	Text* text = data->TitleText[0];
	int32 len = TextLen(text);
	Renderer_drawText(text, len, 20, 10);
}
void release_title(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}
#pragma endregion

#pragma region Main Scene
void init_main(void)
{

}
void update_main(void)
{

}
void render_main(void)
{

}
void release_main(void)
{

}

#pragma endregion


#pragma region Minsub Scene
typedef struct tagMinSubData
{
	Text minsub[128];
	int32 len;
	COORD coord;
} MinSubData;

void init_minsub(void)
{
	g_Scene.Data = malloc(sizeof(MinSubData));
	MinSubData* data = (MinSubData*)g_Scene.Data;
	TextCopy(data->minsub, L"이름에게..", TEXT_COLOR_YELLOW | TEXT_COLOR_STRONG);
	data->len = TextLen(data->minsub);
	int32 x = Random_GetNumber(20, 30);
	int32 y = Random_GetNumber(0, 10);
	SetCoord(data->coord, x, y);
}

void update_minsub(void)
{
	MinSubData* data = (MinSubData*)g_Scene.Data;
	static float elapsedTime;
	elapsedTime += Timer_GetDeltaTime();
	if (elapsedTime >= 0.5f)
	{
		elapsedTime = 0.0f;
		int32 x = Random_GetNumber(20, 30);
		int32 y = Random_GetNumber(0, 10);
		SetCoord(data->coord, x, y);
	}
	/*int32 x = Random_GetNumber(20, 30); 
	int32 y = Random_GetNumber(0, 10);
	data->coord.X = x;
	data->coord.Y = y;*/
}

void render_minsub(void)
{
	MinSubData* data = (MinSubData*)g_Scene.Data;
	Renderer_drawText(data->minsub, data->len, data->coord.X, data->coord.Y);
}

void release_minsub(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}
#pragma endregion

void Scene_SetNextScene(ESceneType scene)
{
	assert(s_nextScene == SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);

	s_nextScene = scene; // 다음 씬의 값을 저장
}

void Scene_Change(void)
{
	assert(s_nextScene != SCENE_NULL);

	switch (s_nextScene)
	{
	case SCENE_TITLE:
		g_Scene.Init = init_title;
		g_Scene.Update = update_title;
		g_Scene.Render = render_title;
		g_Scene.Release = release_title;
		break;
	case SCENE_MAIN:
		g_Scene.Init = init_main;
		g_Scene.Update = update_main;
		g_Scene.Render = render_main;
		g_Scene.Release = release_main;
		break;
	case SCENE_MINSUB:
		g_Scene.Init = init_minsub;
		g_Scene.Update = update_minsub;
		g_Scene.Render = render_minsub;
		g_Scene.Release = release_minsub;
		break;
	}
	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}