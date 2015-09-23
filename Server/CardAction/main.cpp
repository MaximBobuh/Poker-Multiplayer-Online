#include <ctime>
#include <iostream>

#include "combinations.h"
#include "card_deck.h"


int main()
{
    srand((time(0)));

    std::vector<int> coll;
    Card_Deck deck;
    char ch;

    while(std::cin >> ch)
    {
        for(int i = 0; i < 7; ++i)
            coll.push_back(deck.getCard());

        Cmb_Result result = Combinations::defineCombination(coll);
        std::cout <<Cmb_Result::toString(result.name) << " " << result.value;

        coll.clear();
        deck.reset();
    }

    //return 0;
}

