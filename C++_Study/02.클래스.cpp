#include <iostream>

// Ŭ����(class) -> ��ü�� '���赵'
// �ν��Ͻ�(instance) -> Ŭ������ �̿��ؼ� ������� ��ü

class Animal {

// �ڱ� ��ü �ȿ����� ������ �� �ְ� ��ü �ܺο����� ������ �� ����
// Ű���� ��ø� ���� �ʾҴٸ� �⺻������ private �� ����
private:
    // ��� ����(member variable)
    int food;
    int weight;

// �ܺο��� ������ �̿�
public:
    // ��� �Լ�(member function)
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat() {
        std::cout << "�� ������ food   : " << food << std::endl;
        std::cout << "�� ������ weight : " << weight << std::endl;
    }
};  // �����ݷ� ���� ����!

int main() {
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}