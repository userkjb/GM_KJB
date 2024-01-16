#pragma once
#include "Part.h"

class Head : public Part
{

private :
	inline void SetBeforePos(const int2& _Dir)
	{
		BeforePos = _Dir;
	}
	inline int2 GetBeforePos()
	{
		return BeforePos;
	}

	int2 BeforePos = {0, 0};
protected :
	void Update() override;
};

