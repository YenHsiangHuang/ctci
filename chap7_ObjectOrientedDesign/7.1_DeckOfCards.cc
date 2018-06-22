#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deckofcards.h"
using namespace std;

int main(int argc, const char *argv[])
{
    srand(time(nullptr));

    Deck deck;
    deck.shuffle();

    const size_t nPlayer = 5;
    Player player[nPlayer];
    Player dealer;

    for (int p = 0; p < nPlayer; p++) {
        while (!player[p].isBusted() && player[p].score < 17) deck.deal(player[p]);
        dbg_printf("score of player%d: %d\n", p, player[p].score);
    }

    while (!dealer.isBusted() && dealer.score < 17) deck.deal(dealer);
    dbg_printf("score of dealer: %d\n", dealer.score);

    printf("\n");
    printf("       ");
    for (int p = 0; p < nPlayer; p++) {
        printf(" %s %2d  | ", "player", p);
    }
    printf("\b\b \n");

    printf("%s  ", "score");
    for (int p = 0; p < nPlayer; p++) {
        printf("   %4d     | ", player[p].score);
    }
    printf("\b\b \n");

    printf("       ");
    for (int p = 0; p < nPlayer; p++) {
        if (player[p].isBusted()) {
            printf(" %6s     | ", "lose");
        } else {
            if (dealer.isBusted() || player[p].score > dealer.score) {
                printf(" %6s     | ", "win");
            } else {
                printf(" %6s     | ", "lose");
            }
        }
    }
    printf("\b\b \n");

    printf("\n");
    printf("dealer %2d\n", dealer.score);

    return 0;
}
