#include "func_buf.h"
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>


sFuncBuf_t f_buf;

static void advance_pointer(sFuncBuf_t *buf)
{
	assert(buf);

	if(buf->full)
   	{
		if (++(buf->tail) == buf->max) 
		{ 
			buf->tail = 0;
		}
	}

	if (++(buf->head) == buf->max) 
	{ 
		buf->head = 0;
	}
	buf->full = (buf->head == buf->tail);
}

static void retreat_pointer(sFuncBuf_t *buf)
{
    assert(buf);
    
    buf->full = false;
    if(++buf->tail == buf->max)
    {
        buf->tail = 0;
    }
}

void FBUF_buffer_reset(sFuncBuf_t *buf)
{
    buf->head = 0;
    buf->tail = 0;
    buf->full = false;
    for(uint8_t i=0;i<8;i++)
    {
        buf->func[i] = NULL;
    }
}

bool FBUF_buffer_full(sFuncBuf_t *buf)
{
    assert(buf);
    return buf->full;
}

bool FBUF_buffer_empty(sFuncBuf_t *buf)
{
    assert(buf);
    
    return(!buf->full && (buf->head == buf->tail));
}

int FBUF_buffer_put(sFuncBuf_t *buf, void(*func)(void))
{
    assert(buf);
    int r=-1;
    if(!FBUF_buffer_full(buf))
    {
        buf->func[buf->head] = func;
        advance_pointer(buf);
        r=0;
    }
    return r;
}

int FBUF_buffer_get(sFuncBuf_t *buf, void(*func))
{
//    assert(buf);
//    
//    int r=-1;
//    
//    if(!FBUF_buffer_empty(buf))
//    {
//        func = (void*)buf->func[buf->tail];
//        retreat_pointer(buf);
//    }
	return 0;
}

int FBUF_buffer_run(sFuncBuf_t *buf)
{
    assert(buf);
    int r=-1;
    if(!FBUF_buffer_empty(buf))
    {
        buf->func[buf->tail]();
        retreat_pointer(buf);
        r=0;
    }
    return r;
}
