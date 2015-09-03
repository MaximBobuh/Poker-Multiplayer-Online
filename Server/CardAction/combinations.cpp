#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

#include "combinations.h"

int Combinations::defineCombination(const std::vector<int>& desk, std::string& name)
{
    // Convert from int to Card.
    Cards original(desk.begin(), desk.end());
    for(It pos = original.begin(); pos != original.end(); ++pos)
        std::cout << pos->suit << " " << pos->value << std::endl;
    int p;

    std:: cout << isFlash(original, p);


    return 1;
}

bool Combinations::isFlash(const Cards& original, int points)
{
    int val = -1;

    It first, second;
    first = second = original.begin();

    std::advance(second,  4);
    if(std::distance(second, original.end()) <= 0) throw "bad iterator";

    while(second != original.end())
    {
        if(first->suit == second->suit)
            val = first->value;

        ++first;
        ++second;
    }
    return val != -1;
}

