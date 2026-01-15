#include<iostream>
#include<string>

class Computer{
	public:
		class CPU{
			private:
				std::string series;
				int capacity;
			public:
				CPU(const std::string&_series, int _capacity) : series(_series), capacity(_capacity){}
				~CPU() = default;
				void showSpecs() const;
		};
};

void Computer::CPU::showSpecs() const{
	std::cout<<"Series: "<<series<<std::endl;
	std::cout<<"Capacity: "<<capacity<<std::endl;
}

int main(){
	std::string series;
	int capacity;
	
	while(true){
		std::cout<<"Enter the cpu series: "; std::cin>>series;
		if(series.empty()){
			std::cout<<"Empty name"<<std::endl;
		}else{
			break;
		}
	}
	while(true){
		std::cout<<"Enter the CPU capacity: "; std::cin>>capacity;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Enter the capacity in numbers"<<std::endl;
		}else if(capacity <= 0){
			std::cout<<"Introduce a valid capacity"<<std::endl;
		}else{
			break;
		}
	}
	
	Computer::CPU cpu1(series, capacity);
	cpu1.showSpecs();
	
	return 0;
}