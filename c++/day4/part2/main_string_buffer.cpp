#include "string_buffer.h"
#include<iostream>

int main(){
	StringBuffer s1;
	StringBuffer s2("Hello world ");
	
	std::cout<<"s1: ";
	s1.show();
	std::cout<<"s2: ";
	s2.show();
	
	s2.append("Person");
	std::cout<<"s2: ";
	s2.show();
	
	std::cout<<"Size s2: "<<s2.size()<<std::endl;
	
	return 0;
}