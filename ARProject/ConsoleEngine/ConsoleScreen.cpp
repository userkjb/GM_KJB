#include "ConsoleScreen.h"
#include <iostream>
#include "ConsoleObject.h"


ConsoleScreen::ConsoleScreen()
{

}

ConsoleScreen::~ConsoleScreen()
{
	ReleaseScreen();
}

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (0 >= _ScreenX)
	{
		MsgBoxAssert("스크린 X크기가 0이기 때문에 에러");
	}
	if (0 >= _ScreenY)
	{
		MsgBoxAssert("스크린 Y크기가 0이기 때문에 에러");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	if (ScreenData != nullptr)
	{
		MsgBoxAssert("스크린이 만들어져 있습니다.");
	}

	ScreenData = new char* [_ScreenY];
	if (ScreenData == nullptr)
	{
		MsgBoxAssert("스크린 생성에 실패하였습니다.");
	}

	for (int y = 0; y < _ScreenY; y++)
	{
		ScreenData[y] = new char[_ScreenX + 2] {0, };

		if (ScreenData[y] == nullptr)
		{
			MsgBoxAssert("스크린 생성에 실패했습니다.");
		}
	}

	ClearScreen();
}

void ConsoleScreen::ReleaseScreen()
{
	for (int y = 0; y < ScreenY; y++)
	{
		if (ScreenData[y] == nullptr)
		{
			continue;
		}

		delete[] ScreenData[y];
		ScreenData[y] == nullptr;
	}

	if (ScreenData == nullptr)
	{
		delete[] ScreenData;
		ScreenData = nullptr;
	}
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		if (ScreenData[y] == nullptr)
		{
			MsgBoxAssert("존재하지 않는 라인츨 출력하려고 했습니다.");
		}

		printf_s(ScreenData[y]);
	}

	ClearScreen();
}

void ConsoleScreen::ClearScreen()
{
	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[y][x] = '*';
		}
		ScreenData[y][ScreenX] = '\n';
	}
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object)
{
	SetChar(_Object->GetPos(), _Object->GetRenderChar());
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object)
{
	SetChar(_Object.GetPos(), _Object.GetRenderChar());
}

void ConsoleScreen::SetChar(const int2& _Pos, char _Char)
{
	if (_Pos.Y < 0)
	{
		return;
	}
	if (_Pos.X < 0)
	{
		return;
	}

	if (ScreenX <= _Pos.X)
	{
		return;
	}
	if (ScreenY <= _Pos.Y)
	{
		return;
	}

	ScreenData[_Pos.Y][_Pos.X] = _Char;
}
