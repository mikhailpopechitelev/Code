//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//#include <queue/queue.h>
#include <iostream>
#include"queue.h"
	/*
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
			this->data = data;
			this->next = std::move(next);
			this->key = key;
		};
		~knot() {

			this->next = nullptr;
		};
	};

	//поля
	std::unique_ptr<knot> head;
	bool isEmpty = true;

public:

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
			while ((tmp->get_ptr()->get_ptr() != nullptr)&&(find==false))
			{
				if ((T>= tmp->get_key())&&(T>= tmp->get_ptr()->get_key()))
				{
					tmp = tmp->get_ptr().get();
				}
				else if ((T >= tmp->get_key()) && (T < tmp->get_ptr()->get_key()))
				{
					find = true;
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
	void pop() {
		if (head->get_ptr() == nullptr)
		{
			isEmpty = true;
		}
		head = std::move(head->get_ptr()); 
	};
	const int front() const {
		return head->get_key();
	};

	bool is_empty() const{
		return isEmpty;
	};

	//конструкторы/диструкторы
	Queue() {
	};
	Queue(const Queue& copy);
	~Queue() = default;

	//перегрузка операторов
	//Queue& operator= (const Queue&);
	friend struct knot;



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
	*/
	
int main() {
	
	
	Queue q;
	q.push(100);
	q.push(-3);
	q.push(93);
	q.push(1);
	q.push(-99);
	q.push(-22);
	q.push(48);
	Queue q_1(q);
	Queue q_2 = q_1;

	while (!q_2.is_empty())
	{
		std::cout << q_2.front() << ' ';
		q_2.pop();
	}
	
	/*
	Queue q;
	q.push(8);
	q.push(3);
	q.push(-2);
	q.push(80);
	q.push(0);
	q.push(-4);

	while (!q.is_empty())
	{
		std::cout<<q.front()<<' ';
		q.pop();
	}
		*/



	// тест при создании knot1 прямо в файле при main
	/*
	std::unique_ptr<knot> teil = nullptr;
	std::unique_ptr<knot> a = std::make_unique<knot1>(3, 3,std::move(teil));
	std::unique_ptr<knot> b = std::make_unique<knot1>(2, 2, std::move(a));
	std::unique_ptr<knot> head = std::make_unique<knot1>(1, 1, std::move(b));
	*/

	//hui = std::move( std::make_unique<std::unique_ptr<knot1>>( std::move((*hui)->get_ptr())) );
	//std::cout << teil->get_key() << std::endl;
	//hui = std::move(std::make_unique<std::unique_ptr<knot1>>(std::move((*hui)->get_ptr())));
}

