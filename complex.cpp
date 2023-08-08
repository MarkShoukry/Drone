#include <iostream>

class complex
{
    public:
    complex(){};
    complex(int real , int imag) : real_(real) , imaginary(imag){}
    complex operator+(const complex & RHS)
    {
        this->real_ = real_ + RHS.real_;
        this->imaginary = imaginary + RHS.imaginary;
        return *this;
    }
    int getreal()const
    {
        return real_;
    }

     int getimag()const
    {
        return imaginary;
    }

    private:

    int real_ , imaginary;

};

int main()
{
    complex c1(4,5);
    complex c2(6,5);
    complex c3;

    c3 = c1+c2;

    std::cout<<c3.getreal() << " "<< c3.getimag() <<"i"<<std::endl;


    return 0;
}