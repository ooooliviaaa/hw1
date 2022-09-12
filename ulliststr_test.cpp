/*Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
// #include <STDDEF.H>
// #include <cstddef>
using namespace std;


int main(int argc, char* argv[])
{
  cout << "case1: push back / front:" << endl;
  //case 1: there is an empty list and I just want to push_back/push_front 
  //tested: output is 11 8 7 9 / 3 
  ULListStr case1;
  case1.push_front("7");
  case1.push_front("8");
  case1.push_back("9");
  case1.push_front("11");
  cout << case1.get(0) << " " << case1.get(1) << " " << case1.get(2) << " " << case1.get(3) << " " << endl;
  cout << "size: " <<case1.size() << endl;  
  
  //case 2: testing push_back, push_front, pop_back/front at the same time 
  cout << "case2: push back/front with pop back/front:" << endl;
  ULListStr case2;
  case2.push_front("10");
  case2.push_front("3");
  case2.push_back("7");
  case2.push_back("hello");
  cout << case2.get(0) << " " << case2.get(1) << " " << case2.get(2) << " " << case2.get(3) << endl;
  cout << "size: " << case2.size() << endl; 
  case2.pop_back();
  cout << "after pop_back: " << endl << case2.get(0) << " " << case2.get(1) << " " << case2.get(2) << endl;
  cout << "size: " << case2.size() << endl; 
  case2.pop_front();
  cout << "after pop_front: " << endl << case2.get(0) << " " << case2.get(1) << endl;
  cout << "size: " << case2.size() << endl; 

  //testing the back/frontfunction 
  cout << "testing back and front function with case2:" << endl;
  cout << "front: " << case2.front() << endl;
  cout << "back: " << case2.back() << endl;

  return 0;
}

