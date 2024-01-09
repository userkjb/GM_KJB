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

	// ���� �迭�� size���� �Էµ� ���� Ŀ���Ѵ�.
	if (NumValue > _Size)
	{
		MsgBoxAssert("������ ������ �Է¹��� ���� �۽��ϴ�.");
		return;
	}
	
	// �迭�� ����ִٸ�,
	if (ArrPtr == nullptr)
	{
		ArrPtr = new int[_Size];
	}
	else
	{
		IntBuffer = new int[_Size]; // ���ο� ���� ���� ����
		for (int i = 0; i < NumValue; i++) // ������ ũ�� ��ŭ.
		{
			IntBuffer[i] = ArrPtr[i]; // ������ ���� ���ο� ���� �ְ�
		}
		delete[] ArrPtr;

		Release(); // ������ ����. -842150451 (?)
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
