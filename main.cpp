#include <iostream>

struct Base{
	int id;
	float value;
};
struct D1 :Base{
	D1()
	{
		id = 1;
		value = 1.1;
	}
};
struct D2 :Base{
	D2()
	{
		id = 2;
		value = 2.2;
	}
};
struct D3 :D1,D2{
};

Base* D1BaseToD2Base(Base* base)
{
	D1* d1_ptr = static_cast<D1*>(base);
	D3* d3_ptr = static_cast<D3*>(d1_ptr);
	D2* d2_ptr = static_cast<D2*>(d3_ptr);
	Base* base_ptr = static_cast<Base*>(d2_ptr);
	return base_ptr;
}

int main(){
	D3 d3;
	D1* D1_in_D3_ptr = &d3;
	Base* Base_in_D1_ptr = D1_in_D3_ptr;
		
	Base* Base_in_D2_ptr = D1BaseToD2Base(Base_in_D1_ptr);
	std::cout << "Base_in_D1_ptr == " << Base_in_D1_ptr << std::endl;
	std::cout << "Base_in_D2_ptr == " << Base_in_D2_ptr << std::endl;

	std::cout << "id_D1 == " << Base_in_D1_ptr->id << std::endl;
	std::cout << "value_D1 == " << Base_in_D1_ptr->value << std::endl;
	std::cout << "id_D2 == " << Base_in_D2_ptr->id << std::endl;
	std::cout << "value_D2 == " << Base_in_D2_ptr->value << std::endl;
	return 0;
}
