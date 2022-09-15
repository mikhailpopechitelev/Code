//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//#include <queue/queue.h>
#include <iostream>
#include<memory>
//#include"queue.h"

	//возрастающа€ очередь с приоритетом

	struct knot1 {
	private:

		int data = 0;
		std::unique_ptr<knot1> next;
		int key = 0;

	public:

		std::unique_ptr<knot1>& get_ptr() {
			return next;
		};
		int get_key() {
			return key;
		}
		knot1(const int& data, const int& key, std::unique_ptr<knot1>& next) {

			//auto next = std::make_unique<knot>();
			this->data = data;
			this->next = std::move(next);
			this->key = key;
		}

		~knot1() {

			this->next = nullptr;
		}

		//std::unique_ptr<knot> make_unique(knot new_knot);

	};
	
	
	std::unique_ptr< std::unique_ptr<knot1>> find_position_before(const int& T, std::unique_ptr<knot1>& teil , std::unique_ptr<knot1>& head) {
		std::unique_ptr<std::unique_ptr<knot1>> first = std::make_unique<std::unique_ptr<knot1>>(std::move(teil));
		bool find = false;
		while (!find);
		{
			if (T >= ((*first)->get_key()) && ((*((*first)->get_ptr())).get_ptr() != head) && (T >= (*((*first)->get_ptr())).get_key()))
			{
				find = true;
				(*first).swap((*first)->get_ptr());
			}
			else if (T >= ((*first)->get_key()) && ((*((*first)->get_ptr())).get_ptr() != head) && (T < (*((*first)->get_ptr())).get_key()))
			{
				find = true;
				return first;
			}
			else if ((*((*first)->get_ptr())).get_ptr() == head)
			{
				find = true;
				return first;
			}
		}
	}
	
	
int main() {
	/*
	Queue q;
	q.push(4);
	q.push(1);
	q.push(2);
	q.push(5);
	//std::cout<< q.
	*/
	
	//* тест при создании knot1 пр€мо в файле при main
	std::unique_ptr<knot1> head = nullptr;
	std::unique_ptr<knot1> a = std::make_unique<knot1>(3, 3, std::move(head));
	std::unique_ptr<knot1> b = std::make_unique<knot1>(2, 2, std::move(a));
	std::unique_ptr<knot1> teil = std::make_unique<knot1>(1, 1, std::move(b));

	//std::unique_ptr<std::unique_ptr<knot1>> hui = std::make_unique<std::unique_ptr<knot1>>(std::move(teil));
	std::cout << ((*find_position_before(2, teil, head))->get_ptr());
	














	/*
	* тест работает ли свап (хуй-указатель на указатель)
	std::cout << hui <<"\n";
	std::cout << (*hui)->get_key()<< "\n";
	(*hui).swap((*hui)->get_ptr());
	std::cout << hui<< "\n";
	std::cout << (*hui)->get_key() << "\n";
	*/


	//hui = std::move( std::make_unique<std::unique_ptr<knot1>>( std::move((*hui)->get_ptr())) );

	//std::cout << teil->get_key() << std::endl;
	
	//hui = std::move(std::make_unique<std::unique_ptr<knot1>>(std::move((*hui)->get_ptr())));




	//std::cout << (find_position_before(2, teil, head));
	//std::unique_ptr<knot1> c = std::make_unique<knot1>(2, 2, std::move(a));

	//std::unique_ptr<knot1> c = std::make_unique<knot>(3, 3, std::move(b));
	/*
	std::cout << teil->get_key() << std::endl;
	std::cout << teil->get_ptr()->get_key() << std::endl;

	std::cout << teil->get_ptr()->get_ptr()->get_key() << std::endl;
	std::cout << teil->get_key() << std::endl;

	std::cout << teil->get_ptr()->get_key() << std::endl;
	*/
	/*
	c.swap((*c).get_ptr());
	std::cout<<(*c).get_key();
	
	std::unique_ptr<knot1>* d = &c;
	
	std::cout << (*d)->get_key() << "\n";
	d = &((* d)->get_ptr());

	std::cout << (*d)->get_key() << "\n";

	d = &((*d)->get_ptr());
	std::cout << (*d)->get_key() << "\n";
	*/
	/*
	* андрей ху€рил
	std::unique_ptr<knot1> a = std::make_unique<knot1>(1, 1, std::move(nullptr));
	std::unique_ptr<knot1> b = std::make_unique<knot1>(2, 2, std::move(a));

	std::unique_ptr<knot1> c = std::make_unique<knot1>(3, 3, std::move(b));

	//a.swap(b);
	//std::cout << (*b).get_key();
	
	std::unique_ptr<std::unique_ptr<knot1>> d = std::make_unique<std::unique_ptr<knot1>>(std::move(c));

	std::cout << (*d)->get_key() << "\n";

	d = std::make_unique<std::unique_ptr<knot1>>(std::move((*d)->get_ptr()));

	
	std::cout << (*d)->get_key() << "\n";

	d = std::make_unique<std::unique_ptr<knot1>>(std::move((*d)->get_ptr()));
	std::cout << (*d)->get_key() << "\n";
	*/
}

