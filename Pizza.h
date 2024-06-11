#pragma once
/*
Создайте класс Пицца с параметрами
- тесто
- соус
- топпинги

Но тесто имеет тип Тесто, у которого есть свои параметры
- сорт муки
- количестно куриных яиц
- количество молока
- количество соли

Используйте шаблон Строитель для создания классов Пицца и Тесто.
*/

#include <string>
using std::string;
using std::cout;

class Dough {
	string typeOfflour;//сорт муки
	int numberOfeggs;//кол яиц
	double amountOfmilk;//кол молока
	double amountOfsalt;//кол соли
public:
	void SetFlour(string f) { typeOfflour = f; }
	void SetEggs(int e) { numberOfeggs = e; }
	void SetMilk(double m) { amountOfmilk = m; }
	void SetSalt(double s) { amountOfsalt = s; }

	string GetFlour() const { return typeOfflour; }
	int GetEggs() const { return numberOfeggs; }
	double GetMilk() const { return amountOfmilk; }
	double GetSalt() const{ return amountOfsalt; }
};

class Pizza {
	Dough* dough;
	string sous;
	string topping;
public:	
	void SetSous(string s) { sous = s; }
	void SetTopping(string t) { topping = t; }
	void SetDough(Dough* d) {
		dough = d;
	}
	void Display() {
		cout << "Dough from " << dough->GetFlour() << ", from " << dough->GetEggs() << " eggs"
			<< ", from " << dough->GetMilk() << " milk" << ", from " << dough->GetSalt() << " salt"
			<< ", from sous " << sous << ", from topping " << topping;
	}
};

class PizzaBilder {
	Pizza pizza;
	Dough* dough;
public:
	Pizza bild() { return pizza; }
	PizzaBilder& SetDough(string flour, int eggs, double milk, double salt) {
		dough = new Dough;
		dough->SetFlour(flour);
		dough->SetEggs(eggs);
		dough->SetMilk(milk);
		dough->SetSalt(salt);
		pizza.SetDough(dough);
		return *this;
	}
	PizzaBilder& SetSous(string sous) {
		pizza.SetSous(sous);
		return *this;
	}
	PizzaBilder& SetTopping(string topping) {
		pizza.SetTopping(topping);
		return *this;
	}
};