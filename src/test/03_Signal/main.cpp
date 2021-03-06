#include <UDP/Signal/Signal.h>

#include <iostream>

using namespace Ubpa;
using namespace std;

int main() {
	Signal<float, int&, int> s0;
	auto connection = s0.Connect([](float, int& n) {
		n = 3;
		});
	int a = 2;
	s0.Emit(1.f, a, 3);
	cout << a << endl;
	s0.Disconnect(std::move(connection));
	a = 4;
	s0.Emit(1.f, a, 3);
	cout << a << endl;
}
