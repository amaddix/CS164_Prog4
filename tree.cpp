//Ashley Maddix
//CS 163, spring 2018, Program 4

//main.cpp
//menu
//save users
//read file

//***tree.cpp***
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

#include "header.h"

//constructor for the trees class, used to initialize the data members in trees
trees::trees ()
{
	root=NULL; 
}

//destructor for the trees class, used to deallocate memory for the data members in trees
trees::~trees()
{
	remove_all(root); // call function to do this recursivly
}

//function to delete all terms (and the terms information) from the tree
int trees::remove_all (node * root)
{
	//return once we reach a leaf
	if (!root)
		return 0;

	remove_all(root->left); // call nodes on left side
	remove_all(root->right); //call nodes on right side

	//clear arrays with terms information	
	root->term.name=NULL;
	root->term.def=NULL;
	root->term.ref=NULL;
	root->term.citation=NULL;

	delete root;  // delete root, set to null
	root=NULL;
}

//wrapper function for the recusrive function to insert
int trees::insert(definition users)
{
	return insert_rec (root, users);
}

//recursive function to insert a term at leaf of tree
int trees::insert_rec(node * & root, definition users)
{
	//if there is nothing in tree, or we are at a leaf
	if(!root)
	{	
		//set as root
		root= new node;
		//copy information to be added into the current root
		root->term.name=users.name;
		root->term.def=users.def;
		root->term.ref=users.ref;
		root->term.citation=users.citation; 

		//set its left and right to NULL
		root->left=root->right=NULL;

		return 1;
	}

	// the term being added is less then the roots term, go left	
	if (strcmp(users.name, root->term.name) < 0)
		insert_rec(root->left, users);

	// the term being added is more then the roots term, go right
	else 
		insert_rec(root->right, users);

}

//wrapper function to call recursive function to remove all terms matching a particular term
int trees:: remove_term (char * match, definition users)
{
	return remove_term_rec (root, match, users);	

}
//recursive function to find all matching terms and delete the following information
int trees::remove_term_rec(node * & root, char * match, definition users)
{

	int count=0; //increase count of terms deleted

	// nothing in list, or at a leaf, return
	if (!root)
		return 0;

	// if a match is found..
	else if (strcmp(root->term.name, match)==0)
	{
		++count; //increase count to show how many matches have been found

		// if the match has no childeren...
		if (!root->left && !root->right)
		{
			delete root;
			root=NULL;
			return 1;
		}
		//if there is a right child but no left child
		else if (!root->left && root->right)
		{
			node * temp=root->right;
			root->term.name= temp->term.name;
			root->term.def= temp->term.def;
			root->term.ref= temp->term.ref;
			root->term.citation= temp->term.citation;

			if (!temp->left)
			{
				root->right=temp->right;

				temp->right=temp->left=NULL;
				delete temp;
			}
			else
			{
				go_left(temp, users);

				temp->term.name= users.name;
				temp->term.def= users.def;
				temp->term.ref= users.ref;
				temp->term.citation= users.citation;
			}				


		}

		//if there is a left child but no righ child
		else if (!root->right && root->left)
		{
			node * temp=root->left;
			root->term.name= temp->term.name;
			root->term.def= temp->term.def;
			root->term.ref= temp->term.ref;
			root->term.citation= temp->term.citation;

			root->right=temp->right;
			root->left=temp->left;

			temp->right=temp->left=NULL;
			delete temp;

		}

		//if there are two childeren
		else if (root->right && root->left)
		{
			node * temp= root->right; //create temp node for pointing
			// to root's right

			//if the roots right has no left...
			if(!temp->left)
			{
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;

				root->right=temp->right;
				temp->right=temp->left=NULL;
				delete temp;
			}

			//otherwise...
			else
			{
				go_left(temp, users);

				root->term.name= users.name;
				root->term.def= users.def;
				root->term.ref= users.ref;
				root->term.citation= users.citation;

			}
		}

	}

	//if match has bee moved to current ...
	if (strcmp(match, root->term.name) ==0)
		count+=remove_term_rec(root, match, users);

	// if the match is less then the roots term name, go left
	if (strcmp(match, root->term.name) <0 && root->left )
		count+=remove_term_rec(root->left, match, users);

	// if the match is more then the roots term name, go right
	if (strcmp(match, root->term.name) >0  && root->right)
		count+=remove_term_rec(root->right, match, users);

	return count; //return number of terms deleted 
}	

//wrapper function to call recursive function to remove all the terms with the matching source
int trees::remove_source ( char *match, definition users)
{
	return remove_source_rec(root, match, users);
}

//recursive function to remove all the terms with the matching source
int trees::remove_source_rec ( node * & root, char * match, definition users)
{
	int count=0; //create variable to keep track of the amount of terms deleted

	if (!root)
		return 0;

	//if we found a term with a matching source
	if (strcmp(root->term.ref, match)==0)
	{
		++count; //increase the count of nodes deleted

		//if the match is a leaf
		if (!root->left && !root->right)
		{
			delete root;
			root=NULL;

			return 0;
		}

		//if the match has a right child but not a left one
		else if (!root->left && root->right)
		{
			node * temp = root->right;

			root->term.name=temp->term.name;
			root->term.def=temp->term.def;
			root->term.ref=temp->term.ref;
			root->term.citation=temp->term.citation;

			//if the term to the right has not term to the left...
			if (!temp->left)
			{
				//set roots right = to roots rights right
				root->right=temp->right;

				//set roots rights right and left to NULL
				temp->right=temp->left=NULL;
				delete temp;
			}

			//if there is a left
			else
			{
				//find in order successor
				go_left(temp, users);

				temp->term.name= users.name;
				temp->term.def= users.def;
				temp->term.ref= users.ref;
				temp->term.citation= users.citation;
			}				


		}

		//if the match has a left child but not a right one
		else if (!root->right && root->left)
		{
			node * temp = root->left;

			root->term.name= temp->term.name;
			root->term.def= temp->term.def;
			root->term.ref= temp->term.ref;
			root->term.citation= temp->term.citation;

			root->right=temp->right;
			root->left=temp->left;

			temp->right=temp->left=NULL;
			delete temp;

		}


		//if the match has two childeren
		else if (root->right && root->left)
		{
			node * temp= root->right; //create a temp node for the matched right

			// if the matches right has no left
			if(!temp->left)
			{
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;
				root->term.name= temp->term.name;

				root->right=temp->right;
				temp->right=temp->left=NULL;
				delete temp;
			}

			//otherwise...
			//else if (temp->right && temp->left)
			else
			{
				go_left(temp, users);

				root->term.name= users.name;
				root->term.def= users.def;
				root->term.ref= users.ref;
				root->term.citation= users.citation;

			}
		}

	}

	// go to the left and then right
	//		if (root->left)
	count+=remove_source_rec(root->left, match, users);

	//		if (root->right)
	count+=remove_source_rec(root->right, match, users);

	if (strcmp(match, root->term.ref) ==0)
		count+=remove_source_rec(root, match, users);

	return count;
}	

//function to find the left most node, used for finding the in order successor
int trees::go_left(node * & root, definition & users)
{

	//return once we've found the left most node
	if (!root)
		return 1;

	//if roots left is null...
	if (!root->left)
	{
		//save info from that nodes term, into user, to be passed back to 
		//remove function
		users.name= root->term.name;
		users.def=root->term.def;
		users.ref=root->term.ref;
		users.citation=root->term.citation;

		//delete node and set to NULL

		node * temp= root;
		root=root->right;

		temp->right=temp->left=NULL;
		delete temp;
		return 1;
	}

	go_left(root->left, users); //go left
}

//wrapper function to call the recursive function to retrieve the matching term
int trees::retrieve (definition & users)
{
	return retrieve_rec(root, users);
}

//recursive function to find the matching term 
int trees::retrieve_rec (node * root, definition & users)
{

	if (!root)
		return 0;

	//if the match was found, save information into users 
	if (strcmp(root->term.name, users.name)==0)
	{
		users.def=new char[strlen(root->term.def)+1];
		strcpy (users.def, root->term.def);

		users.ref=new char[strlen(root->term.ref)+1];
		strcpy (users.ref, root->term.ref);

		users.citation=new char[strlen(root->term.citation)+1];
		strcpy (users.citation, root->term.citation);

		return 1;	
	}

	// if term name searching for is less then the root's term name, go left
	if(strcmp (users.name, root->term.name) < 0)
		retrieve_rec(root->left, users);	

	// if term name searching for is more then the root's term name, go right
	else
		retrieve_rec(root->right, users);	



}

//wrapper function to call the function to display all the terms
int trees::display ()
{
	return display(root);
}

//recursive function to display all the terms in the tree
int trees::display(node * root)
{
	int count=0;
	if(!root)
		return 0;

	//go to the left
	count+=display(root->left);
	//display	

	cout<<endl<<root->term.name<<endl
		<<root->term.def<<endl
		<<root->term.ref<<endl
		<<root->term.citation<<endl<<endl;
		++count;
	//go to the right
	count+=display(root->right);

	return count;

}

// wrapper function to call the recursive function to find the height of the tree
int trees::height ()
{
	return height (root);
}

//recursive function to find the height of the tree
int trees::height (node * root)
{
	int left_height=0; //variable to keep track of the count on the left
	int right_height=0; // variable to keep track of the count of the right

	if (!root) 
		return 0;

	//call left and save the value
	left_height+=height(root->left) +1;
	//call the right and save the value
	right_height+=height(root->right) +1;

	//if the left height is more then the right, return the height from the left
	if(left_height > right_height)
		return left_height;

	//if the right height is more then the left, return the height from the right

	else
		return right_height;
}
