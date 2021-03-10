#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include <stdlib.h>

#include "logic_domain/model/errors.h"

typedef struct
{
    size_t v1;
    size_t v2;
} edge_t;

error_t read_edge(edge_t &edge, FILE * const f);

void print_edge(FILE * const f, const edge_t &edge);

error_t is_correct_edge(const edge_t &edge, size_t max_vertex);

void copy_edge(edge_t &edge_dst, const edge_t &edge_src);

#endif // EDGE_H
