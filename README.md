# COMPSCI 377 LAB #1: Inverted Index

## Purpose
This lab is designed to make you more familiar with C++, the language you will use in combination with C in this course., and to ensure you are familiar with the Edlab environment. You are expected to already be familiar with essential programming techniques taught in previous classes like CS 121 and CS 187.

Please submit your answers to this lab on Gradescope in the assignment marked **Lab #1: Inverted Index**. Please see Gradescope for the due dates. The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade.

## Part 1: Edlab (10 Points)
First, you will need to show that you know how to successfully access the Edlab environment that we will be using for our programming projects this semester. Using a secure shell such as [this extension](https://chrome.google.com/webstore/detail/secure-shell/iodihamcpbpeioajjeobimgagajmlibd) for Google Chrome should suffice for the access. Connect to _____@elnux.cs.umass.edu, where the blank space is replaced by your UMass student username (the same one used for SPIRE and Moodle). Click on the ‘SFTP’ option to upload files. After it connects, it should ask you for your password, which you input to log in. If you do not already have a password, please create a new one – the default is set to ELaaabbb, where ‘aaa’ is the last 3 digits of your student ID and ‘bbb’ is the first three letters of your student username.

Once you have successfully logged into Edlab, upload a file named ______.txt where the blank space is replaced with your SPIRE username using the ‘put’ command. Then, use the ‘ls’ command to view the file directory, and attach a screenshot to your solution.

## Part 2: Maps (20 Points)
In C++, maps are a data type in the C++ standard library that allows for the mapping of one set of keys to a different set of values. An example of using a map is shown below, mapping a few numbers to their respective Pokémon.

```
int main(){

	map<int, string> pokedex;

	pokedex.insert(pair<int, string>(2, “Ivysaur”));
	pokedex.insert(pair<int, string>(5, “Charizard”));
	pokedex.insert(pair<int, string>(6, “Squirtle”));
	pokedex.insert(pair<int, string>(25, “Pikachu”));
	pokedex.insert(pair<int, string>(39, “Jigglypuff”));

	for (pokemon = pokedex.begin(); pokemon != pokedex.end(); pokemon ++) {
		cout << pokemon->first << ‘: ‘ << pokemon->second << ‘\n’
	}

	//Question code goes here

	return 151;
}

```

The code above shows a map created that maps numbers to strings, and uses an iterator to list each number with its respective Pokémon. With this, we can get the values of our map (in this case, Pokémon) by entering their respective keys. As an example, the code ‘pokedex.at(6)’ would return “Squirtle”, while the code ‘pokedex.at(25)’ would return “Pikachu”. Note that using a key that is not registered in the map will throw an error for the ‘at’ function. Thus, if I ran the code ‘pokedex.at(152)’, it would throw an error.

We can also use the map.delete(key) function to remove a mapping from the object, as long as the key is present in the map already. Using a command like map.size() returns the size of the map being used, which is dynamic depending on the number of elements in the map. Finally, map.clear() empties the map entirely and deletes all entries.

Answer the following questions about maps, with code referencing the main method written above at the designated line:
1. (2 points) Would ‘pokedex.insert(pair<int, string>(“Mew”, 151));’ run properly?
1. (2 points) What is the maximum size of a map? (HINT: there is one)
1. (2 points) If the code map.clear() was run, what would map.size() return?
1. (2 points) Consider the following code. Would its printed output be equal to “Charizard”?
```
	string temp = pokedex.at(5);
	pokedex.delete(5);
	cout << temp;
```
5. (12 points) Write code that would remove all Pokémon whose name starts with the letter ‘M’. Your solution should be no more than 6 lines long.

## Part 3: Sets

In C++, sets are containers that store unique elements (like sets in discrete math). One important
property of sets is that if you try to insert an element that is already in a set, the state of the
set will not change. The following code shows how to

* Create an empty set.
* Add element to the set using the `insert()` method.
* Iterate through the elements of a set.
* Check whether a specific element is in the set.

```c++
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
```

[Run the code yourself on Repl.it](https://repl.it/@wkk/cs377-lab1-set).

## Part 4: Queues

In C++, queues are FIFO (First-In-First-Out) containers. The only way you can modify elements in a
queue is by either 1) putting an element at the end of the queue (using the `push()` method), or 2)
removing the element at the front of the queue (using the `pop()` method).

The following code shows how to use `push()` and `pop()`.

```c++
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
```

[Run the code yourself on Repl.it](https://repl.it/@wkk/cs377-lab1-queue).
