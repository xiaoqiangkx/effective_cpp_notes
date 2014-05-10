#include <iostream>
#include <memory>
#include <pthread.h>

class Uncopyable {
    protected:
        Uncopyable() {}
        ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Lock: private Uncopyable {
    public:
        explicit Lock(pthread_mutex_t* pm)
            : mutexPtr(pm, pthread_mutex_unlock) {
            pthread_mutex_lock(mutexPtr.get());
        }

    private:
        std::shared_ptr<pthread_mutex_t> mutexPtr;
};


void* thr_fn1 (void *arg) {
    Lock lock(static_cast<pthread_mutex_t*>(arg));
    
    std::cout << "start lock in fn1" << std::endl;
    std::cout << "fn1" << std::endl;
}

void* thr_fn2 (void *arg) {
    Lock lock(static_cast<pthread_mutex_t*>(arg));

    std::cout << "start lock in fn2" << std::endl;
    std::cout << "fn2" << std::endl;
}

int main() {
    pthread_mutex_t p_lock;

    pthread_mutex_init(&p_lock, NULL);

    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, thr_fn1, static_cast<void*>(&p_lock));
    pthread_create(&tid2, NULL, thr_fn2, static_cast<void*>(&p_lock));

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
