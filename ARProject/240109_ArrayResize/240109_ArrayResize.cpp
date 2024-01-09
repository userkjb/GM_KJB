#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

#include "IntArray.h"

int main()
{
    IntArray NewArray = IntArray(5);

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }

}
