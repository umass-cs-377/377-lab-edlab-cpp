# COMPSCI 377 LAB: Edlab, VSCode, and C++

## Purpose

This lab is designed to make you more familiar with C++, the language you will use in combination with C in this course, and to ensure you are familiar with the Edlab environment. You are expected to already be familiar with essential programming techniques taught in previous classes like CS 121 and CS 187.

The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade.

Please read through this lab and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this lab by the assigned due date.

**You may work in groups up to 3 to complete this lab. Make sure you as a group member still submit it individually.**

## Part 0: Connecting to Edlab 

First, you will need to show that you know how to successfully access the Edlab environment that we will be using for our programming projects this semester. The `ssh` and `sftp` programs are available from the command line on Mac, Linux, and Windows. If you are unfamiliar with these programs or forgot how to use them make sure you ask questions so we can help you out. Yes, there are GUI programs for transfering files, but this is a systems course so we frown upon their use in this class!

Connect to _____@elnux.cs.umass.edu, where the blank space is replaced by your UMass student username (the same one used for SPIRE and Moodle). Next, click on the ‘**SFTP**’ button to upload files. Note: The SSH Extension for Chrome can be used for both SSH (remote access) and SFTP (file transfer). Once your shell connects, it should ask you for your EdLab password (NOTE: this is a separate account from your CICS and UMass logins), please type your password to log in. If you do not already have a password, the shell will prompt you to create a new one – your customized default password has been set to `ELaaabbb`, where `aaa` is the last 3 digits of your student ID and `bbb` is the first three letters of your student username. If you do not know your password, please visit [this site](https://elipareset.cs.umass.edu:9443/) to reset your EdLab password. If you still cannot login, please email system@cs.umass.edu to connect with the CICS IT team to resolve your connection/account issue. They are good people.

<!---
The following activity is not assigned anymore. I will keep it here but not shown to the student.
Once you have successfully logged into Edlab, you should see a prompt for sftp, confirming your SFTP connection to elnux. Next, using SFTP, upload a file named `______.txt` where the blank space is replaced with your SPIRE username using the `put` command. Note: `put` can only be used when within sftp. To demonstrate that you have successfully used SFTP to `put` aka upload this file, please take a screenshot of the directory contents by using the command `ls` to list out the files in your current directory. 
-->

Now, let's retrieve the files used in this lab. You may clone this repo using

```bash
git clone https://github.com/umass-cs-377/377-lab-edlab-cpp.git
```

Then you can use `cd` to open the directory you just cloned:

```bash
cd 377-lab-edlab-cpp
```
Alterntive to using git clone, you may download a .zip file of the same lab contents [here, via the class github page](https://github.com/umass-cs-377/377-lab-edlab-cpp/archive/refs/heads/main.zip), and then use SFTP to move the files to EdLab.

This repo includes a Makefile that allows you to locally compile and run all the sample code listed in this tutorial. **You can compile them by running `make`.** Feel free to modify the source files yourself, after making changes you can run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something went wrong during the compilation so that you can start fresh. Reminder: To run the "map" program, use "./map"

## Part 1: Maps

In C++, maps are a data type in the C++ standard library that allows for the mapping of one set of keys to a different set of values. An example of using a map is shown below, mapping a few numbers to their respective Pokémon.

```c++
#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int, string> pokedex;

    pokedex.insert(pair<int, string>(2, "Ivysaur"));
    pokedex.insert(pair<int, string>(5, "Charizard"));
    pokedex.insert(pair<int, string>(6, "Squirtle"));
    pokedex.insert(pair<int, string>(25, "Pikachu"));
    pokedex.insert(pair<int, string>(39, "Jigglypuff"));

    for (auto pokemon = pokedex.begin(); pokemon != pokedex.end(); pokemon ++) {
        cout << pokemon->first << ": " << pokemon->second << endl;
    }

    //Question code goes here
}
```

The code above shows a map created that maps numbers to strings, and uses an iterator to list each number with its respective Pokémon. With this, we can get the values of our map (in this case, Pokémon) by entering their respective keys. As an example, the code `pokedex.at(6)` would return "Squirtle", while the code `pokedex.at(25)` would return "Pikachu". Note that using a key that is not registered in the map will throw an error for the `at` function. Thus, if I ran the code `pokedex.at(152)`, it would throw an error.

We can also use the `map.erase(key)` function to remove a mapping from the object, as long as the key is present in the map already. Using a method such as `map.size()` returns the size of the map being used, which is dynamic depending on the number of elements in the map. Finally, `map.clear()` empties the map entirely and deletes all entries.

## Part 2: Sets 

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

## Part 3: Queues

In C++, queues are FIFO (First-In-First-Out) containers. The only way you can modify elements in a queue is by either

1. putting an element at the end of the queue (using the `push()` method), or
1. removing the element at the front of the queue (using the `pop()` method).

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
