#include "ConsoleScreen.h"

#include <iostream>
#include <Windows.h>
#include <assert.h>
#include <conio.h>

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
		MsgBoxAssert("��ũ�� Xũ�Ⱑ 0�̱� ������ ����");
	}
	if (0 >= _ScreenY)
	{
		MsgBoxAssert("��ũ�� Yũ�Ⱑ 0�̱� ������ ����");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	//if (ScreenData != nullptr)
	if(ScreenData.size() != 0)
	{
		MsgBoxAssert("��ũ���� ������� �ֽ��ϴ�.");
	}

	//ScreenData = new char* [_ScreenY];
	ScreenData.resize(ScreenY);

	//if (ScreenData == nullptr)
	if(ScreenData.size() == 0)
	{
		MsgBoxAssert("��ũ�� ������ �����Ͽ����ϴ�.");
	}

	for (int y = 0; y < _ScreenY; y++)
	{
		//ScreenData[y] = new char[_ScreenX + 2] {0, };
		ScreenData[y].resize(ScreenX + 2);

		//if (ScreenData[y] == nullptr)
		if(ScreenData[y].size() == 0)
		{
			MsgBoxAssert("��ũ�� ������ �����߽��ϴ�.");
		}
	}

	ClearScreen();
}

void ConsoleScreen::ReleaseScreen()
{
	ScreenData.clear();

	//for (int y = 0; y < ScreenY; y++)
	//{
	//	if (ScreenData[y] == nullptr)
	//	{
	//		continue;
	//	}

	//	delete[] ScreenData[y];
	//	ScreenData[y] == nullptr;
	//}

	//if (ScreenData == nullptr)
	//{
	//	delete[] ScreenData;
	//	ScreenData = nullptr;
	//}
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		//if (ScreenData[y] == nullptr)
		if(ScreenData[y].size() == 0)
		{
			MsgBoxAssert("�������� �ʴ� ������ ����Ϸ��� �߽��ϴ�.");
		}

		std::vector<char>& Vector = ScreenData[y];
		char& FirstChar = Vector[0];
		char* PrintPtr = &FirstChar;
		//printf_s(ScreenData[y]);
		printf_s(PrintPtr);
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
