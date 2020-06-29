#include <iostream>
#include <vector>
#include <cassert>
#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue(){
}
bool PriorityQueue::enqueue(const ItemType & newEntry){
	heap.push_back(newEntry);
	ItemType tmp;
	int i=heap.size()-1;
	while(i>=0){
		if(heap.at(i)<heap.at((i-1)/2)){
			tmp=heap.at(i);
			heap.at(i)=heap.at((i-1)/2);
			heap.at((i-1)/2)=tmp;
			i=(i-1)/2;
			}
		else{
			return true;	
		}
	}
	return true;
} 
bool PriorityQueue::isEmpty() const{

	if(heap.size()==0){
		return true;
	}
	else{
		return false;
	}
}

int PriorityQueue::length() const {
	return heap.size();
}

ItemType  PriorityQueue::front() const{
	assert(heap.size()>0);
	return heap.at(0);
	

}
bool PriorityQueue::dequeue(){
	heap.at(0)=heap.at(heap.size()-1);
	heap.pop_back();
	ItemType tmp;
	int i=0;
	while(i< heap.size()){
		if(i==0){
			if(heap.at(i)>heap.at(2 *  i  + 2)){
				tmp=heap.at(i);
				heap.at(i)=heap.at((i-1)/2);
				heap.at((i-1)/2)=tmp;
				i=(2 *  i)  + 2;
				}
			else return true;	
		}
		else{
			if(heap.at(i)>heap.at(2 *  i  + 1)){
				tmp=heap.at(i);
				heap.at(i)=heap.at(2 *  i  + 1);
				heap.at((i-1)/2)=tmp;
				i=(2 *  i)  + 1;
				}
			else return true;	
		}	
	}
	return true;
}