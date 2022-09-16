//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//#include <queue/queue.h>
#include <iostream>
#include<memory>
//#include"queue.h"

	//возрастающая очередь с приоритетом

struct Queue {

private:
	//возрастающая очередь с приоритетом
	struct knot {
	private:

		int data = 0;
		std::unique_ptr<Queue::knot> next;
		int key = 0;

	public:

		std::unique_ptr<knot>& get_ptr() {
			return next;
		};
		int get_key() {
			return key;
		};
		knot(const int& data, const int& key, std::unique_ptr<knot>& next) {

			//auto next = std::make_unique<knot>();
			this->data = data;
			this->next = std::move(next);
			this->key = key;
		};
		~knot() {

			this->next = nullptr;
		};
		//std::unique_ptr<knot> make_unique(knot new_knot);

	};

	//поля
	std::unique_ptr<knot> head;
	bool isEmpty = true;

public:

	//методы
	/*
	knot* find_position_before(const int& T) {
		knot* first = head.get();
		while (first->get_ptr()->get_ptr() != nullptr);
		{
			if ((T >= first->get_key()) && (T >= first->get_ptr()->get_key()))
			{
				first = first->get_ptr().get();
			}
			else if ((T >= first->get_key()) && (T < first->get_ptr()->get_key()))
			{
				return first;
			}
			return first;
		}

	}
	*/
	void push(const int& T) {
		if (is_empty())
		{
			std::unique_ptr<knot> teil = nullptr;
			std::unique_ptr<knot>  first = std::make_unique<knot>(T, T, std::move(teil));
			head = std::move(first);
			isEmpty = false;
		}
		else if (T < head->get_key())
		{
			std::unique_ptr<knot> first = std::make_unique<knot>(T, T, std::move(head));
			head = std::move(first);
		}
		else
		{
			knot* tmp = head.get();
			bool find = false;
			bool raz = false;
			while ((tmp->get_ptr()->get_ptr() != nullptr)&&(raz==0))
			{
				if ((T>= tmp->get_key())&&(T>= tmp->get_ptr()->get_key()))
				{
					tmp = tmp->get_ptr().get();
				}
				else if ((T >= tmp->get_key()) && (T < tmp->get_ptr()->get_key()))
				{
					find = true;
					raz = 1;
					std::unique_ptr<knot> first = std::make_unique<knot>(T, T, std::move(tmp->get_ptr()));
					tmp->get_ptr() = std::move(first);

				}
			}
			if (find==false)
			{
				if (tmp->get_ptr()->get_key() > T)
				{
					std::unique_ptr<knot> first = std::make_unique<knot>(T, T, std::move(tmp->get_ptr()));
					tmp->get_ptr() = std::move(first);
				}
				else
				{
					std::unique_ptr<knot> first = std::make_unique<knot>(T, T, std::move(tmp->get_ptr()->get_ptr()));
					tmp->get_ptr()->get_ptr() = std::move(first);
				}
			}
		}
	};
	//void pop();
	//const int& Top() const;
	bool is_empty() const{
		return isEmpty;
}
;

	//конструкторы/диструкторы
	Queue() {

	};
	//Queue(const Queue& copy);
	~Queue() = default;

	//перегрузка операторов
	//Queue& operator= (const Queue&);
	friend struct knot;



	//std::unique_ptr<knot> make_unique(knot new_knot);

	};
	
	
	/*
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
	*/
	

	
int main() {
	
	Queue q;
	q.push(100);
	q.push(-3);
	q.push(0);
	q.push(-4);
	q.push(14);
	q.push(35);


	//std::cout<< q.
	std::cout << q.is_empty();
	
	/*
	//* тест при создании knot1 прямо в файле при main
	std::unique_ptr<knot> teil = nullptr;
	std::unique_ptr<knot> a = std::make_unique<knot1>(3, 3,std::move(teil));
	std::unique_ptr<knot> b = std::make_unique<knot1>(2, 2, std::move(a));
	std::unique_ptr<knot> head = std::make_unique<knot1>(1, 1, std::move(b));
	*/
	//std::unique_ptr<std::unique_ptr<knot1>> hui = std::make_unique<std::unique_ptr<knot1>>(std::move(teil));
	//std::cout << find_position_before(2,head)->get_ptr();
	














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
	* андрей хуярил
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

