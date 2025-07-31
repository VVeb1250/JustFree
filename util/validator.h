#pragma once
#include <stdexcept>
#include <sstream>
#include <limits>
#include <string>

#define default_location \
        const char* file = __builtin_FILE(), int line = __builtin_LINE()
#define sent_location \
        file, line
#define recive_location \
        const char* file, int line

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
    validator::morethan_100(name, value, __FILE__, __LINE__)
    template <typename T>
    void morethan_100(const char* name, const T& value, recive_location) {
        if (value > 100) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " cannot more than 100.";
            throw std::invalid_argument(oss.str());
        }
    }
    #define VALIDATE_NOT_EXCEED(typename, name, value) \
    validator::not_exceed<typename>(name, value, __FILE__, __LINE__)
    template <typename C, typename T>
    void not_exceed(const char* name, const T& value, recive_location) {
        if (value < std::numeric_limits<C>::min()) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " out of range in negative.";
            throw std::range_error(oss.str());
        }
        if (value > std::numeric_limits<C>::max()) {
            std::ostringstream oss;
            oss << file << ":" << line << " -> " << name << " out of range in positive.";
            throw std::range_error(oss.str());
        }
    }
} // namespace validator