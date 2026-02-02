#include "matrix.h"

void Matrix::transposition(){
    // добавить: если матрица квадратная, то новый массив не создаётся
    int* array = new int[height * width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            array[i * width + j] = matrix[j * height + i];
        }
    }
    delete[] matrix;
    matrix = array;
    int swap;
    swap = width;
    width = height;
    height = swap; 
}

int Matrix::determinant(){ // не работает
    int output;
    if (width != height){
        throw std::invalid_argument("The matrix is not square\n");
    }
    output = -1;
    return output;
}

void Matrix::reverse(){ // не работает
    if (width != height){
        throw std::invalid_argument("The matrix is not square\n");
    }
}