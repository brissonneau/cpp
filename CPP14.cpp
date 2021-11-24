#include <iostream>
#include <bitset>
#include <thread>

#include <chrono>

// C++11

template<typename LHS, typename RHS>
auto add(LHS lhs, RHS rhs) -> decltype(lhs + rhs) {
	return lhs + rhs;
}

// C++14

template<typename LHS, typename RHS>
auto add(LHS lhs, RHS rhs) {
	return lhs + rhs;
}

template<typename T>
	constexpr T pi = T(3.1415926535897932385);


	template<typename T, typename U>
	constexpr bool is_same = std::is_same<T, U>::value;

	[[deprecated]] void f() {}
	[[deprecated("cette fonction est depreciee")]] void g() {}


	constexpr int min(std::initializer_list<int> xs) {
		int min = std::numeric_limits<int>::max();
		for (int x : xs) {
			if (x < min) {
				min = x;
			}
		}
		return min;
	}

	class Ressource {};

	std::unique_ptr<Ressource> create_ressource(){
		return std::unique_ptr<Ressource>(new Ressource());
	}

	void do_something(std::unique_ptr<Ressource>&) {}

	// C++17
	[[maybe_unused]]
	void ma_fonction_inutile() {
		std::cout << "oups";
	}

	std::tuple<int,int> fct_tuple() {
		return std::tuple(4, 5);
	}

	template <typename T>
	auto get_value(T t) {
		if constexpr (std::is_pointer_v<T>)
			return *t;
		else
			return t;
	}

	
auto main() -> int {
	


	// C++14

	int d = 0b00101010;           // Base binaire (2)
	std::cout << d << std::endl;  // affiche 42

	std::cout << "0b" << std::bitset<sizeof(d) * 8>(d); // affiche 0b00101010


	

	auto const piD = pi<double>;


	bool t = is_same<int, int>;   // true

	const int million = 1'000'000'000;


	f();
	g();

	constexpr int z = min({ 1, 3, -2, 4 });


	//std::unique_ptr<Ressource> r = create_ressource();
	//auto use_ressource = [ur = std::move(r)](){  /*utiliser ur; };
	//std::thread th(use_ressource);
	
	using namespace std::literals::chrono_literals;

	auto en_secondes = 100s;
	auto val = std::make_unique<int>(5);


	// C++17
	auto [droite, gauche] = fct_tuple();
	
	auto valeur1 = get_value(42);

	auto valeur2 = get_value(new int(42));

	std::string_view valeur_immuable = "Hello";

	 //valeur_immuable += "  world";

	return 0;
}

