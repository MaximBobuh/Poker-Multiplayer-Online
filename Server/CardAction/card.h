#ifndef CARD
#define CARD

struct Card
{

    short value;
    short suit;

    Card() : value(0), suit(0) {}
    Card(int val) : value(val % 13), suit(val / 13) {}  // Each suit has 13 cards.

    //------------------------------

    Card& operator=(const Card& cop)
    {
        value  = cop.value;
        suit = cop.suit;
        return *this;
    }

    bool operator ==(const Card& cop) const
    {
        return value == cop.value;
    }

    bool operator>(const Card& cop) const
    {
        return value > cop.value;

    }

    bool operator <(const Card& other) const
    {
        if(suit != other.suit)
            return suit < other.suit;
        return value < other.value;
    }
};


inline bool sortValue(const Card& c1, const Card& c2)
{
     //sort criterion
    return c1.value < c2.value;
}

inline bool op(const Card& c1, const Card& c2)
{
    return c1.value == c2.value;
}

#endif // CARD

