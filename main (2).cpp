#include <iostream>

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol {
public:
    Nodo* raiz;

    Arbol() : raiz(nullptr) {}

    void Insertar(int val) {
        raiz = InsertarRec(raiz, val);
    }

    Nodo* InsertarRec(Nodo* nodo, int val) {
        if (nodo == nullptr) {
            return new Nodo(val);
        }

        if (val < nodo->valor) {
            nodo->izquierda = InsertarRec(nodo->izquierda, val);
        } else if (val > nodo->valor) {
            nodo->derecha = InsertarRec(nodo->derecha, val);
        }

        return nodo;
    }

    void Eliminar(int val) {
        raiz = EliminarRec(raiz, val);
    }

    Nodo* EliminarRec(Nodo* nodo, int val) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (val < nodo->valor) {
            nodo->izquierda = EliminarRec(nodo->izquierda, val);
        } else if (val > nodo->valor) {
            nodo->derecha = EliminarRec(nodo->derecha, val);
        } else {
            if (nodo->izquierda == nullptr) {
                Nodo* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                Nodo* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }

            Nodo* temp = MinimoValorNodo(nodo->derecha);
            nodo->valor = temp->valor;
            nodo->derecha = EliminarRec(nodo->derecha, temp->valor);
        }

        return nodo;
    }

    Nodo* MinimoValorNodo(Nodo* nodo) {
        Nodo* actual = nodo;
        while (actual->izquierda != nullptr) {
            actual = actual->izquierda;
        }
        return actual;
    }

    void Inorden() {
        InordenRec(raiz);
    }

    void InordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            InordenRec(nodo->izquierda);
            std::cout << nodo->valor << " ";
            InordenRec(nodo->derecha);
        }
    }

    void Preorden() {
        PreordenRec(raiz);
    }

    void PreordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            std::cout << nodo->valor << " ";
            PreordenRec(nodo->izquierda);
            PreordenRec(nodo->derecha);
        }
    }

    void Posorden() {
        PosordenRec(raiz);
    }

    void PosordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            PosordenRec(nodo->izquierda);
            PosordenRec(nodo->derecha);
            std::cout << nodo->valor << " ";
        }
    }
};

int main() {
    Arbol arbol;
    arbol.Insertar(50);
    arbol.Insertar(30);
    arbol.Insertar(70);
    arbol.Insertar(20);
    arbol.Insertar(40);
    arbol.Insertar(60);
    arbol.Insertar(80);

    std::cout << "Inorden: ";
    arbol.Inorden();
    std::cout << std::endl;

    std::cout << "Preorden: ";
    arbol.Preorden();
    std::cout << std::endl;

    std::cout << "Posorden: ";
    arbol.Posorden();
    std::cout << std::endl;

    arbol.Eliminar(30);
    std::cout << "Inorden después de eliminar 30: ";
    arbol.Inorden();
    std::cout << std::endl;

    return 0;
}