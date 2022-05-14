#pragma once

#include <stdbool.h>
#include "Text.h"

bool Renderer_init(void);
void Renderer_flip(void);
void Renderer_close(void);
void Renderer_clear(void);

/// <summary>
/// 텍스트를 출력한다.
/// </summary>
/// <param name="text">텍스트</param>
/// <param name="numberOfChar">출력할 문자의 개수</param>
/// <param name="x">출력할 위치</param>
/// <param name="y">출력할 위치</param>
void Renderer_drawText(const Text* text, int32 numberOfText, int32 x, int32 y); // 텍스트, 글자 수
