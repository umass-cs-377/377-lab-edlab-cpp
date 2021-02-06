# COMPSCI 377 LAB #1: Inverted Index
Professor Tim Richards

TAs Matthew Gregory, Priyanka Mary Mammen, and Bin Wang

## Purpose
This lab is designed to make you more familiar with C++, the language you will need to program with in this course., and to ensure you are familiar with the Edlab environment. You are expected to already be familiar with essential programming techniques taught in previous classes like CS 187 and CS 220. Each lab in this course is counted as part of your lab grade in this class, which totals to 10% of your final grade.

Please submit your answers to this lab on Gradescope in the assignment marked “Lab #1’. All answers are due by the end of discussion, approximately 50 minutes after it has started. The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade.

## Part 1: Edlab (10 Points)
First, you will need to show that you know how to successfully access the Edlab environment that we will be using for our programming projects this semester. Using a secure shell such as this app for Google Chrome should suffice for the access. Connect to _____@elnux.cs.umass.edu, where the blank space is replaced by your UMass student username (the same one used for SPIRE and Moodle). Click on the ‘SFTP’ option to upload files. After it connects, it should ask you for your password, which you input to log in. If you do not already have a password, please create a new one – the default is set to Edaaabbb, where ‘aaa’ is the last 3 digits of your student ID and ‘bbb’ is the first three letters of your student username.

Once you have successfully logged into Edlab, upload a file named ______.txt where the blank space is replaced with your SPIRE username using the ‘put’ command. Then, use the ‘ls’ command to view the file directory, and attach a screenshot to your solution.

## Part 2: Pointers (20 Points)
When programming in C++, we will frequently make use of pointers. Every variable that we make use of in this class has a memory location, which we can access through the ‘&’ operator. When we have such a memory location, we can then access its stored value through the ‘*’ operator. We use this same operator when declaring our pointers in the code. As an example, take the following code:

```
int main() {

	int original = 1; //variable that stores an integer value of 1
	int *pointer = &one; //variable that stores the memory address of ‘original’

	cout << original; //prints out the stored value of original: “1”
	cout << pointer; //prints out the stored value of pointer (some memory address)
	cout << *pointer; //prints out the stored value of the variable at the location of pointer (original): “1”

	//Question code goes here

	return 1;
}
```

As can be seen in the code, pointers allow for a lot of memory reference to be carried out in C++. We can also combine multiple operators (though it is usually very inefficient to do so). This means that ‘&(*pointer)’ will result in just ‘pointer’, but there could be problems if ‘*(*pointer)’ is called, since that would be looking at the data stored with memory address of ‘*pointer’.

Answer the following questions about pointers, with code referencing the main method written above at the designated line:
1. (3 points) Is ‘*pointer’ equal to ‘&one’?
1. (3 points) Would the code ‘&(*(*(&(&(*(&(*one)))))))’ be able to run?
1. (3 points) Is ‘&pointer’ equal to ‘&(&one)’?
1. (3 points) If the code ‘original = 3’ runs, would the value of ‘*pointer’ change as well? Why or why not?
1. (8 points) Write code that would create a variable named ‘super_pointer’ that stores the memory address for the ‘pointer’ variable.

## Part 3: Maps (20 Points)
In C++, maps are a unique data type that allows for the mapping of one set of keys to a different set of values. An example of using a map is shown below, mapping a few numbers to their respective Pokémon.

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
1. (12 points) Write code that would remove all Pokémon whose name starts with the letter ‘M’. Your solution should be no more than 4 lines long.
