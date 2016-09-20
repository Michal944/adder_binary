#include "counter.hpp"



int main()
{
    Counter test;
    test.put_value();
    change_to_binary(test.value_a, test.bits, test.A);
    change_to_binary(test.value_b, test.bits, test.B);
    test.add_f();
    test.view();

    return 0;
}
