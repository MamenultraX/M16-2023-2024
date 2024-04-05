#include <iostream>
#include <string>
#include <map>
#include "ListaCompra.h"



int main() {
    std::map<std::string, std::map<std::string, std::string>> inventario;
    gestion_inventario(inventario);

    return 0;
}

