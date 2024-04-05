#include <string>
#include <map>
#include <iostream>
#pragma once
void producto_añadido(std::map<std::string, std::map<std::string, std::string>>& inventario) {
    std::string nombre_producto;
    std::cout << "Introduce el nombre del producto: ";
    std::cin >> nombre_producto;

    int cantidad_producto;
    std::cout << "Introduce la cantidad de este: ";
    std::cin >> cantidad_producto;

    std::string categoria_producto;
    std::cout << "Introduce de que categoria es: ";
    std::cin >> categoria_producto;

    std::map<std::string, std::string> producto;
    producto["NOMBRE"] = nombre_producto;
    producto["CANTIDAD"] = std::to_string(cantidad_producto);
    producto["CATEGORIA"] = categoria_producto;

    inventario[nombre_producto] = producto;

    std::cout << "El objeto " << nombre_producto << " se ha añadido al inventario" << std::endl;
}

void producto_eliminado(std::map<std::string, std::map<std::string, std::string>>& inventario) {
    std::string nombre_prod;
    std::cout << "¿Qué producto quieres eliminar? ";
    std::cin >> nombre_prod;

    if (inventario.count(nombre_prod) > 0) {
        inventario.erase(nombre_prod);
        std::cout << "Se ha eliminado " << nombre_prod << " de tu inventario" << std::endl;
    }
    else {
        std::cout << "No tienes " << nombre_prod << " en tu inventario" << std::endl;
    }
}

void ver_carrito(const std::map<std::string, std::map<std::string, std::string>>& inventario) {
    std::cout << "En tu carrito tienes:" << std::endl;
    for (const auto& prod : inventario) {
        std::cout << prod.first << ": " << prod.second.at("CANTIDAD") << " (" << prod.second.at("CATEGORIA") << ")" << std::endl;
    }
}

void gestion_inventario(std::map<std::string, std::map<std::string, std::string>>& inventario) {
    while (true) {
        int opcion;
        std::cout << "¿Qué quieres hacer?" << std::endl;
        std::cout << "1. Añadir producto" << std::endl;
        std::cout << "2. Eliminar producto" << std::endl;
        std::cout << "3. Mostrar carrito" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cin >> opcion;

        if (opcion == 1) {
            producto_añadido(inventario);
        }
        else if (opcion == 2) {
            producto_eliminado(inventario);
        }
        else if (opcion == 3) {
            ver_carrito(inventario);
        }
        else if (opcion == 4) {
            std::cout << "Saliendo..." << std::endl;
            break;
        }
        else {
            std::cout << "Opción inválida. Inténtalo de nuevo." << std::endl;
        }
    }
}