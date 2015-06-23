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
void execute(char* file_path, char* argv[]) {
    int res = spawn(file_path, argv);
    if (res == 0) {
        int write_cnt;
        write_cnt = write_(STDOUT_FILENO, file_path, strlen(file_path));
        if (write_cnt == -1) {
            error_foreach(strerror(errno));
        }
        write_cnt = write_(STDOUT_FILENO, argv[1], strlen(argv[1]));
        if (write_cnt == -1) {
            error_foreach(strerror(errno));
        }
        write_char('\n');
    }
}

int main(int argc, char ** argv) {
    char command[4096];
    size_t read_cnt;
    size_t read_all = 0;

    do {
        read_cnt = (size_t) read(STDIN_FILENO, command, sizeof(command));
        if (read_cnt == -1) {
            error_foreach(strerror(errno));
        }
        read_all += read_cnt;
    } while (read_cnt > 0);

    for (int i = 1; i < argc; i++) {
        char * args[2];
        args[0] = command;
        args[1] = argv[i];
        execute(command, args);
    }
}