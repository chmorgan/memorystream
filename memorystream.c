#include <string.h>
#include "memorystream.h"

void memorystream_init(memorystream *pMS, void* data, size_t datalen) {
    pMS->data = data;
    pMS->len = datalen;

    pMS->pos = data;
}

size_t memorystream_bytesavailable(memorystream *pMS) {
    size_t bytesAvailable = pMS->len - (pMS->pos - (uint8_t*)pMS->data);
    return bytesAvailable;
}

long memorystream_getposition(memorystream *pMS) {
    return (pMS->pos - (uint8_t*)pMS->data);
}

void memorystream_setposition(memorystream *pMS, long position) {
    pMS->pos = ((uint8_t*)pMS->data) + position;
}

void* memorystream_getpointer(memorystream *pMS) {
    return pMS->pos;
}

bool memorystream_write8(memorystream *pMS, uint8_t val) {
    if(memorystream_bytesavailable(pMS) < sizeof(uint8_t)) {
        return false;
    }

    *pMS->pos = val;
    pMS->pos++;

    return true;
}

bool memorystream_write16(memorystream *pMS, uint16_t val) {
    if(memorystream_bytesavailable(pMS) < sizeof(uint16_t)) {
        return false;
    }

    *((uint16_t*)pMS->pos) = val;
    pMS->pos += sizeof(uint16_t);

    return true;
}

bool memorystream_writebytes(memorystream *pMS, void* data, size_t len) {
    if(memorystream_bytesavailable(pMS) < len) {
        return false;
    }

    memcpy(pMS->pos, data, len);
    pMS->pos += len;

    return true;
}

bool memorystream_read16(memorystream *pMS, uint16_t *val) {
    if(memorystream_bytesavailable(pMS) < sizeof(uint16_t)) {
        return false;
    }

    *val = *((uint16_t*)pMS->pos);
    pMS->pos += sizeof(uint16_t);

    return true;
}

bool memorystream_readbytes(memorystream *pMS, void* data, size_t len) {
    if(memorystream_bytesavailable(pMS) < len) {
        return false;
    }

    memcpy(data, pMS->pos, len);
    pMS->pos += len;

    return true;
}
