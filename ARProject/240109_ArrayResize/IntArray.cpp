#include "IntArray.h"

IntArray::IntArray(int _Size)
{
}

IntArray::~IntArray()
{
}

void IntArray::ReSize(int _Size)
{
	if (_Size == 0)
	{
		MsgBoxAssert("ReSize() 파라미터의 값이 0입니다.");
	}
	
	if (ArrPtr != nullptr)
	{
		Release();
	}

	NumValue = _Size;
	ArrPtr = new int[_Size];	
}

void IntArray::Release()
{
	if (ArrPtr != nullptr)
	{
		delete[] ArrPtr;
		ArrPtr = nullptr;
	}
}
