#include "../Type.h"
#include "../Common.h"
#include "Text.h"

HANDLE s_screens[2]; // 스크린 버퍼를 저장할 두개의 공간 할당
HANDLE s_consoleHandle;
int32 s_backBufferIndex; // 현 화면이 아닌 back buffer을 저장할 변수

bool Renderer_Init(void) // 버퍼 스크린의 화면을 만드는 함수(두개의 화면을 만든다)
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔에 대한 핸들을 얻는다.

	s_screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//스크린 버퍼 화면 하나를 만들어서 s_screens[0]에다가 넣는다.
	//매개변수가 복잡한데 그냥 복사해서 쓰면됩니다.
	if (s_screens[0] == INVALID_HANDLE_VALUE) //예외 처리 화면 만들다 실패하면 "INVALID_HANDLE_VALUE" 이 값이 나옴
	{
		return false;
	}
	s_screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[1] == INVALID_HANDLE_VALUE)
	{
		CloseHandle(s_screens[0]); // 여기까지 왔다는 것은 s_screens[0]의 화면이 열려있다는 상태이기때문에 s_screens[1]을 만들다 에러가 나면 s_screens[0]을 닫아준다.
		return false;
	}
	return true;
}

void Renderer_Close(void) // 화면을 닫아주는 함수
{
	CloseHandle(s_consoleHandle);
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}
void Renderer_Clear(HANDLE consoleHandle) // 백 버퍼의 화면을 클리어 해주는 함수
{	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}


void Renderer_Flip(void) // 지정한 화면(버퍼)을 현 화면으로 표시해주는 함수
{
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);

	//백 버퍼 전환
	s_backBufferIndex = !s_backBufferIndex;

	Renderer_Clear(s_screens[s_backBufferIndex]);
}

void Renderer_DrawText(const Text* text, int32 numberOfText, int32 x, int32 y)
{
	// 백 버퍼에 대한 핸들을 가져온다.
	HANDLE backBuffer = s_screens[s_backBufferIndex];

	// 커서 위치 옮기기
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 백 버퍼에 텍스트를 출력한다.
	for (int32 i = 0; i < numberOfText; ++i)
	{
		SetConsoleTextAttribute(backBuffer, text[i].Attributes);
		WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
	}
}