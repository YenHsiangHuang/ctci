#include <iostream>

template <typename T>
T** mallocMat2D(size_t row, size_t col) {
    size_t headerSize = row * sizeof(T*);
    size_t dataSize = row * col * sizeof(T);
    T** rowPtr = (T**)new char[headerSize + dataSize];
    if (!rowPtr) return nullptr;

    for (int i = 0; i < row; ++i) rowPtr[i] = (T*)(rowPtr + row) + i * col;
    return rowPtr;
}

template <typename T>
void freeMat2D(T** mat) {
    if (!mat) return;
    delete[] mat;
}

int main(int argc, const char* argv[]) {
    size_t row = 3, col = 2;
    auto mat = mallocMat2D<int>(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    freeMat2D<int>(mat);
    return 0;
}
