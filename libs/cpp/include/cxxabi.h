#pragma once

#include <stddef.h>

namespace __cxxabiv1 {
    extern "C" {
    typedef void (*__cxa_cdtor_type)(void *);

    void __cxa_vec_cleanup(void *array, size_t count, size_t elementSize, __cxa_cdtor_type dtor);
    }
} // namespace __cxxabiv1
