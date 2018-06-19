#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <memory>   // smart pointer
#include <utility>  // swap
using namespace std;

enum Suit {Spade, Heart, Diamond, Club};

class Card
{
public:
    int faceVal;
    Suit suit;

    Card(int v, Suit s) : faceVal(v), suit(s) {};

};

class Deck
{
public:
    short int nCard;
    vector<shared_ptr<Card>> card;

    Deck();

    shared_ptr<Card> deal();
    void shuffle();
};

Deck::Deck() {
    nCard = 52;
    card.clear();
    card.resize(nCard);
    for (int i = 0; i <= 12; i++) card[13*0+i] = make_shared<Card> (i+1, Spade);
    for (int i = 0; i <= 12; i++) card[13*1+i] = make_shared<Card> (i+1, Heart);
    for (int i = 0; i <= 12; i++) card[13*2+i] = make_shared<Card> (i+1, Diamond);
    for (int i = 0; i <= 12; i++) card[13*3+i] = make_shared<Card> (i+1, Club);
}

shared_ptr<Card> Deck::deal() {
    shared_ptr<Card> tmp = card.front();
    card.pop_back();
    return tmp;
}

void Deck::shuffle() {
    for (int i = 0; i < nCard; i++) swap(card[i], card[rand()%nCard]);
}

class Player
{
public:
    int score;
    vector<shared_ptr<Card>> hand;

    int updateScore();

private:
    /* data */
};

int Player::updateScore() {
    score = 0;
    int nAce = 0;
    for (auto& card : hand) {
        if      (card->faceVal  > 9) score += 10;
        else if (card->faceVal != 1) score += card->faceVal;
        else                         nAce++;
    }

    score += 11*nAce;

    for (int i = 0; i < nAce; i++) {
        if (score <= 21) return score;
        score -= 10;
    }
    return score + 10;
}



int main(int argc, const char *argv[])
{
    srand(time(nullptr));

    Deck deck;
    deck.shuffle();
    return 0;
}
