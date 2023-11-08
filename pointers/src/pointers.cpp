void find_mean(int* ptr_a, int* ptr_b, double* ptr_mean) {
    *ptr_mean = (*ptr_a + *ptr_b) / 2.;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int* a, int* b, int* c) {
    if(*a > *b) swap(a, b);
    if(*a > *c) swap(a, c);
    if(*b > *c) swap(b, c);
}

void set(int x, int* w) {
    *w = x;
}