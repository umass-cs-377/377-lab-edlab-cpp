#include <iostream>
#include <set>

void print_set(std::set<int> s) {
  std::cout << "The elements in the set are:";
  for (auto it=s.begin(); it != s.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
  std::cout << "The size of the set is: " << s.size() << std::endl << std::endl;
}

int main() {
  std::set<int> s;
  std::cout << "Initial empty set" << std::endl;
  print_set(s);

  s.insert(10);
  std::cout << "After inserting 10 into the set" << std::endl;
  print_set(s);

  s.insert(42);
  std::cout << "After inserting 42 into the set" << std::endl;
  print_set(s);

  // insert the same item twice has no effect
  s.insert(42);
  std::cout << "After insert 42 twice:" << std::endl;
  print_set(s);

  // Find whether an element is in the set
  if (s.find(42) != s.end()) {
    std::cout << "42 is in the set" << std::endl;
  } else {
    std::cout << "42 is not in the set" << std::endl;
  }
}
