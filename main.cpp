//Ashley Maddix
//CS 163, spring 2018, Program 4

//***main.cpp***
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

#include "header.h"

int main ()
{
	trees tree; //create an instance of the class trees
	definition users; //create an instance of the definition stuct
	char * match; //a pointer to a char array to get a particular value from user
	char choice='0'; // variable to get the users choice of action
	int worked=0; //variable to save returned values from called functions

	do
	{

		worked=menu(); //call function to display possible actions to user

		//if user wants to add a pre existing list from a file	
		if(worked == '1')
		{
		 	worked=read_file(users, tree); //call function 
			//output error or success message
			if(worked)
				cout<<"***successfully opened file***"<<endl;
			else
				cout<<"***Looked like we could not open your file***"<<endl;
		}
		
		//if user wants to add their own terms to the list	
		if(worked == '2')
		{
			//call function to prompt users for information
			worked=save_users (users);
			//call function to insert into list
			worked=tree.insert(users);
		
			if(worked)
				cout<<"***successfully added to list***"<<endl;
			else
				cout<<"***Looks like there was problems adding that term***"<<endl;
		}

		//if user wants to delete all terms matching a particular one
		if(worked == '3')
		{
			char temp [100]; //create temp array to save initial responce
			cout<<"term name?? "<<endl;
			cin.get(temp, 100, '\n');
			cin.ignore(100, '\n');

			match= new char[strlen(temp)+1]; //allocate memory for match of size temp
			strcpy (match, temp); // copy temp into match
			
			worked=tree.remove_term(match, users); //call function to remove the terms

			if(worked)
				cout<<"***successfully deleted "<<worked<<" instances of "
				<<match<<" from list***"<<endl;
			else
				cout<<"***Looks like there was no matching terms in "
				<<"your list***"<<endl;

		}

		//is user wants to delete all terms matching a particular source
		if(worked == '4')
		{
			char temp [100]; //create temp array to save inital responce
			cout<<"source name?? "<<endl;
			cin.get(temp, 100, '\n');
			cin.ignore(100, '\n');

			match= new char[strlen(temp)+1]; //allocate memory for match of size temp
			strcpy (match, temp); //copy temp into match
			
			worked= tree.remove_source (match, users); //call function to remove source
	
			if(worked)
				cout<<"***successfully deleted "<<worked<<" instances of "
				<<match<<" from list***"<<endl;
			else
				cout<<"***Looks like there was no matching terms in "
				<<"your list***"<<endl;
	
			
		}

		//is user wants to out put information on a particular term
		if(worked == '5')
		{ 
			char temp [100]; //create a temp array to save inital responce
			cout<<"term name?? "<<endl;
			cin.get(temp, 100, '\n');
			cin.ignore(100, '\n');

			users.name= new char[strlen(temp)+1]; //allocate memory for users.name
			//of size temp
			strcpy (users.name, temp); // copy temp into users.name
			worked = tree.retrieve(users); //call function to retrieve the rest
		
			if (worked)
				cout<<users.name<<" : "<<users.def<<" : "<<users.ref<<" : "<<users.citation<<endl;
				//output the information following the matching term
			else
				cout<<"***Looks like there were no matching terms in your list***"
				<<endl;			

		}


		//if user wants to output all terms in list
		if(worked == '6')
		{
			cout<<"*** All CS definition terms in list ***"<<endl;
			worked=tree.display (); //call function to display terms
			//output success or error message
			if (worked)
				cout<<"***Displayed "<<worked<<" items***"<<endl;	
			if (!worked)
				cout<<"***looks like there was nothing in your list***"<<endl;
				
		}

		//if user wants to know the height of tree
		if (worked =='7')
		{
			worked= tree.height (); //call function to find the height of the tree
			// output success or failure messages
			if (worked)
				cout<<"***The height of your tree is "<<worked<<"***"<<endl;
			else
				cout<<"***Looks like there is nothing in your list***"<<endl;
		}

	}while (worked != '8');
}

//function to display the possible actions a use can take, and read in their responce
char menu ()
{
        char choose='0';

        cout<<endl<<endl<<endl;
        cout<<" Please choose an action you want the program to preform"<<endl<<endl
                <<"1.	add definition terms from an exisiting file."<<endl
                <<"2.	add a new definition term."<<endl
		<<"3.	remove all the information on a particular term"<<endl
                <<"4.	remove all the terms given by a particular source"<<endl
		<<"5.	display information on a particular term"<<endl
                <<"6.	display all terms in list"<<endl
		<<"7.	find the height of the tree"<<endl
                <<"8.	quit"<<endl<<endl<<endl;

        cin>>choose;
        cin.ignore (100, '\n');

        //return value choosen by user  
        return choose;
}

//function to read in the term information from the user
int save_users (definition & users)
{
        char temp[500]; // temp array to store users initial responce

        //prompt for term
        cout<<"what is the term you are adding?"<<endl;

        cin.get(temp, 500, '\n');
        cin.ignore(100, '\n');

        //allocate memory fro users.name of size temp +1
        users.name= new char[strlen(temp)+1];
        //copy temp into users.name
        strcpy (users.name, temp);
        //###########################################//
        //continue same routine as ^ for rest of definition info
        cout<<"what is the definition for "<<users.name<<" ?"<<endl;

        cin.get(temp, 500, '\n');
        cin.ignore(100, '\n');

        users.def= new char[strlen(temp)+1];
        strcpy (users.def, temp);
        //###########################################//
        cout<<"what is the source for this definition of "<<users.name<<" ?"<<endl;

        cin.get(temp, 500, '\n');
        cin.ignore(100, '\n');

        users.ref= new char[strlen(temp)+1];
        strcpy (users.ref, temp);
        //###########################################//
        cout<<"what is the citation for this source ?"<<endl;

        cin.get(temp, 500, '\n');
        cin.ignore(100, '\n');

        users.citation= new char[strlen(temp)+1];
        strcpy (users.citation, temp);
}

//function to read in a file and insert that information into the BST
int read_file(definition & users, trees & tree)
{
        char temp[500]; //temp variable to read in users initail info

        ifstream read_in; //create a variable of ifstream to read in info from a file

        read_in.open("CS_terms.txt"); //using var to read in, open file

        //return if we could not open file      
        if (!read_in)
                return 0;
        //otherwise...
        else
        {
                //read in the first past of definition (the term)
                read_in.get(temp, 500, '|');
                read_in.ignore (500, '|');

                //allocate memory for users.name of that length
                users.name= new char[strlen(temp)+1];
                //copy temp into users.name
                strcpy (users.name, temp);

                //while we have not reached the end of file...
                while(!read_in.eof())
                {

                        //read in the next section of the definition ( the actual
                        // definition)
                        read_in.get(temp, 500, '|');
                        read_in.ignore (500, '|');

                        //allocate memory for users.def
                        users.def= new char[strlen(temp)+1];
                        strcpy (users.def, temp);

                        //read in next section of definition (the source)       
                        read_in.get(temp, 500, '|');
                        read_in.ignore (500, '|');

                        users.ref= new char[strlen(temp)+1];
                        strcpy (users.ref, temp);

                        //read in the last section of definition (the citation) 
                        read_in.get(temp, 500, '\n');
                        read_in.ignore (500, '\n');

                        users.citation= new char[strlen(temp)+1];
                        strcpy (users.citation, temp);

                        //call function to add the last term read in by user in
                        //the BST
			tree.insert (users);

                        //read in the next term from our file   
                        read_in.get(temp, 500, '|');
                        read_in.ignore (500, '|');

                        users.name= new char[strlen(temp)+1];
                        strcpy (users.name, temp);
                }
                //close file
                read_in.close();
        }
}	
