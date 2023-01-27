//concat = s1 + s2 + s3;
// s2�� ���Ҷ� �޸� �Ҵ��� �߻��ϰ� s3�� ���Ҷ� �޸� �Ҵ��� �� �ѹ� �߻�
//concat = s1.operator+(s2).operator+(s3);

// �޸� �Ҵ� 1������
//std::string concat;
//concat.reserve(s1.size() + s2.size() + s3.size());  // ���⼭ �Ҵ� 1 �� ����
//concat.append(s1);
//concat.append(s2);
//concat.append(s3);

// StrCat�Լ��� ������ ������ ���ڸ� �޾ƾߵȴ�.
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
    // ���� ������ ���ڿ��� �� ���̸� ���Ѵ�.
    size_t total_size = GetStringSize(s, strs...);

    // reserve �� ���� �̸� ������ �Ҵ��� ���´�.
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
//    // operator+�� �Ź� ȣ��
//    return std::string(s) + StrCat(strs...);
//}

int main() {
    // std::string �� const char* �� ȥ���ؼ� ��� �����ϴ�.
    // ���� �� ��ŭ �޸� �Ҵ��� �Ͼ��.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
        " ", std::string("sentence"));
}