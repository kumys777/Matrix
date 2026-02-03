#include <stdio.h>
#include "matrix.h"
#include "rational_number.h"


int main(){
    try{
        int ret;
        Matrix<Rational> A, B;
        ret = A.read_matrix(3, 3, "a.txt");
        if (ret != 0){
            printf("Read error\n");
            return 1;
        }
        A.print_matrix();

        ret = B.read_matrix(3, 3, "b.txt");
        if (ret != 0){
            printf("Read error\n");
            return 1;
        }
        printf("==========\n");
        B.print_matrix();
        Matrix<Rational> C = A + B;
        printf("==========\n");
        C.print_matrix();
        return 0;
    }

    catch(const std::exception& e){
        printf("%s \n", e.what());
        return 2;
    }
}