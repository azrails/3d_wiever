#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include <float.h>
#include <math.h>

#include "figure.h"

void rotation_figure(figure *fig, float x, float y, float z);
float *figure_center(figure *fig);
void transform_coordinates(figure *fig, float *center);
void translate_figure(figure *fig, float x, float y, float z);
void scale_figure(figure *fig, float x, float y, float z);

#endif  // TRANSFORMS_H
