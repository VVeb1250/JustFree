#pragma once
// #include <iostream>
// #include <cstdint>
// #include <cmath>
#include "basic_stat_attribute.h"
// #include "..\..\util\calculate.h"
// #include "..\..\util\validator.h"

namespace attribute {
    class stat : public basic_stat_attribute {
    public:
    
        stat() : basic_stat_attribute() { }
        
        stat(int64_t hp, uint32_t atk) 
            : basic_stat_attribute(hp, atk) { }
        
        stat(uint32_t hp, uint32_t atk, 
            uint16_t ap, uint16_t def, 
            uint16_t acc, uint16_t eva, 
            uint16_t cr, uint16_t cdmg, uint16_t cdef)
            : basic_stat_attribute(hp, atk, ap, def, acc, eva, cr, cdmg, cdef) { }
    
        void toString() {
            basic_stat_attribute::toString();
        }
    };
}