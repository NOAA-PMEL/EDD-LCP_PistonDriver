#ifndef FUNC_BUF_H
#define FUNC_BUF_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void (*func[8])(void);
    size_t head;
    size_t tail;
    size_t max;
    bool full;
    size_t write;
}sFuncBuf_t;

void FBUF_buffer_reset(sFuncBuf_t *buf);
bool FBUF_buffer_full(sFuncBuf_t *buf);
bool FBUF_buffer_empty(sFuncBuf_t *buf);
int FBUF_buffer_put(sFuncBuf_t *buf, void(*func)(void));
int FBUF_buffer_get(sFuncBuf_t *buf, void(*func));
int FBUF_buffer_run(sFuncBuf_t *buf);

extern sFuncBuf_t f_buf;

#endif // FUNC_BUF_H
