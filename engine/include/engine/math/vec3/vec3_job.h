#pragma once

#include "engine/common.h"

#include "engine/math/vec3/vec3.h"
#include "engine/math/vec3/vec3_constants.h"
#include "engine/math/vec3/vec3_math.h"

// Idea:
// VectorOp queues, where we can add vectors due for a certain operation (addition,
// subtraction, etc), and during a pass (i.e. once per frame) the engine
// resolves these operations and stores the results
// Would require lots of complicated math and syntax and shit (probably using c++
// asyncs and futures) but hell, it might just work
