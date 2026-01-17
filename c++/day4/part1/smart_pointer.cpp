#include<iostream>
#include<memory>
#include<cstring>

class Text{
	private:
		std::unique_ptr<char[]> text;
	public:
		Text(const char*t){
			size_t len = strlen(t) + 1;
			text = std::make_unique<char[]>(len);
			strcpy(text.get(), t);
		}
		void show() const{
			std::cout<<"Text: "<<text.get()<<std::endl;
		}
};

int main(){
	Text t1("k");
	Text t3 = std::move(t1);
	
	t3.show();
	
	return 0;
}