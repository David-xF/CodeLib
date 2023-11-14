#pragma once

#include "mem.h"
#include "rawFunc.h"
#include "startup.h"
#include "Random.h"

#define WIDTH 640
#define HEIGHT 360

#define MC_SIZE(a, x) static_assert(sizeof(a) == x);