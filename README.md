# CS164_Prog4

Programming Assignment #4 
CS 163 Data Structures 
Submit your assignment to the D2L Dropbox (sign on via d2l.pdx.edu)



Programming – Goal: The goal of this program is to create a binary search tree (BST) and to implement the BST algorithms recursively. 
Background: The advantage of a binary search tree is the ability to retrieve our  data using a logarithmic performance assuming that the tree is relatively balanced  and be able to search for a range of information and obtain our data in sorted  order. In program #4 we will experience all of these characteristics. We will use  the same data as program #3 except that instead of using a hash table, we will  implement a binary search tree. PLEASE NOTE – we are REPLACING the  concept of a hash table with a binary search tree when moving from program  #3 to program #4. 
Specifics: In Program #4 we will use a BST to search for a CS term. We will also  now be able to display all of the terms in sorted order!. You will be basing this  program off of the same data as in program #3 but now using a DIFFERENT  data structure! We are moving away from hash tables and learning about BSTs. 
The use of external data files is now optional, but recommended. 
The information that we want to keep track of includes: 
1. Term (e.g., Hash Function) 
2. Definition (e.g., “A hash function is any function that can be used to map data of  arbitrary size to data of fixed size.” 
3. Reference information - where you found this information (e.g.,Wikipedia) 4. Citation - a citation could be a textbook or a website (e.g.,  https://en.wikipedia.org/wiki/Hash_function) 
The ADT operations that must be performed on this data are: 1) Constructor – initialize all data members 
2) Destructor – deallocate (release) all dynamic memory and reset the data  members to their zero equivalent value; this should call a recursive function  that performs postorder traversal (recursively) to deallocate all data and nodes. 
3) Insert a new location, using the CS term for the BST algorithm.  4) Remove all information about a CS term 
5) Remove all CS terms that were found from a particular source (e.g.,Wikipedia) 6) Retrieve the information about a particular CS term 
a. Remember, retrieve is NOT a display function and should supply  the matching information back to the calling routine through the 
CS163 Spring 2018 Assignment #4 
argument list. 
7) Display all CS terms (displayed alphabetically!). 
8) Height – supply the height back to the calling routine. 
Data Structures: Write a C++ program that implements a binary search tree. The  binary search tree should be a non-linear implementation (using left and right  pointers). The underlying data may be stored as a struct or class. 
Evaluate the performance of storing and retrieving items from this tree. Monitor  the height of the tree and determine how that relates to the number of items. If the  number of items is 100 and the height is 90, we know that we do not have a  relatively balanced tree!! Use the information from the Carrano reading to assist  in determine if we have a reasonable tree, or not. Your efficiency write up must  discuss what you have discovered.  
Things you should know...as part of your program: 
1) Do not use statically allocated arrays in your classes or structures. All  memory must be dynamically allocated and kept to a minimum!  2) All data members in a class must be private 
3) Never perform input operations from your class in CS163 
4) Global variables are not allowed in CS163 
5) Do not use the String class! (use arrays of characters instead and the cstring  library!) 
6) Use modular design, separating the .h files from the .cpp files. Remember, .h  files should contain the class header and any necessary prototypes. The .cpp  files should contain function definitions. You must have at least 1 .h file and  2 .cpp files. Never "#include" .cpp files! 
7) Use the iostream library for all I/O; do not use stdio.h. 
8) Make sure to define a constructor and destructor for your class. Your  destructor must deallocate all dynamically allocated memory.
-------------------------------------------------------------------------


What functions your ADT will need to have
The abstract data type of this function will be a binary search tree. For this abstract data type, it will need 6 functions (not including the constructor and destructor) to complete the tasks required of this program.
It will need an insert function to add a new term onto the list of terms. To do this, it will need to recursively go through each node of the trees until it has found its proper placement. First checking if the root’s not is smaller or larger than the data being added ( going left if it is larger, and right if the root is smaller). 
It will also need a function to remove all the information on a certain CS term added in by user (and passed from client program into function). My program will recursively search through each node in tree, only stopping if it has found a matching term name to the one passed in. Once it has found a match, it will check if the node that term is placed in has 0, 1, or 2 children. Depending on that number it will perform a different algorithm for deleting the information in that node and connecting the nodes up around it. 
I will also have a similar node to delete all the information attached to a particular source. This function will basically follow the same algorithm as the one to delete all information attached to a CS term. The only difference being that it will be looking for the source, not term name.
It will also have a retrieve function to retrieve information on a particular CS term and save that information into a struct variable to be passed back to the client program. This function will be passed a term that the user would want to retrieve (sent through the client program), and search through the tree until it has found the first instance of this term. Then the program will copy this information and store it into the struct variable.
This function will also have a ‘display all’ function to go through each node of the tree ( in _______ order), and output each member of information from the struct data member. It will continue doing this until it has reached the end.
The last function that will be implemented in this function will be to find the height of the tree. It will call the left side of the tree, increase the count, and save that into a counter variable for the left side. Then it will call the right side of the program, increase the counter and save that into a variable counter for the right side of the program. It will lastly compare these two counts, and the larger of the two will be returned back as the height of the tree. 
How each function will report success/failure back to the calling routine
Each function will have 1+ return statement to keep send back a value ( either 0 or not 0) to the client program. The Client program can then use this value to sent back error/ success messages back to the user.

How each function will shield the client program from the details of the data structure
All the data members used in my abstract data type (specific to my data structure) will be in the private section of my abstract data type class. This way the client won't have access to them, and I won't use any function calls within my client program that call these data members. 

What data structures you will be using and how each of the special cases. Consider drawing pointer diagrams with “before” and “after” diagrams for each special case
I will be using a node, with a struct data type ( which will contain the information on the CS term), and it will have two node pointers. One will be pointing to the ‘left’ of that node, and the other will be pointing to the ‘right’ of that node. Their are special cases that apply when deleting a node with 2 children. Because this would involve a replacement, and some sort of swapping of children/ parent relationship. 

EFFICIENCY WRITE UP 

How well did the data structure selected perform for the assigned application?
I think for the purpose of this program, using a node with two pointers for the data structure of my tree works well.  This makes it easy to determine which pointer to traverse to. If the data being added or the match in trying to find is less then the current roots data, then I would traverse left, otherwise I would traverse right. 
Would a different data structure work better? If so, which one and why…
Although the way my text file was listed resulted in a pretty well balanced binary search tree, If that information has been sorted differently (like already sorted in alphabetical order), the use of a 2-3 tree or 2-3-4 tree would prove to be much more efficient. Because in this case a binary search tree my data would all just go to the right of each node, creating a linear linked list and defeating the purpose and efficiency of this abstract data type. With a 2-3 tree or 2-3-4 tree, my tree would be guaranteed to always be full and balanced. 
What was efficient about your design and use of the data structure?
When adding a term to my list, and searching for a matching term name ( which my tree was sorted by term names), I would look at the current roots term name, and determine if the information being added or information looking for was either less or more then that data. In the case that it is less, then I would call the function to the left. And only call the function to the right if my the information is more or equal to the data or the current root. This means that I will only be traversing through my tree the amount needed to find my match or add to a leaf. 
In addition, the way my text file was sorted made my programs binary search tree pretty well balanced. Being that I have 100 definition terms in my tree, and the height is 10, it seems like my tree would be balanced well, and potentially also full. 
What was not efficient?
For my remove source function, since my terms were sorted by name and not source, I had to traverse to each node in my tree in order to find all occurrences of the match. This is much less efficient then the remove term function which only has to traverse in the direction that the match is supposed to be, avoiding traversing through a lot of unnecessary nodes. 
As stated earlier, if my text file was already in a sorted order, then all the terms would just be added to the right of the previous on, creating a linear linked list. So depending on the order of the information being added, this may not be the most efficient way to add information. Had my program been implemented like a 2-3 tree or a 2-3-4 tree, then all my information would be more likely to be sorted in a more efficient tree format. 
What would you do differently if you had more time to solve the problem?
As of the time that I am writing this (and unless I was able to fix it by the time i turned it in, it still might be), my remove all terms function and remove all source function were not removing like they were initially intended.  In some cases, not all matches are deleted from my list, leaving a few matching terms or sources remaining. In addition to this, sometimes when going through and deleting terms, my function does not properly link the surrounding terms back up. This leads to unintended nodes being delete from my program. If I had more time, I would spend it fixing these two functions so they worked properly.
