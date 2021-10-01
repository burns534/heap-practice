#include "max-heap.h"

static void error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void Heap::swap(size_t parent, size_t child) {
    ElementType temp = data[parent];
    data[parent] = data[child];
    data[child] = temp;
}

void Heap::heapify(size_t index) {
    size_t left = 2 * index + 1, right = 2 * index + 2;
    if (data[index] < data[left] && left < count - 1) {
        swap(index, left);
        heapify(left);
    } else if (data[index] < data[right] && right < count - 1) {
        swap(index, right);
        heapify(right);
    }
}

void Heap::print_util(size_t index, int spacing) {
    if (index >= count) return;
    print_util(2 * index + 2, spacing + PRINT_SPACING);
    for (size_t i = 0; i < spacing; i++) {
        std::cout << " ";
    }
    std::cout << data[index];
    std::cout << "\n";
    print_util(2 * index + 1, spacing + PRINT_SPACING);
}

Heap::Heap(size_t size) {
    this->count = 0;
    this->size = size;
    this->data = (ElementType *) malloc(size * sizeof(ElementType));
}

Heap::~Heap() {
    free(data);
}

void Heap::insert(ElementType element) {
    if (count > LOAD_FACTOR * size) {
        data = (ElementType *) realloc(data, (size *= 2) * sizeof(ElementType)); // compiler warning
    }
    data[count] = element;
    for (size_t index = count++; data[index] > data[index / 2]; index /= 2) {
        swap(index, index / 2);
    }
}

ElementType Heap::max() {
    if (count > 0) return data[0];
    error("Error: Heap is empty");
    return -1; // compiler warning
}

ElementType Heap::popMax() {
    if (count == 0) error("Error: Heap is empty");
    ElementType result = data[0];
    swap(0, count - 1);
    heapify(0);
    count--;
    return result;
}

void Heap::print() {
    print_util(0);
}

void Heap::shrink_to_fit() {
    data = (ElementType *) realloc(data, count * sizeof(ElementType)); // compiler warning
    size = count;
}
