#include <stdio.h>

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define RED_COLOR_CODE "\033[91m"
#define GREEN_COLOR_CODE "\033[32m"
#define NORMAL_COLOR_CODE "\033[37m"
#define CYAN_COLOR_CODE "\033[36m"
#define LIGHT_RED_COLOR_CODE "\033[31m"
#define GRAY_COLOR_CODE "\033[30m"

const int SIZEY = 26;
const int SIZEX = 100; 
const int BOARD_SIZEX = 49;
const int GRID_SIZEX = 12;
const int GRID_SIZEY = 6;

enum wins {
    CONTINUE_GAME = 0, END = 1, DRAW = 2
};

struct game {
    char pole[3][3];
    wins who_wins;
};

void set_cursor_position(char x, char y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_plane(char plane[SIZEY][SIZEX]) {
    for (int i = 0; i < SIZEY; i++) {
        for (int j = 0; j < BOARD_SIZEX; j++) {
            if (plane[i][j] != '*')
                putchar(plane[i][j]);
            else 
                putchar(' ');
        }
        putchar('\n');
    }
}

int are_same(int x1, int x2, int x3) {
    return x1 == x2 && x2 == x3 && x3 == x1;
}

void print_moves(int moves[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", moves[i][j]);
        }
        putchar('\n');
    }
}

enum wins check_for_win(game *game, char move) {
    // rows
    for (int i = 0; i < 3; i++) {
        if (are_same(game->pole[i][0], game->pole[i][1], game->pole[i][2]) && game->pole[i][0] != 0) {
            game->who_wins = END;
            return END;
        }
    }

    // columns
    for (int i = 0; i < 3; i++) {
        if (are_same(game->pole[0][i], game->pole[1][i], game->pole[2][i]) && game->pole[0][i] != 0) {
            game->who_wins = END;
            return END;
        }
    }

    // main diagonal
    if (are_same(game->pole[0][0], game->pole[1][1], game->pole[2][2]) && game->pole[1][1] != 0) {
        game->who_wins = END;
        return END;
    }

    // cosv diagonal
    if (are_same(game->pole[2][0], game->pole[1][1], game->pole[0][2]) && game->pole[1][1] != 0) {
        game->who_wins = END;
        return END;
    }

    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3; j++) {
            if (game->pole[i][j] == 0)
                return CONTINUE_GAME;
        }
    }
    return DRAW;
}

enum wins check_for_win_global(game games[3][3], char move) {
    game moves = {};
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            moves.pole[i][j] = games[i][j].who_wins;
        }
    }
    return check_for_win(&moves, move);
}

void print_introduction() {
    system("cls");
    printf("Tictactoe, press enter to start");
    while(getchar() != '\n')
        ;
    system("cls");
}

void change_and_write_move(char plane[SIZEY][SIZEX], game games[3][3], char *move, int startx, int starty, int *i, int *j) {
    if (plane[starty][startx] == '*' && games[starty/9][startx/17].who_wins == CONTINUE_GAME && ((starty/9 == *i && startx/17 == *j) || (*i == -1 && *j == -1))) {
        games[starty/9][startx/17].pole[(starty%9-1)/2][(startx%17-3)/4] = *move;
        plane[starty][startx] = *move;
        if (games[(starty%9-1)/2][(startx%17-3)/4].who_wins == CONTINUE_GAME) {
            *i = (starty%9-1)/2;
            *j = (startx%17-3)/4;
        }
        else {
            *i = -1;
            *j = -1;
        }
        (*move == 'X') ? *move = 'O': *move = 'X';
    }
}

const char BIGX[GRID_SIZEY][GRID_SIZEX] = {
    {"\\         /"},
    {"  \\     /  "},
    {"    \\ /    "},
    {"    / \\    "},
    {"  /     \\  "},
    {"/         \\"},
};

const char BIGO[GRID_SIZEY][GRID_SIZEX] = {
    {"  /-----\\  "},
    {" /       \\ "},
    {"|         |"},
    {"|         |"},
    {" \\       /"},
    {"  \\_____/  "},
};


void make_big_XorY(int x, int y, char plane[SIZEY][SIZEX], char move) {
    for (int i = 0; i < GRID_SIZEY; i++) {
        set_cursor_position(x*17+2, y*9+1+i);
        for (int j = 0; j < GRID_SIZEX; j++) {
            if (move == 'O')
                putchar(BIGX[i][j]);
            else
                putchar(BIGO[i][j]);
        }
    }
}

int main() {
    game games[3][3] = {};
    char plane[SIZEY][SIZEX] = {
        {"               II               II               "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"     |   |     II     |   |     II     |   |     "},
        {"               II               II               "},
        {"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"},
        {"               II               II               "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"     |   |     II     |   |     II     |   |     "},
        {"               II               II               "},
        {"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"},
        {"               II               II               "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"  ___|___|___  II  ___|___|___  II  ___|___|___  "},
        {"   * | * | *   II   * | * | *   II   * | * | *   "},
        {"     |   |     II     |   |     II     |   |     "},
        {"               II               II               "}
    };
    int startx = 0, starty = 0;
    char move = 'X';
    int i = -1, j = -1;
    
    print_introduction();
    print_plane(plane);
    wins type_of_win = DRAW;

    while ((type_of_win = check_for_win_global(games, move)) == CONTINUE_GAME) {
        if (check_for_win(&games[starty/9][startx/17], move) == END) {
            make_big_XorY(startx/17, starty/9, plane, move);
        }
        set_cursor_position(startx, starty);

        int ch = _getch();
        if (ch == 'q') // quit
            return 0;

        if (ch == ' ') { // want to place
            change_and_write_move(plane, games, &move, startx, starty, &i, &j);
            continue;
        }
        
        ch = _getch(); // второй код
        if (ch == 72 || ch == 75 || ch == 77 || ch == 80) {

            set_cursor_position(startx, starty);
            if (plane[starty][startx] != '*') 
                putchar(plane[starty][startx]);
            else putchar(' ');
            
            switch (ch) {
                case 72: if (starty > 0) starty--; break;
                case 80: if (starty < SIZEY) starty++; break;
                case 75: if (startx > 0) startx--; break;
                case 77: if (startx < BOARD_SIZEX) startx++; break;
            }
        }
    }

    set_cursor_position(0, 28);
    if (type_of_win == DRAW)
        printf("The game has ended in a draw booooring");
    else
        printf("player %c has won the game, congratulations", (move == 'X') ? 'O': 'X');
    return 0;

}