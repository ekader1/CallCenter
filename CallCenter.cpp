#include <iostream>
#include "CallCenter.h"

using namespace std;

CallCenter::CallCenter(int process,float Rate){
	Time=process;
	arrivalRate=Rate;
}

int CallCenter::getTime(){
	return this->Time;
}

float CallCenter::getArrivalRate(){
	return this->arrivalRate;
}

PriorityQueue CallCenter::getWaitlist(){
	return this->waitList;
}
void CallCenter::addtoWaitingList(Call& Obj){
	(this->waitList).enqueue(Obj);
}