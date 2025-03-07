#ifndef GO_ZERO_API_MESSAGE_H
#define GO_ZERO_API_MESSAGE_H

#include <stdbool.h>
#include <stdint.h>

// declare
struct __request_t;
struct __response_t;


// define
typedef struct __request_t { 
    char* name;
} request_t;

typedef struct __response_t { 
    char* message;
} response_t;



// function declare

char* response_to_json(response_t *message);

bool response_from_json(response_t *message, char* body);

#endif
