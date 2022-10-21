#include "stack.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

int main(){
	Stack<int> test;
	test.push_back(3);
	test.push_back(8);
	test.push_back(10);
	std::cout << test.size() << std::endl;
	test.pop();
	std::cout << test.top();
	test.pop();
	std::cout << " ";
  std::cout << test.top();
	test.pop();
	std::cout << " ";
	test.push_back(4);
	test.push_back(5);
	test.push_back(12);
	test.push_back(16);
	test.pop();
	test.pop();
	test.pop();
	test.pop();
	test.pop();
	//show throw exception
	return 0;
}
