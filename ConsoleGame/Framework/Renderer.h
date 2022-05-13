#pragma once

#include <stdbool.h>

bool Renderer_init(void);
void Renderer_flip(void);
void Renderer_close(void);
void Renderer_clear(void);
void Renderer_drawText(const char* text, int numberOfText); // 텍스트, 글자 수
