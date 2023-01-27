#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 파일 쓰기 준비
    // ofstream 은 열려는 파일이 존재하지 않으면 해당 파일을 생성하고 연다.
    // 해당 파일이 이미 존재 시 특별한 설정을 하지 않는다면 해당 파일 내용이 다 지워지고 새로운 내용을 덮어 씌어진다.
    std::ofstream out("test.txt");
    
    // out 객체를 생성시 옵션으로 app을 주면 파일에 기존 파일의 내용을 지우고 쓰는 것이 아닌 뒤에 내용을 붙여 쓴다.
    std::ofstream out("test.txt", std::ios::app);

    /*
    ios::ate - 자동으로 파일 끝에서 부터 읽기와 쓰기 실시(파일 열 때 위치 지정자가 파일 끝을 가리키고 있다.)
    ios::trunc - 파일 스트림을 열면 기존에 있던 내용들이 모두 지워진다 / 기본적으로 ofstream 객체를 생성할 때 이와 같은 설정
    ios::in, std::ios::out 파일에 입력을 할 지 출력을 할 지 지정 / ifstream/ofstream객체를 생성할때 각각 이미 설정 
    */

    std::string s;
    if (out.is_open()) {
        out << "이걸 쓰자~~";
    }

    // 두 파일에는 모두 abc 라고 써 있었습니다.
    std::ofstream out("test.txt", std::ios::app);
    std::ofstream out2("test2.txt", std::ios::ate);

    // 현재 파일은 빈 파일이라 생각되어 위치 지정자라 움직일 공간이 없기에 위치 지정자는 움직이지 않고 출력
    out.seekp(3, std::ios::beg);

    // 스트림 위치 지정자는 움직여서 3칸 뒤에 출력되긴 했지만 기존에 써져 있던 내용이 모두 지워진다(ate는 기존 파일의 내용을 보존하지 않는다)
    out2.seekp(3, std::ios::beg);

    out << "추가";
    out2 << "추가";

    return 0;
}