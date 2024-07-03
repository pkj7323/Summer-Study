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

//friend 키워드를 함수 앞에 쓰면, 해당 함수는 해당 클래스의 private 멤버에 접근할 수 있다.
//이를 이용해 operator overloading을 구현할 수 있다.-> 연산자 중 이항 연산자의 경우
//위치가 바뀌면 오류가 나는 경우가 존재 한다. 이를 해결하기 위해 friend 키워드를 사용한다.
//오류가 나는 이유가 컴파일러가 암시적 생성자로 생성하지만 클래스의 멤버 변수에 접근하지 못하는 경우 이기 때문이다.
//  friend (리턴타입) operator+(const (클래스)& a, const (클래스)& b);

//자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의합시다!

//좀더 공부해야 할 부분 은 입출력,첨자,타입변환,증감연산자들의 원형이 어떤 것인지 알아야 한다.

//타입 변환 연산자가 필요한 이유 모든 연산자를 다만들기에는 너무 고통스럽다.
//원형:  operator (변환 하고자 하는 타입) ()
