#pragma once
#ifndef queue
#define queue

#include<iosfwd>
#include<stdint.h>
#include<memory>



struct Queue{

private:
	//возрастающая очередь с приоритетом
	struct knot {
	private:

		int data = 0;
		std::unique_ptr<Queue::knot> next;
		int key = 0;

	public:

		std::unique_ptr<knot>& get_ptr();
		int get_key();
		knot(const int& data, const int& key, std::unique_ptr<knot>& next);
		~knot();
		//std::unique_ptr<knot> make_unique(knot new_knot);
		
	};

	//поля
	std::unique_ptr<knot> head;
	bool isEmpty = true;

public:

	//методы
	void push(const int& T);
	void pop();
	const int front() const;
	bool is_empty() const;

	//конструкторы/диструкторы
	Queue();
	Queue(Queue& copy);
	~Queue() = default;

	//перегрузка операторов
	Queue& operator= (Queue&);
	friend struct knot;
};

#endif