#include <iostream>
#include <string>
#include <vector>

#include "indexedcontainer.hpp"

int main()
{
    std::vector<std::string> stringList{"bonjour", "hello", "hola", "hallo"};

    for (const auto& str : plu::makeIndexedContainer(stringList))
    {
        std::cout << str.second << ": " << str.first << std::endl;
    }

    return 0;
}