#ifndef STACK_H
#define STACK_H

/*
 * You will need to implement a stack supporting most of functions std::stack provides.
 * If you are not sure how your implementation should behave, try it yourself with std::stack.
 * Here is reference page of std::stack: http://www.cplusplus.com/reference/stack/stack/
 *
 * Graders will not care how you implement this.
 * Just leave function definitions intact so they can call them.
 */

 int lim = 1e5;

template <typename type>
class Stack {
    // As we said, we do not care if you use these private members.
    // Modify them if you want to.
    //type* _array;
    type* a = new type[lim];
    int sz;
    int stack_sz;
    //int _array_size;
    //int _stack_size;

public:
    // Constructor
    explicit Stack();

    // Destructor
    ~Stack();

    // Store new element
    void push(const type& item);

    // Return first element
    type& top() const;

    // Remove first element
    void pop();

    // Number of elements stored
    int size() const;

    // Return true if empty, false otherwise
    bool empty() const;
};

// Implement functions below

template <typename type>
Stack<type>::Stack() {
    sz = 0;
    stack_sz = lim;
}

template <typename type>
Stack<type>::~Stack() {
    sz = stack_sz = 0;
    delete[] a;
}

template <typename type>
void Stack<type>::push(const type &item) {
    if (sz > stack_sz) {
        type* nw_a = new type[stack_sz + lim];
        for (int i = 0;i <= stack_sz;i ++) nw_a[i] = a[i];
        //memcpy_s (nw_a, a, stack_sz * sizeof (int));
        delete[] a;
        a = nw_a;
        stack_sz += lim;
    }
    a[sz ++] = item;
    //std::cout << sz << ' ' << item << '\n';
}

template <typename type>
type& Stack<type>::top() const {
    return a[sz - 1];
}

template <typename type>
void Stack<type>::pop() {
    if (sz == 0) return;
    sz --;  
}

template <typename type>
int Stack<type>::size() const {
    return sz;
}

template <typename type>
bool Stack<type>::empty() const {
    return (sz == 0);
}

#endif //STACK_H
