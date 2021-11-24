#include <iostream>
#include <array>
#include <algorithm>

auto calculSommePairs(std::array<int,50>& tab) {
	int retval{ 0 };
	for (auto v : tab) {
		if (v % 2 == 0) retval += v;
	}
	return retval;
}

enum class exercice {
	PAIRS, FIB, TVARIADIC
};

auto fibonacci(int n)  {
	if (n < 2)  return n;
	auto n1 = fibonacci(n - 1);
	return n1 + n;
}
 /*
Point de départ pour template variadic */

template <typename T>
double somme(T t) {
	return t;
}


template <typename T, typename... Rest>
double somme(T t, Rest... rest) {
	
	static_assert(sizeof ...(rest) <3 , "Trop de parametres");

	return t + somme(rest...);
}

auto main() -> int{

	auto exo = exercice::TVARIADIC;


	// 1
	if (exo == exercice::PAIRS) {
		auto indice{ 0 };
		std::array<int, 50> tab;
		std::generate_n(begin(tab), 50, [&indice]() {return indice++; });

		auto res = calculSommePairs(tab);
		std::cout << " Résultat " << res << std::endl;
	}

	// 2
	if (exo == exercice::FIB) {
		std::cout << " Fibonacci " << fibonacci(4);

	}

	//3
	if (exo == exercice::TVARIADIC) {

		std::cout << " Variadic " << somme(1.0,2.0,3.0) << std::endl;

		std::cout << " Variadic " << somme(1.0, 2.0, 3, 5L, 7.8, 3.5) << std::endl;
	}

	return 0;
}

/*

auto main() -> int {

	auto exo = // valeur d'un énuméré typé 

	// 1
	if (exo == <valeur1>) {
		// Créer et remplir un tableau d'entiers

		auto res = calculSommePairs(tab);
		std::cout << " Résultat " << res << std::endl;
	}

	// 2
	if (exo == <valeur2>) {

		std::cout << " Fibonacci " << fibonacci(4);

	}

	//3
	if (exo ==<valeur3>) {

		std::cout << " Variadic " << somme(1.0, 2.0, 3.0) << std::endl;

		std::cout << " Variadic " << somme(1.0, 2.0, 3, 5L, 7.8, 3.5) << std::endl;

	}

	return 0;
}*/