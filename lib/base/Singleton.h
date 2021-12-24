//
// Created by gels on 2021/12/24.
// 1. thread is safe now
// 2. memory doesn't leak
//

#ifndef OPENGE2_SINGLETON_H
#define OPENGE2_SINGLETON_H

#include <stdio.h>
#include <iostream>
#include <memory> //for std::shared_ptr
#include <mutex> //for std::mutex

//class of Singleton
template<typename T>
class Singleton {
private:
    static std::shared_ptr<T> m_instance;
    static std::mutex m_mutex;

protected:
    Singleton();
    Singleton(Singleton&) = delete;
    Singleton operator=(const Singleton&) = delete;

public:
    virtual ~Singleton() noexcept;

public:
    static std::shared_ptr<T> GetInstance();
};

template<typename T>
std::shared_ptr<T> Singleton<T>::m_instance = nullptr;

template<typename T>
std::mutex Singleton<T>::m_mutex;

template<typename T>
Singleton<T>::Singleton()
{
    printf("==Singleton::Singleton==\n");
}

template<typename T>
Singleton<T>::~Singleton<T>() noexcept {
    printf("==Singleton::~Singleton==\n");
}

template<typename T>
std::shared_ptr<T> Singleton<T>::GetInstance()
{
    if(m_instance == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if(m_instance == nullptr) {
            m_instance = std::shared_ptr<T>(new T());
        }
    }
    return m_instance;
}

#endif //OPENGE2_SINGLETON_H
