 #include <iostream>
#include <set>

using namespace std;

void print_set(set<int> s) {
    cout << "The elements in the set are:";
    for (auto it=s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    cout << "The size of the set is: " << s.size() << endl << endl;
}

int main() {
    set<int> s;
    cout << "Initial empty set" << endl;
    print_set(s);

    s.insert(10);
    cout << "After inserting 10 into the set" << endl;
    print_set(s);

    s.insert(42);
    cout << "After inserting 42 into the set" << endl;
    print_set(s);

    // insert the same item twice has no effect
    s.insert(42);
    cout << "After insert 42 twice:" << endl;
    print_set(s);

    // Find whether an element is in the set
    if (s.find(42) != s.end()) {
        cout << "42 is in the set" << endl;
    } else {
        cout << "42 is not in the set" << endl;
    }
}
