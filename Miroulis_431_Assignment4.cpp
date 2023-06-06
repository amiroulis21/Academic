/*This program queries the user for the name of a file
  and then reads the words from the file into two lists.
  One list contains all the words starting with 'd'. (onlyD)
  The other list contains all other words (notD). Both lists are
  sorted alphabetically and there are no repeated words. 
  Both lists keeps track of how many times a word has appeared.
  The program will display each word and word count of the onlyD
  list first, then it will do the same for notD, then it will terminate.
  Written in C++
  Written by Andrew Miroulis
  4/14/23 */
	
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
/* The WordNode and WordList classes are used to create a linked list.
   The structure of both classes was heavily inspired by the code used here:
   https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
   Written by Andrew Miroulis + the help of the link above
   Written in C++
   4/14/23*/


class WordNode {
    public:
	string word;
	int count;
	WordNode *next;

	WordNode() {
	    word = "";
	    count = 1;
	    next = NULL;
	}

	WordNode(string w) {
	    this->word = w;
	    count = 1;
	    this->next = NULL;
	}
	
};

class WordList {
    public:
	
	WordNode *head;
	
	WordList() {
	    head = NULL;
	}
	
	
	void insert(string);
	void printList();
	int isDuplicate(string);
};

	void WordList::insert(string word) {
	/* This method inserts a WordNode into the list 
         in the correct alphabetical position
	   Written by Andrew MIroulis
	   Written in C++
	   4/14/23 */

	WordNode *node = new WordNode(word);
	
	if(head == NULL) {
	    head = node;
	   
	    return;
	}
	WordNode *previous;
	WordNode *temp = head;

	    while(temp != NULL){  
		if(word.compare(temp->word) == 1) {
		 
		    previous = temp;
		    temp = temp->next;
		   
            }
		else if(word.compare(temp->word) < 0) {
		    
			 if(temp == head) {
				head = node;
				head->next = temp;
			  }
			  else{
			  previous->next = node;
			  node->next = temp;
			 
		    	  }
			 
			  return;
		}
	  
	    }
	    
	    previous->next = node;
	    return;
    }
	  

	void WordList::printList() {
      /* The method prints the word and count of each
         WordNode in the WordList on a seperate line. 
	   It ends with a new line.
         Written by Andrew Miroulis
         Written in C++
         4/14/23 */

	    if(this->head == NULL) {
		cout << "NULL";
		return;
	    }
	   
		WordNode *temp = head;
		
		while(temp != NULL) {
		    cout << temp->word << " " << temp->count << "\n";
		    temp = temp->next;
		}
		cout << "\n";
		return;
		
	   
	}
	
	int WordList::isDuplicate(string s) {
	/* This method checks if the string s is a word
         already contained in this WordList. If yes, 
	   it updates the count of that WordNode and returns 1 (meaning true).
         If no, it simply returns 0 (meaning false).
	   Written by Andrew Miroulis
	   Written in C++
         4/14/23 */

		WordNode *node = head;
		
		while(node != NULL) {
		    if(!s.compare(node->word)) {
			 node->count++;
		       return 1;
		    }
		    node = node->next;
		}
	
		return 0;
	}




int main() {
/* This is the driver function. It queries the user for the
   name of a text file, and if the file exists, then it reads each
   word in the file and inserts each unique word into either the onlyD list
   or the notD list, depending on if the word starts with 'd'. After the end
   of the file is reached, it call printList() for each list. If the file the
   user entered does not exist, then "No such file exists" is printed, and the 
   program terminates.
   Written by Andrew Miroulis
   Written in C++
   4/14/23 */
    string fileName;
    string word;
    WordList onlyD;
    WordList notD;


    cout << "Enter the name of a text file (make sure it ends with \".txt\")";
    cin >> fileName;
    ifstream f(fileName);
    
    if(!f) {
	cout << "No such file exists.";
	
    }
    else{
        while(!f.eof()) {
	      f >> word;
		if (word[0] == 'd' || word[0] == 'D') {
		    if(!onlyD.isDuplicate(word)) {
			onlyD.insert(word); 
	
		    }
			
		}
		else  {
		    if(!notD.isDuplicate(word)) {
			notD.insert(word); 
		    }
			
		}
	
	  }
	   cout << "\nAll words that start with \"d\":\n";
	   onlyD.printList();
	   cout << "All other words:\n";
	   notD.printList();
    }
}
	
    

	

