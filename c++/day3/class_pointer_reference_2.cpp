#include<iostream>

class BankAccount{
	private:
		double *balance;
	public:
		explicit BankAccount(double _balance){
			balance = new double(_balance);
		}
		~BankAccount(){
			delete balance;
		}
		BankAccount(const BankAccount&);
		BankAccount& operator = (const BankAccount&);
		BankAccount(BankAccount&&) noexcept;
		BankAccount& operator = (BankAccount&&) noexcept;
		void deposit(const double&);
		void withdraw(const double&);
		void show() const;
};
BankAccount::BankAccount(const BankAccount&other){
	balance = new double(*other.balance);
}
BankAccount& BankAccount::operator = (const BankAccount&other){
	if(this != &other){
		delete balance;
		balance = new double(*other.balance);
	}
	return *this;
}
BankAccount::BankAccount(BankAccount&&other) noexcept{
	balance = other.balance;
	other.balance = nullptr;
}
BankAccount& BankAccount::operator = (BankAccount&&other) noexcept{
	if(this != &other){
		delete balance;
		balance = other.balance;
		other.balance = nullptr;
	}
	
	return *this;
}  

void BankAccount::deposit(const double& amount){
	if(amount <= 0){
		std::cout<<"Invalid amount"<<std::endl;
		return;
	}
	
	*balance += amount;
}
void BankAccount::withdraw(const double& amount){
	if((amount <= 0) || (amount > *balance)){
		std::cout<<"Invalid amount"<<std::endl;
		return;
	}
	
	*balance -= amount;
}
void BankAccount::show() const{
	std::cout<<"The balance of the account: "<<*balance<<std::endl;
}

int main(){
	BankAccount ba(1000.56);
	double deposit, withdraw;
	
	while(true){
		std::cout<<"How much money will you deposit?: "; std::cin>>deposit;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Enter a valid amount"<<std::endl;
		}else{
			break;
		}
	}
	
	std::cout<<std::endl;
	ba.deposit(deposit);
	ba.show();
	
	while(true){
		std::cout<<"How much money will you withdraw?: "; std::cin>>withdraw;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Enter a valid amount"<<std::endl;
		}else{
			break;
		}
	}
	
	std::cout<<std::endl;
	ba.withdraw(withdraw);
	ba.show();
	
	return 0;
}