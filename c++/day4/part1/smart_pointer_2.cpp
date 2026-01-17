#include<iostream>
#include<memory>
#include<cstring>

class Person{
	private:
		std::unique_ptr<char[]>name;
	public:
		Person(const char*n){
			size_t len = strlen(n) + 1;
			name = std::make_unique<char[]>(len);
			strcpy(name.get(), n);
		}
		void show() const{
			std::cout<<"Name: "<<name.get()<<std::endl;	
		}
};

int main(){
	Person p1("j");
	
	p1.show();
	
	return 0;
}