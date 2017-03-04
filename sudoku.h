/*
Improvements 
- check_row() and check_column() save 0s, more efficient if they were not stored in array
- more effiecient if check_row() and check_column() just go through row or column instead of saving to an array 

- check_box() needs to be completed
*/

#include <stdio.h>
#include <stdbool.h>

static int puzzle[9][9]; 

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
}


void check_row(int i){
int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
int cc = 0;

    for (int j = 0; j <= 8; j++){ //for each entry in the row
            for (int c = 0; c <= 8; c++){//for all values in the row
                if (puzzle[i][j] == 0){ //0 represents empty box, should not be tested
                    break;
                }
                else if (puzzle[i][j] != arr[c]){ //Current value doesnt already exist in array
                    printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i][j]);
                }
                else{ //number was already in the row
                    printf("There are multiple %d's in row %d\n",puzzle[i][j], i);
                    return; //Ends loop if an issue is found
                }
            } 
            printf("\nEntry %d is valid\n", puzzle[i][j]);
                arr[cc] = puzzle[i][j];
                cc++; 
    } 
}



void check_column(int j){
    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cc = 0;

    for (int i = 0; i <= 8; i++){ //for each entry in the row
            for (int c = 0; c <= 8; c++){//for all values in the row
                if (puzzle[i][j] == 0){ //0 represents empty box, should not be tested
                    break;
                }
                else if (puzzle[i][j] != arr[c]){ //Current value doesnt already exist in array
                    printf("Test: arr[%d] entry %d is valid\n", c, puzzle[i][j]);
                }
                else{ //number was already in the row
                    printf("There are multiple %d's in column %d\n",puzzle[i][j], i);
                    return; //Ends loop if an issue is found
                }
            } 
            printf("Entry %d is valid\n\n", puzzle[i][j]);
                arr[cc] = puzzle[i][j];
                cc++; 
    } 
}

void check_box(){
 
}

