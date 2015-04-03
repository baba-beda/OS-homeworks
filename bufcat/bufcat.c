#include <bufio.h>
#include <unistd.h>

int main() {
    int ret_code = 0;
    struct buf_t * buf = buf_new(4096);
    ssize_t read_cnt, written_cnt;

    do {
        read_cnt = buf_fill(STDIN_FILENO, buf, buf_capacity(buf));
        written_cnt = buf_flush(STDOUT_FILENO, buf, buf_size(buf));
        if (read_cnt == -1 || written_cnt == -1) {
            ret_code = 1;
            break;
        }
    } while (read_cnt > 0);

    buf_free(buf);
    return ret_code;
}