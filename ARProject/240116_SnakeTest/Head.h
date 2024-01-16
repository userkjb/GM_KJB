#pragma once
#include "Part.h"

class Head : public Part
{

private :
	int2 BeforePos = {0, 0};
protected :
	void Update() override;
};

