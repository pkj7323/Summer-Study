class A {
private:
    void private_func() {}
    int private_num;

    // B 는 A 의 친구!
    friend class B;

    // func 은 A 의 친구!
    friend void func();
};

class B {
public:
    void b() {
        A a;

        // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
        a.private_func();
        a.private_num = 2;
    }
};

void func() {
    A a;

    // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
    // 가능하다.
    a.private_func();
    a.private_num = 2;
}

int main() {}
//friend 키워드는 클래스나 함수를 친구로 지정하는 키워드이다.
//친구로 지정된 클래스나 함수는 해당 클래스의 private 멤버에 접근할 수 있다.
//하지만 B는 A의 모든 private 멤버에 접근할 수 있지만, A는 B의 private 멤버에 접근할 수 없다.