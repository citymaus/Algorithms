#ifndef CARD_H
#define CARD_H

#include <string>

const int SUIT_MAX(4);
const int RANK_MAX(13);

class Card
{
    friend class Deck; // Deck Class needs to access to Card Class but not vice versa
public:
    explicit Card();
    explicit Card(const int &suit, const int &rank);

    std::string Card2Str() const;

private:
    int generate_suit();
    int generate_rank();
    int get_suit() const;
    int get_rank() const;
    int m_suit;
    int m_rank;
};
#endif

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include <fstream>
#include "card.h"

using namespace std;

class Deck
{ 
public:
      explicit Deck();
      void print_Deck() const;
      void getOneCard();
private:
    std::vector<Card> m_deck;

};

#endif

#include <cstdlib>     /* srand, rand */
#include <iostream>
#include "card.h"


const std::string SUIT[SUIT_MAX]  = {"S", "H", "D", "C"};
const std::string RANK[RANK_MAX]  = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


Card::Card()
{
   m_suit = generate_suit(); 
   m_rank = generate_rank();
}

Card::Card(const int &suit, const int &rank) : m_suit(suit), m_rank(rank)
{

}

int Card::generate_suit()
{
    return rand() % (SUIT_MAX-1) + 0;
}

int Card::generate_rank()
{
    return rand() % (RANK_MAX-1) + 0;
}

std::string Card::Card2Str() const
{
    return SUIT[get_suit()] + RANK[get_rank()];
}

int Card::get_suit() const
{
    return m_suit;
}

int Card::get_rank() const
{
    return m_rank;
}


#include <iostream>
#include "deck.h"


Deck::Deck()
{
    for (unsigned int i(0); i < SUIT_MAX; ++i)
    {
        for (unsigned int j(0); j < RANK_MAX; ++j)
        {
            Card card(i, j);
            m_deck.push_back(card);
        }
    }
}


void Deck::print_Deck() const
{
    unsigned int count(1);

    for (unsigned int i(0); i < m_deck.size(); ++i)
    {
        std::cout << m_deck[i].Card2Str() << " ";
        if ( count == 13 )
        {
          std::cout << std::endl;
          count = 0;
        }
        ++count;
    }
}

void Deck::getOneCard()
{   
    Card cd(m_deck.back().get_suit(), m_deck.back().get_rank());
    m_deck.pop_back();
    std::cout << cd.Card2Str() << std::endl;
}

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <cstring>

#include "card.h"
#include "deck.h"

int main()
{
    srand (time(NULL));

    Deck _deck; 
    _deck.print_Deck();
    _deck.getOneCard();

    std::cout << std::endl;
    _deck.print_Deck();


    std::cout << std::endl;

    return 0;
}