#ifndef QUEUE_H
#define QUEUE_H

/*
 * You will need to implement a queue supporting most of functions std::queue provides.
 * If you are not sure how your implementation should behave, try it yourself with std::queue.
 * Here is reference page of std::queue: http://www.cplusplus.com/reference/queue/queue/
 *
 * Graders will not care how you implement this.
 * Just leave function definitions intact so they can call them.
 */

template <typename type>
class Queue {
    // As we said, we do not care if you use these private members.
    // Modify them if you want to.
    type* a = new type[lim];
    int leftt;
    int rightt;
    int queue_sz;

public:
    // Constructor
    explicit Queue();

    // Destructor
    ~Queue();

    // Store new element
    void push(const type& item);

    // Return first element
    type& front() const;

    // Remove first element
    void pop();

    // Number of elements stored
    int size() const;

    // Return true if empty, false otherwise
    bool empty() const;
};

// Implement functions below

template <typename type>
Queue<type>::Queue() {
    queue_sz = lim;
    leftt = 0;
    rightt = 0;
}

template <typename type>
Queue<type>::~Queue() {
    queue_sz = leftt = rightt = 0;
    delete[] a;
}

template <typename type>
void Queue<type>::push(const type &item) {
    if (rightt > queue_sz) {
        type* nw_a = new type[queue_sz + lim];
        for (int i = 0;i <= queue_sz;i ++) nw_a[i] = a[i];
        delete[] a;
        a = nw_a;
        queue_sz += lim;
    }
    a[rightt ++] = item;
    //std::cout << rightt << ' ' << item << '\n';
}

template <typename type>
type& Queue<type>::front() const {
    //std::cout << leftt << '\n';
    return a[leftt];
}

template <typename type>
void Queue<type>::pop() {
    if (leftt == rightt) return;
    leftt ++;
}

template <typename type>
int Queue<type>::size() const {
    return (rightt - leftt);
}

template <typename type>
bool Queue<type>::empty() const {
    //std::cout << leftt << ' ' << rightt << '\n';
    return ((rightt - leftt) == 0);
}

#endif //QUEUE_H
