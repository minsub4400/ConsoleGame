#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"
#include "Timer.h"
#include "Random.h"
#include "Text.h"
#include "../Game/Scene.h"

void processinput(void);
void update(void);
void render(void);

bool App_init(void) // Renderer_init 가 존재하는지, 실행이 되는지 확인하기 위함.
{
	if (false == Renderer_init())
	{
		return false;
	}
	return true;
}

//게임 루프 구성
void App_run(void)
{
	Timer_init(60); // 프로그램이 처음 시작했을 시점을 저장하기 위해선 프로그램 실행 함수에 포함 시켜야 한다

	Scene_SetNextScene(SCENE_TITLE);

	while (true)
	{
		if (Scene_IsSetNextScene())
		{
			Scene_Change();
		}

		Timer_Update();	//델타 타임 구하기 함수 시작
		processinput();		//입력 담당
		update();				//업데이트 담당
		render();				//출력 담당
	}
}

void processinput()
{
	
}

void update()
{
	g_Scene.Update();
}

void render()
{
	g_Scene.Render();

	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
