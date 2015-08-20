#include "card_deck.h"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(NULL));
    Card_Desk deck;

    std::cout << deck.getCard() << std::endl;
    deck.reset();
    std::cout << deck.getCard();

    return 0;
}
