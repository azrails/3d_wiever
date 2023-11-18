#include "transforms.h"

float *figure_center(figure *fig) {
  figure *head = fig;
  float *center = (float *)malloc(sizeof(float) * 3);
  float max_x, max_y, max_z;
  max_x = FLT_MIN;
  max_y = FLT_MIN;
  max_z = FLT_MIN;
  float min_x, min_y, min_z;
  min_x = FLT_MAX;
  min_y = FLT_MAX;
  min_z = FLT_MAX;
  while (head) {
    for (int i = 0; i < head->count_point; i++) {
      if (head->array_coords[i * 3] > max_x) max_x = head->array_coords[i * 3];
      if (head->array_coords[i * 3] < min_x) min_x = head->array_coords[i * 3];
      if (head->array_coords[i * 3 + 1] > max_y)
        max_y = head->array_coords[i * 3 + 1];
      if (head->array_coords[i * 3 + 1] < min_y)
        min_y = head->array_coords[i * 3 + 1];
      if (head->array_coords[i * 3 + 2] > max_z)
        max_z = head->array_coords[i * 3 + 2];
      if (head->array_coords[i * 3 + 2] < min_z)
        min_z = head->array_coords[i * 3 + 2];
    }
    head = head->next;
  }

  center[0] = (max_x + min_x) / 2;
  center[1] = (max_y + min_y) / 2;
  center[2] = (max_z + min_z) / 2;
  return center;
}

void transform_coordinates(figure *fig, float *center) {
  figure *head = fig;
  while (head) {
    for (int i = 0; i < fig->count_point; i++) {
      head->array_coords[i * 3] = head->array_coords[i * 3] - center[0];
      head->array_coords[i * 3 + 1] = head->array_coords[i * 3 + 1] - center[1];
      head->array_coords[i * 3 + 2] = head->array_coords[i * 3 + 2] - center[2];
    }
    head = head->next;
  }
}

void rotation_figure(figure *fig, float x, float y, float z) {
  float *coor;
  float x_cord, y_cord, z_cord;
  float cos_x, sin_x, cos_y, sin_y, cos_z, sin_z;
  cos_x = cos(x);
  sin_x = sin(x);
  cos_y = cos(y);
  sin_y = sin(y);
  cos_z = cos(z);
  sin_z = sin(z);
  figure *head = fig;
  while (head) {
    coor = head->array_coords;
    for (int i = 0; i < fig->count_point; i++) {
      x_cord = coor[3 * i] * cos_y + coor[3 * i + 2] * sin_y;
      z_cord = -coor[3 * i] * sin_y + coor[3 * i + 2] * cos_y;
      coor[3 * i] = x_cord;
      coor[3 * i + 2] = z_cord;
      y_cord = coor[3 * i + 1] * cos_x - coor[3 * i + 2] * sin_x;
      z_cord = coor[3 * i + 1] * sin_x + coor[3 * i + 2] * cos_x;
      coor[3 * i + 1] = y_cord;
      coor[3 * i + 2] = z_cord;
      x_cord = coor[3 * i] * cos_z - coor[3 * i + 1] * sin_z;
      y_cord = coor[3 * i] * sin_z + coor[3 * i + 1] * cos_z;
      coor[3 * i] = x_cord;
      coor[3 * i + 1] = y_cord;
    }
    head = head->next;
  }
}

void translate_figure(figure *fig, float x, float y, float z) {
  figure *head = fig;
  float *coor;
  while (head) {
    coor = head->array_coords;
    for (int i = 0; i < fig->count_point; i++) {
      coor[3 * i] += x;
      coor[3 * i + 1] += y;
      coor[3 * i + 2] += z;
    }
    head = head->next;
  }
}

void scale_figure(figure *fig, float x, float y, float z) {
  figure *head = fig;
  float *coor;
  while (head) {
    coor = head->array_coords;
    for (int i = 0; i < fig->count_point; i++) {
      coor[3 * i] = coor[3 * i] * x;
      coor[3 * i + 1] = coor[3 * i + 1] * y;
      coor[3 * i + 2] = coor[3 * i + 2] * z;
    }
    head = head->next;
  }
}
