#pragma once
#include "ConsoleMath.h"

class ConsoleObject
{
public :
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	~ConsoleObject();
	
	inline int2 GetPos() const
	{
		return Pos;
	}
	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}
	
	inline char GetRenderChar() const
	{
		return RenderChar;
	}

	inline void SetRenderChar(char _ch)
	{
		RenderChar = _ch;
	}

	inline void AddPos(const int2& _Dir)
	{
		Pos += _Dir;
	}

private :
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

