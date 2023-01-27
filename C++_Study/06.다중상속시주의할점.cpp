class A {
public:
	int a;
};

class B {
public:
	int a;
};

class C : public B, public A {
public:
	int c;
};

int main() {
	C c;

	// B의 a인지, A의 a인지 구분할 수 없다는 오류 발생
	//c.a = 3;
}


// 다이아몬드 상속 
// Me가 두 개의 클래스를 상속 받기에 Human의 두 변수가 중복된다.
class Human {
	// ...
};
// Human을 virtual로 상속 받는다면 Me에서 다중 상속시에도 컴파일러가 언제나 Human을 한번만 포함하도록 지정 가능 
// 가상 상속 시에 Me의 생성자에서 HandsomeHuman 과 SmartHuman 의 생성자를 호출하고, Human 의 생성자 또한 호출
//class HandsomeHuman : public Human {
class HandsomeHuman : public virtual Human {
	// ...
};
//class SmartHuman : public Human {
class SmartHuman : public virtual Human {
	// ...
};
class Me : public HandsomeHuman, public SmartHuman {
	// ...
};