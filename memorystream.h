#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct memorystream {
    void *data;
    size_t len;

    // position of the next data to write in the buffer
    uint8_t *pos;
} memorystream;

void memorystream_init(memorystream *pMS, void* data, size_t datalen);

size_t memorystream_bytesavailable(memorystream *pMS);

long memorystream_getposition(memorystream *pMS);
void memorystream_setposition(memorystream *pMS, long position);

void* memorystream_getpointer(memorystream *pMS);

bool memorystream_write8(memorystream *pMS, uint8_t val);
bool memorystream_write16(memorystream *pMS, uint16_t val);
bool memorystream_writebytes(memorystream *pMS, void* data, size_t len);

bool memorystream_read8(memorystream *pMS, uint8_t *val);
bool memorystream_read16(memorystream *pMS, uint16_t *val);
bool memorystream_readbytes(memorystream *pMS, void* data, size_t len);

#ifdef __cplusplus
}
#endif
