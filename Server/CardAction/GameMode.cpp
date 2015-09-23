#include <algorithm>
#include <iterator>
#include <set>

#include "gamemode.h"


Cmb_Result Combinations::defineCombination(const std::vector<int>& desk)
{
    Cmb_Result result, temp;
    Cards original(desk.begin(), desk.end());   // Convert from int to Card.

    original.sort(sortValue);
    result = isStreetFlash(original);

    if(result.name != STREET_FLASH && result.name != ROYAL_FLASH)
    {
        if(result.name == FLASH)
            temp = result;

        result = isFourOfKind(original);
        if(result.name == FOUR_OF_KIND)
            return result;

        result = isFullHouse(original);
        if(result.name == FULL_HOUSE)
            return result;

        if(temp.name == FLASH)
            return temp;

        temp = isStreet(original);
        if(temp.name == STREET)
            return temp;
    }
    return result;
}

//----------------------------------------------------------


// Desk contains five cards identical suit.

Cmb_Result Combinations::isStreetFlash(const Cards& original)
{
    Cmb_Result result;

    // Sort cards by suit.
    std::set<Card> desk(original.begin(), original.end());
    std::set<Card>::iterator first, second;


    first = second = desk.begin();
    std::advance(second,  4);
    if(std::distance(second, desk.end()) <= 0) throw "bad iterator";


    for(;second != desk.end();  ++first, ++second)
    {
        // Five card has identical suit?
        if(first->suit == second->suit)
        {
            if((second->value - first->value) != 4)
            {
                if(result.name != STREET_FLASH)
                {
                    result.value = second->value;
                    result.name  = FLASH;
                }
            }
            else
            {
                result.value = second->value;
                result.name  = (result.value == 12 ? ROYAL_FLASH : STREET_FLASH);
            }
        }
    }
    return result;
}


//-------------------------------------------------------------

// Check: desk contains FullHouse(2+3 cards with identical values) or Four of Kind(3 same cards)
// Two pairs or One pair.

Cmb_Result Combinations::isFullHouse(const Cards& original)
{
    Cmb_Result result;

    int firstPair, secondPair, triple;
    firstPair = secondPair = triple = -1;

    Const_It pos = original.begin();
    while(pos != original.end())
    {
        int value = pos->value;
        int len   = std::count(pos, original.end(), *pos);

        if(len == 3 && value > triple)
        {
            triple = value;
        }
        else if(len >= 2)
        {
            if(value > firstPair || value > secondPair)
            {
                secondPair = value;
                if(firstPair < value)
                    std::swap(firstPair, secondPair);
            }
        }
        std::advance(pos, (len > 0 ? len : 1));
    }

    result.value = (--pos)->value;
    if(triple != -1)
    {
        if(firstPair != -1)
        {
            result.name  = FULL_HOUSE;
            result.value = 20 * (++triple) + firstPair;
        }
        else
        {
            result.name   = THREE_OF_KIND;
            result.value += (++triple) * 20;
        }
    }
    else if(firstPair != -1)
    {
        result.name   = (secondPair != -1 ? TWO_PAIR : PAIR);
        result.value += (++firstPair) * 200 + (++secondPair) * 20;
    }
    return result;
}

//-------------------------------------------------------------


void add(Card val, std::set<short>& container)
{
    container.insert(val.value);
}

// Desk contains five cards in squence.
Cmb_Result  Combinations::isStreet(const Cards& original)
{
    Cmb_Result result;
    std::set<short> values;

    // Copy card values.
    std::for_each(original.begin(), original.end(),
                  std::bind2nd(std::ptr_fun(add), values));

    if(values.size() >= 5)
    {
        std::set<short>::iterator first, second;
        first = second = values.begin();

        std::advance(second, 4);

        for(; second != values.end(); ++first, ++second)
            if((*second - *first) == 4)
            {
                result.value = *second;
                result.name  = STREET;
            }
    }
    return result;
}

//-------------------------------------------------------------


// Check Four of Kind combination.
Cmb_Result  Combinations::isFourOfKind(const Cards& original)
{
    Cmb_Result result;

    Const_It pos = std::adjacent_find(original.begin(), original.end());

    while(pos != original.end() && result.name != FOUR_OF_KIND)
    {
        int len = std::count(pos, original.end(), *pos);
        if(len == 4)
        {
            result.value = pos->value;
            result.name  = FOUR_OF_KIND;
        }

        std::advance(pos, len);
        pos = std::adjacent_find(pos, original.end(), op);
    }
    return result;
}
