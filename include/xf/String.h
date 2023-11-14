#pragma once

#include <minecraft/util/MallocOperator.h>
#include "Vector.h"

namespace xf {
    template<typename T>
    class String {
    public:
        String(const T* _str) {
            bool found = false;
	        int l = 0;
            while (!found) {
	        	if (_str[l++] == 0x0) {
	        		found = true;
	        		l--;
	        	}
	        }
            
            size = l;
            string = new T[size + 1];
            for (int i = 0; i < size; i++) {
                string[i] = _str[i];
            }

            string[size] = 0x0;
        }

        String(T t) {
            string = new T[2];
            string[0] = t;
            string[1] = '\0';
            size = 1;
        }

        ~String() {
            // _delete(string);
        }

        String() = default;

        static String<T> randomStr(int _length, String<T> charSet) {
            String<T> result = (T*) L"";
            for (int i = 0; i < _length; i++) {
                result = result + charSet[code::Random::next(0, charSet.length())];
            }

            return result;
        }

        static String<T> intToStr(int input) {
            wchar_t t[0x30];
            mc_swprintf(t, 0x30, L"%d", input);
            if      (sizeof(T) == sizeof(wchar_t)) return (T*) t;
            else if (sizeof(T) == sizeof(char))    return (T*) wcharToChar(t);
        }
        
        static String<T> intToHexStr(uint32_t input, int l = 8) {
            wchar_t t[0x30];
            mc_swprintf(t, 0x30, L"%s%dX", "%0", l, input);
            mc_swprintf(t, 0x30, t, input);
            if      (sizeof(T) == sizeof(wchar_t)) return (T*) t;
            else if (sizeof(T) == sizeof(char))    return (T*) wcharToChar(t);
        }

        bool startsWith(T input) {
            return string[0] == input;
        }

        bool startsWith(String<T> input) {
            bool matches = true;
            for (int i = 0; i < input.length(); i++) {
                if (string[i] != input[i]) matches = false;
            }

            return matches;
        }

        static int strToInt(String<T> input) {
            int t = 0;
            int m = 0;
            int l = input.length();
            if (input.c_str()[0] == '-') {
                l--;
                for (int i = 1; i < input.length(); i++) {
                    t = input.c_str()[i] - '0';
                    l--;
                    int n = 1;
                    for (int j = 0; j < l; j++) n *= 10;
                    m += t * n;
                }
                m = -m;
            } else {
                for (int i = 0; i < input.length(); i++) {
                    t = input.c_str()[i] - '0';
                    l--;
                    int n = 1;
                    for (int j = 0; j < l; j++) n *= 10;
                    m += t * n;
                }
            }
            return m;
        }

        static uint32_t hexStrToInt(String<T> input) {
            int t = 0;
            int m = 0;
            int l = input.length();
            int _l = l;
            String<T> _input = input.toLowerCase();

            auto conv = [&](T c) {
                if (c >= '0' && '9' >= c) {
                    return c - '0';
                } else {
                    if (c >= 'a' && 'f' >= c) {
                        return c - 'a' + 10;
                    }
                }

                return 0;
            };
            
            for (int i = 0; i < _l; i++) {
                t = conv(_input.c_str()[i]);
                l--;
                int n = 1;
                for (int j = 0; j < l; j++) n *= 16;
                m += t * n;
            }
            
            return m;
        }

        String<T> toLowerCase() {
            T* newStr = new T[size + 1];
            newStr[size] = 0x0;
            for (int i = 0; i < size; i++) {
                newStr[i] = string[i];
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < 26; j++) {
                    if (newStr[i] == j + 'A') newStr[i] = j + 'a';
                }
            }

            return newStr;
        }

        String<T> toUpperCase() {
            T* newStr = new T[size + 1];
            newStr[size] = 0x0;
            for (int i = 0; i < size; i++) {
                newStr[i] = string[i];
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < 26; j++) {
                    if (newStr[i] == j + 'a') newStr[i] = j + 'A';
                }
            }

            return newStr;
        }

        Vector<String<T>> matches(String<T> regex) {
            Vector<String<T>> toRet;
            bool hasStarted = false;
            bool greedy = false;
            
            auto isNumber = [](T t) {
                for (char i = '0'; i <= '9'; i++) {
                    if (t == i) return true;
                }

                return false;
            };

            auto isChar = [](T t) {
                for (char i = 'a'; i <= 'z'; i++) {
                    if (t == i) return true;
                }

                for (char i = 'A'; i <= 'Z'; i++) {
                    if (t == i) return true;
                }

                return false;
            };

            String<T> allowedChars = "";
            for (int i = 0; i < regex.length(); i++) {
                if (regex[i] == '[') hasStarted = true;
                else if (regex[i] == ']') hasStarted = false;
                else if (regex[i] == '+' && !hasStarted) greedy = true;
                else if (regex[i + 1] == '-') {
                    if (hasStarted) {
                        if (isNumber(regex[i]) && isNumber(regex[i + 2])) {
                            int numberA = (regex[i]   - '0');
                            int numberB = (regex[i+2] - '0') + 1;
                            for (int i = numberA; i < numberB; i++) {
                                allowedChars += ('0' + i);
                            }

                            i += 2;
                        } else if (isChar(regex[i]) && isChar(regex[i + 2])) {
                            T charA = regex[i];
                            T charB = regex[i+2] + 1;
                            for (T i = charA; i < charB; i++) {
                                allowedChars += i;
                            }
                            i += 2;
                        } else {
                            allowedChars += regex[i];
                        }
                    } else {
                        allowedChars += regex[i];
                    }
                } else {
                    allowedChars += regex[i];
                }
            }

            String<T> tempString = "";
            for (int i = 0; i < length(); i++) {
                bool isValid = false;
                for (int j = 0; j < allowedChars.length(); j++) {
                    if (operator[](i) == allowedChars[j]) isValid = true;    
                }

                if (!isValid) {
                    if (tempString.length() > 0) {
                        toRet.push_back(tempString.c_str());
                        tempString = "";
                    }
                } else {
                    if (greedy) {
                        tempString += operator[](i);
                    } else {
                        tempString += operator[](i);
                        toRet.push_back(tempString.c_str());
                        tempString = "";    
                    }
                }
            }

            if (tempString.length() > 0) toRet.push_back(tempString.c_str());

            return toRet;
        }

        Vector<String<T>> split(T c) {
            int amount = find(c);

            if (amount == 0) {
                Vector<String<T>> arr;
                arr.push_back(string);
                return arr;
            }

            int arrIndex = 0;
            int index = 0;
            Vector<String<T>> arr;
            T* temp = new T[size + 1];
            temp[size] = 0x0;
            for (int i = 0; i < size; i++) temp[i] = 0x0;

            for (int i = 0; i < size + 1; i++) {
                if (string[i] == c || i == size) {
                    T* finalTmp = new T[index + 1];
                    finalTmp[index] = 0x0;
                    for (int j = 0; j < index; j++) finalTmp[j] = temp[j];
                    if (String<T>(finalTmp).length() != 0) arr.push_back(finalTmp);
                    for (int j = 0; j < size; j++) temp[j] = 0x0;
                    index = 0;
                } else {
                    temp[index++] = string[i];
                }
            }

            return arr;
        }

        bool contains(Vector<String<T>> vec) {
            for (String<T> str : vec) {
                for (int i = 0; i < size; i++) {
                    int corrects = 0;
                    for (int y = 0; y < str.length(); y++) {
                        if (str[y] == string[y + i]) corrects++;
                    }

                    if (corrects == str.length()) return true;
                }
            }

            return false;
        }

        bool containsOnlyValidCharacter(String<T> charSet) {
            bool isValid = true;
            for (int i = 0; i < size; i++) {
                bool isCharValid = false;
                for (T c : charSet) {
                    if (string[i] == c) isCharValid = true;
                }

                if (!isCharValid) isValid = false;
            } 
            return isValid;
        }

        int find(T c) {
            int amount = 0;
            for (int i = 0; i < size; i++) {
                if (string[i] == c) amount++;
            }

            return amount;
        }

        long hashCode() {
            long hash = 0;

            if (size == 0) return hash;

            auto func = [](int a, int b) {
                int c = a;
                if (b == 0) return 1;
                for (int i = 0; i < b - 1; i++) c = c * a;
                return c;
            };

            for (int i = 0; i < size; i++) {
                hash += ((int) string[i]) * func(31, size - (i + 1));
            }

            return hash; // hashCode from Java
        }

        int length()  { return size;   }
        T* c_str() const   { return string; }

        bool operator==(String<T> other) {
            return hashCode() == other.hashCode();
        }

        T& operator[](int i) const { 
            if (0 > i) return string[size + i];
            return string[i]; 
        }

        String<T> operator+(T c) {
            int newLength = length() + 2;
            T* newT = new T[newLength];
            int newIndex = 0;
            for (int i = 0; i < length(); i++) {
                newT[newIndex++] = string[i];
            }

            newT[newIndex++] = c;
            newT[newIndex]   = 0;
            return newT;
        }

        String<T> operator+(String<T> other) {
            int newLength = other.length() + length() + 1;
            T* newT = new T[newLength];
            int newIndex = 0;
            for (int i = 0; i < length(); i++) {
                newT[newIndex++] = string[i];
            }

            for (int i = 0; i < other.length(); i++) {
                newT[newIndex++] = other[i];
            }

            newT[newIndex] = 0;
            return newT;
        }

        String<T> substr(size_t start, size_t count) const {
            if (start >= size) return "";

            if (count > (size - start)) count = size - start;
            T* newData = new T[count + 1];
            strncpy(newData, string + start, count);
            newData[count] = '\0';

            return newData;
        }

        void operator+=(String<T> other) {
            string = (xf::String<T>(string) + other.c_str()).c_str();
            size += other.length();
        }

        void operator+=(T other) {
            string = (xf::String<T>(string) + other).c_str();
            size++;
        }

        bool operator!=(String<T> other) {
            return hashCode() != other.hashCode();
        }

        void operator=(String<T> other) {
            size = other.length();
            string = &other[0];
        }

        // Used for 
        // for (T t : this) {}
        typedef       T*  iter;
        typedef const T* citer;

        iter  begin()       { return &string[0]; }
        citer begin() const { return &string[0]; }
        iter  end()       { return &string[size]; }
        citer end() const { return &string[size]; }

    private:
        int size;
        T* string;
    };

    typedef xf::String<wchar_t> WString;
}