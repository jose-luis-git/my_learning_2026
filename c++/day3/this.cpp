#include<iostream>

class Box{
	private:
		int width;
	public:
		Box(int width) : width(width){}
		Box& setWidth(){
			this->width++;
			return *this;
		}
		void show() const;
};

void Box::show() const{
	std::cout<<"Width: "<<width<<std::endl;
}

int main(){
	Box b(3);
	
	b.setWidth();
	b.show();
	b.setWidth();
	b.show();
	
	
	return 0;
}