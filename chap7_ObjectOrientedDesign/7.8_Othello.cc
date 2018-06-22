#include <codecvt>
#include <iostream>
#include <vector>

enum Mode { Simple, UTF8 };

void printUTF_8(std::wstring s) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>
        convert;  // converts between UTF-8 and UCS-4 (given sizeof(wchar_t)==4)
    std::cout << convert.to_bytes(s);
}

class Board {
   public:
    Board();
    void printBoard(Mode mode);
    bool placeDisk(const char* pos, char& color);
    bool canGoOn(char& color);
    void terminate();

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
    bool hasNeighbor(int index);
    inline int pos2index(const char* pos);
    bool flip(const char* pos);
    bool flip(int index);
    bool eat(const char* pos, char color);
    void updateScore();
    void updateScore(int plusScore);

    inline void raySpread(int index[]);  // Helper

   private:
    char pattern[64];
    Disk_t disk[64];
    int blackScore = 0, whiteScore = 0;
};

Board::Board() {
    // Init pattern to white spaces with four initial disks
    for (int i = 0; i < 64; i++) pattern[i] = ' ';

    setDisk("d4", 'w');
    setDisk("e5", 'w');
    setDisk("e4", 'b');
    setDisk("d5", 'b');

    //setDisk("d2", 'w');
    //setDisk("e2", 'w');
    //setDisk("f2", 'w');
    //setDisk("d3", 'w');
    //setDisk("e3", 'b');
    //setDisk("f3", 'w');
    //setDisk("c4", 'w');
    //setDisk("d4", 'w');
    //setDisk("e4", 'w');
    //setDisk("f4", 'w');
    //setDisk("c5", 'w');
    //setDisk("f5", 'w');
    //setDisk("c6", 'w');
    //setDisk("d6", 'w');
    //setDisk("e6", 'w');
    //setDisk("f6", 'w');
    //setDisk("d5", 'b');

    updateScore();
}

void Board::printBoard(Mode mode) {
    switch (mode) {
        case Simple:
            printf("\n");
            printf("         A B C D E F G H\n");
            for (int i = 0; i < 64; i++) {
                if (i % 8 == 0) printf("\n     %d  ", i / 8 + 1);
                printf(" %c", pattern[i]);
            }
            printf("\n");
            break;
        case UTF8:
            auto rightShift = "   ";
            auto lineSegment = "+    +    +    +    +    +    +    +    +";
            auto whiteDisk = L"  ◉  ", blackDisk = L"  ◎  ";

            printf("\n");
            printf("      A    B    C    D    E    F    G    H\n");
            for (int i = 0; i < 64; i++) {
                if (i % 8 == 0)
                    printf("\n%c%s%s\n%d%s", ' ', rightShift, lineSegment,
                           i / 8 + 1, rightShift);
                if (pattern[i] == 'o')
                    printUTF_8(whiteDisk);
                else if (pattern[i] == 'x')
                    printUTF_8(blackDisk);
                else
                    printf("     ");
            }
            printf("\n%c%s%s\n", ' ', rightShift, lineSegment);
            printf("\n");
            break;
    }
}

void Board::setDisk(const char* pos, char color) {
    auto index = pos2index(pos);

    disk[index] = Disk_t(pos, color);
    if (color == 'w') {
        pattern[index] = 'o';
        whiteScore++;
    } else {
        pattern[index] = 'x';
        blackScore++;
    }
}

bool Board::canGoOn(char& color) {
    for (int origin = 0; origin < 64; origin++) {
        if (!disk[origin].empty() || !hasNeighbor(origin)) continue;
        int index[8];
        bool eatSomeOne[8], done[8];
        for (int i = 0; i < 8; i++) {
            index[i] = origin;
            eatSomeOne[i] = false;
            done[i] = false;
        }

        bool run = true;
        while (run) {
            raySpread(index);
            for (int i = 0; i < 8; i++) {
                if (index[i] == -1)
                    done[i] = true;
                else if (disk[index[i]].color != color)
                    eatSomeOne[i] = true;
                else {
                    if (eatSomeOne[i])
                        return true;
                    else
                        done[i] = true;
                }
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
    // 4 corners
    switch (index) {
        case 0:
            if (!disk[1].empty() || !disk[8].empty() || !disk[9].empty())
                return true;
            break;
        case 7:
            if (!disk[6].empty() || !disk[14].empty() || !disk[15].empty())
                return true;
            break;
        case 56:
            if (!disk[48].empty() || !disk[49].empty() || !disk[57].empty())
                return true;
            break;
        case 63:
            if (!disk[54].empty() || !disk[55].empty() || !disk[62].empty())
                return true;
            break;
        default:
            break;
    }

    //  4 edges
    if ((index < 7 && index > 0)) {
        if (!disk[index - 1].empty() || !disk[index + 1].empty() ||
            !disk[index + 7].empty() || !disk[index + 8].empty() ||
            !disk[index + 9].empty()) {
            return true;
        }
    }
    if (index % 8 == 0) {
        if (!disk[index - 8].empty() || !disk[index - 7].empty() ||
            !disk[index + 1].empty() || !disk[index + 8].empty() ||
            !disk[index + 9].empty()) {
            return true;
        }
    }
    if (index % 8 == 7) {
        if (!disk[index - 8].empty() || !disk[index - 9].empty() ||
            !disk[index - 1].empty() || !disk[index + 7].empty() ||
            !disk[index + 8].empty()) {
            return true;
        }
    }
    if (index > 56 && index < 63) {
        if (!disk[index - 1].empty() || !disk[index - 7].empty() ||
            !disk[index - 8].empty() || !disk[index - 9].empty() ||
            !disk[index + 1].empty()) {
            return true;
        }
    }

    //  general case
    if (!disk[index + 1].empty() || !disk[index - 7].empty() ||
        !disk[index - 8].empty() || !disk[index - 9].empty() ||
        !disk[index - 1].empty() || !disk[index + 7].empty() ||
        !disk[index + 8].empty() || !disk[index + 9].empty()) {
        return true;
    }

    return false;
}

bool Board::placeDisk(const char* pos, char& color) {
    if (!disk[pos2index(pos)].empty()) {
        printf("\n");
        printf("A disk has already in here, please choose another position.");
        printf("\n");
        return false;
    }
    if (!eat(pos, color)) {
        printf("\n");
        printf("Invalid position: cannot eat any disk.\n");
        printf("Please choose another position.\n");
        printf("\n");
        return false;
    }

    setDisk(pos, color);
    return true;
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
            if (index[i] == -1) {  // Out-of-bound position
                done[i] = true;
            } else {
                if (disk[index[i]].color != color) {  // Find different color
                    toFlip[i].push_back(index[i]);
                } else {  // Find same color
                    if (toFlip[i].empty()) {
                        done[i] = true;
                    } else {
                        isValidStep = true;
                        for (auto& it : toFlip[i]) flip(it);
                        if (color == 'w')
                            updateScore(toFlip[i].size());
                        else
                            updateScore(-toFlip[i].size());
                        done[i] = true;
                        toFlip[i].clear();
                    }
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

void Board::updateScore() {
    whiteScore = 0;
    blackScore = 0;
    for (int i = 0; i < 64; i++) {
        if (disk[i].color == 'n') continue;
        if (disk[i].color == 'w')
            whiteScore++;
        else
            blackScore++;
    }
}

void Board::updateScore(int plusScore) {
    whiteScore += plusScore;
    blackScore -= plusScore;
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

    index[0] = (index[0] == -1 || tmp[0] % 8 == 0) ? -1 : tmp[0];
    index[1] = (index[1] == -1 || tmp[1] % 8 == 0 || tmp[1] < 0) ? -1 : tmp[1];
    index[2] = (index[2] == -1 || tmp[2] < 0) ? -1 : tmp[2];
    index[3] = (index[3] == -1 || tmp[3] % 8 == 7 || tmp[3] < 0) ? -1 : tmp[3];
    index[4] = (index[4] == -1 || tmp[4] % 8 == 7) ? -1 : tmp[4];
    index[5] = (index[5] == -1 || tmp[5] % 8 == 7 || tmp[5] > 63) ? -1 : tmp[5];
    index[6] = (index[6] == -1 || tmp[6] > 63) ? -1 : tmp[6];
    index[7] = (index[7] == -1 || tmp[7] % 8 == 0 || tmp[7] > 63) ? -1 : tmp[7];
}

void Board::terminate() {
    if (whiteScore > blackScore)
        printf("White Wins!\n");
    else if (whiteScore < blackScore)
        printf("Black Wins!\n");
    else
        printf("Fair game.\n");
    printf("White score: %2d\n", whiteScore);
    printf("Black score: %2d\n", blackScore);
}

bool Board::Disk::empty() { return color == 'n'; }

int main() {
    Board game;
    bool run = true, switchPlayer;
    char pos[2];
    char color = 'b';
    while (run) {
        game.printBoard(UTF8);
        std::cout << "Player " << color << ": ";
        std::cin >> pos;
        if (pos[0] == 'q') break;
        switchPlayer = game.placeDisk(pos, color);
        game.printBoard(UTF8);

        if (switchPlayer) color = (color == 'w') ? 'b' : 'w';
        run = game.canGoOn(color);
    }
    game.terminate();

    std::cin.get();
}
