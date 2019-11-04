#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdexcept>

inline void throw_if_failed(HRESULT result)
{
    if (FAILED(result))
    {
        throw std::runtime_error("HRESULT failed");
    }
}
