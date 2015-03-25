#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <helpers.h>
#include <unistd.h>


void error_filter(const char* error_str) {
    fprintf(stderr, "%s\n", error_str);
    exit(1);
}

void write_char(char c)
{
    write_(STDOUT_FILENO, &c, 1);
}

void execute(char* file_path, char* argv[], char word[4097], int word_pos) {
    int res = spawn(file_path, argv);
    if (res == 0) {
        write_(STDOUT_FILENO, word, word_pos);
        write_char('\n');
    }
}


int main(int argc, char* argv[]) {
    char* file_path = argv[1];
    for (int i = 0; i < argc - 1; i++) {
        argv[i] = argv[i + 1];
    }

    char buf[4096];
    char word[4097];

    int word_pos = 0;
    size_t read_cnt;
    argv[argc - 1] = word;

    do {
        read_cnt = (size_t) read_until(STDIN_FILENO, buf, sizeof(buf), '\n');

        if (read_cnt == -1) {
            error_filter(strerror(errno));
        }

        for (int i = 0; i < read_cnt; i++) {
            if (buf[i] == '\n') {
                if (word_pos != 0) {
                    word[word_pos] = 0;
                    execute(file_path, argv, word, word_pos);
                    word_pos = 0;
                }

            } else {
                word[word_pos++] = buf[i];
            }
        }

    } while (read_cnt > 0);

    if (word_pos != 0) {
        execute(file_path, argv, word, word_pos);
    }
    return 0;
}