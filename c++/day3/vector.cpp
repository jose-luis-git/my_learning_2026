#include<iostream>
#include<vector>

void show_vector(const std::vector<int>&);
void sum_vector(const std::vector<int>&);
void average_vector(const std::vector<int>&);

int main(){
	std::vector<int> numbers;
	int amount, number;
	
	while(true){
		std::cout<<"Enter an amount: "; std::cin>>amount;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Amount invalid"<<std::endl;
		}else if(amount <= 0){
			std::cout<<"The amount must be positive"<<std::endl;
		}
		else{
			break;
		}
	}	
	
	for(int i=0;i<amount;i++){
		std::cout<<i+1<<".)Enter a number: "; std::cin>>number;
		numbers.push_back(number);
	}
	
	show_vector(numbers);
	sum_vector(numbers);
	average_vector(numbers);
	
	return 0;
}

void show_vector(const std::vector<int>&numbers){
	if(numbers.empty()) return;
	
	std::cout<<"Vector numbers: ";
	
	
	for(const auto&n : numbers){
		std::cout<<n<<" ";
	}
}
void sum_vector(const std::vector<int>&numbers){
	if(numbers.empty()) return;
	
	int sum = 0;
	
	
	for(const auto&n : numbers){
		sum += n;
	}
	
	std::cout<<"\nThe sum of the numbers in the vector is: "<<sum<<std::endl;
}
void average_vector(const std::vector<int>&numbers){
	if(numbers.empty()) return;
	
	int sum = 0;
	double average = 0.0;
	
	
	for(const auto&n : numbers){
		sum += n;
	}
	
	average = static_cast<double>(sum) / numbers.size();
	
	std::cout<<"The average of the numbers in the vector is: "<<average<<std::endl;
}