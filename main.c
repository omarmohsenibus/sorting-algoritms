#include "sort.h"

int compare_int(void *a, void *b){
    int *pa = a;
    int *pb = b;

    return *pa - *pb;
}

void print_vec(char **v, int n){
    printf("\n[");
    for(int i=0; i<n; i++){
        printf("%s", v[i]);
        if(i+1 != n)    printf(", ");
    }
    printf("]\n");
}

int compare_string(void *a, void *b){
    char **pa = a;
    char **pb = b;

    return strcmp(*pa, *pb);
}

int main(void){
    
    char *stringhe[] = {
        "filippo", "alberto", "carlo", "omar"
    };
    int n = 4;
    
    print_vec(stringhe, n);

    selection_sort(stringhe, n, sizeof(char *), compare_string);
    
    print_vec(stringhe, n);
    

    return 0;
}