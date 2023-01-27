class Array {
    const int dim;  // 몇 차원 배열인지
    int* size;  // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다.

    // 클래스 안에도 클래스를 넣을 수 있다.
    struct Address {
        int level;
        // 맨 마지막 레벨(dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위
        // 레벨에서는 다음 Address 배열을 가리킨다.
        void* next;
    };
    // 배열의 시작점을 가리키기 위한 Adress 포인터
    Address* top;

public:
    Array(int dim, int* array_size) : dim(dim) {
        size = new int[dim];
        for (int i = 0; i < dim; i++) size[i] = array_size[i];
    }
};

Array(int dim, int* array_size) : dim(dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = array_size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);
}
Array(const Array& arr) : dim(arr.dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = arr.size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);

    // 내용물 복사
    copy_address(top, arr.top);
}

void copy_address(Address* dst, Address* src) {
    if (dst->level == dim - 1) {
        for (int i = 0; i < size[dst->level]; ++i)
            static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
        return;
    }
    for (int i = 0; i != size[dst->level]; i++) {
        Address* new_dst = static_cast<Address*>(dst->next) + i;
        Address* new_src = static_cast<Address*>(src->next) + i;
        copy_address(new_dst, new_src);
    }
}

~Array() {
    delete_address(top);
    delete[] size;
}


// N차원 배열을 생성 
// N차원 이기에 for문으로 수행할 수 없다
// 재귀 함수를 통해 배열을 생성해야 한다.

// 재귀 함수를 위한 두 가지 스텝
// 1. 함수에서 처리하는 것, 현재 단계에서 다음 단계로 넘어가는 과정이 무엇인가
// -> n 레벨의 Address 배열이라면 이들의 next 다음 레벨인 n+1 레벨의 Address 배열을 지정해주고 각각 원소에 대해 처리 
// 2. 재귀 호출이 종료되는 조건은 무엇인가
// -> Address 배열의 레벨이 (dim - 1) 
// 배열의 레벨이 (dim - 1)이면 Address의 next에 int 배열의 데이터가 들어가게 되서 재귀 호출이 끝난다.

// address 를 초기화 하는 함수이다. 재귀 호출로 구성되어 있다.
// 생성자는 위에서 아래로 메모리 확장
void initialize_address(Address* current) {
    if (!current) return;
    if (current->level == dim - 1) {  // 두 번째 질문 (종료 조건)
        current->next = new int[size[current->level]];
        return;
    }
    current->next = new Address[size[current->level]];
    for (int i = 0; i != size[current->level];
        i++) {  // 다음 단계로 넘어가는 과정
        (static_cast<Address*>(current->next) + i)->level = current->level + 1;

        initialize_address(static_cast<Address*>(current->next) + i);
    }
}

// 소멸자는 아래에서 위로 메모리를 소멸 
void delete_address(Address* current) {
    if (!current) return;
    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
        delete_address(static_cast<Address*>(current->next) + i);
    }

    if (current->level == dim - 1) {
        delete[] static_cast<int*>(current->next);
    }

    delete[] static_cast<Address*>(current->next);
}