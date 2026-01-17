#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

#include<cstddef>
#include<memory>

class StringBuffer{
	private:
		std::unique_ptr<char[]> buffer;
		size_t length;
	public:
		StringBuffer();
		explicit StringBuffer(const char*);
		
		size_t size() const;
		const char* c_str() const;
		void append(const char*);
		void show() const;
};

#endif