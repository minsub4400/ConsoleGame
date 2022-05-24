#include "Timer.h"
#include <time.h>

//clock_t 는 long을 typedef한 것
clock_t beforTime;		//프로그램 실행 '이전' 시점 저장 변수
clock_t currenTime;	//프로그램 실행 '현재' 시점 저장 변수
float s_deltaTime;     //델타타임 저장 변수
float s_fixedTime;

bool Timer_Init(int32 fps)
{
	// 고정 시간을 계산한다.
	s_fixedTime = 1.0 / fps;

	//프로그램 실행 '이전' 시점 저장
	beforTime = clock();
}

bool Timer_Update(void)
{
	//프로그램 실행 '현재' 시점 저장
	currenTime = clock();

	//델타타임 구하기 : (현재 시점 - 이전 시점) / CLOCKS_PER_SEC
	float deltaTime = (float)(currenTime - beforTime) / CLOCKS_PER_SEC;
	//나눌 땐, 부동소수로 바꿔서 나눠야 소수점까지 나올 수 있다.

	// 이전 프레임으로 부터 시간이 얼마 지나지 않았다면
	if (deltaTime < s_fixedTime)
	{
		return false;
	}

	s_deltaTime = deltaTime;
	// 이전 시점을 현재 시점으로 업데이트
	beforTime = currenTime;

	return true;
}

float Timer_GetDeltaTime(void)
{
	return s_deltaTime;
}