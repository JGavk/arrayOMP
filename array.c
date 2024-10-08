#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000;
    int avg;
    #pragma omp parallel num_threads(100) 
    {
    int thread_id = omp_get_thread_num();
      for (int i=0 ; i<100 ; i++)
      {
        Array[i] = rand() % 10000;
       printf("thread num %d for Array %d test = %d \n ", thread_id, i, Array[i]);
      }

    }
    #pragma omp parallel reduction(max:max) reduction(min:min) reduction(+:avg)
    {
      for(int i=0; i<100; i++)
      {
        if(Array[i]>max){
          max = Array[i];
        }
      }
      printf("maximun value: %d\n", max);

      for(int i=0; i<100; i++)
      {
        if(Array[i]<min){
          min = Array[i];
        }
      }
      printf("minimum value: %d\n", min);
      
      for(int i=0; i<100; i++)
      {
        avg += Array[i];
      }
      avg = avg/100;
      printf("average value: %d\n", avg);
    }
    
    return 0;
}
