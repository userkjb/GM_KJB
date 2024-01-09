#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

#include "IntArray.h"

int main()
{
    LeckCheck;

    IntArray NewArray = IntArray(5);
    NewArray.SetNumValue(0);

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }

    // print
    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }


    //NewArray.ReSize(10);

    //// print
    //for (int i = 0; i < NewArray.Num(); i++)
    //{
    //    std::cout << NewArray[i] << std::endl;
    //}
}
