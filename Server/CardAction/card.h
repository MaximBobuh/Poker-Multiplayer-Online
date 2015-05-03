#ifndef CARD
#define CARD

struct card
{

    int first; //value
    int second; //suit
    card(int f, int s) : first(f), second(s) {}
    card() : first(0), second(0) {}


    card& operator=(const card& cop)
    {
        first  = cop.first;
        second = cop.second;
        return *this;
    }

    bool operator==(const card& cop)
    {
        return first == cop.first;
    }

    bool operator>(const card& cop)
    {
        return first > cop.first;

    }

    bool operator<(const card& cop)
    {
        return first < cop.first;
    }

};


bool op(const card& c1, const card& c2)
{
     //sort criterion
    return c1.first < c2.first;
}

bool op2(const card& c1, const card& c2)
{
    return c1.first == c2.first;
}
#endif // CARD

