/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens){
  // cout << "split helper function" << endl;
  
  // if any of them is nullptr just return 
  if(in == nullptr){
    // if (odds!=nullptr) 
    odds->next = nullptr;
    // if (evens!=nullptr) 
    evens->next = nullptr;
    return;
  }
  
  //set two boolean so I can easily use them later
  bool ifEven = in->value % 2 == 0;
  bool ifOdd = !ifEven;

  //cout << in->value << ifEven<< endl;

  if(ifOdd){
    if(odds == nullptr){
        odds = in;
        split(in->next,odds,evens);
    }
    else{ 
      odds->next = in;
      split(in->next,odds->next,evens);
    }
    //cout << "odds " << odds->value << endl;
    
  }

  else if(ifEven){
    if(evens == nullptr){
      evens = in;
      split(in->next,odds,evens);
    }
    else{
      evens->next = in;
      split(in->next,odds,evens->next);
    }
    // cout << "evens " << evens->value << endl;
    
  }
  
}


/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE
