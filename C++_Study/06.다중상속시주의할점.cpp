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

	// B�� a����, A�� a���� ������ �� ���ٴ� ���� �߻�
	//c.a = 3;
}


// ���̾Ƹ�� ��� 
// Me�� �� ���� Ŭ������ ��� �ޱ⿡ Human�� �� ������ �ߺ��ȴ�.
class Human {
	// ...
};
// Human�� virtual�� ��� �޴´ٸ� Me���� ���� ��ӽÿ��� �����Ϸ��� ������ Human�� �ѹ��� �����ϵ��� ���� ���� 
// ���� ��� �ÿ� Me�� �����ڿ��� HandsomeHuman �� SmartHuman �� �����ڸ� ȣ���ϰ�, Human �� ������ ���� ȣ��
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