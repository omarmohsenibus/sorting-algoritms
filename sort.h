#if !defined SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum order {
    ASC,
    DESC
};

extern void selection_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *));
extern void bubble_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *));
extern void insert_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *));
extern void quick_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *));
extern void merge_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *));



#endif //SORT_H