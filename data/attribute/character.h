#pragma once
#include <iostream>
#include "stat.h"
#include "..\role\role.h"

using namespace attribute;

class character : public stat {
private:
    role c_role;
public:
    string name;

    character() : stat(), name(""), c_role() { }
    character(string name) : stat(), name(name), c_role() { }
    character(string name, role r) : stat(), name(name), c_role(r) { }
    character(string name, role r, int64_t hp, uint32_t atk) 
        : stat(hp, atk), name(name), c_role(r) { }
    character(string name, role r, uint32_t hp, uint32_t atk, 
        uint16_t ap, uint16_t def, 
        uint16_t acc, uint16_t eva, 
        uint16_t cr, uint16_t cdmg, uint16_t cdef)
        : stat(hp, atk, ap, def, acc, eva, cr, cdmg, cdef), name(name), c_role(r) { }

    role getRole() const { return c_role; }
    char getFirstName() const { return name.at(0); }
    string getRoleName() const { return role_data::getRoleName(c_role); }

    void setRole(role c_role) { this->c_role = c_role; }
    
    void toString() {
        cout << name << " ;; ";
        cout << getRoleName() << endl;
        basic_stat_attribute::toString();
    }
};