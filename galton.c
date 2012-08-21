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

/**
 * Creates an array with the binominalverfahren based on a galton
 * machine.
 *
 * @param   nboxes      how many boxes there are for the balls to fall in
 * @param   nballs      how many balls we want to drop
 * @param   galton_arr  the filled array [out]
 * @return  void
 */
void galton(int  nboxes,
            int  nballs,
            int *galton_arr)
{
    int     box[nboxes];
    int     left_or_right = 0;
    int     counter;
    int     i, j;

    /* seed randomness */
    srand(time(NULL));

    /* initialize galton board */
    for (i = 0; i < nboxes; i++) {
        box[i] = 0;
    }

    /* drop the balls down the board */
    for (i = 0; i < nballs; i++) {
        counter = 0;
        for (j = 0; j < nboxes-1; j++) {
            /* decide if it goes left or right */
            left_or_right = rand() %2;
            counter = counter + left_or_right;
        }
        box[counter] = box[counter]++;
    }

    /* copy result */
    for (i = 0; i < nboxes; i++) {
        galton_arr[i] = box[i];
    }

    return ;
}

int main (int argc, char **argv)
{
    char    line[] =    "  +----+----+----+----+----+----+----+----+----+----+----+----+----+--->";
    char    numbers[] = "  0    5    10   15   20   25   30   35   40   45   50   55   60   65";

    int nboxes;
    int nballs;

    /* get cmd args */
    if (argc < 3) {
        fprintf(stderr, "usage: %s nboxes nballs\n", argv[0]);
        return -1;
    } else {
        nboxes = atoi(argv[1]);
        nballs = atoi(argv[2]);
    }

    int galton_arr[nboxes];
    int i, j;

    printf("%s\n%s\n", numbers, line);

    galton(nboxes, nballs, galton_arr);

    /* print out the results */
    for (i = 0; i < nboxes; i++) {
        printf("%d |", i);
        for (j = 0; j < galton_arr[i]; j++) {
            /* the '#' indicates the balls */
            printf("#");
        }
        printf(" %d\n%s\n", galton_arr[i], line);
    }

    return 0;
}
