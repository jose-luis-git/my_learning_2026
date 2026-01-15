#include<iostream>

class GameStore{
	private:
		int *score;
	public:
		explicit GameStore(int _score){
			score = new int(_score);
		}
		~GameStore(){
			delete score;
		}
		GameStore(const GameStore&other){
			score = new int(*other.score);
		}
		GameStore& operator = (const GameStore&other){
			if(this != &other){
				delete score;
				score = new int(*other.score);
			}
			return *this;
		}
		GameStore(GameStore&&other) noexcept{
			score = other.score;
			other.score = nullptr;
		}
		GameStore& operator = (GameStore&&other) noexcept{
			if(this != &other){
				delete score;
				score = other.score;
				other.score = nullptr;
			}
			return *this;
		}
		void add(const int&new_score){
			if(new_score <= 0){
				std::cout<<"Invalid score"<<std::endl;
				return;
			}
			*score += new_score;
		}
		void show() const{
			std::cout<<"Score: "<<*score<<std::endl;
		}
};

int main(){
	GameStore score(34);
	int add_score;
		
	while(true){
		std::cout<<"Enter a new score: "; std::cin>>add_score;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Enter a valid score"<<std::endl;
		}else{
			break;
		}
	}
	
	score.add(add_score);
	score.show();
	
	return 0;
}