//
// Created by lendys on 11.12.23.
//
#include "HeapException.h"
#include <iostream>
using namespace std;
HeapException::HeapException(int code) {
    m_code = code;
}
void HeapException::print() {
    switch (m_code) {
        case HEAP_OVERFLOW:
        {
            cerr << "Error: Stack is full!!!\n";
            break;
        }
        case HEAP_EMPTY:
        {
            cerr << "Error: Stack is empty!!!\n";
        }
        default:
        {
            cerr << "Error: Unknow error!!!\n";
        }
    }
}