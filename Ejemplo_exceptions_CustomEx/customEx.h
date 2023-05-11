#pragma once
#include <exception>
#include <string>

template<typename T>
class EMPTY_STR : public std::exception {
	T where_;
	std::string to_string();
public:
	EMPTY_STR() {
		this->where_ = "";
	}
	EMPTY_STR(T where_) {
		this->where_ = where_;
	}
	~EMPTY_STR() {
	}
	virtual const char* what() const throw();
};

template<typename T>
inline std::string EMPTY_STR<T>::to_string() {
	std::string data = "Empty String Exception" + this->where_;
	return data;
}

template<typename T>
inline const char* EMPTY_STR<T>::what() const throw() {
	return "Empty String Exception";
}
