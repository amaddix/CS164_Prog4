//Ashley Maddix
//CS 163, spring 2018, Program 4

//main.cpp
//menu
//save users
//read file

//tree.cpp
//constructor
//desturctor
//delete all
//insert wrapper
//insert recursive
// remove term wrapper
//remove term recursion
//remove source wrapper
//remove source recusrion
//go left
//retrieve wrapper
//retrieve recursion
//display wrapper
//display recursion
//height wrapper
//height recusrsion

#include <iostream>
#include <fstream> 
#include <cstring>
#include <cctype> 

using namespace std;


// struct for all the information that goes into a 'definition'
struct definition
{
        char * name;
        char * def;
        char * ref;
        char * citation;
};

struct node
{
        //pointer to type definition
        definition term;
        //pointer to the next pointer in the list
        node * left; //pointer to left child
        node * right; //pointer to right child
};

//class for our bianary search tree
class trees
{
	public:
		trees (); //constructor to initiallize the data members
		~trees(); //destructore to deallocate memory for data members

		int insert(definition users); // wrapper function to call recusrsive 
		//insert function

		int remove_term (char * match, definition users); //wrapper function to call
		//recursive remove term function
		int remove_source ( char *match, definition users);// wrapper function to call 
		//recursive remove source function

		int retrieve (definition & users); // wrapper function to call recursive
		//retrieve function
		int display (); //wrapper function to call recusrsive display function
		int height (); //wrapper function to call recursive heigh function
	private:
		node * root; // pointer of type node to the 'root' of our tree 

		int remove_all (node * root); // recursive function to be called by destructor
		// to delete all nodes in tree

		int insert_rec(node * & root, definition to_add); // recursive function to
		// to insert a term at the leaf of a tree

		int remove_term_rec(node * & root, char * match, definition users);
		// recursive function to remove all the information following a matching term name
		int remove_source_rec ( node * & root, char * match, definition users);
		// recursive function to remove all the information following a matching term source
		int go_left(node * & root, definition & users); //function to be called from 
		// the remove functions to be for when the match has two leafs (used to find the
		//in order successor)
		
		int retrieve_rec (node * root, definition & users); //recursive function to find
		// and save the information matching a term
		int display(node * root); //recursive function to display each term in the tree
		int height (node * root); // recursive function to count the height of tree
};

char menu (); 
//function to display the possible actions a use can take, and read in their responce
int save_users (definition & users);
//function to read in the term information from the user
int read_file(definition & users, trees & tree);
//function to read in a file and insert that information into the BST
