#include "Base.hpp"
#include "common.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// const std::type_info *inheritedTypesOfStruct[3] = {
//     &typeid(A), &typeid(B), &typeid(C)
// };

Base* generate(void) {
	srand(time(NULL));
	switch ("\0\1\2"[rand() % 3]) {
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	}
	return NULL;
}

void identify(Base* p) {
	cout << (dynamic_cast<A*>(p) ? "A" :
			dynamic_cast<B*>(p) ? "B" :
			dynamic_cast<C*>(p) ? "C" : NULL) << endl;
}
void identify(Base& p) {
	try { (void)(dynamic_cast<A&>(p)); cout << "A" << endl; return; } catch (exception& e) {};
	try { (void)(dynamic_cast<B&>(p)); cout << "B" << endl; return; } catch (exception& e) {};
	try { (void)(dynamic_cast<C&>(p)); cout << "C" << endl; return; } catch (exception& e) {};
}

int main() {
	Base* randomly_class_object = generate();
	identify(randomly_class_object);
	identify(*randomly_class_object);
	return 0;
}
