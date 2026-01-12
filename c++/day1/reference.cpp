#include<iostream>
#include<vector>

void change(std::vector<int>&);

int main(){
	std::vector<int> numbers;
	int size, number;
	
	
	std::cout<<"Enter the vectro size: ";
	std::cin>>size;
	
	for(int i=0;i<size;i++){
		std::cout<<"Enter a number: "; std::cin>>number;
		numbers.push_back(number);
	}
	
	std::cout<<"Numbers before function"<<std::endl;
	std::cout<<"Vector numbers: ";
	for(int i=0;i<size;i++){
		std::cout<<numbers[i]<<" ";
	}
	
	change(numbers);
	
	std::cout<<"\n\nNumbers after function"<<std::endl;
	std::cout<<"Vector numbers: ";
	for(int i=0;i<size;i++){
		std::cout<<numbers[i]<<" ";
	}
	
	return 0;
}
void change(std::vector<int>&numbers){
	int& first = numbers[0];
	first*= 3;
	int* last = &numbers[numbers.size() - 1];
	*last *= 2;
}