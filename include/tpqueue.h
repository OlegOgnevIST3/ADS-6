// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T* arr;
    uint64_t x, y, k;

 public:
    TPQueue(): x(0), y(0), k(0) {
        arr = new T[size];
    }
    bool full() const {
        return k == size;
    }
    bool empt() const {
        return k == 0;
    }
    void push(const T& val) {
        if (full()) {
            throw std::string("full");
        } else {
            k++;
            int id = l;
            for (int i = x; i < y; i++) {
                if (arr[i].prior < val.prior) {
                    id = i;
                    break;
                }
            }
            for (int i = y; i > id; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[id % size] = val;
            y++;
        }
    }
    T& pop() {
        if (empt())
            throw std::string("empty");
        k--;
        return arr[x++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
