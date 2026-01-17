#include<iostream>
#include<cstring>

class Text{
	private:
		char *text;
	public:
		Text(const char*);
		~Text();
		Text(const Text&);
		Text& operator = (const Text&);
		Text(Text&&) noexcept;
		Text& operator = (Text&&) noexcept;
		void show() const;
};

Text::Text(const char* t){
	text = new char[strlen(t) + 1];
	strcpy(text, t);
}
Text::~Text(){
	delete[] text;
}
Text::Text(const Text&other){
	text = new char[strlen(other.text) + 1];
	strcpy(text, other.text);
}
Text& Text::operator = (const Text&other){
	if(this != &other){
		delete[] text;
		text = new char[strlen(other.text) + 1];
		strcpy(text, other.text);
	}
	return *this;
}
Text::Text(Text&&other) noexcept{
	text = other.text;
	other.text = nullptr;
}
Text& Text::operator = (Text&&other) noexcept{
	if(this != &other){
		delete[] text;
		text = other.text;
		text = nullptr;
	}
	return *this;
}
void Text::show() const{
	std::cout<<"Text: "<<*text<<std::endl;
}
 
int main(){
	Text t1("p");
	Text t2 = t1;
	Text t3 = std::move(t1);
	
	t2.show();
	t3.show();
	
	return 0;
}
