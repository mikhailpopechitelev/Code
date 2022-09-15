#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
// сортировка очередями ,со сложностью n+w 

template<typename T>
void Radix_sort(std::vector<T>& v, const int& left, const int& right) {

	std::vector<std::queue<T>> q(256);
	const int cluster = sizeof(T);

	for (size_t k = 0; k < cluster; ++k)
	{
		for (size_t i = left; i <= right; ++i)
		{
			int r = (v[i] >> 8 * k) & 255;
			q[r].push(v[i]);
		}
		size_t pos = left;
		for (int i = 0; i < q.size(); i++)
		{
			while (!q[i].empty())
			{
				v[pos++] = q[i].front();
				q[i].pop();
			}
		}
	}
	int pos = right + 1;
	for (size_t i = left; i < right + 1; i++)
	{
		if (v[i] < 0)
		{
			pos = i;
			break;
		}
	}
	if (pos != right + 1)
	{
		std::reverse(v.begin() + left, v.begin() + pos);
		std::reverse(v.begin() + pos, v.begin() + right + 1);
		std::reverse(v.begin() + left, v.begin() + right + 1);
	}
}

int main() {

	std::vector<int64_t> v = { 7,5,3,1,5,7,-6,-2,-68,34 };
	Radix_sort(v, 0, v.size() - 1);

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}