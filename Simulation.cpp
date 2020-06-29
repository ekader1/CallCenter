#include "CallCenter.cpp"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
/*
  g++ -c -std=c++11 Simulation.cpp
  g++ Simulation.o -o program.exe
  ./program.exe
*/

void display(int Time,int x,int y){
	cout<<"Time = "<<Time<<endl;
	cout<<"Number of calls in the waiting list = "<<x<<endl;
	cout<<"number of calls completed = "<<y<<endl;
}

void displayresults(int sumOfcalls, int answerTime,int answered,float avg1,float avg2,float avg3){
	cout<<"Number of calls entered = "<<sumOfcalls<<" and answered = "<<answered<<endl;
	cout<<"Total time taken to answer all calls "<<answerTime<<endl;
	cout<<"Average wait time priority1= "<<avg1<<endl;
	cout<<"Average wait time priority2= "<<avg2<<endl;
	cout<<"Average wait time priority3= "<<avg3<<endl;
}
	
int main(){
	srand (time(NULL));
	float ArrivalRate;
	int ArrTime,Talking,sumofAnswering,Sum,totalTime;

	cout<<"Total time to simulate: ";
	cin>>totalTime;	
	cout<<"Arrival rate to simulate: ";
	cin>>ArrivalRate;

	CallCenter centerObj = CallCenter(totalTime,ArrivalRate); 	//Create the Call Center

	vector<int> answeredFifth(totalTime+1,0);
	vector<int> callsFifth(totalTime+1,0);
	vector<int> Answered(totalTime+1,0);
	
	int y=0;
	int sumOfcalls=0;
	int firstCall=0;
	int firstCallTime;
	for(int i=1;i<=totalTime;i++){
		bool isArrived = (rand() % 100) < (ArrivalRate*100);		
		if(isArrived==true){								
			firstCall++;
			Call call=Call();								
			if(firstCall==1){
				firstCallTime=i;
			}
			call.setArrivingTime(i);
			centerObj.addtoWaitingList(call);	
			sumOfcalls++; 
			}
		
		if(i%5==0) {
			callsFifth.at(y)=centerObj.getWaitlist().length(); 
			y++;
			}
		}

	int answered=0;
	int x=0;
	float sumOfavg1=0,sumOfavg2=0,sumOfavg3=0,sumOfavg4=0;	
	int ctr1=0,ctr2=0,ctr3=0,ctr4=0;
	int AnsweredTime;
	
	Talking=0;
	
	for(int j=firstCallTime; j<totalTime && sumofAnswering<totalTime; j+=Talking){
		
		if(!(centerObj.getWaitlist().isEmpty())){
		ArrTime = (centerObj.takeCall()).getArrivingTime();			
		Talking = (centerObj.takeCall()).getTalkingTime();	
	
		if((centerObj.takeCall()).getPriority()==1){
			sumOfavg1+=(j-ArrTime);
			if(sumOfavg1<0) sumOfavg1*=-1;
			ctr1++;	
		}
		else if((centerObj.takeCall()).getPriority()==2){
			sumOfavg2+=(j-ArrTime);
			if(sumOfavg2<0) sumOfavg2*=-1;
			ctr2++;
		}
		else if( (centerObj.takeCall()).getPriority()==3){
			sumOfavg3+=(j-ArrTime);
			if(sumOfavg3<0) sumOfavg3*=-1;
			ctr3++;
		}

		
		
		centerObj.answer();
		answered++;	
		
		if(j+Talking<totalTime){
			answeredFifth.at(x)=j+Talking;
			x++;
			}
			sumofAnswering += Talking;	
		}else{
			j=totalTime;
		}
	}
	
	int ctr=0;	
	x=0;
	int hmFive=totalTime/5;				
	for(int i=1;i<=hmFive;i++){			
		ctr=0;
		for(int k=0;k<totalTime;k++){
			if(answeredFifth.at(k)<=(5*i) && answeredFifth.at(k)!=0){
				ctr++;
			}
		}
		Answered.at(i-1)=ctr;
	}

	cout<<"\n\n";	
	int tmp=0;
	for(int k=1; k<=totalTime;k++){
		if(k%5==0){
			display(k,callsFifth.at(tmp)-Answered.at(tmp),Answered.at(tmp));
			tmp++;
		}
	}
	float a1,a2,a3,a4;
	
	if(ctr1!=0)  a1=(sumOfavg1/ctr1);
	if(ctr2!=0)  a2=(sumOfavg2/ctr2);
	if(ctr3!=0)  a3=(sumOfavg3/ctr3);
	
	cout<<"\n\n"<<endl;
	displayresults(sumOfcalls,sumofAnswering,answered,a1,a2,a3);
	return 0;
}












