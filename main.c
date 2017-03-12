#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sudoku.h"

    int main (){

        initialize_puzzle(); //converts puzzle to 2d array 
        
        pthread_t thc[9], thr[9], thb[9]; 
        int *x = malloc(sizeof(int));
        for (int j = 0; j<9; j++){
            *x = j;
            pthread_create(&thc[j], NULL, check_column, (void*)(x)); //check each column with thread
            pthread_create(&thr[j], NULL, check_row, (void*)(x)); //check each row with thread
            pthread_create(&thb[j], NULL, check_box, (void*)(x)); //check each box with thread
		    pthread_join(thc[j], NULL);
            pthread_join(thr[j], NULL);
            pthread_join(thb[j], NULL);
        }    

        pthread_t parent_thread;
        pthread_create(&parent_thread, NULL, check_all, NULL); 
        pthread_join(parent_thread, NULL);//parent thread to check the validity
 
      //  show_array_test(); //test that array has been properly processed
 
} 
