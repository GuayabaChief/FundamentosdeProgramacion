#include <stdio.h>

int matrix[4][4] = {{11, 12, 13, 14},{21, 22, 23, 24},{31, 32, 33, 34},{41, 42, 43, 44}};

void print_matrix(int n){
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         printf(" %d ", matrix[i][j]);
      }
      printf("\n");
   }
}
int *get(int offset, int x, int y){
   return &matrix[offset + x][offset + y];
}

void transpose(int offset, int n){
   if (n > 1) {
      for (int i = 0; i < n - 1; i++) {
         int *val1 = get(offset, 0, i);
         int *val2 = get(offset, i, n - 1);
         int *val3 = get(offset, n - 1, n - 1 - i);
         int *val4 = get(offset, n - 1 - i, 0);

         int temp = *val1;
         *val1 = *val4;
         *val4 = *val3;
         *val3 = *val2;
         *val2 = temp;
      }
      transpose(offset + 1, n - 2);
   }
}

int main(int argc, char *argv[]){
   print_matrix(4);
    printf("\n");
   transpose(0, 4);
   transpose(0, 4);
   print_matrix(4);
   return 0;
}