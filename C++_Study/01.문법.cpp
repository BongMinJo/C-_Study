#include <iostream>

using namespace std;

int main() {
    int i = 1, sum = 0;

    // for 문
    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    // while 문
    while (i <= 10) {
        sum += i;
        i++;
    }

    // if - else 문
    int lucky_number = 3;
    std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

    int user_input;  // 사용자 입력

    while (1) {
        std::cout << "입력 : ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        }
        else {
            std::cout << "다시 생각해보세요~" << std::endl;
        }
    }

    // switch case 문
    int user_input;
    cout << "저의 정보를 표시해줍니다" << endl;
    cout << "1. 이름 " << endl;
    cout << "2. 나이 " << endl;
    cout << "3. 성별 " << endl;
    cin >> user_input;

    switch (user_input) {
    case 1:
        cout << "Psi ! " << endl;
        break;

    case 2:
        cout << "99 살" << endl;
        break;

    case 3:
        cout << "남자" << endl;
        break;

    default:
        cout << "궁금한게 없군요~" << endl;
        break;
    }

    return 0;
}