#pragma once
#ifndef queue
#define queue

#include<iosfwd>
#include<stdint.h>
#include<>

//������������ ������� � �����������

struct Queue {
private:
	//����


public:
	//������
	void push(const int& T);
	void pop();
	const int& T() const;
	bool is_empty() const;

	//������������/�����������
	Queue();
	Queue(const Queue& copy);
	~Queue() = default;

	//���������� ����������
	Queue& operator= (const Queue&);



};

#endif