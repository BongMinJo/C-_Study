/* new �� �迭 �Ҵ��ϱ� */

#include <iostream>

void func1() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int* list = new int[arr_size];
    //T* pointer = new T[size];

    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list;
}

void func2() {
    {
        int a = 4;
        std::cout << "�ȿ��� a : " << a;
    }

    std::cout << "�ۿ��� a : " << a;
}

void func3() {
    int a = 4;
    {
        std::cout << "�ܺ��� ���� 1" << a << std::endl;
        int a = 3;
        std::cout << "������ ���� " << a << std::endl;
    }

    std::cout << "�ܺ��� ���� 2" << a << std::endl;
}