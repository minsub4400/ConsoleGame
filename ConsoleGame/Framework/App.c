#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"
#include "Timer.h"
#include "Random.h"

void processinput(void);
void update(void);
void render(void);

char str[2][128];

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

void update(void)
{
	
}

void render(void)
{
	Sleep(1000);
	int32 minVal = -50;
	int32 maxVal = 100;
	int32 randInt = Random_GetNumber(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d 사이의 정수 : %d\n", minVal, maxVal, randInt);

	float fminVal = -50.666f;
	float fmaxVal = 550.333;
	float frand = Random_GetFNumber(fminVal, fmaxVal);
	assert(fminVal <= frand && frand <= fmaxVal);

	sprintf_s(str[1], sizeof(str[1]), "%f ~ %f 사이의 실수 : %f", fminVal, fmaxVal, frand);

	Renderer_drawText(str[0], sizeof(str[0]));
	Renderer_drawText(str[1], sizeof(str[1]));
	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
