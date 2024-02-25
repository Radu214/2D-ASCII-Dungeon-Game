#include <iostream>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int gen(char cmap[17][28], int & h, int & w) { //generates random map levels(random positions for walls '#', traps @, enemy spawn and exit)
    strcpy(cmap[0], "__________________________");
    strcpy(cmap[1], "|                         |");
    strcpy(cmap[2], "|                         |");
    strcpy(cmap[3], "|                         |");
    strcpy(cmap[4], "|                         |");
    strcpy(cmap[5], "|                         |");
    strcpy(cmap[6], "|                         |");
    strcpy(cmap[7], "|                         |");
    strcpy(cmap[8], "|                         |");
    strcpy(cmap[9], "|                         |");
    strcpy(cmap[10], "|                         |");
    strcpy(cmap[11], "|                         |");
    strcpy(cmap[12], "|                         |");
    strcpy(cmap[13], "|                         |");
    strcpy(cmap[14], "|                         |");
    strcpy(cmap[15], "|                         |");
    strcpy(cmap[16], "-------------------------");
    for (int i = 1; i <= 15; i++) {
        int y = rand() % 6 + 1;
        int z = rand() % 25 + 1;
        if (y == 1 or y == 4) {
            cmap[i][z] = '#';
            if (z + 1 != 26)
                cmap[i][z + 1] = '#';
        }
        if (y == 2) {
            cmap[i][z] = '@';
        }
        if (y == 3) {
            if (nr < 2) {
                if (i > 2 and z > 5) {
                    cmap[i][z] = '$';
                    nr++;
                    h = i;
                    w = z;

                }
            }

        }

    }
    for (int i = 1; i <= 15; i++) {
        int y = rand() % 6 + 1;
        int z = rand() % 25 + 1;
        if (y == 1 or y == 4) {
            cmap[i][z] = '#';
            if (z + 1 != 26)
                cmap[i][z + 1] = '#';
        }
        if (y == 2) {
            cmap[i][z] = '@';
        }
        if (y == 3) {
            if (nr < 2) {
                if (i > 2 and z > 5) {
                    cmap[i][z] = '$';
                    nr++;
                    h = i;
                    w = z;
                }
            }
        }

    }
    //generate exit and make sure it is not blocked
    int x = rand() % 15 + 1;
    cmap[x][26] = ' '; 
    cmap[x][25] = ' ';
    cmap[x - 1][25] = ' ';
    return x;

}