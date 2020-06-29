#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
//#include "Call.h"


using namespace std;


Call::Call(){
	
	int TrueFalse = rand()% 100 ;
	
	if(TrueFalse < 10){
		priority=1;
	}
	else if(TrueFalse < 20){
		priority=2;
	}
	else if(TrueFalse < 30){
		priority=3;
	}
	else if(TrueFalse < 40){
		priority=4;
	}
	talkingTime=rand()%5 +1;	
	
}

//Getter Methods
int Call::getArrivingTime(){
	return this->arrivingTime;
}

int Call::getPriority(){
	return this->priority;
}

int Call::getTalkingTime(){
	return this->talkingTime;
}

//Setter Methods
void Call::setArrivingTime(int x){
	this->arrivingTime=x;
}

//Operators
bool Call::operator <(const Call & rhsOperand) const{
	if(this->priority < rhsOperand.priority ){
		return true;
	}else{
		return false;
	} 
}
bool Call::operator >(const Call & rhsOperand) const{
	if(this->priority > rhsOperand.priority ){
		return true;
	}else{
		return false;
	} 
}

bool Call::operator ==(const Call & rhsOperand) const{
	if(this->priority == rhsOperand.priority ){
		return true;
	}else{
		return false;
	} 
}
