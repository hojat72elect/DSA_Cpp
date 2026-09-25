#include <cassert>
#include <iostream>

#include "Stack.hpp"

int main() {
    Stack<int> sut;
    assert(sut.isEmpty());
    assert(sut.length() ==0);

    sut.push(10);
    sut.push(20);
    assert(!sut.isEmpty());
    assert(sut.length()==2);
    assert(sut.peek()==20);
    assert(sut.pop() == 20);
    assert(sut.pop() == 10);
    assert(sut.isEmpty());

    std::cout << "[PASS] Basic Operations\n";

    return 0;
}
