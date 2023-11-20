#pragma once

#include "mem.h"
#include "Func.h"
#include "startup.h"
#include "Random.h"

#define WIDTH 640
#define HEIGHT 360

#define MC_CHECK_SIZE(type, size) static_assert(sizeof(mc::type) == size, #type " has invalid size.")