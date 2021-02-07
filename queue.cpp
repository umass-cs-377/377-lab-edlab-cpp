#include <iostream>
#include <queue>

int main() {
  std::queue<int> q;

  for (int i = 0; i < 10; i++) {
    q.push(i);
  }

  while(!q.empty()) {
    // Note that the pop() method only removes the first element but doesn not return it.
    // You need to get the first element using the front() method.
    std::cout << q.front() << std::endl;
    q.pop();
  }
}
