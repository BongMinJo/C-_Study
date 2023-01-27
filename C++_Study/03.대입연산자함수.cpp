#include <iostream>

class Complex {
private:
    double real, img;

public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img; }

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    void println() {
        std::cout << "( " << real << " , " << img << " ) " << std::endl;
    }
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex c(0.0, 0.0);

    // operator=를 만들지 않더라도 컴파일하면 잘 작동
    // 컴파일러 차원에서 디폴트 대입 연산자를 지원
    // 디폴트 복사 생성자와 일맥상통 
    c = a * b + a / b + a + b;
    c.println();

    // a의 복사 생성자 호출
    //Some_Class a = b;  // ①
    
    // a의 기본 생성자가 호출된 다음 대입 연산자 함수가 실행 
    //Some_Class a;  // ②
    //a = b;

    // 연산자 오버로딩을 사용시 a+=b 와 a = a+b가 같다고 보장되지 않는다.
    // 컴파일러는 operator+ 와 operator= 를 정의해놓았다고 해서 a+=b 를 자동으로 a = a + b; 로 바꾸어 주지 않는다.
    // operator+=를 따로 만들어야지 +=를 사용할 수 있다.
    // 연산자 오버로딩을 하게 된다면 개별적인 정의 필요 
    a += b;
    a.println();
    b.println();
} 