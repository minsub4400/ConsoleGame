#pragma once

#include "../Type.h"

bool Timer_Init(int32 fps);
bool Timer_Update(void);
float Timer_GetDeltaTime(void);