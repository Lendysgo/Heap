//
// Created by lendys on 11.12.23.
//

#ifndef HEAP_HEAPEXCEPTION_H
#define HEAP_HEAPEXCEPTION_H
//Набор допустимых кодов ошибки
#define HEAP_OVERFLOW 0
#define HEAP_EMPTY 1
class HeapException{
    private:
        //Код ошибки
        int m_code;
    public:
        HeapException(int code);
        void print();
};
#endif //HEAP_HEAPEXCEPTION_H
