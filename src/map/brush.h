#ifndef LIBMAP_BRUSH_H
#define LIBMAP_BRUSH_H

#include "vector.h"
#include <stdlib.h>

struct LMFace;

struct LMBrush {
	int face_count = 0;
	LMFace *faces = NULL;
	vec3 center;
};

#endif