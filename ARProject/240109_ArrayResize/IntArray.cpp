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
		MsgBoxAssert("ReSize() �Ķ������ ���� 0�Դϴ�.");
		return;
	}
	
	int* IntBuffer = ArrPtr; // ���� �迭 �ּ� ����.
	ArrPtr = new int[_Size];

	int CopySize = NumValue <= _Size ? NumValue : _Size;
	
	for (int i = 0; i < CopySize; i++)
	{
		ArrPtr[i] = IntBuffer[i];
	}

	delete[] IntBuffer;

	NumValue = _Size; // GetFunction
}

void IntArray::Release()
{
	if (ArrPtr != nullptr)
	{
		delete[] ArrPtr;
		ArrPtr = nullptr;
	}
}

void IntArray::Copy(const IntArray& _Other)
{
	NumValue = _Other.NumValue;

	ReSize(NumValue); // ����.
	for (int i = 0; i < NumValue; i++)
	{
		ArrPtr[i] = _Other.ArrPtr[i];
	}
}
