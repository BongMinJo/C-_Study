class Parent {
public:

	// �ڹٿ����� ��� �Լ����� ����Ʈ�� �����Լ��� ���� ������ ���� ���ε� ����
	// C++������ virtual Ű���带 ����ؾ��Ѵ�.
	// �����Լ��� ���� �ణ�� ������� ����
	// �̷����� C++������ ��� �Լ��� ����Ʈ�� �����Լ��� �ǵ��� �������� �ʴ´�.
	virtual void func1();
	virtual void func2();
};
class Child : public Parent {
public:
	// C++ �����Ϸ��� ���� �Լ��� �ϳ��� �����ϴ� Ŭ������ ���� ���� �Լ� ���̺��� �����.

	virtual void func1();
	void func3();
};

int main() {
	Parent* p = new Parent();
	p->func1();

	Parent* c = new Child();
	// ���� �Լ� ���̺��� �����Ͽ� Child::func1()�� ȣ�� 
	// Parent::func() �������̵�
	c->func1();
}