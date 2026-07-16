#include <bits/stdc++.h>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;

    Singleton()
    {
        cout << "Singleton constructor called!" << endl;
    }

public:
    static Singleton *getInstance()
    {
        return instance;
    }
};

// initalise static members;
Singleton *Singleton::instance = new Singleton();
mutex Singleton::mtx;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}