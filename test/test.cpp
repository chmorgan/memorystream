#include <stdio.h>
#include "memorystream.h"

bool test_writing_uint8() {
    memorystream ms;
    uint8_t data[1];

    memorystream_init(&ms, data, sizeof(data));

    auto ba = memorystream_bytesavailable(&ms);
    if(ba != sizeof(data)) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    if(!memorystream_write8(&ms, 0xAA)) {
        printf("Failed to write byte\n");
        return false;
    }

    ba = memorystream_bytesavailable(&ms);
    if(ba != 0) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    if(memorystream_write8(&ms, 0xAA)) {
        printf("memorystream_write8 success writing beyond buffer\n");
        return false;
    }

    return true;
}

bool test_writing_uint16() {
    memorystream ms;
    uint16_t data[1];

    memorystream_init(&ms, data, sizeof(data));

    auto ba = memorystream_bytesavailable(&ms);
    if(ba != sizeof(data)) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    if(!memorystream_write16(&ms, 0xAABB)) {
        printf("memorystream_write16 failed to write uint16\n");
        return false;
    }

    ba = memorystream_bytesavailable(&ms);
    if(ba != 0) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    // attempt to write beyond the end of the buffer
    if(memorystream_write16(&ms, 0xCCDD)) {
        printf("memorystream_write16 sucess writing beyond buffer\n");
        return false;
    }

    return true;
}

bool test_writing_bytes() {
    memorystream ms;
    uint8_t data[64];
    uint8_t src[64];

    memorystream_init(&ms, data, sizeof(data));

    auto ba = memorystream_bytesavailable(&ms);
    if(ba != sizeof(data)) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    if(!memorystream_writebytes(&ms, src, sizeof(src))) {
        printf("Failed to write bytes\n");
        return false;
    }

    ba = memorystream_bytesavailable(&ms);
    if(ba != 0) {
        printf("memorystream_bytesavailable expected %zu was %zu\n", sizeof(data), ba);
        return false;
    }

    // attempt to write beyond the end of the buffer
    if(memorystream_writebytes(&ms, src, sizeof(src))) {
        printf("memorystream_writebytes sucess writing beyond buffer\n");
        return false;
    }

    return true;
}

int main() {
    int retval = 0;
    if(!test_writing_uint8()) {
        printf("test_writing_uint8 failed\n");
        retval = 1;
    }

    if(!test_writing_uint16()) {
        printf("test_writing_uint16 failed\n");
        retval = 1;
    }

    if(!test_writing_bytes()) {
        printf("test_writing_bytes failed\n");
        retval = 1;
    }

    return retval;
}
