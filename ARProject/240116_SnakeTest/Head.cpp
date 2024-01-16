#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	switch (Select)
	{
	case 'A':
	case 'a':
	{
		int2 MovePos = GetPos() + Left;
		if (MovePos == BeforePos)
		{
			break;
		}
		else
		{
			BeforePos = GetPos();
			AddPos(Left);
			break;
		}
	}
	case 'D':
	case 'd':
	{
		int2 MovePos = GetPos() + Right;
		if (MovePos == BeforePos)
		{
			break;
		}
		else
		{
			BeforePos = GetPos();
			AddPos(Right);
			break;
		}
	}
	case 'S':
	case 's':
	{
		int2 MovePos = GetPos() + Down;
		if (MovePos == BeforePos)
		{
			break;
		}
		else
		{
			BeforePos = GetPos();
			AddPos(Down);
			break;
		}
	}
	case 'W':
	case 'w':
	{
		int2 MovePos = GetPos() + Up;
		if (MovePos == BeforePos)
		{
			break;
		}
		else
		{
			BeforePos = GetPos();
			AddPos(Up);
			break;
		}
	}	
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Back = CurBody;
		BodyManager::ResetBody();
	}
}
