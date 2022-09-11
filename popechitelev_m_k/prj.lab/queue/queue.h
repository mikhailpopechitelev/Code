#pragma once
#ifndef queue
#define queue

#include<iosfwd>
#include<stdint.h>
#include<memory>



struct Queue{

private:
	//������������ ������� � �����������
	struct knot {
	private:

		int data = 0;
		std::unique_ptr<knot> next;    
		int key = 0;

	public:

		knot(const int& data, const int& key, std::unique_ptr<knot>& next);
		~knot();
		//std::unique_ptr<knot> make_unique(knot new_knot);
	};

	//����
	std::unique_ptr<knot> head;
	std::unique_ptr<knot> teil;
	bool isEmpty = true;

public:
	//������
	knot& find_position(const int& T);
	void push(const int& T);
	void pop();
	const int& Top() const;
	bool is_empty() const;

	//������������/�����������
	Queue();
	Queue(const Queue& copy);
	~Queue() = default;

	//���������� ����������
	Queue& operator= (const Queue&);

};

#endif