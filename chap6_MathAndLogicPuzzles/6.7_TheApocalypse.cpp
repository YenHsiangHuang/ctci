#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Family
{
public:
    Family () : nBoy(0), nGirl(0) {
        reproduce();
    };

    void reproduce() {
        while (nGirl == 0) {
            if (rand()%2) nBoy ++;
            else          nGirl++;
        }
    };

    int getNBoy()  { return  nBoy; }
    int getNGirl() { return nGirl; }

private:
    int nBoy;
    int nGirl;
};

int main()
{
    srand(time(nullptr));
    const int nFamilies = 1000;
    Family family[nFamilies];

    int totalBoy = 0, totalGirl = 0;
    for (int i = 0; i < nFamilies; i++) {
        totalBoy  += family[i]. getNBoy();
        totalGirl += family[i].getNGirl();
    }
    printf("Boys  %5d\n", totalBoy);
    printf("Girls %5d\n", totalGirl);
}
