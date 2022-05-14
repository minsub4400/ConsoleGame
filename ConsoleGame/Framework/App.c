#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"

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
	while (true)
	{
		processinput();		//입력 담당
		update();				//업데이트 담당
		render();				//출력 담당
	}
}

void processinput(void)
{

}

void update(void)
{

}

char str[128];

void render(void)
{
	sprintf_s(str, sizeof(str), "아무런 키가 눌려있지 않은 상태.");

	if (Input_GetKeyDown(VK_UP))
	{
		sprintf_s(str, sizeof(str), "위쪽 방향키 눌림");
	}
	if (Input_GetKeyDown(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "아래쪽 방향키 눌림");
	}
	if (Input_GetKeyDown(VK_LEFT))
	{
		sprintf_s(str, sizeof(str), "왼쪽 방향키 눌림");
	}
	if (Input_GetKeyDown(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "아래쪽 방향키 눌림");
	}

	Renderer_drawText(str, sizeof(str));
	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
