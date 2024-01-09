#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

#include "IntArray.h"

int main()
{
    LeckCheck;

    IntArray NewArray = IntArray();
    NewArray.SetNumValue(0);
    NewArray.ReSize(5);

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }

    // print
    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }

    NewArray.ReSize(10);

    // print
    std::cout << std::endl;
    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }
}
