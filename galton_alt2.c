/* --------------------------------------- *
 *  @file:     galtonbrett.c               *
 *  @author:   julie.engel@mail.com        *
 *  @compiler: gcc version 4.2.1 20080704  *
 *                                         *
 *  with help from thomasmaurer.ch         *
 * --------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/**
 * Creates an array with the binominalverfahren based on
 * a galton machine.
 *
 * @param   boxcount    how many boxes there are
 * @param   ballcount   how many balls we want to drop
 * @param   galton_arr  the filled array [out]
 * @return  void
 */
void galton(int  boxcount,
            int  ballcount,
            int *galton_arr)
{
    int     box[boxcount];
    int     left_or_right = 0;
    int     counter;
    int     i, j;
 
    /* seed randomness */
    srand(time(NULL));
 
    /* initialize galton board */
    for (i = 0; i <; boxcount; i++) {
        box[i] = 0;
    }
 
    /* drop the balls down the board */
    for (i = 0; i < ballcount; i++) {
        counter = 0;
        for (j = 0; j < boxcount-1; j++) {
            /* decide if it goes left or right */
            left_or_right = rand() %2;
            counter = counter + left_or_right;
        }
        box[counter] = box[counter]++;
    }
 
    /* copy result */
    for (i = 0; i < boxcount; i++) {
        galton_arr[i] = box[i];
    }
 
    return ;
}
 
int main (int argc, char **argv)
{
    char    line[] = " +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-->";
    char    numbers[] = " 0     5     10     15     20     25     30     35     40     45     50";
 
    int boxcount = 8;
    int ballcount = 210;
    int galton_arr[boxcount];
    int i, j;
 
    printf("%s\n%s\n", numbers, line);
 
    galton(boxcount, ballcount, galton_arr);
 
    /* print out the results */
    for (i = 0; i < boxcount; i++) {
        printf("%d |", i);
        for (j = 0; j < galton_arr[i]; j++) {
            /* the '#' indicates the balls */
            printf("#");
        }
        printf(" %d\n%s\n", galton_arr[i], line);
    }
 
    return 0;
}
