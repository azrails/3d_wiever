#ifndef FIGURE_H
#define FIGURE_H

#include <stdlib.h>

typedef struct figure_t {
  int count_point;
  float *array_coords;
  struct figure_t *next;
} figure;

typedef struct config_t {
  figure *fig;
  float color_fon[4];  // цвет фона
  int type_projection;
  int vertex_count;
  int edge_count;

  int type_line;     // тип линий, 1-сплошная, 2-пунктир
  float line_width;  //толщина линий
  float color_line[3];  // цвет линий

  int type_point;  // тип вершин, 0-нет, 1-круг, 2-квадрат
  float point_width;     // толщина вершин
  float color_point[3];  // цвет вершин
} config;

figure *new_figure_node(int count_point, float *array_coords);
int figure_push_back(figure **head, figure *new_node);
config *new_config(figure *fig);
void delete_node_figure(figure **head);
void delete_node_config(config **conf);

#endif  // FIGURE_H
