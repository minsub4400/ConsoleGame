#include "Text.h"

void TextCopy(CHAR_INFO* dest, WCHAR* src, WORD attributes)
{
	while (*src) // src에 문자가 남아 있을 때까지 while문 실행
	{
		dest->Char.UnicodeChar = *src;
		dest->Attributes = attributes;
		dest++;
		src++;
	}
	dest->Char.UnicodeChar = L'\0';
	dest->Attributes = 0;
}

int32 TextLen(Text* text)
{
	int32 result = 0;
	while (text->Char.UnicodeChar)
	{
		result++;
		text++;
	}
	return result;
}