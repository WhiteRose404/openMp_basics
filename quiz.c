#include <stdio.h>
#include <omp.h>
#define ORDRE 3

int main(){
     int A[ORDRE][ORDRE]={{0,1,-1},{3,0,2},{1,1,0}}, B[ORDRE][ORDRE]={{1,0,5},{-1,1,0},{0,4,1}};
     int i, j, k, somme, C[ORDRE][ORDRE];

     for (i=0; i<ORDRE; i++){
          for (j=0; j<ORDRE; j++){
               C[i][j] = 0;
               omp_set_num_threads(ORDRE);
               #pragma omp parallel
               for (k=0; k<ORDRE; k++){
		    #pragma omp atomic
                    C[i][j] += A[i][k]*B[k][j];
		}
          }
     }

     printf(" A B C\n");
     for (i=0; i<ORDRE; i++){
          for (j=0; j<ORDRE; j++) printf(" %4d", A[i][j]);
          for (j=0; j<ORDRE; j++) printf(" %4d", B[i][j]);
          for (j=0; j<ORDRE; j++) printf(" %4d", C[i][j]);
          printf("\n");
     }
     return 0;
}
