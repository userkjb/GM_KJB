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
		MsgBoxAssert("ReSize() �Ķ������ ���� 0�Դϴ�.");
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
