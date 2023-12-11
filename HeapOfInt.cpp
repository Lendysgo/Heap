//
// Created by lendys on 11.12.23.
//

#include "HeapOfInt.h"
#include "HeapException.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

HeapOfInt::HeapOfInt()
    :HeapOfInt(10)
{}
HeapOfInt::HeapOfInt(int capacity) {
    m_piData = new int [capacity];
    m_iCapacity = capacity;
    m_iSize = 0;
}
HeapOfInt::~HeapOfInt(){
    delete [] m_piData;
}
void HeapOfInt::growTo(int newCapacity) {
    if (newCapacity > m_iCapacity){
        newCapacity = min(newCapacity, 2 * m_iCapacity);
        int* piDataNew = new int[newCapacity];
        int* piDataOLd = m_piData;
        if (piDataOLd != NULL){
            copy(m_piData, m_piData + m_iCapacity, piDataNew);
        }
        m_piData = piDataNew;
        if (piDataOLd != NULL){
            delete [] piDataOLd;
        }
    }
}
bool HeapOfInt::isEmpty() {
    return m_iSize == 0;
}
int HeapOfInt::size() {
    return m_iSize;
}
void HeapOfInt::add(int value) {
    if (m_iSize >= m_iCapacity){
        growTo(m_iSize + 1);
    }
    m_piData[m_iSize] = value;
    m_iSize++;
    flowUp(m_iSize-1);
}
int HeapOfInt::poll() {
    if (m_iSize == 0){
        throw HeapException(HEAP_EMPTY);
    }
    m_iSize--;
    int result = m_piData[0];
    m_piData[0] = m_piData[m_iSize];
    flowDown(0);
    return result;
}
void HeapOfInt::printState() {
    cout << "heap: ";
    for (int i = 0; i < m_iSize ; ++i) {
        cout << m_piData[i] << " ";
        
    }
    cout << endl;
}
void HeapOfInt::flowUp(int index) {
    int value = m_piData[index];
    while (index > 0){
        int parentIdx = (index - 1) / 2;
        if(m_piData[parentIdx] > value){
            m_piData[index] = m_piData[parentIdx];
            index = parentIdx;
        } else{
            break;
        }
    }
    m_piData[index] = value;
}
void HeapOfInt::flowDown(int index) {
    int currentIdx = index;
    while (true){
        int minIdx = currentIdx;
        int childIdx = currentIdx * 2 + 1;
        if(childIdx < m_iSize && m_piData[childIdx] < m_piData[minIdx]){
            minIdx = childIdx;
        }
        childIdx++;
        if (childIdx < m_iSize && m_piData[childIdx] < m_piData[minIdx]){
            minIdx = childIdx;
        }
        if (currentIdx == minIdx)
            break;
        int value = m_piData[currentIdx];
        m_piData[currentIdx] = m_piData[minIdx];
        m_piData[minIdx] = value;

        currentIdx = minIdx;
    }
}

