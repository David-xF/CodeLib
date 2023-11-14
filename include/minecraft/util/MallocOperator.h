#pragma once

#include <code/code.h>
#include <cstdio>
#include <cstring>

#include <string>

void _delete(void* ptr) {
	code::Func<void, 0x0382ABB4, void*>()(ptr);
}

template<typename T>
T* _new(size_t size) {
    T* t = code::Func<T*, 0x0382AACC, size_t>()(sizeof(T) * size);
    memset(t, 0, sizeof(T) * size);
    return t;
}

void* operator new(size_t size) {
    return _new<char>(size);
}

void* operator new[](size_t size) {
    return _new<char>(size);
}

void operator delete(void* ptr) _GLIBCXX_USE_NOEXCEPT {
    return _delete(ptr);
}

void operator delete[](void* ptr) _GLIBCXX_USE_NOEXCEPT {
    return _delete(ptr);
}

namespace mstd {
    // See StackOverflow replies to this answer for important commentary about inheriting from std::allocator before replicating this code.
    // https://stackoverflow.com/questions/826569/compelling-examples-of-custom-c-allocators
    template <typename T>
    class allocator : public std::allocator<T> {
    public:
        template<typename _Tp1>
        struct rebind {
            typedef allocator<_Tp1> other;
        };

        T* allocate(size_t n, const void* hint = nullptr) {
            return _new<T>(n);
        }

        void deallocate(T* p, size_t n) {
            return _delete(p);
        }

        allocator() throw(): std::allocator<T>() {  }
        allocator(const allocator &a) throw(): std::allocator<T>(a) { }
        template <class U>                    
        allocator(const allocator<U> &a) throw(): std::allocator<T>(a) { }
        ~allocator() throw() { }
    };

    typedef std::basic_string<char,    std::char_traits<char>,    allocator<char>>    xf_string;
    typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, allocator<wchar_t>> xf_wstring;
}