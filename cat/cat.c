

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <helpers.h>


void error_cat(const char *error_str)
{
    fprintf(stderr, "%s\n", error_str);
    exit(1);
}


int main()
{
    char buf[4096];
    size_t read_cnt;

    do
    {
        read_cnt = (size_t) read_(STDIN_FILENO, buf, sizeof(buf));
        if (read_cnt == -1)
        {
            error_cat(strerror(errno));
        }

        size_t written_cnt = (size_t) write_(STDOUT_FILENO, buf, read_cnt);

        if (written_cnt < read_cnt)
        {
            error_cat("Unexpected EOF");
        }
    } while (read_cnt == sizeof(buf));

    return 0;
}

