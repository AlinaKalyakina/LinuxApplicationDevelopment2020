#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define DX 3

struct string {
    char* buf;
    size_t len;
};


struct string* read_file(char* filename, int* file_len) {
    FILE *f;
    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"Can't open file %s", filename);
        return NULL;
    }
    struct string* strings=NULL;
    int str_num = 0;
    while (!feof(f)) {
        strings = realloc(strings, (str_num+1)*sizeof(*strings));
        if (strings == NULL) {
            fprintf(stderr, "Can't realloc buffer");
            exit(1);
        }
        strings[str_num].buf = NULL;
        if (getline(&strings[str_num].buf, &strings[str_num].len, f) != -1) {
            strings[str_num].len = strlen(strings[str_num].buf);
            if (strings[str_num].buf[strings[str_num].len-1] == '\n'){
                strings[str_num].buf[strings[str_num].len-1] = '\0';
            }
        }
        str_num++;
    }
    fclose(f);
    *file_len = str_num;
    return strings;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Filename was expected");
        exit(0);
    }
    int str_num;
    struct string* strings = read_file(argv[1], &str_num);
    if (strings == NULL) {
        exit(1);
    }
    WINDOW *win;
    int c = 0;
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    printw("File: %s; size: %d\n", argv[1], str_num);
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    int line_capacity = LINES-2*DX;
    int col_capacity = COLS-2*DX;
    int cur_line = 0;
    int cur_col = 0;
    do {
        switch (c) {
            case KEY_DOWN:
                cur_line++;
                break;
            case KEY_UP:
                cur_line--;
                break;
            case KEY_LEFT:
                cur_col--;
                break;
            case KEY_RIGHT:
                cur_col++;
                break;
            case KEY_NPAGE:
                cur_line += line_capacity-2;
                break;
            case KEY_PPAGE:
                cur_line -= line_capacity-2;
                break;
        }
        if (cur_line >= str_num) {
            cur_line = str_num - 1;
        }
        if (cur_line < 0) {
            cur_line = 0;
        }
        if (cur_col < 0) {
            cur_col = 0;
        }
        werase(win);
        int i;
        for (i = 0; i <= line_capacity && cur_line + i < str_num; i++) {
            mvwprintw(win, i+1, 1, "%d: ", cur_line + i+1);
            if (strings[cur_line+i].len > cur_col) {
                mvwaddnstr(win, i+1, 5, strings[cur_line+i].buf+cur_col, col_capacity-5);
            }
        }
        while (i <= line_capacity) {
            mvwprintw(win, i+1, 1, "%d: ", cur_line + i+1);
            i++;
        }

        box(win, 0, 0);
        wrefresh(win);
    } while((c = wgetch(win)) != 27);
    endwin();
    for (int i = 0; i < str_num; i++) {
        free(strings[i].buf);
    }
    free(strings);
    return 0;
}