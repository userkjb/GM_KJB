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
}

void IntArray::Release()
{
}
