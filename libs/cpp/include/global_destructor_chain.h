#pragma once

typedef struct DestructorChain {
    /* 0 */ struct DestructorChain *next;
    /* 4 */ void *destructor;
    /* 8 */ void *object;
    /* c */
} DestructorChain;

void *__register_global_object(void *object, void *destructor, DestructorChain *link);
