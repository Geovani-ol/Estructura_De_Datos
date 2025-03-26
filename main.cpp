#include "iostream"
#include "queue"    // Colas Simples
#include "deque"    // Colas Bicolas

using namespace std;

int main() {
    cout << "Colas Simples" << endl;

    queue<int> q;     // Colas Simples

    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl << "Colas Bicolas" << endl;

    deque<int> b;

    b.push_front(10);
    b.push_front(20);
    b.push_back(30);
    b.push_back(40);

    for (int i : b) {
        cout << i << " ";
    }

    b.pop_front();
    b.pop_back();

    cout << endl;

    for (int i : b) {
        cout << i << " ";
    }

    return 0;
}
