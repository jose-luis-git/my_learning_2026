#include<iostream>
#include<string>

class Student{
	private:
		std::string *name;
		int *grade;
	public:
		Student(const std::string& _name, int _grade){
			name = new std::string(_name);
			grade = new int(_grade);
		}
		~Student(){
			delete name;
			delete grade;
		}
		void show() const;
		void setGrade(int);
};
void Student::show() const{
	std::cout<<"Name: "<<*name<<std::endl;
	std::cout<<"Grade: "<<*grade<<std::endl;
}
void Student::setGrade(int newGrade){
	*grade = newGrade;
}

int main(){
	Student student("Jose", 6);
	student.show();
	student.setGrade(7);
	student.show();
	
	return 0;
}