#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <set>
#include <vector>
#include <string>
#include <iostream>

class Combinations
{
    struct Card
    {
        short value;
        short suit;

        Card(const int& val)
        {
            // Card deck contains 52 cards =  4 suits * 13 cards.
            value = val % 13;
            suit  = val / 13;
        }
        bool operator <(const Card other) const
        {
            if(suit != other.suit)
                return suit < other.suit;
            return value < other.value;
        }
    };

    //-----------------------------

    typedef std::set<Card> Cards;
    typedef Cards::iterator It;

    //-----------------------------
    static bool isFlash(const Cards&, int);

public:
    static int defineCombination(const std::vector<int>&, std::string& );
};



#endif // COMBINATIONS_H
