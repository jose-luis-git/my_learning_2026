#include<iostream>

class Buffer{
	private:
		int* data;
		size_t size;
	public:
		explicit Buffer(size_t);
		~Buffer();
		Buffer(const Buffer&);
		Buffer& operator = (const Buffer&);
		Buffer(Buffer&&) noexcept;
		Buffer& operator = (Buffer&&) noexcept;
};

Buffer::Buffer(size_t s){
	size = s;
	data = new int[size];
	for(size_t i;i<size;i++){
		data[i] = 0;
	}
}
Buffer::~Buffer(){
	delete[] data;
}
Buffer::Buffer(const Buffer&other){
	size = other.size;
	data = new int[size];
	for(size_t i=0;i<size;i++){
		data[i] = other.data[i];
	}
}
Buffer& Buffer::operator = (const Buffer&other){
	if(this != &other){
		delete[] data;
		size = other.size;
		data = new int[size];
		for(size_t i=0;i<size;i++){
			data[i] = other.data[i];
		}
	}
	return *this;
}
Buffer::Buffer(Buffer&&other) noexcept{
	data = other.data;
	size = other.size;
	
	other.data = nullptr;
	other.size = 0;
}
Buffer& Buffer::operator = (Buffer&&other) noexcept{
	if(this != &other){
		delete[] data;
		size = other.size;
		data = other.data;
		other.data = nullptr;
		other.size = 0;
	}
	return *this;
}


int main(){
	Buffer b1(5);
	Buffer b2 = b1;
	Buffer b3 = std::move(b1);
	
	
	return 0;
}