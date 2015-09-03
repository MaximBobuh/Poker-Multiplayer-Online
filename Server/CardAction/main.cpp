#include <ctime>

#include "combinations.h"
#include "card_deck.h"

int main()
{
    srand((time(0)));
    std::vector<int> coll;
    std::string result;

    Card_Desk deck;
    for(int i = 0; i < 7; ++i)
        coll.push_back(deck.getCard());

    Combinations::defineCombination(coll, result);
    //return 0;
}

