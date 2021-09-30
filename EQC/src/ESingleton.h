#pragma once
#ifndef ESINGLETON_H_22B96600_44BB_4B8A_9E69_54EFB92851FE
#define ESINGLETON_H_22B96600_44BB_4B8A_9E69_54EFB92851FE

#include <stdlib.h>
#include <mutex>

template <typename T>
class ESingleton
{
public:
    static T *instance() {
        static std::once_flag onceFlag;
        std::call_once(onceFlag, [&] {
            t = new (T)();
            atexit(destory);
        });
        return t;
    }

    ~ESingleton() = default;

private:

    static void destory() {
        delete t;
        t = nullptr;
    }

    ESingleton() = default;

    ESingleton(ESingleton const&) = delete;
    ESingleton(ESingleton&&) = delete;
    ESingleton& operator=(ESingleton const&) = delete;
    ESingleton& operator=(ESingleton &&) = delete;

private:
    static T* volatile t;
};

template <typename T>
T* volatile ESingleton<T>::t = nullptr;

#endif // ESINGLETON_H_22B96600_44BB_4B8A_9E69_54EFB92851FE
