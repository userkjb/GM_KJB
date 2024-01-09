#pragma once
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{
public :
	IntArray();
	~IntArray();

	void ReSize(int _Size);
	void Release();

	void Copy(const IntArray& _Other);

	inline int Num()
	{
		return NumValue;
	}

	inline void SetNumValue(const int _Value)
	{
		NumValue = _Value;
	}

	int& operator[](int _Count)
	{
		return ArrPtr[_Count];
	}
	
private :
	int NumValue = -1;
	int* ArrPtr = nullptr;
	int* IntBuffer = nullptr;
};

