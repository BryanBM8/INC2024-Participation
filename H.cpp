#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

struct Item {
    int berat;
    int harta;
};

int compareForQuickSort(const void *a, const void *b) {
    return ((struct Item *)a)->berat - ((struct Item *)b)->berat;
}

int main(void) {
    int berat, harta;
   	 scanf("%d %d", &berat, &harta);
    struct Item items[MAX];
    for (int i = 0; i<berat; i++) {
        	scanf("%d %d", &items[i].berat, &items[i].harta);
    }
    int kapasitas[MAX];
    for (int i = 0; i < harta; i++) {
        scanf("%d", &kapasitas[i]);
    }
    qsort(items, berat, sizeof(struct Item), compareForQuickSort);
    qsort(kapasitas, harta, sizeof(int), compareForQuickSort);

    struct Item maxHeap[MAX];
    int maxHeapSize = 0;
    int curr = 0;
    long long total = 0;
    int index = 0;
    while (index < harta) {
        while (curr <berat && items[curr].berat <= kapasitas[index]) {
            maxHeap[maxHeapSize] = items[curr];
            int i = maxHeapSize;
            while (i>0) {
                int j = (i-1) / 2;
                if (maxHeap[j].harta >= items[curr].harta){
                    break;
				}
                maxHeap[i] = maxHeap[j];
                i=j;
            }
            maxHeap[i] = items[curr];
            maxHeapSize++;
            curr++;
        }
        if (maxHeapSize> 0) {
            total += maxHeap[0].harta;
            maxHeapSize--;
            maxHeap[0] = maxHeap[maxHeapSize];
            int i = 0;

            while (i*2+1<maxHeapSize) {
                int left = i * 2 + 1;
                int right = i * 2 + 2;
                int j = left;
                if (right < maxHeapSize && maxHeap[right].harta > maxHeap[left].harta){
                    	j = right;
				}
                if (maxHeap[j].harta <= maxHeap[maxHeapSize].harta){
                  break;
				}
                maxHeap[i]=maxHeap[j];
                i = j;
            }
            maxHeap[i]=maxHeap[maxHeapSize];
        } index++;
    }
    printf("%lld\n", total);
    return 0;
}

