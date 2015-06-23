#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <helpers.h>
#include <unistd.h>
#include <bufio.h>


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
void execute(char* file_path, char* argv[], int argc, char * args[], int counter) {
    for (int i = 1; i < argc; i++) {
        args[counter] = argv[i];
        args[counter + 1] = NULL;
        int res = spawn(args[0], args);
        if (res == 0) {
            int write_cnt;
            for (int i = 0; i <= counter; i++) {
                write_cnt = write_(STDOUT_FILENO, args[i], strlen(args[i]));
                if (write_cnt == -1) {
                    error_foreach(strerror(errno));
                }
                write_char(' ');
            }
            write_char('\n');
        }
    }
}

int main(int argc, char ** argv) {

    ssize_t read_cnt;
    struct buf_t * buf = buf_new(4096);

    char ** args = malloc(sizeof(char *) * 4096);
    int counter = 0;
    args[counter] = malloc(4096);
    int arg_len = 0;
    do {
        read_cnt = buf_fill(STDIN_FILENO, buf, 1);



        if (read_cnt == -1) {
            error_foreach(strerror(errno));
        }

        char * command = buf_get_data(buf);

        for (int i = 0; i < read_cnt; i++) {
            if (command[i] == ' ') {
                args[counter++][arg_len] = '\0';
                args[counter] = malloc(4096);
                arg_len = 0;
            } else {
                if (command[i] == '\n') {
                    args[counter][arg_len++] = '\0';
                    execute(args[0], argv, argc, args, counter + 1);
                    free(args);
                    arg_len = 0;
                    args = malloc(sizeof(char *) * 4096);   
                    counter = 0;
                    args[counter] = malloc(4096);
                }
                else {
                    args[counter][arg_len++] = command[i];
                }
            }
        }
    } while (read_cnt > 0);

    return 0;
}