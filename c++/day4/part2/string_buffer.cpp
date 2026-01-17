#include "string_buffer.h"
#include<iostream>
#include<memory>
#include<cstddef>
#include<cstring>

StringBuffer::StringBuffer(): buffer(nullptr), length(0){
}
StringBuffer::StringBuffer(const char*text){
	if(text){
		length = std::strlen(text) + 1;
		buffer = std::make_unique<char[]>(length);
		std::strcpy(buffer.get(), text);
	}else{
		buffer = nullptr;
		length = 0;
	}
}
size_t StringBuffer::size() const{
	return length;
}
const char* StringBuffer::c_str() const{
	return buffer? buffer.get() : "";
}
void StringBuffer::show() const{
	std::cout<<c_str()<<std::endl;
}
void StringBuffer::append(const char*text){
	if(!text) return;
	
	size_t extra_len = std::strlen(text);
	size_t new_len = length + extra_len;
	
	auto new_buffer = std::make_unique<char[]>(new_len + 1);
	
	if(buffer){
		std::strcpy(new_buffer.get(), buffer.get());
	}else{
		new_buffer[0] = '\0';
	}
	
	std::strcat(new_buffer.get(), text);
	
	buffer = std::move(new_buffer);
	length = new_len;
}
