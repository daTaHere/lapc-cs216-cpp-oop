#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {

    // STACK (LIFO)
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: "
        << st.top()
        << endl;

    st.pop();

    cout << "Stack top after pop: "
        << st.top()
        << endl;

    cout << endl;

    // QUEUE (FIFO)
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue front: "
        << q.front()
        << endl;

    cout << "Queue back: "
        << q.back()
        << endl;

    q.pop();

    cout << "Queue front after pop: "
        << q.front()
        << endl;

    cout << endl;

    // PRIORITY QUEUE
    priority_queue<int> pq;

    pq.push(2);
    pq.push(10);
    pq.push(5);

    cout << "Priority Queue top: "
        << pq.top()
        << endl;

    return 0;
}