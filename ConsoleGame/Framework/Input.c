#include "Input.h"
#include "../Common.h"

//#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))
//
//bool s_isKeyDownOnPrevFrame[256];
//bool s_isKeyDownOnCurrentFrame[256];

void Input_update(void)
{
	//memcpy(s_isKeyDownOnPrevFrame, s_isKeyDownOnCurrentFrame, sizeof(s_isKeyDownOnCurrentFrame)); //현재의 값을 이전에 값 위치로 복사

	//for (int32 vkey = 0; vkey < 256; ++vkey)
	//{
	//	if (IS_KEY_DOWN(vkey))
	//	{
	//		s_isKeyDownOnCurrentFrame[vkey] = true;
	//	}
	//	else
	//	{
	//		s_isKeyDownOnCurrentFrame[vkey] = false;
	//	}
	//}
}
bool Input_GetKeyUp(uint8 vkey) // 키가 떼졌다면, true 아니면 false
{
	if (GetAsyncKeyState(vkey) & 0x0000)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input_GetKeyDown(uint8 vkey) // 키가 눌렸을때, true 아니면 false
{
	if (GetAsyncKeyState(vkey) & 0x8000)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input_GetKey(uint8 vkey) // 키가 이전 프레임과 현제 프레임에 모두 눌렸다면, true 아니면 false
{
	if (GetAsyncKeyState(vkey) && GetAsyncKeyState(vkey))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bool Input_GetKeyUp(uint8 vkey)
//{
//	if (true == s_isKeyDownOnPrevFrame[vkey] && false == s_isKeyDownOnCurrentFrame[vkey])
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Input_GetKeyDown(uint8 vkey)
//{
//	if (true == s_isKeyDownOnPrevFrame[vkey] && false == s_isKeyDownOnCurrentFrame[vkey])
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Input_GetKey(uint8 vkey)
//{
//	if (true == s_isKeyDownOnPrevFrame[vkey] && true == s_isKeyDownOnCurrentFrame[vkey])
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}