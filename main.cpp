#include <iostream>

struct Base{
	int id;
	float value;
};
struct D1 :virtual Base{
	D1()
	{
		id = 1;
		value = 1.1;
	}
};
struct D2 :virtual Base{
	D2()
	{
		id = 2;
		value = 2.2;
	}
};
struct D3 :D1,D2{
};

int main(){
	D3 d3;
	std::cout << "id == " << d3.id << std::endl;
	std::cout << "value == " << d3.value << std::endl;
	return 0;
}
