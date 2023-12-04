// g++ -o out_test_thread test_thread.cpp -lpthread -std=c++11
#include<stdio.h>
#include<iostream>
// #include<pthread.h>
#include<thread>
#include<string.h>
#include<stdlib.h>
#include<mutex>

// void *f(void *t) {
//     int *num = (int*) t;
//     printf("t_print num=%d\n", *num);
//     pthread_exit(NULL);
// }
// int main(int n, char *argv[]) {
//     printf("===test==\n");
//     int arr[5] = {1, 2, 3, 4, 5};
//     pthread_t threads[5];
//     int r;
//     for(int i=0;i<5;i++) {
//         r = pthread_create(&threads[i], NULL, f, (void*)(&arr[i]));
//         if(r) {
//             std::cout << "pthread_create fail, r=" << r << std::endl;
//             exit(-1);
//         }
//     }
//     pthread_exit(NULL);
//     return 0;
// }

int cnt = 0;
std::mutex m;
void f1(int *num) {
    std::lock_guard<std::mutex> lock(m);
    // m.lock();
    *num = 100;
    (*num)++;
    printf("f1 num=%d threadid=%ld\n", *num, std::this_thread::get_id());
    // m.unlock();
}
void f2(int *num) {
    std::lock_guard<std::mutex> lock(m);
    // m.lock();
    *num = 200;
    (*num)--;
    printf("f2 num=%d threadid=%ld\n", *num, std::this_thread::get_id());
    m.unlock();
}
int main(int n, char *argv[]) {
    printf("===test==\n");
    std::thread t1(f1, &cnt);
    std::thread *t2 = new std::thread(f2, &cnt);
    t1.join();
    t2->join();
    return 0;
}