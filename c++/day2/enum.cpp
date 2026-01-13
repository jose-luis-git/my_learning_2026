#include<iostream>

enum class ProgramStatus{
	Income,
	Calculation,
	End	
};

void sum(const int&, const int&, const ProgramStatus&);
void average(const int&, const int&, const ProgramStatus&);

int main(){
	int n1,n2;
	
	if(ProgramStatus::Income == ProgramStatus::Income) std::cout<<"Entering the program"<<std::endl;
	
	while(true){
		std::cout<<"Enter a number: "; std::cin>>n1;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Error: Enter a number"<<std::endl;
		}else if(n1 < 0){
			std::cout<<"The number must be positive"<<std::endl;
		}else{
			break;
		}
	}
	while(true){
		std::cout<<"Enter another number: "; std::cin>>n2;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Error: Enter a number"<<std::endl;
		}else if(n2 < 0){
			std::cout<<"The number must be positive"<<std::endl;
		}else{
			break;
		}
	}
	
	sum(n1, n2, ProgramStatus::Calculation);
	average(n1, n2, ProgramStatus::Calculation);
	
	if(ProgramStatus::End == ProgramStatus::End) std::cout<<"\nFinished program"<<std::endl;
	
	return 0;
}
void sum(const int&n1, const int&n2, const ProgramStatus&calculation){
	int number_sum = n1 + n2;
	
	if(calculation == ProgramStatus::Calculation) std::cout<<"\nCalculating sum...."<<std::endl;
	
	std::cout<<"The sum of the numbers is: "<<number_sum<<std::endl;
}
void average(const int&n1, const int&n2, const ProgramStatus&calculation){
	int number_sum = n1 + n2;
	double number_average = static_cast<double>(number_sum) / 2;
	
	if(calculation == ProgramStatus::Calculation) std::cout<<"\ncalculating average...."<<std::endl;
	
	std::cout<<"The average of the numbers is: "<<number_average<<std::endl;
}