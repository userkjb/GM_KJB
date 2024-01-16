#pragma once
#include "ConsoleMath.h"
#include "ConsoleUpdater.h"

class ConsoleObject : public ConsoleUpdater
{
	friend class EngineCore;

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

	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	// 나랑 충돌한 오브젝트
	ConsoleObject* Collision(int _UpdateOrder);


private :
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

