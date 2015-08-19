#ifndef CARD_DECK
#define CARD_DECK

#include <vector>
#include <algorithm>

//-----------------------


class Card_Desk
{
    typedef int Card;
    typedef std::vector<Card> Deck;
    typedef Deck::iterator It;


public:
    Card_Desk(int size = 52)
    {
        for(int i = 0; i < size; ++i)
            cards.push_back(i);
        reset();
    }

    void reset()
    {
        std::random_shuffle(cards.begin(), cards.end());
        position = cards.begin();
    }

    Card getCard() { return (++position != cards.end() ? *position : -1); }

private:
    Deck cards;
    It position;
};

#endif // CARD_DECK

