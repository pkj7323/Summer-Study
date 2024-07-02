class A {
private:
    void private_func() {}
    int private_num;

    // B �� A �� ģ��!
    friend class B;

    // func �� A �� ģ��!
    friend void func();
};

class B {
public:
    void b() {
        A a;

        // ��� private �Լ��� �ʵ�������� ģ���̱� ������ ���� �����ϴ�.
        a.private_func();
        a.private_num = 2;
    }
};

void func() {
    A a;

    // ��� private �Լ��� �ʵ�������� ���� ���������� ģ���̱� ������ ����
    // �����ϴ�.
    a.private_func();
    a.private_num = 2;
}

int main() {}
//friend Ű����� Ŭ������ �Լ��� ģ���� �����ϴ� Ű�����̴�.
//ģ���� ������ Ŭ������ �Լ��� �ش� Ŭ������ private ����� ������ �� �ִ�.
//������ B�� A�� ��� private ����� ������ �� ������, A�� B�� private ����� ������ �� ����.