#include <iostream>
#include "HeapOfInt.h"
using namespace std;
int main() {
    // Создание объекта кучи
    HeapOfInt heap;

    // Тестирование
    heap.add(15);
    heap.add(5);
    heap.add(10);
    heap.add(5);
    heap.add(1);
    heap.printState();
    cout << "Heap size: " << heap.size() << std::endl;

    while (!heap.isEmpty()) {
        cout << heap.poll() << endl;
        heap.printState();
    }

    cout << "Heap size: " << heap.size() << endl;

    return 0;
}
