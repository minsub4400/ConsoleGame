#include "Type.h"
#include "App.h"
#include "Common.h"

int main(void)
{
	//App.h - 게임 루프
	//Renderer.h - 버퍼 스크린(화면)
	//Input.h - 입력 키
	//Time.h - DeltaTime
	//프로그램 초기화
	if (false == App_Init())
	{
		puts("App 실행 실패.");
		exit(1);
	}
	//프로그램 실행
	App_Run();
}