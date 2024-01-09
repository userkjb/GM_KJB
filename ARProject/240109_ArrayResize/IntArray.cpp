#include "IntArray.h"

IntArray::IntArray()
{
}

IntArray::~IntArray()
{
	Release();
}

void IntArray::ReSize(int _Size)
{
	if (_Size == 0)
	{
		MsgBoxAssert("ReSize() 파라미터의 값이 0입니다.");
		return;
	}

	// 기존 배열의 size보다 입력된 값이 커야한다.
	if (NumValue > _Size)
	{
		MsgBoxAssert("기존의 값보다 입력받은 값이 작습니다.");
		return;
	}
	
	// 배열에 비어있다면,
	if (ArrPtr == nullptr)
	{
		ArrPtr = new int[_Size];
	}
	else
	{
		IntBuffer = new int[_Size]; // 새로운 것을 만든 다음
		for (int i = 0; i < NumValue; i++) // 기존의 크기 만큼.
		{
			IntBuffer[i] = ArrPtr[i]; // 기존의 값을 새로운 곳에 넣고
		}
		delete[] ArrPtr;

		Release(); // 문제의 원인. -842150451 (?)
	}

	NumValue = _Size; // Get
}

void IntArray::Release()
{
	if (ArrPtr != nullptr)
	{
		delete[] ArrPtr;
		ArrPtr = nullptr;
	}
}
