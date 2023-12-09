#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;


struct Registro {
    int id;
    string nombre;
    string apellido;
    int pedido, pedido1;
    float cont2 = 0.0;
    int cont3 = 0;
    float total;
    float impuesto;
    float IVA = 0.16;
    float propina = 0.0;
    float totals = 0.0;
    float totals2;
};

const int MAX_REGISTROS = 100; 


void alta(Registro[], int&);
void modificar(Registro[], int);
void eliminar(Registro[], int&);
void listar(Registro[], int);
void limpiarPantalla();
void mostrarMenu();
void guardarBaseDatos(Registro[], int);
void cargarBaseDatos(Registro[], int&);

int main() {
    Registro baseDeDatos[MAX_REGISTROS];
    int numRegistros = 0;
    int opcion;
    float total = 0;
    float impuesto;
    float cont2 = 0.0;
    float IVA = 0.16;

    
    cargarBaseDatos(baseDeDatos, numRegistros);
    impuesto = cont2 * IVA;

    do {
        mostrarMenu();
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            alta(baseDeDatos, numRegistros);
            break;
        case 2:
            modificar(baseDeDatos, numRegistros);
            break;
        case 3:
            eliminar(baseDeDatos, numRegistros);
            break;
        case 4:
            listar(baseDeDatos, numRegistros);
            break;
        case 5:
            limpiarPantalla();
            break;
        case 6:
            
            guardarBaseDatos(baseDeDatos, numRegistros);
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opción no válida. Inténtelo de nuevo.\n";
        }

    } while (opcion != 6);

    return 0;
}

void alta(Registro baseDeDatos[], int& numRegistros) {
    int opc;
    float cont2 = 0.0;
    int cont3 = 0;
    float propina = 0;
    float total = 0;
    float totals = 0;
    float totals2;
    totals2 = cont2 + totals;
    cout << "Bienvenido a los Boneless LJ, en que le podemos ayudar? " << endl;
    cout << " " << endl;
    cout << " Este seria nuestro menu " << endl;
    cout << " " << endl;
    cout << " 1.- Boneless... $55 " << endl;
    cout << " " << endl;
    cout << " 2.- Papas a la francesa... $35 " << endl;
    cout << " " << endl;
    cout << " 3.- Alitas... $45 " << endl;
    cout << " " << endl;
    cout << " 4.- Dedos de queso... $35 " << endl;
    cout << " " << endl;
    cout << " 5.- Tenemos una promocion de Boneless con papas a $75 " << endl;
    cout << " " << endl;
    cout << " 6.- Tambien tenemos una promocion de Boneless, Papas y Dedos de queso a $105 " << endl;
    cout << " " << endl;

    if (numRegistros < MAX_REGISTROS) {
        int nuevoID;
        cout << "Ingrese el Ticket: ";
        cin >> nuevoID;

        for (int i = 0; i < numRegistros; i++) {
            if (baseDeDatos[i].id == nuevoID) {
                cout << "El ticket ya está en la base de datos. No se puede agregar.\n";
                return;
            }
        }

        baseDeDatos[numRegistros].id = nuevoID;
        cout << "Ingrese el nombre del vendedor: ";
        cin >> baseDeDatos[numRegistros].nombre;
        cout << "Ingrese la fecha: ";
        cin >> baseDeDatos[numRegistros].apellido;
        cout << "Que porcentaje de propina? %10, %15 o %20" << endl;
        cin >> propina;
        do {
            cout << "Ingrese el numero del pedido" << endl;
            cin >> baseDeDatos[numRegistros].pedido;

            cout << "Desea agregar otro articulo" << endl;
            cout << "(1.- Si 2.- No)" << endl;
            cin >> opc;








            if (baseDeDatos[numRegistros].pedido == 1) {
                cout << "costo = $55" << endl;
                cout << "pedido = Boneless" << endl;

                cont2 += 55;

            }
            else
            {
                if (baseDeDatos[numRegistros].pedido == 2) {
                    cout << "costo = $35" << endl;
                    cout << "pedido = Papas a la francesa" << endl;

                    cont2 += 35;
                }
                else {
                    if (baseDeDatos[numRegistros].pedido == 3) {
                        cout << "costo = $45" << endl;
                        cout << "pedido = Alitas" << endl;

                        cont2 += 45;
                    }
                    else {
                        if (baseDeDatos[numRegistros].pedido == 4) {
                            cout << "costo = $35" << endl;
                            cout << "pedido = Dedos de Queso" << endl;

                            cont2 += 35;

                        }
                        else {
                            if (baseDeDatos[numRegistros].pedido == 5) {
                                cout << "costo = $75" << endl;
                                cout << "pedido = Promo 1" << endl;
                                cout << "Boneless con Papas" << endl;

                                cont2 += 75;
                            }
                            else {
                                if (baseDeDatos[numRegistros].pedido == 6) {
                                    cout << "costo = $105" << endl;
                                    cout << "pedido = Promo 2" << endl;
                                    cout << "Boneless, Papas y Dedos de Queso" << endl;

                                    cont2 += 105;
                                }
                            }
                        }
                    }
                }
            }
        } while (opc == 1);

        if (propina == 10) {
            totals = cont2 * .10;
        }
        else {
            if (propina == 15) {
                totals = cont2 * .15;
            }
            else {
                if (propina == 20) {
                    totals = cont2 * .20;
                }
                else {
                }
            }
        }


        total = cont2 + totals;
        totals2 = total + (total * baseDeDatos[numRegistros].IVA); 

        
        baseDeDatos[numRegistros].cont2 = cont2;
        baseDeDatos[numRegistros].totals = totals;
        baseDeDatos[numRegistros].total = total;
        baseDeDatos[numRegistros].totals2 = totals2;

        numRegistros++;

        cout << "Registro añadido correctamente.\n";
    }
    else {
        cout << "La base de datos está llena. No se pueden agregar más registros.\n";
    }
}

void modificar(Registro baseDeDatos[], int numRegistros) {
    int idModificar;
    cout << "Ingrese el ticket del registro que desea modificar: ";
    cin >> idModificar;

    for (int i = 0; i < numRegistros; i++) {
        if (baseDeDatos[i].id == idModificar) {
            cout << "Ingrese el nuevo nombre: ";
            cin >> baseDeDatos[i].nombre;
            cout << "Ingrese el nuevo apellido: ";
            cin >> baseDeDatos[i].apellido;
            cout << "Registro modificado correctamente.\n";
            return;
        }
    }

    cout << "No se encontró un registro con el ID especificado.\n";
}

void eliminar(Registro baseDeDatos[], int& numRegistros) {
    int idEliminar;
    cout << "Ingrese el ID del registro que desea eliminar: ";
    cin >> idEliminar;

    for (int i = 0; i < numRegistros; i++) {
        if (baseDeDatos[i].id == idEliminar) {
            
            for (int j = i; j < numRegistros - 1; j++) {
                baseDeDatos[j] = baseDeDatos[j + 1];
            }

            numRegistros--;

            cout << "Registro eliminado correctamente.\n";
            return;
        }
    }

    cout << "No se encontró un registro con el ID especificado.\n";
}


void listar(Registro baseDeDatos[], int numRegistros) {


    float IVA = 0.16;





    if (numRegistros > 0) {
        cout << "Listado de registros:\n";
        for (int i = 0; i < numRegistros; i++) {
            cout << "Ticket: " << baseDeDatos[i].id << ", Nombre: " << baseDeDatos[i].nombre
                << ", fecha: " << baseDeDatos[i].apellido << ", Pedido: " << baseDeDatos[i].pedido
                << ", Total: " << baseDeDatos[i].cont2 << ", IVA: " << baseDeDatos[i].cont2 * IVA
                << ", Propina: " << baseDeDatos[i].totals << ", Total a pagar: " << baseDeDatos[i].totals2 << endl;



        }
    }
    else {
        cout << "La base de datos está vacía.\n";
    }
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Alta de Ordenes\n";
    cout << "2. Modificar Orden\n";
    cout << "3. Eliminar o Cancelar Orden\n";
    cout << "4. Lista de Ordenes\n";
    cout << "5. Limpiar Pantalla\n";
    cout << "6. Salir\n";
}

void guardarBaseDatos(Registro baseDeDatos[], int numRegistros) {
    ofstream archivo("basededatos.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < numRegistros; i++) {
            archivo << baseDeDatos[i].id << " "
                << baseDeDatos[i].nombre << " "
                << baseDeDatos[i].apellido << " "
                << baseDeDatos[i].pedido << " "
                << baseDeDatos[i].cont2 << " "
                << baseDeDatos[i].IVA << " "
                << baseDeDatos[i].totals << " "
                << baseDeDatos[i].totals2 << "\n";
        }
        archivo.close();
        cout << "Base de datos guardada correctamente en 'basededatos.txt'.\n";
    }
    else {
        cout << "No se pudo abrir el archivo para guardar la base de datos.\n";
    }
}

void cargarBaseDatos(Registro baseDeDatos[], int& numRegistros) {
    ifstream archivo("basededatos.txt");

    if (archivo.is_open()) {
        while (!archivo.eof()) {
            archivo >> baseDeDatos[numRegistros].id
                >> baseDeDatos[numRegistros].nombre
                >> baseDeDatos[numRegistros].apellido
                >> baseDeDatos[numRegistros].pedido
                >> baseDeDatos[numRegistros].cont2
                >> baseDeDatos[numRegistros].IVA
                >> baseDeDatos[numRegistros].totals
                >> baseDeDatos[numRegistros].totals2;







            numRegistros++;
        }
        archivo.close();
        numRegistros--; 
        cout << "Base de datos cargada correctamente desde 'basededatos.txt'.\n";
    }
    else {
        cout << "No se pudo abrir el archivo para cargar la base de datos.\n";
    }
}
