#include "generate.h" //generate infinite level maps
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <ctime>

using namespace std;

char map[17][28];
char cmap[17][28]; ///15*25
int x = 1, y = 1, i, j, lives = 5, f, score = 0, fx, fy, coordx, coordy;
bool gun = false, valid = true;
bool ban = true;
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    NONE,
    ENTER2
};
Direction dir;
void dlt(char h[17][28]) {
    for (int i = 0; i <= 16; i++)
        for (int j = 1; j <= 25; j++) {
            if (h[i][j] == '$')
                if (i != 0)
                    h[i][j] = ' ';
                else
                    h[i][j] = cmap[i][j];
        }
}

char key() {
    time_t start = time(NULL);
    while (!kbhit()) {
        if (time(NULL) - start >= 0.3)
            return -1;
    }
    return getch();
}

void Input() { //handles input cases
    switch (key()) {
    case 'a': {
        dir = LEFT;
        break;
    }
    case 'd': {
        dir = RIGHT;
        break;
    }
    case 'w': {
        dir = UP;
        break;
    }
    case 's': {
        dir = DOWN;
        break;
    }
    case 'e': {
        if (gun == false) {
            dir = ENTER;
            gun = true;
        }
        break;
    }
    default: {
        dir = NONE;
    }

    }
}

void Movement() {   //moves the player according to Input
    map[y][x] = cmap[y][x];
    if (dir == UP) {
        if (map[y - 1][x] == ' '
            or map[y - 1][x] == '@'
            or map[y - 1][x] == '$')
            y = y - 1;
    }
    if (dir == DOWN) {
        if (map[y + 1][x] == ' '
            or map[y + 1][x] == '@'
            or map[y + 1][x] == '$')
            y++;
    }
    if (dir == LEFT) {
        if (map[y][x - 1] == ' '
            or map[y][x - 1] == '@'
            or map[y][x - 1] == '$')
            x--;
    }
    if (dir == RIGHT) {
        if (map[y][x + 1] == ' '
            or map[y][x + 1] == '@'
            or map[y][x + 1] == '$')
            x++;
    }
    if (map[y][x] == '@')
        lives--;
    if (map[y][x] == '$')
        lives = 0;

    if (dir == ENTER) {
        fx = x;
        fy = y;
        if (map[fy][fx] == ' ')
            map[fy][fx] = '*';

    }
}

void Animation() {  //prints the player position
    map[y][x] = 'x';
}

bool Check(int x, int y) {
    if (y == f)
        if (x == 26 and valid == false)
            return true;
        else
            return false;
    else
        return false;
}

void Weapon() { //handles the weapon firing
    if (gun == true and fx == coordx and fy == coordy) {
        dlt(map);
        valid = false;
    }
    if (gun == true) {
        if (map[fy][fx] == '*')
            map[fy][fx] = ' ';
        fx++;
        if (map[fy][fx] == ' ') {
            map[fy][fx] = '*';
        }
        if (map[fy][fx] == '$') {
            map[fy][fx] = cmap[fy][fx] = ' ';
            gun = false;
            score++;
        }

        if (map[fy][fx] == '#'
            or map[fy][fx] == '@'
            or cmap[fy][fx] == '|')
            gun = false;
        if (gun == true and fx == coordx and fy == coordy) {
            dlt(map);
            valid = false;
        }
    }
}

void Enemy() { //handles enemy movement

    dlt(map);
    if (gun == true and fx == coordx and fy == coordy) {
        dlt(map);
        valid = false;
        return;
    }
    ban = !ban;
    if (ban == true) {
        if (coordx < x) {
            if (coordx + 1 != 26)
                map[coordy][++coordx] = '$';
        } else
        if (coordx > x) {
            if (coordx - 1 != 0)
                map[coordy][--coordx] = '$';
        } else
        if (coordy > y) {
            if (coordy - 1 != 0)
                map[--coordy][coordx] = '$';
        } else
        if (coordy < y) {
            if (coordy + 1 != 16)
                map[++coordy][coordx] = '$';
        }
        if (gun == true and fx == coordx and fy == coordy) {
            dlt(map);
            valid = false;
            return;
        }
    }
}

int main() {

    srand(time(NULL));
    f = gen(map, coordy, coordx);
    for (int i = 0; i <= 16; i++) {
        strcpy(cmap[i], map[i]);
    }

    while (lives > 0) {
        cout << "lives: " << lives << "  Score: " << score << endl;
        for (i = 0; i <= 16; i++) {
            cout << map[i] << endl;
        }
        cout << x << " " << y;
        cout << endl << coordy << " " << coordx;
        Input();
        Movement();
        Animation();
        if (valid == true)
            Enemy();
        Weapon();
        if (Check(x, y)) {
            f = gen(map, coordy, coordx);
            valid = true;
            for (int i = 0; i <= 16; i++)
                strcpy(cmap[i], map[i]);
            x = 1;
            y = 1;
            map[y][x] = 'x';
            score++;
        }
        system("cls");

    }
    system("cls");
    cout << "You Lost!";

}