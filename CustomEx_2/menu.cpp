#include "menu.h"

plato* menu::operator[](std::string PlatoInteres) {
    std::list<plato>::iterator aux = this->begin();

    while (aux != this->end()) {
        if ((*aux).get_nombre() == PlatoInteres) {
            //std::cout << aux._Ptr->_Myval;
            return &(aux._Ptr->_Myval);
        }
        aux++;
    }
    return nullptr;
}
