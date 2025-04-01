template <typename T> requires std::floating_point<T>
class complex_number
{
	T parte_reale, parte_immaginaria;
	
public:

//seguono i costruttori
	complex_number()
		: parte_reale(0), parte_immaginaria(0)
	{}
	
	explicit complex_number(T re)
		:parte_reale(re), parte_immaginaria(0)
	{}
	
	complex_number (T re, T im)
		: parte_reale(re), parte_immaginaria(im)
	{}
	//segue il metodo che restituisce la parte reale del numero complesso
	T p_reale(void) const {
		return parte_reale;
	}
	
	//segue il metodo che restituisce la parte reale del numero complesso
	T p_imag(void) const{
		return parte_immaginaria;
	}
	
	//segue il metodo che restituisce la parte reale del numero complesso
	complex_number<T> coniugato(void) {
		return complex_number<T>(parte_reale,-parte_immaginaria);
	}
	
	// definizione dell'operatore += tra complessi
	complex_number& operator+=(const complex_number& other) {
        T a = parte_reale;
        T b = parte_immaginaria;
        T c = other.parte_reale;
        T d = other.parte_immaginaria;
        parte_reale = a+c;
     parte_immaginaria = b+d;
        return *this;
	}
	
	//L'operatore + deve creare un nuovo oggetto, senza modificare quelli esistenti.

//Se avessimo scritto direttamente this += other;, 
//avremmo modificato l'oggetto originale, il che non è desiderato per +.
	// definizione dell' operatore + in termini dell' operatore +=
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	// definisco l'operatore += tra un complesso ed un elemento di tipo T a destra
	complex_number& operator+=(const T& other) {
        parte_reale += other;
        return *this;
	}
	// come prima definisco l'operatore + in termini dell' operatore +=, questa volta
	// come operazione += tra un complesso ed un elt di tipo T a destra
	complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	// definizione dell'operatore *= 
	complex_number& operator*=(const complex_number& other) {
        T a = parte_reale;
        T b = parte_immaginaria;
        T c = other.parte_reale;
        T d = other.parte_immaginaria;
        parte_reale = a*c-b*d;
     parte_immaginaria = a*d+b*c;
        return *this;
	}
	
	// definizione dell' operatore * in termini dell' operatore *=
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	// definisco l'operatore *= tra un complesso ed un elemento di tipo T a destra
	complex_number& operator*=(const T& other) {
        parte_reale *= other;
	 parte_immaginaria *= other;
        return *this;
	}
	//come prima definisco l'operatore * in termini dell' operatore *=, questa volta
	// come operazione *= tra un complesso ed un elt di tipo T a destra
	complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

// le seguenti 2 operazioni sono definite fuori dalla classe e sono necessarie per la 
// computazione della somma e del prodotto di un elt di tipo T a sinistra e un 
// numero complesso a destra
template<typename T> requires std::floating_point<T>
complex_number<T>
operator+(const T& i, const complex_number<T>& r)
{
    return r + i;
}

template<typename T> requires std::floating_point<T>
complex_number<T>
operator*(const T& i, const complex_number<T>& r)
{
    return r * i;
}

// overload di << per rendere stampabiili i numeri complessi.

template<typename T> requires std::floating_point<T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& c) {
    if (c.p_imag() != 0)
		if(c.p_imag()>0)
			if(c.p_imag()!=1)
				os << c.p_reale() << "+" << c.p_imag()<< "i";
			else
				os << c.p_reale() << "+i";
		else
			if(c.p_imag()!=-1)
				os << c.p_reale() << "" <<c.p_imag()<<"i";
			else
				os << c.p_imag() << "-i";
    else
        os << c.p_reale();

    return os;
}