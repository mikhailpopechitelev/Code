//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//#include <queue/queue.h>
#include <iostream>
#include<memory>

int main() {
	std::unique_ptr<int> a;
	if (a==nullptr)
	{
		std::cout << 'p';
	}
}

