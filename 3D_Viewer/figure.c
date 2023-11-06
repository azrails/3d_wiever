#include "figure.h"

figure *new_figure_node(int count_point, float *array_coords) {
    figure *structure = (figure *)malloc(sizeof(figure) * 1);
    structure->count_point = count_point;
    structure->array_coords = array_coords;
    structure->next = NULL;

    return structure;
}

int figure_push_back(figure **head, figure *new_node) {
    int flag = 1;
    if (!new_node)
        flag = 0;
    else {
        if (!*head) *head = new_node;
        else {
            figure *start = *head;
            while (start->next != NULL)
                start = start->next;
            start->next = new_node;
        }
    }
    return flag;
}

void delete_node_figure(figure **head) {
    if (!(*head)) return;
    figure *next;
    figure *prev = *head;
    while (prev) {
        next = prev->next;
        if (prev->array_coords)
            free(prev->array_coords);
        free(prev);
        prev = next;
    }
    *head = NULL;
}

config *new_config(figure *fig) {
    config *structure = malloc(sizeof(config) * 1);
    structure->box[0] = -3.0;
    structure->box[1] = 3.0;
    structure->box[2] = -3.0;
    structure->box[3] = 3.0;
    structure->box[4] = -4.0;
    structure->box[5] = 4.0;

    structure->color_fon[0] = 0.0;
    structure->color_fon[1] = 0.0;
    structure->color_fon[2] = 0.0;
    structure->color_fon[3] = 1.0;

    structure->color_line[0] = 0.4;
    structure->color_line[1] = 0.0;
    structure->color_line[2] = 0.6;

    structure->color_point[0] = 0.0;
    structure->color_point[1] = 0.0;
    structure->color_point[2] = 1.0;

    structure->line_width = 3;
    structure->type_line = 0;
    structure->type_point = 0;
    structure->point_width = 10;

    structure->fig = fig;
    structure->edge_count = 0;
    structure->vertex_count = 0;

    return structure;
}

void delete_node_config(config **conf) {
    if (!*conf) return;
    delete_node_figure(&((*conf)->fig));
    free(*conf);
    *conf = NULL;
}


