#ifndef _C_STDDEF_H
#define _C_STDDEF_H

#define NULL 0

typedef unsigned int size_t;

#define offsetof(type, member) ((size_t) &((type *) NULL)->member)

#endif
