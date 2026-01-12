#include<iostream>
#include<stdexcept>

class BankAccount{
	private:
		float balance;
	public:
		explicit BankAccount(float _balance): balance(_balance){}
		~BankAccount(){}
		void setBalance(float);
		float getBalance() const;
		float operator[](int);
		const float operator[](int) const;
		void deposit(double);
		void withdraw(double);
		void show() const;
};

void BankAccount::setBalance(float _balance){
	balance = _balance;
}
float BankAccount::getBalance() const{
	return balance;	
}
float BankAccount::operator[](int index){
	if(index == 0) return balance;
	
	throw std::out_of_range("The index exceeds the limit");
}
const float BankAccount::operator[](int index) const{
	if(index == 0) return balance;
	
	throw std::out_of_range("The index exceeds the limit");
}
void BankAccount::deposit(double amount){
	if(amount <= 0){
		std::cout<<"Invalid deposit"<<std::endl;
		return;
	}
	balance += amount;
	std::cout<<"Account money: "<<balance<<std::endl;
}
void BankAccount::withdraw(double amount){
	if(amount <= 0 || amount > balance){
		std::cout<<"Invalid withdraw"<<std::endl;
		return;
	}
	balance -= amount;
	std::cout<<"Accout money: "<<balance<<std::endl;
}
void BankAccount::show() const{
	std::cout<<"Balance: "<<balance;
}

int main(){
	BankAccount ba(100);
	double amount;
	double moved = 0;
	
	
	std::cout<<"Enter the amount of money you will deposit: "; std::cin>>amount;
	ba.deposit(amount);
	moved += amount;
	std::cout<<"Enter the amount of money you will withdraw: "; std::cin>>amount;
	ba.withdraw(amount);
	moved += amount;
	
	std::cout<<"\nTotal amount of money moved: "<<moved<<std::endl;
	std::cout<<"Total money: "<<ba[0]<<std::endl;
	
	return 0;
}