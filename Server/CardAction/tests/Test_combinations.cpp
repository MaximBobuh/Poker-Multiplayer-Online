#include <algorithm>
#include <iostream>
#include <vector>

#include "combinations.h"


int Combinations::defineCombination(const std::vector<int>& desk, std::string& name)
{
    Cards original;

    //convert from int to Card
    std::copy(desk.begin(), desk.end(), original.begin());

    for(It pos = original.begin(); pos != original.end(); ++pos)
        std::cout << pos->value << " " << pos->suit << std::endl;

    return 1;
}
