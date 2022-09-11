#include <iostream>
#include <stdint.h>
#include "queue.h"
/*
Queue::Queue() {
	knot a;

}
*/

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
/*
Queue::Queue(const Queue& copy) {
*/

void Queue::push(const int& T) {
	if (is_empty())
	{
		std::unique_ptr<knot>  f = std::make_unique<knot>(T,T,head);
		teil = std::move(f);
	}
	else
	{
		std::unique_ptr<knot>  f = std::make_unique<knot>(T, T, find_position(T));
		teil = std::move(f);
	}
}

bool Queue::is_empty() const {
	return isEmpty;
}

