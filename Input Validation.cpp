#include<iostream>
#include<iomanip>
using namespace std;

unsigned int GetCargoNum(){
	int res;
	int CargoNum;
  
  cout<<"is there any Cargo? (1 for yes or 0 for no)\n";
  cin>>setw(1)>>res;
  
  while(!cin.good()||res>1||res<0){
  	cin.clear();
  	cin.ignore(1000, '\n');
  	
  	cout<<"invalid input.\n Only Valid inputs are 1 and 0.\n";
  	cout<<"is there any Cargo?(1 for yes, 0 for no)\n";
  	cin>>setw(1)>>res;
  }
  if(res==1){
  	cout<<"how many?\n";
  	cin>>CargoNum;
  	while(!cin.good())
  	{cin.clear();
  	cin.ignore(1000, '\n');
  	cout<<"invalid input.\n PLease enter the correct amout of cargo: \n";
  	cin>>CargoNum;
	  }
  }
  return CargoNum;
  }
  
  
unsigned int GetPassNum(const unsigned int MaxPass){
	unsigned int x;
	cout<<"Enter the number of passengers(MAX 143): \n";
	cin>>setw(3)>>x;			//only store the first 3 digits

	//error checking
	while(x>MaxPass||!cin.good()){			//checks if input is a positive int and below the max
		cin.clear();
		cin.ignore(1000,'\n');//clearing the cin stream so that the next input isn't tainted
		cout<<"invalid input.\n Input must be a number and 143 or less.\n";
		cout<<"please enter the number of passengers: \n";
		cin>>setw(3)>>x;
		cin.clear();
	    cin.ignore(1000,'\n');
	}
	return x;
}

unsigned int GetPassWeight(unsigned int x, const unsigned int y){
	int w;
	w = x*y;
	return w;
}


int main(){


	unsigned int CargoNum, StrMax=10, tempw,tempttot, diff, PassNum, PassWeight, TotalWeight;
	char **name, airline[StrMax],FlightNum[5];
	const unsigned int BaseWeight=130000, MaxWeight=175000, MaxPass=143, AvgWeight=175;
	
	for(int i=0; i<StrMax;i++){
		airline[i]='\n';			//initializing array to term characters
	}
	
	cout<<"Enter Airline Name: without any spaces. limit 10 characters\n";
	cin>>setw(10)>>airline;
	cin.clear();
	cin.ignore(10000,'\n');

	for(int i=0;i<5;i++){
		FlightNum[i]='\n';			//array initialization
	}
	
	cout<<"Enter the flight Number: \n";
	cin>>setw(5)>>FlightNum;
	cin.clear();
	cin.ignore(10000,'\n');



	diff=MaxWeight-BaseWeight;
	
	PassNum=GetPassNum(MaxPass);
	PassWeight=GetPassWeight(PassNum, AvgWeight);
	diff-=PassWeight;
	TotalWeight=BaseWeight+PassWeight;			//updating total weight
	
	cout<<"The airplane originally weighed "<<BaseWeight<<".\n";
	cout<<"The passengers add "<<PassWeight<<" to this."<<endl;
	cout<<"Making the total weight "<<TotalWeight<<".\n";
	
	CargoNum=GetCargoNum();


	

	
	name = new char* [CargoNum];						//dynamically allocating an array based on user input
	for (int i=0; i<CargoNum;i++)
	{name[i]= new char[StrMax];}						//dynamically allocating a multidimensional array to be able t store names
	
	for(int i=0;i<CargoNum;i++){
		for(int j=0;j<StrMax;j++)
		name[i][j]='\n';								//ensuring that memory space is clear before using
	}	
	
	unsigned int CargoWeight[CargoNum];
	
	for (int i=0; i<CargoNum;i++)
	{cout<<"what is the name of cargo number "<<i+1<<"?(please note there is a character limit of 10 and any characters past 10 will be disregarded)\n";
	char temp[StrMax];
	cin>>setw(StrMax)>>temp;
	cin.clear();				
	cin.ignore(1000, '\n');								//clear and ignore any characters past 10
		for(int j=0;j<StrMax;j++){
			name[i][j]=temp[j];
		}
	cout<<"what is the weight of cargo number "<<i+1<<"?\n";
	cin>>tempw;
	
	if(tempw>diff)//checking if cargo is too heavey to fit on airplane
	{cout<<"cargo too heavy. removing from list and setting weight to zero.\n";
	CargoWeight[i]=0;
	
	for(int j=0;j<StrMax;j++){
		temp[j]='\n';									//clearing temp array
	}
	
	name[i][0]='x';	
	name[i][1]='\n';									//term character to stop inputting data

	}
	else
	CargoWeight[i]=tempw;								//sets weight of cargo with the same index number as its name
	
	cout<<"adding "<<CargoWeight[i]<<endl;
	TotalWeight+=CargoWeight[i];
	diff-=CargoWeight[i];
	cout<<"TotalWeight of airplane is "<<TotalWeight<<endl;
	
	for(int j=0;j<StrMax;j++){
		temp[j]='\n';									//essentially clearing temp array
	}
	}
	
	cout<<"The Airline name is: "<<endl<<"	";
	for(int i=0;i<StrMax;i++){
		if(airline[i]=='\n')
			break;
		cout<<airline[i];
	}
	cout<<"\n The Flight Number is :"<<endl<<"	";
	for(int i=0;i<5;i++){
		if(FlightNum[i]=='\n')
			break;
		cout<<FlightNum[i];
	}
	cout<<"\nThe Number of Passengers is "<<PassNum<<endl;
	cout<<"The Number of Cargo is "<<CargoNum<<endl;
	
	for(int i=0; i<CargoNum;i++){
		cout<<"cargo #"<<i+1<<" ";
		for(int j=0;j<StrMax;j++){
			if(name[i][j]=='\n')
			{break;}									//breaks loop at term character
			cout<<name[i][j];							//prints name of cargo
		}
		cout<<" weighs "<<CargoWeight[i]<<endl;			//prints weight of that cargo
	}
	
	cout<<"The Airplane weighs "<<TotalWeight<<endl;
	cout<<"The Maximum Weight is "<<MaxWeight<<endl;

	system("pause");
	return 0;
}
