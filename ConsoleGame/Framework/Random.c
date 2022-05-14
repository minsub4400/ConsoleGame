#include "Random.h"
#include "../Common.h"

// 랜덤 수 초기화
void Random_init(void)
{
	srand(time(NULL));
}
// 무작위 '정수'
int32 Random_GetNumber(int32 minNumber, int32 maxNumber)
{
	int32 range = maxNumber - minNumber; // 100 - 60 = 40 , 60부터 ~ 100사이의 수
	int32 count = range / RAND_MAX + 1;	   // 40 / 32767 + 1 = 1

	int32 result = 0;
	for (int32 i = 0; i < count; i++)
	{
		result += rand() % range; // 40 , 0 ~ 39의 수
	}
	result += minNumber; // 60 + rand() , 0 ~ 39사이 수
	return result; // 즉,  60 ~ 99까지의 수가 리턴
}
// 무작위 '실수'
float Random_GetFNumber(float minNumber, float maxNumber) // 60.666 ~ 100. 333
{
	float normalizedRandom = rand() / (float)RAND_MAX; // 0.??????
	float range = maxNumber - minNumber; // 39.666999
	float result = minNumber + normalizedRandom * range; // 0.?????? x 39.666999 =  0.049623 + 60.666 = 60.715623

	return result;
}