// file: PriorityQueueInterface.h
#include "Call.h"
#ifndef PQUEUE_INTERFACE_
#define PQUEUE_INTERFACE_

typedef Call ItemType; 


class PriorityQueueInterface
{
public: 

   virtual bool isEmpty() const = 0;

   virtual int length() const = 0;
   
   virtual bool enqueue(const ItemType& newEntry) = 0;

   virtual bool dequeue() = 0;   

   virtual ItemType front() const = 0;   

};

#include "Call.cpp"

#endif