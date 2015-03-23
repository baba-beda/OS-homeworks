#include "helpers.h"

ssize_t read_until(int fd, void *buf, size_t count, char delimiter)
{
    size_t read_cnt = 0;
    size_t read_int_cnt = 0;
    int del_found = 0;
    if (count == 0)
    {
        read(fd, buf, 0);
    }

    do
    {
        read_int_cnt = (size_t) read(fd, buf + read_cnt, count);

        if (read_int_cnt == -1)
        {
            return  -1;
        }

        for(int i = 0; i < read_int_cnt; i++)
        {
            if (((char*)buf)[read_cnt + i] == delimiter)
            {
                del_found = 1;
                break;
            }
        }

        read_cnt += read_int_cnt;
        count -= read_int_cnt;
    } while (count > 0 && read_int_cnt > 0 && !del_found);

    return read_cnt;
}

ssize_t read_(int fd, void *buf, size_t count)
{
    size_t read_cnt = 0;
    size_t read_int_cnt = 0;
    if (count == 0)
    {
        read(fd, buf, 0);
    }

    do
    {
        read_int_cnt = (size_t) read(fd, buf + read_cnt, count);

        if (read_int_cnt == -1)
        {
            return  -1;
        }

        read_cnt += read_int_cnt;
        count -= read_int_cnt;
    } while (count > 0 && read_int_cnt > 0);

    return read_cnt;
}

ssize_t write_(int fd, const void *buf, size_t count)
{
    size_t written_cnt = 0;
    size_t written_int_cnt;

    if (count == 0)
    {
        return write(fd, buf, 0);
    }

    do
    {
        written_int_cnt = (size_t) write(fd, buf + written_cnt, count);

        if (written_int_cnt == -1)
        {
            return  -1;
        }

        written_cnt += written_int_cnt;
        count -= written_int_cnt;
    } while (count > 0 && written_int_cnt > 0);

    return written_cnt;
}

int spawn(const char * file, char * const argv []) {
    
}



