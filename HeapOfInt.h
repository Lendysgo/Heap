//
// Created by lendys on 11.12.23.
//

#ifndef HEAP_HEAPOFINT_H
#define HEAP_HEAPOFINT_H


class HeapOfInt {
private:
    int* m_piData;
    int m_iCapacity;
    int m_iSize;
public:
    HeapOfInt();
    HeapOfInt(int capacity);
    virtual ~HeapOfInt();
    bool isEmpty();
    int size();
    void add(int value);
    int poll();
    void printState();
private:
    void growTo(int newSize);
    void flowUp(int index);
    void flowDown(int index);
};


#endif //HEAP_HEAPOFINT_H
