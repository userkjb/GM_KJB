#include "EngineCore.h"
#include "EngineDebug.h"
#include "time.h"

void EngineCore::Init(int2 _ScreenSize)
{
	LeakCheck;

	Screen.CreateScreen(_ScreenSize.X, _ScreenSize.Y);
	srand(time(0));
}

void EngineCore::Start()
{

}
