#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"
#include "Timer.h"

void processinput(void);
void update(void);
void render(void);

char str[128];

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
	Timer_init(); // 프로그램이 처음 시작했을 시점을 저장하기 위해선 프로그램 실행 함수에 포함 시켜야 한다

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

float elapsedTime;
bool canShow = false;
#define DELTA_TIME Timer_GetDeltaTime();

void update(void)
{
	//델타타임을 이용해 0.5초마다 깜박거리는 텍스트 구현하기.
    //fps = 1 / deltaTime
    //sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime());
	
	//Timer_init();
	Timer_Update();

    elapsedTime += DELTA_TIME;
    if (elapsedTime >= 0.5)
    {
		elapsedTime = 1.0f;
		canShow = !canShow;
    }
}

void render(void)
{
	if (canShow)
	{
		Renderer_drawText("이 텍스트는 깜빡입니다.", sizeof("이 텍스트는 깜빡입니다."));
	}
	
	//Renderer_drawText(str, sizeof(str));
	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
