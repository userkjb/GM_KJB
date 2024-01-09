#pragma once
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{
public :
	IntArray(int _Size);
	~IntArray();

	void ReSize(int _Size);
	void Release();

	inline int Num()
	{
		return NumValue;
	}

	int& operator[](int _Count)
	{
		return ArrPtr[_Count];
	}
	
private :
	int NumValue = -1;
	int* ArrPtr = nullptr;
};

