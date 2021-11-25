#include <iostream>
#include <string>

struct Qualif {

	std::string data;


	Qualif(std::string nom) : data(nom) {
		std::cout << " creation de qualif " << data << std::endl;
	}

	Qualif(const Qualif& other) : data(other.data) {
		std::cout << " cpy ctor de qualif " << data << std::endl;
	}

	Qualif& operator=(const Qualif& other) {
		data = other.data;
		std::cout << " op cpy de qualif " << data << std::endl;
		return *this;
	}

	Qualif(Qualif&& other) noexcept : data(other.data) {
		std::cout << " move ctor de qualif " << data << std::endl;
	}

	Qualif& operator=(Qualif&& other) noexcept{
		data = other.data;
		std::cout << " op move de qualif " << data << std::endl;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Qualif& d);

	
};

std::ostream& operator<<(std::ostream& os, const Qualif& d) {
	os << d.data;
	return os;
}

class Tableau
{
private:
	int* _p_vals;
	int _size;
	Qualif _nom;

public:
	Tableau(int n, std::string nom)
		: _p_vals(new int[n])
		, _size(n),
		_nom(nom)
	{
		std::cout << "creation de " << _nom.data << std::endl;
	}

	Tableau(const Tableau& other)
		: _p_vals(new int[other._size])
		, _size(other._size)
		, _nom(other._nom)

	{
		for (int i = 0; i < _size; ++i)
		{
			_p_vals[i] = other._p_vals[i];
		}
		std::cout << " copie du tableau " << _nom.data << std::endl;
		_nom.data = "copie";
	}
	Tableau(Tableau&& other) noexcept
		: _p_vals(other._p_vals)
		, _size(other._size)
		, _nom(std::move(other._nom))

	{
		other._p_vals = nullptr;

		std::cout << " move du tableau " << _nom.data << std::endl;
		_nom.data = "move";
	}

	Tableau& operator=(const Tableau& other)  {
		if (this == &other) return *this;

		delete[] _p_vals;

		_p_vals = new int[other._size];
		_size = other._size;
		_nom = other._nom;

		for (int i = 0; i < _size; ++i)
		{
			_p_vals[i] = other._p_vals[i];
		}
		std::cout << " op copie du tableau " << _nom.data << std::endl;
		_nom.data = "op copie";
		return *this;
	}

	Tableau& operator=(Tableau&& other) noexcept {
		if (this == &other) return *this;

		delete[] _p_vals;

		_p_vals = other._p_vals;
		_size = other._size;
		_nom = std::move(other._nom);

		std::cout << " op move du tableau " << _nom.data << std::endl;
		_nom.data = "op move";

		other._p_vals = nullptr;
		return *this;
	}

	~Tableau()
	{
		delete[] _p_vals;
		std::cout << "suppression de " << _nom.data << std::endl;
	}

};

Tableau fabrique(std::string nom)
{
	Tableau tab{ 42,nom };
	return tab;
}

class Complexe {

	int reel;
	int img;

public :
	Complexe(int a, int b) : reel(a), img(b) {}
	explicit Complexe(int a) : reel(a), img(a) {}


	friend Complexe operator +(const Complexe& g, const Complexe& d) {
		return Complexe(g.reel + d.reel, g.img + d.img);
	}
	Complexe& operator ++() {
		++reel;
		++img;
		return *this;
	}
	Complexe operator ++(int) {
		Complexe ret(*this);
		reel++;
		img++;
		return ret;
	}
	explicit operator int() {
		return reel;
	}
};

int main() {

	Complexe c1{ 1,2 };
	Complexe c2{ 4,5 };

	Complexe c3 = c1 + c2;

	Complexe c4{ 42 };
	//c4 = 56;
	Complexe c5 = c1 + (Complexe)1; // ambiguuite

		Complexe c6 = ++c5;

		Complexe c7 = c6++;

		int valeur = (int)c7;

		//valeur = c6;


	{
		Tableau tab_copy{ fabrique("origine") };





	//	Tableau tab_autre{ 32,"autre" };
	//	tab_copy = std::move(fabrique("origine"));
	}















	

	system("pause");
}