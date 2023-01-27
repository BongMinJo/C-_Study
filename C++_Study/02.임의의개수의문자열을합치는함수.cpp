//concat = s1 + s2 + s3;
// s2를 더할때 메모리 할당이 발생하고 s3을 더할때 메모리 할당이 또 한번 발생
//concat = s1.operator+(s2).operator+(s3);

// 메모리 할당 1번으로
//std::string concat;
//concat.reserve(s1.size() + s2.size() + s3.size());  // 여기서 할당 1 번 수행
//concat.append(s1);
//concat.append(s2);
//concat.append(s3);

// StrCat함수가 임의의 개수의 인자를 받아야된다.
//std::string concat = StrCat(s1, "abc", s2, s3);

#include <iostream>
#include <string>

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    // 먼저 합쳐질 문자열의 총 길이를 구한다.
    size_t total_size = GetStringSize(s, strs...);

    // reserve 를 통해 미리 공간을 할당해 놓는다.
    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;
    AppendToString(&concat_str, strs...);

    return concat_str;
}

//template <typename String>
//std::string StrCat(const String& s) {
//    return std::string(s);
//}
//
//template <typename String, typename... Strings>
//std::string StrCat(const String& s, Strings... strs) {
//    // operator+를 매번 호출
//    return std::string(s) + StrCat(strs...);
//}

int main() {
    // std::string 과 const char* 을 혼합해서 사용 가능하다.
    // 인자 수 만큼 메모리 할당이 일어난다.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
        " ", std::string("sentence"));
}