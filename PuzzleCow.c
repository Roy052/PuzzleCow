#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>

#define WORD_SIZE  31
#define BACK_FAIR  1
#define FONT_FAIR  2
#define FBACK_FAIR 3

void mainMenu();
void printBackGround();
void printAlphabet(char alphabet[][WORD_SIZE], int x, int y);

int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{
    int i , j;

    char P[WORD_SIZE][WORD_SIZE] = { {"11111111110 "},
                                     {"1111    1110"},
                                     {"1111    1110"},
                                     {"11111111110 "},
                                     {"1111000000  "},
                                     {"11110       "},
                                     {"11110       "},
                                     {"00000       "}};
    char U[WORD_SIZE][WORD_SIZE] = { {"111     1110"},
                                     {"111     1110"},
                                     {"111     1110"},
                                     {"111     1110"},
                                     {"111     1110"},
                                     {"111111111110"},
                                     {"  1111111110"},
                                     {"   000000000"} };
    char Z[WORD_SIZE][WORD_SIZE] = {0, };
    char L[WORD_SIZE][WORD_SIZE] = {0, };
    char E[WORD_SIZE][WORD_SIZE] = {0, };
    char C[WORD_SIZE][WORD_SIZE] = {0, };
    char O[WORD_SIZE][WORD_SIZE] = {0, };
    char W[WORD_SIZE][WORD_SIZE] = {0, };

    initscr();
    start_color();
    init_pair(BACK_FAIR, COLOR_BLACK, COLOR_BLACK);
    init_pair(FONT_FAIR, COLOR_BLACK, COLOR_GREEN);
    init_pair(FBACK_FAIR, COLOR_BLACK, COLOR_WHITE);

    printBackGround();
    printAlphabet(P, 10, 10);
    printAlphabet(U, 25, 10);

    refresh();


    getchar();

    endwin();
}

void printBackGround()
{
    int y = 0;

    move(0, 0);
    attron(COLOR_PAIR(BACK_FAIR));
    for (y = 0; y < LINES; y++)
        mvhline(y, 0 , ' ' , COLS);
    attroff(COLOR_PAIR(BACK_FAIR));

    refresh();

}

void printAlphabet(char alphabet[][WORD_SIZE], int x, int y)
{
    int i, j;

    for (i = 0; i < 8; i++)
    {
        move(y+i, x);
        for (j = 0; alphabet[i][j] != '\0'; j++)
        {
            if (alphabet[i][j] == '1')
                attron(COLOR_PAIR(FONT_FAIR));
            else if (alphabet[i][j] == '0')
                attron(COLOR_PAIR(FBACK_FAIR));
            else
            {
                attroff(COLOR_PAIR(FONT_FAIR));
                attroff(COLOR_PAIR(FBACK_FAIR));
            }
            addch(' ');
        }
        addch('\n');
    }

}