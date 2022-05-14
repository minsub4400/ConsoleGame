#pragma once

#include "../Type.h"

// 랜덤 수 초기화
void Random_init(void);
// 무작위 '정수'
int32 Random_GetNumber(int32 minNumber, int32 maxNumber);
// 무작위 '실수'
float Random_GetFNumber(float minNumber, float maxNumber);