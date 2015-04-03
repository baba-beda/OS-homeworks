#include <bufio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define DEBUG_ASSERT(cond) if(!(cond)) abort();
#else
#define DEBUG_ASSERT(cond)
#endif

struct buf_t *buf_new(size_t capacity) {
    struct buf_t *rv = (struct buf_t*) malloc(sizeof(size_t) * 2 + capacity);
    if(rv == 0)
        return rv;
    rv->size = 0;
    rv->capacity = capacity;
    return rv;
}

void buf_free(struct buf_t *buf) {
    free(buf);
}

size_t buf_capacity(struct buf_t *buf) {
    DEBUG_ASSERT(buf != 0);
    return buf->capacity;
}

size_t buf_size(struct buf_t *buf) {
    DEBUG_ASSERT(buf != 0);
    return buf->size;
}

char *buf_get_data(struct buf_t *buf) {
    DEBUG_ASSERT(buf != 0);

    return ((char*) buf) + 2 * sizeof(size_t);
}

ssize_t buf_fill(fd_t fd, struct buf_t *buf, size_t required) {
    char *data = buf_get_data(buf);
    DEBUG_ASSERT(required <= buf->capacity);

    while(buf->size < required) {
        ssize_t rres = read(fd, data + buf->size, buf->capacity - buf->size);
        if(rres < 0) {
            return -1;
        }
        if(rres == 0) {
            return buf->size;
        }
        buf->size += rres;
    }
    return buf->size;
}

ssize_t buf_flush(fd_t fd, struct buf_t *buf, size_t required) {
    char *data = buf_get_data(buf);

    size_t offset = 0;
    while(buf->size > 0 && offset < required) {
        ssize_t wres = write(fd, data + offset, buf->size - offset);
        if(wres < 0) {
            memmove(data, data + offset, buf->size - offset);
            buf->size -= offset;
            return -1;
        }
        offset += wres;
    }
    memmove(data, data + offset, buf->size - offset);
    buf->size -= offset;
    return offset;
}
