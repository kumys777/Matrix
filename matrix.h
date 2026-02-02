#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdexcept>
#include "exception.h"
using namespace std;


class Matrix{
    private:
        int width = 0;
        int height = 0;
        int* matrix = nullptr;
    public:
        Matrix(){
            width = 0;
            height = 0;
            matrix = nullptr;
        };
        Matrix (const Matrix& x){
            width = x.width;
            height = x.height;
            matrix = make_copy(x, x.width, x.height);
        }

        Matrix(Matrix&& x){
            width = x.width; x.width = 0;
            height = x.height; x.height = 0;
            matrix = x.matrix; x.matrix = nullptr;
        }

        Matrix(int w, int h, const char* filename){
            read_matrix(w, h, filename);
        };

        Matrix(const char* filename){
            read_matrix(filename);
        };

        Matrix(int w, int h, int* m){
            width = w;
            height = h;
            matrix = m;
        }

        ~Matrix(){
            if (matrix){
                delete[] matrix;
                matrix = nullptr;
            }
            width = 0;
            height = 0;
        }
    public:
        int read_matrix(int w, int h, const char* filename){
            FILE* file;
            if (!(file = fopen(filename, "r"))){
                return 1;
            }
            int* new_array = new int[w * h];
            if (!new_array){
                return 3;
            }
            int index = 0;
            while (fscanf(file, "%d", new_array + index) == 1 && index <= w * h){
                index++;
            }
            if (!feof(file)){
                delete[] new_array;
                return 2;
            }
            if (index <= w * h){
                return 2;
            }
            matrix = new_array;

            width = w;
            height = h;
            return 0;
        }

        int read_matrix(const char* filename){
            FILE* file;
            if (!(file = fopen(filename, "r"))){
                return 1;
            }
            if (fscanf(file, "%d", &width) != 1){
                return 2;
            }
            if (fscanf(file, "%d", &height) != 1){
                return 2;
            }

            int* new_array = new int[width * height];
            if (!new_array){
                return 3;
            }
            int index = 0;
            while (fscanf(file, "%d", new_array + index) == 1 && index <= width * height){
                index++;
            }
            if (!feof(file)){
                delete[] new_array;
                return 2;
            }
            if (index <= width * height){
                return 2;
            }
            matrix = new_array;
            return 0;
        }
    
        void print_matrix(FILE* fp=stdout){
            for (int i = 0; i < width; i++){
                for (int j = 0; j < height; j++){
                    fprintf(fp, "%d ", matrix[i * height + j]);
                }
                printf("\n");
            }
        }

        int* make_copy(const Matrix x, int width, int height){
            int* array = new int[width * height];
            if (!array){
                throw MemoryError("No memory\n");
            }
            for (int i = 0; i < width; i++){
                for (int j = 0; j < height; j++){
                    array[i * height + j] = x.matrix[i * height + j];
                }
            }
            return array; 
        }
    public:
        void transposition();
        int determinant();
        void reverse();
    public:
        Matrix operator+(const Matrix& other) const {
            int* array = new int[width * height];
            if (!array){
                throw MemoryError("No memory\n");
            }
            if (width != other.width || height != other.height){
                throw OperationError("Sizes do not match");
            }
            Matrix A;
            A.width = width;
            A.height = height;
            A.matrix = array;
            for (int i = 0; i < width; i++){
                for (int j = 0; j < height; j++){
                    A.matrix[i * height + j] = matrix[i * height + j] + other.matrix[i * height + j];
                }
            }
            return A;
        }
        
        Matrix operator*(const Matrix& other) const {
            if (height != other.width){
                throw OperationError("number of columns in 1st matrix must match number of rows in 2nd");
            }
            int new_width = width;
            int new_height = other.height;
            int* array = new int[new_width * new_height];
            if (!array){
                throw MemoryError("No memory\n");
            }
            int sum;
            Matrix A;
            A.width = new_width;
            A.height = new_height;
            A.matrix = array;
            for (int i = 0; i < new_width; i++){
                for (int j = 0; j < new_height; j++){
                    sum = 0;
                    for (int k = 0; k < height; k++){
                        sum += matrix[i * height + k] * other.matrix[k * height + j]; 
                    }
                    array[i * height + j] = sum;
                }
            }
            return A;
        }

};
#endif