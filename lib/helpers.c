#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count)
{
    ssize_t read_cnt = 0;
    ssize_t read_int_cnt = 0;

    if (count == 0)
    {
        read(fd, buf, count);
    }

    do
    {
        read_int_cnt = read(fd, buf + read_cnt, count);

        if (read_int_cnt == -1)
        {
            return -1;
        }

        read_cnt += read_int_cnt;
        count -= read_int_cnt;
    } while (count > 0 && read_int_cnt > 0);
    return read_cnt;
}

ssize_t write_(int fd, const void *buf, size_t count)
{
    ssize_t written_cnt = 0;
    ssize_t written_int_cnt;

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


