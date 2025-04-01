#include <iostream>
#include "function.hpp"
int main (void){
	using ncomp = complex_number<double>;
	ncomp c1(-1.0,7.0);
	ncomp c2(-2.2,12.0);
	ncomp c3(-1.0,5);
	
	// controllo che i metodi definiti nel file function.hpp
	// p_reale e p_imag siano ben definiti
	
	std::cout<<"parte reale di c1:  "<<c1.p_reale()<<" parte immaginaria di c1: "<<c1.p_imag()<<std::endl;
	
	// controllo che l'operatore << funzioni correttamente
	
	std::cout<<c1<<std::endl;
	std::cout<<c2<<std::endl;
	std::cout<<c3<<std::endl;
	
	//creo un numero complesso senza parametri e uso il costruttore di default della classe complex_number<T>
	ncomp c4;
	std::cout<<c4<<std::endl; 
	
	// controllo che il construttore ove è presente explicit funzioni correttamente
	ncomp c5(2.1);
	std::cout<<"controllo che il construttore ove è presente explicit funzioni correttamente " 
		<< "c5=(2.1) = "<<c5<<std::endl;
		std::cout << "(" << c1 << ")" << "+" << "(" << c5 << ")" << " = " << c1+c5 << std::endl;
	
	// controllo il funzionamento del metodo per trovare il coniugato (metodo coniugato)
	std::cout << "Il coniugato di "<< c1 << " è "<< c1.coniugato() << std::endl;
	
	
	//verifico ora la correttezza dei risultati nella somma di 2 complessi
	std::cout <<"verifico ora la correttezza dei risultati nella somma di 2 complessi"<<std::endl;
	std::cout << "(" << c1 << ")" << "+" << "(" << c2 << ")" << " = " << c1+c2 << std::endl;
	std::cout << "(" << c2 << ")" << "+" << "(" << c5 << ")" << " = " << c2+c5 << std::endl;
	
	// controllo che la somma di un complesso con un elt di tipo T a destra sia corretta
	std::cout << c1 << " + 1.16 = " << c1 + 1.16 <<std::endl;
	
	// verifico ora che il prodotto funzioni correttamente
	std::cout <<"verifico ora che il prodotto funzioni correttamente"<<std::endl;
	std::cout << "(" << c1 << ")" << "*" << "(" << c2 << ")" << " = " << c1*c2 << std::endl;
	std::cout << "(" << c1 << ")" << "*" << "(" << c3 << ")" << " = " << c1*c3 << std::endl;
	std::cout << "(" << c2 << ")" << "*" << "(" << c3 << ")" << " = " << c2*c3 << std::endl;
	
	// controllo che il prodotto di un complesso con un elt di tipo T a destra sia corretta
	std::cout << "(" << c2 << ")" << "*(-2) = " << c2*-2.0 <<std::endl;
	
	// controllo che le operazioni ove si ha un tipo T a sinistra e un complesso a destra 
	// funzionino correttamente.
	std::cout<<"controllo che le operazioni ove si ha un tipo T a sinistra e un complesso a destra  funzionino correttamente."<<std::endl;
	// per la somma:
	ncomp c6 = 1.1+c2;
	std::cout << 1.1 << "+" << "(" << c2 << ")" << " = "<< c6 << std::endl;
	
	// per il prodotto: 
	ncomp c7 = -2.0*c1;
	std::cout << "(" << -2 << ")*(" << c1 << ") = " << c7 << std::endl;
}