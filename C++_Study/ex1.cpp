#include "header1.h"
#include "header2.h"

//자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 앞에 이름 공간을 명시하지 않고 자유롭게 부를 수 있다.
namespace header1 {
	int func() {
		foo();  // 알아서 header1::foo() 가 실행된다.
	}
}  // namespace header1

//다른 이름 공간에서 호출시 
namespace header1 {
	int func() {
		foo();           // 알아서 header1::foo() 가 실행된다.
		header2::foo();  // header2::foo() 가 실행된다.
	}
}  // namespace header1