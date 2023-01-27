#include <iostream>
using namespace std;

//int main() {
//	std::cout << "Hello, World!!" << std::endl;
//	return 0;
//}

int main() {
	cout << "Hello, World!!" << endl; // cout endl 모두 iostream 헤더파일의 std라는 이름 공간에 정의되어 있는 것 
	return 0;
}


// 이름 공간에 굳이 이름을 설정하지 않을 수 있다.
// 해당 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있음
// static 키워드를 사용한 것과 같은 효과
namespace {
	// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
	// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
	int OnlyInThisFile() {}

	// 이 변수 역시 static int x 와 동일합니다.
	int only_in_this_file = 0;
}  // namespace

int main() {
	OnlyInThisFile();
	only_in_this_file = 3;
}