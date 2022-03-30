#ifndef STRUCT_H

#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>

enum {
        TODO,
        DOING,
        DONE,
};

enum {
        BEGIN,
        CHECK,
        EDIT,
        DELETE,
        RESET,
};

typedef struct project {
        char *task;
        int status;
        int index;
        struct project *next;
}p_s;

typedef struct {
        char **arr;
        char *file;
        const char *buf;
}s_t;

#endif
