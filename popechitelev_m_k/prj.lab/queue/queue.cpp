#include <iostream>
#include <stdint.h>
#include "queue.h"

Queue::knot::knot(const int& data, const int& key, std::unique_ptr<Queue::knot>& next) {

	//auto next = std::make_unique<knot>();
	this->data = data;
	this->next = std::move(next);
	this->key = key;
}

Queue::knot::~knot() {

	this->next = nullptr;
}

Queue::Queue() {

}

void Queue::push(const int& T) {


	if (is_empty())
	{
		std::unique_ptr<knot>  first = std::make_unique<knot>(T, T, head);
		teil = std::move(first);
	}
	else if (T < (*teil).get_key())
	{
		std::unique_ptr<knot> first = std::make_unique<knot>(T, T, teil);
		teil = std::move(first);
	}
	else
	{
		//std::unique_ptr<knot>  first = std::make_unique<knot>(T, T, std::move((*find_position_before(T)).get_ptr()));
		//teil = std::move(first);
		//std::unique_ptr<knot>  f = std::make_unique<knot>(T, T, find_position_before(T));
		// = std::move(f);
		//(*first).get_ptr() = std::move((*find_position_before(T)).get_ptr());
		//(*first).get_ptr() = std::move(first);
	}
}


bool Queue::is_empty() const {
	return isEmpty;
}

int Queue::knot::get_key() {

	return key;
}

std::unique_ptr<Queue::knot>& Queue::knot::get_ptr() {
	return next;
};

/*
std::unique_ptr<Queue::knot> Queue::find_position_before(const int& T) {
	
	//реализация нахождения предыдущего указателя
	std::unique_ptr<knot> first = std::move(teil);
	bool find = false;
	while (!find);
	{
		if (T >= ((*teil).get_key()) && ((*((*first).get_ptr())).get_ptr() != head) && (T >= (*((*first).get_ptr())).get_key()))
		{
			first.swap((*first).get_ptr());
		}
		else if (T >= ((*first).get_key()) && ((*((*first).get_ptr())).get_ptr() != head) && (T < (*((*first).get_ptr())).get_key()))
		{
			find = true;
			return first;
		}
		else if ((*((*first).get_ptr())).get_ptr() == head)
		{
			find = true;
			return first;
		}
	}
}
*/
