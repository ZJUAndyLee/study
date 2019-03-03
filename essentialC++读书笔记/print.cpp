#include<iostream>
using namespace std;

class print_it {
public:
	print_it(ostream &ios) :os(ios) {};
	template<typename type>
	void print(const type &elem, char need = '\n') { os << elem << need; };
private:
	ostream &os;
};

int main() {
	print_it standard_out(cout);
	standard_out.print("hello world!");
	standard_out.print(211314);
	int a;
	cin >> a;
}
