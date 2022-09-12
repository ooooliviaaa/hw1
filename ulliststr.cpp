#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//add new value to the back of the list 
void ULListStr::push_back(const std::string& val){
// 1. this is the condition when it's empty, in this case we need to 
//create a new item to store this val 
  if(empty()){
    Item* addition = new Item();
    //let the val be at the end of the list 
    addition->val[addition->last] = val;
    head_ = addition;
    tail_ = addition;
    //update last because there's value added 
    addition->last++;
  }
  // since first = 0 and last = 10 indicates that 10 elements
  // are occupied 
  else if(tail_->last == 10){
    //create a new tail 
    Item* add_tail = new Item();
    add_tail->val[add_tail->last] = val;
    //therefore the last will be 1
    add_tail->last = 1; // bc there is one value in the item 
    add_tail->prev = tail_;
    tail_->next = add_tail;
    tail_ = add_tail;
  }
  // last and final condition when there is space for adding 
  // value at the back. 
  else{
    tail_->val[tail_->last] = val;
    tail_->last ++;
  }
    size_++;
}

void ULListStr::push_front(const std::string& val){
  if(empty()){
    //if it's empty i create a new item called addition 
    Item* addition = new Item();
    //let the val be at the end of the list 
    addition->val[ARRSIZE-1] = val;
    head_ = addition;
    tail_ = head_;
    //update last because there's value added 
    addition->first = ARRSIZE-1;
    addition->last = ARRSIZE;
  }

  //if there is something at the beginning of the list basically 
  else if(head_->first == 0){
    ////  create a new tail 
    Item* add_head = new Item();
    //then the head should be 9 and last should be 10 because we want to 
    //start from the end of the new item 
    add_head->first = 9;
    add_head->last = 10;
    //assign value 
    add_head->val[add_head->first] = val;
    add_head->next= head_;
    //assign new head_
    head_->prev = add_head;
    head_ = add_head;
  }
  //if there is space for adding one in the front 
  else{
    // std::cout << "Hello there!" <<std::endl;
    head_->val[--head_->first] = val;
    // head_->first--;
  }
  size_++;
}




void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  // if there is only one val in the list in the Item
  else if((head_->last) - (head_->first) == 1){
    //if there is only one item in the list 
    if(head_==tail_){
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
    }
    else{
      Item* temp = new Item();
      temp = head_->next;
      temp->prev = nullptr;
      delete temp->prev;
      head_ = temp;
      size_--;
    }
  }
  // if it's the regular situation 
  else{
    //the last of the tail i will just make it less one 
    head_->first++;
    size_--;
  }
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  // if there is only one Item in the list 
  //and there is one item in the item 
  else if((tail_->last) - (tail_->first) == 1){
    //when there is one item in the list 
    if(head_==tail_){
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
    }
    //when it's not the only item in the list 
    else{
      Item* temp = new Item();
      temp = tail_->prev;
      temp->next = nullptr;
      delete temp->next;
      tail_ = temp;
      size_--;
    }
  }
  // if it's the regular situation 
  else{
    //the last of the tail i will just make it less one 
    tail_->last--;
    size_--;
  }
}


std::string const & ULListStr::front() const{
  return head_->val[head_->first]; 
}


std::string const & ULListStr::back() const{
  return tail_->val[--tail_->last]; 
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  //base case: when the value it gives me is smaller than 0 or it's more than the indexes I have 
  if(loc < 0 || loc >= size_){
    return NULL;
  }
  // normal situation 
  Item* curr = head_; 
  size_t index_ = head_->first;
  //for loop through to see if i need to go to the next item 
  for(size_t i = 0; i < loc; i++){
    if(index_ == head_->last-1){
      curr = curr->next;
      index_ = curr->first;
    }
    else{
      index_++;
    }
  }
  return &curr->val[index_];
}