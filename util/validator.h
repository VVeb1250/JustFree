#pragma once
#include <stdexcept>
#include <sstream>
#include <limits>
#include <string>

#define default_location \
        const char* file = __builtin_FILE(), int line = __builtin_LINE()
#define old_location \
        __builtin_FILE(), __builtin_LINE()
#define sent_location \
        file, line
#define recive_location \
        const char* file, const int& line

namespace validator
{
    #define VALIDATE_NON_NEGATIVE(name, value) \
    validator::non_negative(name, value, __FILE__, __LINE__)
    template <typename T>
    void non_negative(const char* name, const T& value, recive_location) {
        if (value < 0) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " cannot be negative.";
            throw std::invalid_argument(oss.str());
        }
    }
    #define VALIDATE_MORETHAN_100(name, value) \
    validator::morethan(value, name, check, __FILE__, __LINE__)
    template <typename T1, typename T2>
    void morethan(const T1& value, const char* name, const T2& check, recive_location) {
        if (static_cast<T1>(check) > value) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " cannot more than " << value;
            throw std::invalid_argument(oss.str());
        }
    }
    #define VALIDATE_NOT_EXCEED(typename, name, value) \
    validator::not_exceed<typename>(name, value, __FILE__, __LINE__)
    template <typename C, typename T>
    void not_exceed(const char* name, const T& value, recive_location) {
        if (value < std::numeric_limits<C>::min()) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " out of range in negative." << " [value=" << value << "]";
            throw std::range_error(oss.str());
        }
        if (value > std::numeric_limits<C>::max()) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " out of range in positive" << " [value=" << value << "]";
            throw std::range_error(oss.str());
        }
    }
} // namespace validator