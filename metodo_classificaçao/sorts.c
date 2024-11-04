#include <stdio.h>
#include <stdlib.h>

int bubble_comparisons = 0, bubble_swaps = 0;
int insertion_comparisons = 0, insertion_swaps = 0;
int heap_comparisons = 0, heap_swaps = 0;
int merge_comparisons = 0, merge_swaps = 0;
int quick_comparisons = 0, quick_swaps = 0;
int radix_comparisons = 0; // Radix não faz trocas

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bubble_comparisons++;
            if (arr[j] > arr[j + 1]) {
                bubble_swaps++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            insertion_comparisons++;
            if (arr[j] > key) {
                insertion_swaps++;
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        insertion_swaps++;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        heap_comparisons++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        heap_comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        heap_swaps++;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        heap_swaps++;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        merge_comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        merge_swaps++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        merge_swaps++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        merge_swaps++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        quick_comparisons++;
        if (arr[j] < pivot) {
            i++;
            quick_swaps++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quick_swaps++;
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void counting_sort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);
}

void compare_sorting_algorithms() {
    int sizes[] = {100, 1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    FILE* file = fopen("sorting_results.txt", "w");
    fprintf(file, "Tamanho da Lista\tBubble Comparisons\tBubble Swaps\tInsertion Comparisons\tInsertion Swaps\t"
                  "Heap Comparisons\tHeap Swaps\tMerge Comparisons\tMerge Swaps\tQuick Comparisons\tQuick Swaps\tRadix Comparisons\n");

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int* arr = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 10000;
        }

        // Reset counters
        bubble_comparisons = bubble_swaps = 0;
        insertion_comparisons = insertion_swaps = 0;
        heap_comparisons = heap_swaps = 0;
        merge_comparisons = merge_swaps = 0;
        quick_comparisons = quick_swaps = 0;
        radix_comparisons = 0;

        bubble_sort(arr, size);
        fprintf(file, "%d\t%d\t%d\t", size, bubble_comparisons, bubble_swaps);

        insertion_sort(arr, size);
        fprintf(file, "%d\t%d\t", insertion_comparisons, insertion_swaps);

        heap_sort(arr, size);
        fprintf(file, "%d\t%d\t", heap_comparisons, heap_swaps);

        merge_sort(arr, size);
        fprintf(file, "%d\t%d\t", merge_comparisons, merge_swaps);

        quick_sort(arr, size);
        fprintf(file, "%d\t%d\t", quick_comparisons, quick_swaps);

        radix_sort(arr, size);
        fprintf(file, "%d\n", radix_comparisons);

        free(arr);
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    compare_sorting_algorithms();
    printf("Resultados salvos em sorting_results.txt\n");
    return 0;
}