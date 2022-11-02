/*Implement a class Complex which represents the Complex Number data type. Implement 
the following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers*/

#include<iostream>
using namespace std;
int r1,r2,i1,i2;
class Complex {

	public:
		int r, i;
    
    Complex(int tempr = 0, int tempi = 0)
	{
		r = tempr;
		i = tempi;
    }

	Complex addComp(Complex C1, Complex C2)
	{
		Complex temp;
        temp.r = C1.r + C2.r;
        temp.i = C1.i + C2.i;
        return temp;
	}
    
    Complex multComp(Complex C1, Complex C2)
	{
		Complex temp;
        temp.r = (C1.r * C2.r) - (C1.i * C2.i) ;
        temp.i = (C1.r * C2.i) + (C1.i * C2.r);
    	return temp;
	}

};


int main()
{
    Complex C1(1, 2);
    cout<<"Complex number 1 : "<< C1.r<< " + i"<< C1.i<<endl;
    Complex C2(3, 4);
    cout<<"Complex number 2 : "<< C2.r<< " + i"<< C2.i<<endl;
    Complex C3;
    C3 = C3.addComp(C1, C2);
    cout<<"Sum of complex number : "<< C3.r << " + i"<< C3.i<<endl;
    C3 = C3.multComp(C1, C2);
    cout<<"Product of complex number : "<< C3.r << " + i"<< C3.i<<endl;                
}


