#include "matrix.h"

template <typename T>
void Matrix<T>::transposition(){
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

template <typename T>
int Matrix<T>::determinant(){ // не работает
    int output;
    if (width != height){
        throw std::invalid_argument("The matrix is not square\n");
    }
    output = -1;
    return output;
}

template <typename T>
void Matrix<T>::reverse(){ // не работает
    if (width != height){
        throw std::invalid_argument("The matrix is not square\n");
    }
}