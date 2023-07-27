#include <iostream>
#include <semaphore.h>
#include <threading>
using namespace std;

// bools
class Foo {
public:
    bool firstRan = false;
    bool secondRan = false;
    Foo() { }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        firstRan = true;
    }

    void second(function<void()> printSecond) {
        while(!firstRan) { }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondRan = true;
    }

    void third(function<void()> printThird) {
        while (!(firstRan && secondRan))  { }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};



// std::promise
class Foo {
private:
    std::promise<void> p1;
    std::promise<void> p2;

    public:
    void first(function<void()> printFirst) {
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();
        printThird();
    }
};


// mutex
class Foo {   
    mutex m1, m2;
public:
    Foo() {
        m1.lock(), m2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m1.unlock();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m2.unlock();
    }
};




// semaphores


class Foo {
public:
    sem_t s1;
    sem_t s2;

    Foo() {
        sem_init(&s1, 0, 0);
        sem_init(&s2, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&s1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&s1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&s2);
        
    }

    void third(function<void()> printThird) {
        sem_wait(&s2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};





// mutex
class Foo {
public:
    bool firstRan = false;
    bool secondRan = false;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv1 = PTHREAD_COND_INITIALIZER;
    pthread_cond_t cv2 = PTHREAD_COND_INITIALIZER;
	
    Foo() { }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        pthread_mutex_lock(&m);
        firstRan = true;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv1);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&m);
		
        while (!firstRan) { 
            pthread_cond_wait(&cv1, &m);
        }
		
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        secondRan = true;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv2);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&m);
		
        while (!firstRan) {
             pthread_cond_wait(&cv1, &m);
        }
        while (!secondRan) {
             pthread_cond_wait(&cv2, &m);
        }
		
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&m);
    }
};