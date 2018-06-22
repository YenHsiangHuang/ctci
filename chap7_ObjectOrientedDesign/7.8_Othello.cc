//#include <stdio.h>
//#include <string>
//#include <locale>
#include <codecvt>
#include <iostream>
#include <vector>

class Board {
   public:
    Board();
    void printBoard();
    bool placeDisk(const char* pos, char& color);

   protected:
    typedef struct Disk {
       public:
        Disk() {
            position[0] = 'z';
            position[1] = 'z';
            color = 'n';
        }
        Disk(const char* pos, char c) {
            position[0] = pos[0];
            position[1] = pos[1];
            color = c;
        }

        void flip();
        bool empty();

        char position[2];  // a2, h7, etc
        char color;
    } Disk_t;

    void setDisk(const char* pos, char color);
    bool canGoOn(char& color);
    bool hasNeighbor(int index);
    inline int pos2index(const char* pos);
    bool flip(const char* pos);
    bool flip(int index);
    bool eat(const char* pos, char color);

    inline void raySpread(int index[]);  // Helper

   private:
    char pattern[64];
    Disk_t disk[64];
};

Board::Board() {
    // Init pattern to white spaces with four initial disks
    for (int i = 0; i < 64; i++) pattern[i] = ' ';

    setDisk("d4", 'w');
    setDisk("e5", 'w');
    setDisk("e4", 'b');
    setDisk("d5", 'b');
}

void Board::printBoard() {
    printf("\n");
    printf("         A B C D E F G H\n");
    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0) printf("\n     %d  ", i / 8 + 1);
        printf(" %c", pattern[i]);
    }
    printf("\n");
}

void Board::setDisk(const char* pos, char color) {
    auto index = pos2index(pos);

    disk[index] = Disk_t(pos, color);
    pattern[index] = (color == 'w') ? 'o' : 'x';
}

bool Board::canGoOn(char& color) {
    color = (color == 'w') ? 'b' : 'w';

    for (int origin = 0; origin < 64; origin++) {
        if (!disk[origin].empty() || !hasNeighbor(disk[origin])) continue;
        int index[8];
        bool done[8];
        for (int i = 0; i < 8; i++) {
            index[i] = origin;
            done[i] = false;
        }

        bool run = true;
        while (run) {
            raySpread(index);
            for (int i = 0; i < 8; i++) {
                if (index[i] == -1)
                    done[i] = true;
                else if (disk[index[i]].color == color)
                    return true;
            }

            run = false;
            for (int i = 0; i < 8; i++) {
                if (done[i] == false) run = true;
            }
        }
    }
    return false;
}

bool Board::hasNeighbor(int index) {
    // Need more implementation
    return true;
}

bool Board::placeDisk(const char* pos, char& color) {
    printf("Receive requist %s from player %c\n", pos, color);
    if (!eat(pos, color)) return false;

    setDisk(pos, color);
    return canGoOn(color);
}

inline int Board::pos2index(const char* pos) {
    return 8 * (std::atoi(pos + 1) - 1) + (pos[0] - 'a');
}

bool Board::flip(const char* pos) {
    auto index = pos2index(pos);
    return flip(index);
}

bool Board::flip(int index) {
    if (disk[index].color == 'n') return false;  // no disk at that position

    if (disk[index].color == 'w')
        pattern[index] = 'x';
    else
        pattern[index] = 'o';

    disk[index].flip();
    return true;
}

void Board::Disk::flip() {
    if (color == 'n') return;
    color = (color == 'w') ? 'b' : 'w';
}

bool Board::eat(const char* pos, char color) {
    bool isValidStep = false;
    int origin = pos2index(pos);

    int index[8];
    bool done[8];
    for (int i = 0; i < 8; i++) {
        index[i] = origin;
        done[i] = false;
    }

    std::vector<std::vector<int>> toFlip(8);
    for (auto& it : toFlip) it.reserve(8);

    bool run = true;

    while (run) {
        raySpread(index);
        for (int i = 0; i < 8; i++) {
            if (index[i] == -1) {
                done[i] = true;
            } else {
                if (disk[index[i]].color != color) {
                    toFlip[i].push_back(index[i]);
                } else {
                    isValidStep = true;
                    for (auto& it : toFlip[i]) flip(it);
                    done[i] = true;
                    toFlip[i].clear();
                }
            }
        }

        run = false;
        for (int i = 0; i < 8; i++) {
            if (done[i] == false) run = true;
        }
    }

    return isValidStep;
}

inline void Board::raySpread(int index[]) {
    /**
       increment index in a spreading sense
       3 2 1
       4   0
       5 6 7
     */
    int tmp[8];
    tmp[0] = (disk[index[0] + 1].empty()) ? -1 : index[0] + 1;
    tmp[1] = (disk[index[1] - 7].empty()) ? -1 : index[1] - 7;
    tmp[2] = (disk[index[2] - 8].empty()) ? -1 : index[2] - 8;
    tmp[3] = (disk[index[3] - 9].empty()) ? -1 : index[3] - 9;
    tmp[4] = (disk[index[4] - 1].empty()) ? -1 : index[4] - 1;
    tmp[5] = (disk[index[5] + 7].empty()) ? -1 : index[5] + 7;
    tmp[6] = (disk[index[6] + 8].empty()) ? -1 : index[6] + 8;
    tmp[7] = (disk[index[7] + 9].empty()) ? -1 : index[7] + 9;

    index[0] = (index[0] == -1 || tmp[0] % 8 == 0               ) ? -1 : tmp[0];
    index[1] = (index[1] == -1 || tmp[1] % 8 == 0 || tmp[1]  < 0) ? -1 : tmp[1];
    index[2] = (index[2] == -1 ||                    tmp[2]  < 0) ? -1 : tmp[2];
    index[3] = (index[3] == -1 || tmp[3] % 8 == 7 || tmp[3]  < 0) ? -1 : tmp[3];
    index[4] = (index[4] == -1 || tmp[4] % 8 == 7               ) ? -1 : tmp[4];
    index[5] = (index[5] == -1 || tmp[5] % 8 == 7 || tmp[5] > 63) ? -1 : tmp[5];
    index[6] = (index[6] == -1 ||                    tmp[6] > 63) ? -1 : tmp[6];
    index[7] = (index[7] == -1 || tmp[7] % 8 == 0 || tmp[7] > 63) ? -1 : tmp[7];
}

bool Board::Disk::empty() { return color == 'n'; }

/**
    printUTF_8(L"+    +    +");
    printUTF_8(L"  ◎    ◉   ");
    printUTF_8(L"+    +    +");
    printUTF_8(L"  ◎    ◉   ");
    printUTF_8(L"+    +    +");

    wchar_t wstr[] = L"+    +    +\n  ◎    ◉   ";
    setlocale(LC_ALL, "zh_TW.UTF-8");
    wprintf(L"%ls\n", wstr);
*/
/**
void printUTF_8(std::wstring s) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>
        convert;  // converts between UTF-8 and UCS-4 (given sizeof(wchar_t)==4)
    std::cout << convert.to_bytes(s) << std::endl;
}
*/

int main() {
    Board game;
    bool run = true;
    char pos[2];
    char color = 'b';
    while (run) {
        game.printBoard();
        std::cout << "Player " << color << ": ";
        std::cin >> pos;
        run = game.placeDisk(pos, color);

        color = (color == 'w') ? 'b' : 'w';
    }

    std::cin.get();
}
