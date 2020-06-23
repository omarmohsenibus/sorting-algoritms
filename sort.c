#include "sort.h"
void swap(void *a, void *b, size_t data_size){
    char *tmp = malloc(data_size);
    char *pa = a;
    char *pb = b;
    
    memcpy(tmp, pa, data_size);
    memcpy(pa, pb, data_size);
    memcpy(pb, tmp, data_size);

    free(tmp);
}


int find_max_pos(void *data, size_t data_size, int n, int(*cmp)(void *, void *)){
    int ret = 0;

    for(int i=1; i<n; i++){
        if(cmp(&data[ret * data_size], &data[i * data_size]) < 0){
            ret = i;
        }
    }

    return ret;
}
void selection_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *)){
    while(n > 1){
        int pos = find_max_pos(data, data_size, n, cmp);
        if(pos < n - 1){
            swap(&data[pos*data_size], &data[(n - 1)*data_size], data_size);
        }
        n--;
    }
}


void bubble_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *)){
    bool ordinato = false;

    while(n>1 && !ordinato){
        ordinato = true;
        for(int i=0; i<n-1; i++){
            if(cmp(&data[i*data_size], &data[(i+1)*data_size]) > 0){
                swap(&data[i*data_size], &data[(i+1)*data_size], data_size);
                ordinato = false;
            }
        }
        n--;
    }
}


//non funziona ancora
void insert_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *)){
    for(int i=1; i<n; i++){
        int last_pos = i;
        int *x = &data[last_pos * data_size];
        int j;
        for(j=last_pos - 1; j>=0 && cmp(x, &data[j*data_size]) < 0; j--){
            memcpy(&data[(j+1)*data_size], &data[j*data_size], data_size);
        }
        memcpy(&data[(j+1)*data_size], x, data_size);
    }
}

void quick_rec(void *data, int first, int last, size_t data_size, int(*cmp)(void *, void *)){
    if(first < last){
        int i = first;
        int j = last;
        int middle = (first + last) / 2;
        void *pivot = &data[middle * data_size];
        do {
            while (cmp(&data[i*data_size], pivot) < 0)  i++;   
            while (cmp(&data[j*data_size], pivot) > 0)  j--;

            if(i <= j){
                swap(&data[i*data_size], &data[j*data_size], data_size);
                i++;
                j--;
            }
        } while(i <= j);
        quick_rec(data, first, j, data_size, cmp);
        quick_rec(data, i, last, data_size, cmp);
    }
}
void quick_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *)){
    quick_rec(data, 0, n, data_size, cmp);
}



void merge_rec(void *data, int n, size_t data_size, int a, int b, int last, int(*cmp)(void *, void *)){
    void *tmp = malloc(n*data_size);
    int i = a;
    int j = b;
    int k = a;

    while (i < b - 1 && j <= last){
        if(cmp(&data[i*data_size], &data[j*data_size]) < 0){
            memcpy(&tmp[k*data_size], &data[i*data_size], data_size);
            i++;
        } else {
            memcpy(&tmp[k*data_size], &data[j*data_size], data_size);
            j++;
        }
        k++;
    }

    while(i <= b - 1){
        memcpy(&tmp[k*data_size], &data[i*data_size], data_size);
        i++;
        k++;
    }

    while(j <= last){
        memcpy(&tmp[k*data_size], &data[j*data_size], data_size);
        j++;
        k++;
    }

    for(i=a; i<=last; i++){
        memcpy(&data[i*data_size], &tmp[i*data_size], data_size);
    }



    free(tmp);
}
void merge(void *data, int n, int first, int last, size_t data_size, int(*cmp)(void *, void *)){
    if(first < last){
        int middle = (last + first) / 2;
        merge(data, n, first, middle, data_size, cmp);
        merge(data, n, middle + 1, last, data_size, cmp);
        merge_rec(data, n, data_size, first, middle + 1, last, cmp);
    }
}
void merge_sort(void *data, int n, size_t data_size, int(*cmp)(void *, void *)){
    merge(data, n, 0, n, data_size, cmp);
}
