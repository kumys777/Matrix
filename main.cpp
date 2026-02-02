#include <stdio.h>
#include "matrix.h"


int main(){
    try{
        int ret;
        Matrix A, B;
        ret = A.read_matrix(3, 3, "a.txt");
        if (ret != 0){
            printf("Read error\n");
            return 1;
        }
        ret = B.read_matrix("b.txt");
        if (ret != 0){
            printf("Read error\n");
            return 1;
        }
        Matrix C = A * B;
        C.print_matrix();
        return 0;
    }

    catch(const std::exception& e){
        printf("%s \n", e.what());
        return 2;
    }
}