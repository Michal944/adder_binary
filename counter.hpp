#ifndef _COUNTER_HPP
#define _COUNTER_HPP
#include <iostream>
#include <vector>




typedef unsigned short US;

void change_to_binary(const int &value,
                      const US &bitX,
                      std::vector<US> &vec);

class Counter
{
    public:
    std::vector<US> A;
    std::vector<US> B;
    std::vector<US> VALUE;
    int value_a, value_b;
    US bits;
    Counter();
    ~Counter();

    void put_value();
    void view();
    void add_f();
};


#endif
