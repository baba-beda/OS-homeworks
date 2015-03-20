#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "../lib/helpers.h"

void error_lenwords(const char* error_str) {
    fprintf(stderr, "%s\n", error_str);
    exit(1);
}

void write_char(char c)
{
    write_(STDOUT_FILENO, &c, 1);
}

void len(size_t word_pos) {
    if (word_pos) {
        char len[4];
        sprintf(len, "%d", (int) word_pos);
        write_(STDOUT_FILENO, len, word_pos);
    }
    else {
        write_char('0');
    }
}


int main() {
    char buf[4096];
    char word[4096];
    size_t word_pos = 0;
    size_t read_cnt;

    do {
        read_cnt = (size_t) read_until(STDIN_FILENO, buf, sizeof(buf), ' ');

        if (read_cnt == -1) {
            error_lenwords(strerror(errno));
        }

        for (int i = 0; i < read_cnt; i++) {
            if (buf[i] == ' ') {
                len(word_pos);
                word_pos = 0;
                write_char(' ');
            }
            else {
                word[word_pos++] = buf[i];
            }
        }
    } while (read_cnt > 0);

    if (word_pos) {
        len(word_pos);
    }
    return 0;
}