/*
Improvements 
- check_row() and check_column() save 0s, more efficient if they were not stored in array
- more effiecient if check_row() and check_column() just go through row or column instead of saving to an array 

- check_box() needs to be completed
*/

#include <stdio.h>
#include <stdbool.h>

static int puzzle[9][9]; 
int col_threads[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
int row_threads[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
int box_threads[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};

void initialize_puzzle(){ //convert puzzle.txt to a 2-D array
    FILE *f;
    f = fopen("puzzle.txt", "r");

    for (int i = 0; i<=8; i++){ //row of puzzle
        for (int j = 0; j<= 8; j++){ //column of puzzle
            fscanf(f, "%d", &puzzle[i][j]);            
        }
    }

    fclose(f);
}

void show_array_test(){ //Testing purposes prints array as stored
    for (int i = 0; i<=8; i++){ //row of puzzle
    printf("\n");
        for (int j = 0; j<= 8; j++){ //column of puzzle
            printf("%d ", puzzle[i][j]); 
        }
    }
    printf("\n");//needed this
}


void *check_row(void *x){
    int i = *((int*)x);
    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cc = 0; 

    for (int j = 0; j <= 8; j++){ //for each entry in the row
            for (int c = 0; c <= 8; c++){//for all values in the row
                if (puzzle[i][j] == 0){ //0 represents empty box, should not be tested
                    break;
                }
                else if (puzzle[i][j] != arr[c]){ //Current value doesnt already exist in array
                    //printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i][j]);
                }
                else{ //number was already in the row
                 //   printf("There are multiple %d's in row %d\n",puzzle[i][j], i);
                    return; //Ends loop if an issue is found
                }
            } 
           // printf("\nEntry %d is valid\n", puzzle[i][j]);
                arr[cc] = puzzle[i][j];
                cc++; 
    }
    row_threads[i] = 1; 
}



void *check_column(void *x){
    int j = *((int*)x);

    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cc = 0;

    for (int i = 0; i <= 8; i++){ //for each entry in the row
            for (int c = 0; c <= 8; c++){//for all values in the row
                if (puzzle[i][j] == 0){ //0 represents empty box, should not be tested
                //    printf("Space %d is empty, skip\n", cc);
                    break;
                }
                else if (puzzle[i][j] != arr[c]){ //Current value doesnt already exist in array
                  //  printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i][j]);
                }
                else{ //number was already in the row
                   // printf("There are multiple %d's in column %d\n",puzzle[i][j], i);
                    return; //Ends loop if an issue is found
                }
            } 
          //  printf("Entry %d is valid\n\n", puzzle[i][j]);
                arr[cc] = puzzle[i][j];
                cc++; 
    } 
    col_threads[j] = 1;
   // printf("Column %d is valido\n", j);
    
}

void check_all(){
    for (int j=0; j<9; j++)
        {
            if (!col_threads[j] || !row_threads[j] || !box_threads[j]) //if anything has an invalid entry
            {
            printf("INVALID\n");
            return;
            }
        }
    printf("VALID\n"); //if we are still running, we havent recieved any invalid entries
}


void *check_box(void *x){
    int boxno = *((int*)x);

    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cc = 0;
    int i = boxno/3 *3;
    int j = (boxno%3)*3;

        for (int crow = 0; crow <= 2; crow++){ //for each row in the box
            for (int ccol = 0; ccol <= 2; ccol++){ //for each column in the box
                for (int c= 0; c <= 8; c++){
                    if (puzzle[i+crow][j+ccol] == 0){ //0 represents empty box, should not be tested
                    break;
                }
                else if (puzzle[i+crow][j+ccol] != arr[c]){ //Current value doesnt already exist in array
                //    printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i+crow][j+ccol]);
                }
                else{ //number was already in the row

                  //  printf("There are multiple %d's in box %d\n",puzzle[i+crow][j+ccol], boxno);
                    return; //Ends loop if an issue is found
                }
            } 
              //printf("Entry %d is valid\n\n", puzzle[i+crow][j+ccol]);
                arr[cc] = puzzle[i+crow][j+ccol];
                cc++;  
        }           
    }
    box_threads[boxno] = 1; 

}






/*
        for (int crow = 0; crow <= 2; crow++){ //for each row in the box
            for (int ccol = 0; ccol <= 2; ccol++){ //for each column in the box
                for (int c= 0; c <= 8; c++){
                    if (puzzle[i][j] == 0){ //0 represents empty box, should not be tested
                    break;
                }
                else if (puzzle[i][j] != arr[c]){ //Current value doesnt already exist in array
                    printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i][j]);
                }
                else{ //number was already in the row

                    printf("There are multiple %d's in box %d\n",puzzle[i][j], boxno);
                    return; //Ends loop if an issue is found
                }
            } 
              printf("Entry %d is valid\n\n", puzzle[i][j]);
                arr[cc] = puzzle[i][j];
                cc++;  
        } i++;            
    } 
*/
