// g++ -o out_test_thread test_thread.cpp -lpthread -std=c++11
#include<stdio.h>
#include<iostream>
// #include<pthread.h>
#include<thread>
#include<string.h>
#include<stdlib.h>
#include<mutex>
#include<unistd.h>

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
    while(true) {
        {
            std::lock_guard<std::mutex> lock(m);
            // m.lock();
            *num = 100;
            (*num)++;
            printf("f11 num=%d threadid=%ld\n", *num, std::this_thread::get_id());
            // m.unlock();
        }
        sleep(1);
    }
}
void f2(int *num) {
    while(true) {
        {
            std::lock_guard<std::mutex> lock(m);
            // m.lock();
            *num = 200;
            (*num)--;
            printf("f22 num=%d threadid=%ld\n", *num, std::this_thread::get_id());
            //m.unlock();
        }
        sleep(1);
    }
}
int main(int n, char *argv[]) {
    printf("===test==\n");
    std::thread t1(f1, &cnt);
    std::thread *t2 = new std::thread(f2, &cnt);
    t1.detach(); //t1自由执行
    if (t2->joinable()) {
        t2->join();//当前线程等待t2结束
    }
    return 0;
}