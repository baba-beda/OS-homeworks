#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <helpers.h>
#include <unistd.h>


void error_foreach(const char* error_str) {
    fprintf(stderr, "%s\n", error_str);
    exit(1);
}

void write_char(char c)
{
    int write_cnt = write(STDOUT_FILENO, &c, 1);
    if (write_cnt == -1) {
        error_foreach(strerror(errno));
    }
}
void execute(char* file_path, char* argv[], int argc) {
    int res = spawn(file_path, argv);
    if (res == 0) {
        int write_cnt;
        for (int i = 0; i < argc; i++) {
            write_cnt = write_(STDOUT_FILENO, argv[i], strlen(argv[i]));
            if (write_cnt == -1) {
                error_foreach(strerror(errno));
            }
            write_char(' ');
        }
        write_char('\n');
    }
}

int main(int argc, char ** argv) {
    char * command;
    command = malloc(4096);
    ssize_t read_cnt;

    char ** args = malloc(sizeof(char *) * 4096);
    int counter = 0;
    args[counter] = malloc(4096);
    int arg_len = 0;
    do {
        read_cnt = read_(STDIN_FILENO, command, sizeof(command));

        if (read_cnt == -1) {
            error_foreach(strerror(errno));
        }

        for (int i = 0; i < read_cnt; i++) {
            if (command[i] == ' ') {
                args[counter++][arg_len] = '\0';
                args[counter] = malloc(4096);
                arg_len = 0;
            } else {
                if (command[i] == '\n') {
                    args[counter][arg_len++] = '\0';
                }
                args[counter][arg_len++] = command[i];
            }
        }
        free(command);
        command = malloc(4096);
    } while (read_cnt > 0);

    if (arg_len != 0) {
        counter++;
    }

    for (int i = 1; i < argc; i++) {
        args[counter] = argv[i];
        args[counter + 1] = NULL;
        execute(args[0], args, counter + 1);
    }
}