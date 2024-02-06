#include <condition_variable>
#include <functional>

class Foo {

std::atomic<int> cnt;
int count = 0;
std::mutex mut;
std::condition_variable c;

public:
    Foo() :
    {
    }

    void first(std::function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++cnt;
    }

    void second(std::function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        while(cnt != 1){};
        printSecond();
        ++cnt;
    }

    void third(std::function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        while(cnt != 2){};
        printThird();
    }
};
