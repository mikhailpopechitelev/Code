#pragma once
#ifndef queue
#define queue

#include<iosfwd>
#include<stdint.h>
#include<>

//возрастающая очередь с приоритетом

struct Queue {
private:
	//поля


public:
	//методы
	void push(const int& T);
	void pop();
	const int& T() const;
	bool is_empty() const;

	//конструкторы/диструкторы
	Queue();
	Queue(const Queue& copy);
	~Queue() = default;

	//перегрузка операторов
	Queue& operator= (const Queue&);



};

#endif