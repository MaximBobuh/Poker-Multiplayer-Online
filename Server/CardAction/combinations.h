#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <list>
#include <vector>
#include <string>
#include <iostream>

class Combinations
{
    struct Card
    {
        short value;
        short suit;

        Card& operator =(const int& val)
        {
            //card deck contains 52 cards =  4 suits * 13 cards
            value = val % 13;
            suit  = val / 13;

            return *this;
        }
    };

    //-----------------------------

    typedef std::list<Card> Cards;
    typedef Cards::iterator It;

public:
    static int defineCombination(const std::vector<int>&, std::string& );
};


#endif // COMBINATIONS_H
