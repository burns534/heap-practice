#include "max-heap.h"
#include "PriorityQueue.h"
#include <random>

int main(int argc, char **argv) {
    srand(time(nullptr));
    Heap heap;
    for(size_t i = 0; i < 50; i++) {
        heap.insert(rand() % 600);
    }
    heap.print();

    for (size_t i = 0; i < 5; i++) {
        std::cout << heap.popMax() << "\n";
        heap.print();
        std::cout << "\n\n\n";
    }

    return 0;
}
