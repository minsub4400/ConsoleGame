#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"
#include "Timer.h"
#include "Random.h"
#include "Text.h"
#include "../Game/Scene.h"


bool App_Init(void) // Renderer_init 가 존재하는지, 실행이 되는지 확인하기 위함.
{
	if (false == Renderer_Init())
	{
		return false;
	}
	return true;
}

void processinput()
{
	//Input_Update();
}

void update()
{
	g_Scene.Update();
}

void cleanup(void)
{
	Renderer_Close();
}

void render()
{
	g_Scene.Render();

	//화면 전환
	Renderer_Flip();
}

//게임 루프 구성
void App_Run(void)
{
	atexit(cleanup);

	Timer_Init(60); // 프로그램이 처음 시작했을 시점을 저장하기 위해선 프로그램 실행 함수에 포함 시켜야 한다

	Scene_SetNextScene(SCENE_TITLE);

	while (true)
	{
		if (Scene_IsSetNextScene())
		{
			Scene_Change();
		}

		if (Timer_Update())
		{
			processinput();
			update();
			render();
		}

		//Timer_Update();		//델타 타임 구하기 함수 시작
		//processinput();		//입력 담당
		//update();				//업데이트 담당
		//render();				//출력 담당
	}
}

