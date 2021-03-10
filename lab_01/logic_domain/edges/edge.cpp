#include "edge.h"

error_t read_edge(edge_t &edge, FILE * const f)
{
    error_t err = OK;
    if (fscanf(f, "%lu", &edge.v1) != 1)
        err = READ_EDGES_ERROR;
    if (err == OK)
        edge.v1--;
    if (err == OK && (fscanf(f, "%lu", &edge.v2 ) != 1))
        err = READ_EDGES_ERROR;
    if (err == OK)
        edge.v2--;
    return err;
}
error_t is_correct_edge(const edge_t &edge, size_t max_vertex)
{
    error_t err = OK;
    if (edge.v1 > max_vertex || edge.v1 < 1)
        err = INCORRECT_MODEL;
    if (err == OK && (edge.v2 > max_vertex || edge.v2 < 1))
        err = INCORRECT_MODEL;
    return err;
}
void print_edge(FILE * const f, const edge_t &edge)
{
    fprintf(f, "%lu %lu", edge.v1 + 1, edge.v2 + 1);
}

void copy_edge(edge_t &edge_dst, const edge_t &edge_src)
{
    edge_dst.v1 = edge_src.v1;
    edge_dst.v2 = edge_src.v2;
}
