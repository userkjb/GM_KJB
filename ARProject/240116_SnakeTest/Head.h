#pragma once
#include "Part.h"
#include <vector>
#include "Body.h"

class Head : public Part
{
public :
	void BeginPlay();

private :
	int2 BeforePos = {0, 0};
	std::vector<Body*> BodyArr;
protected :
	void Update() override;
};

