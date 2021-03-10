#include "edges.h"

void init_edges(edges_t &edges)
{
    edges.edges_arr = NULL;
    edges.n = 0;
}
error_t alloc_edges(edges_t &edges, size_t n)
{
    error_t err = OK;
    edges.n = n;
    edges.edges_arr = (edge_t *) malloc(n * sizeof(edge_t));
    if (edges.edges_arr == NULL)
        err = MEMORY_ALLOCATION_ERROR;
    return err;
}
void delete_edges(edges_t &edges)
{
    free(edges.edges_arr);
    edges.edges_arr = NULL;
    edges.n = 0;
}
error_t read_edges_num(size_t &n, FILE *const f)
{
    error_t err = OK;
    if (fscanf(f, "%lu", &n) != 1 || n < 1)
    {
        n = 0;
        err = READ_POINTS_ERROR;
    }
    return err;
}
error_t read_edges(edges_t &edges, FILE * const f)
{
    error_t err = read_edges_num(edges.n, f);

    if (err == OK)
        err = alloc_edges(edges, edges.n);

    for (size_t i = 0; err == OK && i < edges.n; i++)
        err = read_edge(edges.edges_arr[i], f);

    if (err != OK)
        delete_edges(edges);

    return err;
}
void print_edges_num(FILE * const f, size_t n)
{
    fprintf(f, "%lu\n", n);
}
void print_edges(FILE * const f, const edges_t &edges)
{
    print_edges_num(f, edges.n);
    for (size_t i = 0; i < edges.n; i++)
    {
        print_edge(f, edges.edges_arr[i]);
        fprintf(f, "\n");
    }
}
error_t copy_edges(edges_t &edges_dst, const edges_t &edges_src)
{
    edges_dst.n = edges_src.n;
    error_t err = alloc_edges(edges_dst, edges_dst.n);
    for (size_t i = 0; err == OK && i < edges_dst.n; i++)
    {
        copy_edge(edges_dst.edges_arr[i], edges_src.edges_arr[i]);
    }
    return err;
}
error_t are_correct_edges(const edges_t &edges, size_t max_vertex)
{
    error_t err = OK;
    for (size_t i = 0; err == OK && i < edges.n; i++)
        err = is_correct_edge(edges.edges_arr[i], max_vertex);
    return err;
}
