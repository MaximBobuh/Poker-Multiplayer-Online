#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <list>
#include <vector>
#include <string>

#include "card.h"

//-----------------------------

enum Cmb_Name {ROYAL_FLASH = 0, STREET_FLASH, FOUR_OF_KIND, FULL_HOUSE,
               FLASH, STREET, THREE_OF_KIND, TWO_PAIR, PAIR, KICKER};

//-----------------------------

struct Cmb_Result
{
    Cmb_Name name;
    int value;

    //---------------

    Cmb_Result() : name(KICKER), value(-1) {}

    static std::string toString(const Cmb_Name& name)
    {
        static const std::string names[] = {"ROYAL_FLASH", "STREET_FLASH", "FOUR_OF_KIND",
                                            "FULL_HOUSE", "FLASH", "STREET", "THREE_OF_KIND",
                                            "TWO_PAIR", "PAIR", "KICKER"};
        return names[(int)name];
    }
};

//-----------------------------

class Combinations
{
    typedef std::list<Card> Cards;
    typedef Cards::iterator It;
    typedef Cards::const_iterator Const_It;

    //-----------------------------

    static Cmb_Result isStreetFlash(const Cards&);
    static Cmb_Result isFullHouse  (const Cards&);
    static Cmb_Result isStreet     (const Cards&);
    static Cmb_Result isFourOfKind (const Cards&);

    //-----------------------------

public:
    static Cmb_Result defineCombination(const std::vector<int>&);
};


#endif // COMBINATIONS_H
