#include <iostream>
#include "PriorityQueue.cpp"

using namespace std;

class CallCenter {
	private:
		int Time;
		float arrivalRate;
		PriorityQueue waitList; //PQ waitlist obj
	public:
		CallCenter(int process,float Rate);	//constructor for CallCenter class 
		//(gets current process and rate of calls as parameters )
		
		Call takeCall(){
			return this->waitList.front();	
		}		
		
		void answer(){
			this->waitList.dequeue();
		}	

		void addtoWaitingList(Call& Obj);
		
	//Getter Methdos
		int getTime(); // returns current time for the callcenter object
		float getArrivalRate();
		PriorityQueue getWaitlist(); //retruns waitlist object
};