
#include <iostream>
#include "Pizza.h";

int main()
{
    setlocale(LC_ALL,"Ru");
    Pizza pizza = PizzaBilder()
        .SetDough("высший", 2, 0.5, 1)
        .SetSous("chily")
        .SetTopping("1234")
        .bild();
    pizza.Display();
    return 0;
}

