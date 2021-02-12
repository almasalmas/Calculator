#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"
#include "to_postfix.h"
#include "calculator.h"

int main() {

    // part 1: stack & queue
    Stack<int> s;
    for (int i = 0; i < 8; ++i) {
        s.push(i);
    }
    while (!s.empty()) {
        std::cout << s.top() << " "; // 7 6 5 4 3 2 1 0
        s.pop();
    }
    std::cout << std::endl;

    Queue<int> q;
    for (int i = 0; i < 8; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        std::cout << q.front() << " "; // 0 1 2 3 4 5 6 7
        q.pop();
    }
    std::cout << std::endl;

    // part 2: infix to postfix
    std::string infix("-10-((-2+(2+4*3))-12) + 122 * (123 + (120+888) - 300)");

    std::cout << to_postfix(infix) << std::endl;

    // part 3: calculate
    std::cout << Eval(infix) << std::endl; // 101372

    return 0;
}
