#include "App.h"
#include "../Type.h"
#include "Renderer.h"
#include "../Common.h"
#include "Input.h"
#include "Timer.h"
#include "Random.h"
#include "Text.h"

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

void update(void)
{
	
}

Text text[128];

void render(void)
{
	//Text text;
	//text.Char.UnicodeChar = L'A';
	//text.Attributes = TEXT_COLOR_GREEN;

	Renderer_drawText(text, TextLen(text), 10, 10);
	TextCopy(text, L"그댄 나의 전부 그댄 나의 운명 헤어질 수 없어요~", FOREGROUND_GREEN);
	for (int i = 15;  i <= 16; i++)
	{
		text[i].Attributes = BACKGROUND_GREEN | TEXT_COLOR_YELLOW;
	}
	
	//화면 전환
	Renderer_flip();
	//백 버퍼 내용 클리어
	Renderer_clear();
}
