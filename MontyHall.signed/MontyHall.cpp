//FileName:Montyhall.cpp
//Author:VagdeviChalla
//Assignment Number:2
//Description:Monty Hall Problem
//Last changed:02/08/2018

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<iomanip>

using namespace std;
const int simulation_Count=100;


int door_firstChoice(int first_Choice){
	
	return first_Choice;
}

//validating the randomly generated door and finding the correctly opened door

int opened_Door(int door_opened,int first_Choice,int carhere){
	
	do{
		 door_opened = rand() % 3 + 1;
	}
	while(door_opened == first_Choice || door_opened == carhere); 
	
	return door_opened;
}  

//validating second choice and finding the correct second choice
int door_secondChoice(int second_Choice, int first_choice, int opened_door){
    do{
		second_Choice = rand() % 3 + 1;
	}
	while(second_Choice == opened_door || second_Choice == first_choice); 
	return 	second_Choice;
}

int main () {
	
string winFirst="";
string winSecond="";
srand(time(0));
int firstwinCounter=0;
int seconwinCounter=0;

cout<< setw(3) << "#" << setw(10) << "Carhere" << setw(13) << "Firstchoice" << setw(13) << "Opendoor" << setw(15) << "SecondChoice" << setw(13) << "Win first" << setw(13) << "Win second" <<endl;	
for(int i=1;i<=simulation_Count;i++){
	
	//Randomly generating door numbers for car,opened door,door that selected firts and second
	int carhere = rand() % 3 + 1;
	int first_Choice = rand() % 3 + 1;
	int door_opened = rand() % 3 + 1;
	int second_Choice = rand() % 3 + 1;
	
	//doing validation for randomly generated doors and storing those values in variables
	int firstchoice = door_firstChoice(first_Choice);
	int openeddoor = opened_Door(door_opened,first_Choice,carhere);
	int secondchoice = door_secondChoice(second_Choice,firstchoice,openeddoor);
	
	//determing the win based on stay and switch
	if(firstchoice == carhere){
		winFirst="yes";	
		firstwinCounter++;
		
	}
	if(secondchoice == carhere){
		 winSecond="yes";
		 seconwinCounter++;
	}	

//Printing the simulation output	
cout << setw(3) << i << setw(10) << carhere << setw(13) << firstchoice << setw(13) << openeddoor << setw(15) << secondchoice << setw(13) << winFirst <<  setw(13) << winSecond <<endl;
winFirst="";
winSecond="";	
}

cout << firstwinCounter << " wins if stay with the first choice" <<endl;
cout << seconwinCounter << " wins if switch to the second choice" << endl;

//finding switch over stay ratio
double winSwitchratio=static_cast<double>(seconwinCounter)/firstwinCounter;

cout<<"win ratio of switch over stay: " << winSwitchratio<<endl;

}
	