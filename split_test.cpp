#include "split.h"
#include<iostream>
#include<cstddef>
using namespace std;



//print function 
void print (Node* head){
    if(head == NULL){
      cout << "NULL" << endl;
      return;
    }
    cout << head->value << "->";
    print(head->next);
  }



int main(){
  //a print function 
  //create a linked list with 1,2,3,4,5
  // Node* listss = new Node(1, new Node(3,  nullptr));
  Node* listss = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))));
  Node* odd_num = NULL;
  Node* even_num = NULL;

  cout << "The complete lists of numbers" << endl;
  print(listss);
  //call the function split 
  split(listss, odd_num, even_num);
  //print the final result 

  //cout << "five next " << five->next->value << endl;

  cout << "odd numbers are: ";
  print(odd_num);
  cout << "even numbers are: ";
  print(even_num);

  Node* temp = odd_num;
  while(odd_num != nullptr){
    temp = odd_num;
    odd_num = odd_num->next;
    delete temp;
  }

  while(even_num != nullptr){
    temp = even_num;
    even_num = even_num->next;
    delete temp;
  }
}