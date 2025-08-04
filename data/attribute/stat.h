#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>
#include "basic_stat_attribute.h"
#include "..\..\util\calculate.h"
#include "..\..\util\validator.h"

namespace attribute {
    class stat : public basic_stat_attribute {
    public:
        string name;
    
        stat() : basic_stat_attribute(), name("") { }
        
        stat(string name) : basic_stat_attribute(), name(name) { }
        
        stat(string name, int64_t hp, uint32_t atk) 
            : basic_stat_attribute(hp, atk), name(name) { }
        
        stat(string name, uint32_t hp, uint32_t atk, 
            uint16_t ap, uint16_t def, 
            uint16_t acc, uint16_t eva, 
            uint16_t cr, uint16_t cdmg, uint16_t cdef)
            : basic_stat_attribute(hp, atk, ap, def, acc, eva, cr, cdmg, cdef), name(name) { }
    
        char getFirstName() {
            return name.at(0);
        }
        void toString() {
            cout << name << " ;; ";
            basic_stat_attribute::toString();
        }
    };
}