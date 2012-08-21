/* ------------------------------------------------------------------- *
 *  @file:     galtonbrett.c                                           *
 *  @author:   julie.engel@mail.com                                    *
 *  @compiler: gcc version 4.2.1 20080704 (Red Hat 4.1.2-46)           *
 *                                                                     *
 *  original from thomasmaurer.ch                                      *
 * ------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLCOUNT   210         /* how many balls we have to drop */
#define BOXCOUNT    10          /* how many boxes we have */

int main (int argc, char **argv)
{
    int     box[BOXCOUNT];
    int     left_or_right = 0;
    int     counter;
    int     i, j;

    char    line[] = " +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-->";
    char    numbers[] = " 0     5     10     15     20     25     30     35     40     45     50";
    printf("%s\n%s\n", numbers, line);

    /* seed randomness */
    srand(time(NULL));

    /* initialize galton board */
    for (i = 0; i < BOXCOUNT; i++) {
        box[i] = 0;
    }

    /* drop the balls down the board */
    for (i = 0; i < BALLCOUNT; i++) {
        counter = 0;
        for (j = 0; j < BOXCOUNT-1; j++) {
            /* decide if it goes left or right */
            left_or_right = rand() %2;
            counter = counter + left_or_right;
        }
        box[counter] = box[counter]++;
    }

    /* print out the results */
    for (i = 0; i < BOXCOUNT; i++) {
        printf("%d |", i);
        for (j = 0; j < box[i]; j++) {
            /* the '#' indicates the balls */
            printf("#");
        }
        printf(" %d\n%s\n", box[i], line);
    }

    return 0;
}
