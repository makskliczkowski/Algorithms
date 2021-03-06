#ifndef PCH_H
#define PCH_H
float* Insertsort_up(float *table, int size);
float* Insertsort_down(float *table, int size);
float* Insertsort_up(float *table, int size, int iterations);
float* Insertsort_down(float *table, int size, int iterations);
float* Randomise_Table(float *table, int size);
void writeToFile(float*table,int size);
void almostQuickSort(float *table,int l, int r, int numElem,float & elem, int & iterations);
int partition(float* table, int l, int r);
void haro();
int compare(const void* a, const void* b);
#endif
