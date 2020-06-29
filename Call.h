#include <iostream>

using namespace std;

class Call{

	private:
		int arrivingTime; //the time during the simulation at which the call arrived at the call center
		int priority; //its priority -  the priority is randomly computed (10% of calls have a priority of 1, 30%  have a priority of 2 and 60% have a priority of 3)
		int talkingTime; //the time it will take to answer the call - the time is randomly computed and can be from 3 to 8 minutes

	public: 
		Call();	//Constructor function for Call Class

	// The Call class needs to overload the relational operator(s) used in your PriorityQueue class. 
	// Call class objects need to be compared based on their priority values.
		bool operator <(const Call & rhsOperand) const; // operator overloading function <
		bool operator >(const Call & rhsOperand) const; // operator overloading function >
		bool operator ==(const Call & rhsOperand) const; // operator overloading function ==
	
	//Getter Methods
		int getArrivingTime();
		int getPriority();
		int getTalkingTime();

	//Setter Methods
		void setArrivingTime(int x);
		
};	