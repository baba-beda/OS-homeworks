#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "../lib/helpers.h"


void error_revwords(const char* error_str)
{
    fprintf(stderr, "%s\n", error_str);
    exit(1);
}

void reverse(char word[4096], size_t word_pos)
{
    for (int i = 0; i < word_pos / 2; i++)
    {
        char t = word[i];
        word[i] = word[word_pos - i - 1];
        word[word_pos - i - 1] = t;
    }
    write_(STDOUT_FILENO, word, word_pos);
}

void write_char(char c)
{
    write_(STDOUT_FILENO, &c, 1);
}


int main()
{
    char buf[4096];
    char word[4096];
    size_t word_pos = 0;
    size_t read_cnt;

    do
    {
        read_cnt = (size_t) read_until(STDIN_FILENO, buf, sizeof(buf), ' ');

        if (read_cnt == -1)
        {
            error_revwords(strerror(errno));
        }

        for (int i = 0; i < read_cnt; i++)
        {
            if (buf[i] == ' ')
            {
                if (word_pos != 0)
                {
                    reverse(word, word_pos);
                }
                word_pos = 0;
                write_char(' ');
            }
            else
            {
                word[word_pos++] = buf[i];
            }
        }
    } while (read_cnt > 0);

    if (word_pos != 0)
    {
        reverse(word, word_pos);
    }
    return 0;
}