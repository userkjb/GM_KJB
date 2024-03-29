#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

void Head::BeginPlay()
{
	int x = GetCore()->Screen.GetScreenX();
	int y = GetCore()->Screen.GetScreenY();
	int VectorCapacitySize = (x * y) - 1;
	BodyArr.assign(VectorCapacitySize, 0);
	BodyArr.clear();
}

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

	// Body Move
	{
		int ArrSize = BodyArr.size(); // 5
		if (ArrSize != 0)
		{
			for (int i = 0; i < ArrSize; i++)
			{
				int SetNum = ArrSize - (i + 1); // 4
				int GetNum = SetNum - 1; // 3
				if (SetNum != 0)
				{
					BodyArr[SetNum]->SetPos(BodyArr[GetNum]->GetPos());
				}
				else if (SetNum == 0)
				{
					BodyArr[SetNum]->SetPos(BeforePos);
				}
			}
		}
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	// 충돌...
	if (CurBody->GetPos() == GetPos())
	{
		//Back = CurBody;
		//BodyManager::ResetBody(); // CurBody nullptr

		BodyArr.push_back(CurBody);
		BodyManager::ResetBody();
	}
}
