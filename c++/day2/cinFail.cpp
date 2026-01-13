#include<iostream>

void sum(const int&, const int&, const int&);
void average(const int&, const int&, const int&);

int main(){
	int n1,n2,n3;
	
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
		std::cout<<"Enter a number: "; std::cin>>n2;
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
	while(true){
		std::cout<<"Enter a number: "; std::cin>>n3;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Error: Enter a number"<<std::endl;
		}else if(n3 < 0){
			std::cout<<"The number must be positive"<<std::endl;
		}else{
			break;
		}
	}
	
	std::cout<<std::endl;
	sum(n1,n2,n3);
	average(n1,n2,n3);
	
	
	return 0;
}
void sum(const int&n1, const int&n2, const int&n3){
	int sum_numbers = 0;
	sum_numbers = n1 + n2 + n3;
	std::cout<<"The sum of the numbers is: "<<sum_numbers<<std::endl;
}
void average(const int&n1, const int&n2, const int&n3){
	int sum_numbers = 0;
	double average_numbers = 0;
	
	sum_numbers = n1 + n2 + n3;
	average_numbers = static_cast<double>(sum_numbers) / 3;
	
	std::cout<<"The average of the numbers is: "<<average_numbers<<std::endl;
}