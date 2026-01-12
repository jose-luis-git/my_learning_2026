#include<iostream>
#include<cmath>

struct Vector2D{
	int x, y;
	Vector2D(int x, int y) : x(x), y(y){}
	Vector2D operator + (const Vector2D&) const;
	Vector2D operator - (const Vector2D&) const;
	double length() const;
};

Vector2D Vector2D::operator + (const Vector2D&other) const{
	return Vector2D(x + other.x, y + other.y);
} 
Vector2D Vector2D::operator - (const Vector2D&other) const{
	return Vector2D(x - other.x, y - other.y);
}
double Vector2D::length() const{
	return std::sqrt(x*x + y*y);
}

int main(){
	Vector2D v1(2, 3);
	Vector2D v2(2, 3);
	
	Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
	
	std::cout<<"v3 length: "<<v3.length()<<std::endl;
	std::cout<<"v4 length: "<<v4.length()<<std::endl;
	
	return 0;
}