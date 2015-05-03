#ifndef POKERMODE
#define POKERMODE
#include <list>
#include <vector>
//#include "card.h"


class PokerMode
{
public:
    typedef int Card;

    virtual static fillDeck(std::list<Card>&) = 0;
    virtual static int countPoints(std::vector<Card>&) = 0;
};

#endif // POKERMODE

