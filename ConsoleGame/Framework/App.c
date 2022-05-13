#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"

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
	sprintf_s(str, sizeof(str), "안녕 나야, 잘지내지 요즘 날씨 많이 춥지..");

	Renderer_drawText(str, sizeof(str));
	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
