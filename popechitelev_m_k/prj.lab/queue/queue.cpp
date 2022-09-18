#include <iostream>
#include <stdint.h>
#include "queue.h"

Queue::knot::knot(const int& data, const int& key, std::unique_ptr<Queue::knot>& next) {

	this->data = data;
	this->next = std::move(next);
	this->key = key;
}

Queue::knot::~knot() {

	this->next = nullptr;
}

Queue::Queue() {

}

Queue::Queue(Queue& copy):head(nullptr),isEmpty(true) {
	head = std::move(copy.head);
	isEmpty = copy.isEmpty;
}


Queue& Queue::operator=(Queue& rhs) {
	head = std::move(rhs.head);
	isEmpty = rhs.isEmpty;
	return *this;
}



void Queue::push(const int& T) {
	if (is_empty())
	{
		std::unique_ptr<knot> teil = nullptr;
		std::unique_ptr<knot>  first = std::make_unique<knot>(T, T, teil);
		head = std::move(first);
		isEmpty = false;
	}
	else if (T < head->get_key())
	{
		std::unique_ptr<knot> first = std::make_unique<knot>(T, T, head);
		head = std::move(first);
	}
	else
	{
		knot* tmp = head.get();
		bool find = false;
		while ((tmp->get_ptr()->get_ptr() != nullptr) && (find == false))
		{
			if ((T >= tmp->get_key()) && (T >= tmp->get_ptr()->get_key()))
			{
				tmp = tmp->get_ptr().get();
			}
			else if ((T >= tmp->get_key()) && (T < tmp->get_ptr()->get_key()))
			{
				find = true;
				std::unique_ptr<knot> first = std::make_unique<knot>(T, T,tmp->get_ptr());
				tmp->get_ptr() = std::move(first);
			}
		}
		if (find == false)
		{
			if (tmp->get_ptr()->get_key() > T)
			{
				std::unique_ptr<knot> first = std::make_unique<knot>(T, T,tmp->get_ptr());
				tmp->get_ptr() = std::move(first);
			}
			else
			{
				std::unique_ptr<knot> teil = nullptr;
				std::unique_ptr<knot> first = std::make_unique<knot>(T, T, teil);
				tmp->get_ptr()->get_ptr() = std::move(first);
			}
		}
	}
};

bool Queue::is_empty() const {
	return isEmpty;
}

int Queue::knot::get_key() {

	return key;
}

std::unique_ptr<Queue::knot>& Queue::knot::get_ptr() {
	return next;
};

void Queue::pop(){
	if (head->get_ptr() == nullptr)
	{
		isEmpty = true;
	}
	head = std::move(head->get_ptr());
};

const int Queue::front() const{
	return head->get_key();
};