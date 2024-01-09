#pragma once
class IntArray
{
public :
	IntArray(int _Size);
	~IntArray();

	void ReSize(int _Size);
	void Release();

	inline int Num();	
	
private :
	int NumValue = -1;
	int* ArrPtr = nullptr;
};

