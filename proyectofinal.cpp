#include <iostream>
#include <fstream>

using namespace std;

void menu();
void registrarProducto();
void listarProductos();
void mostrarEncabezado();
void pausarSistema();

struct Producto {
    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};

void mostrarEncabezado() {
    cout<<"\n--------Sistema de Ventas e Inventarios--------";
}

void pausarSistema() {
    cout<<"\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void menu() {
    int opcion;

    do {
        mostrarEncabezado();

        cout<<"\n1. Registrar producto";
        cout<<"\n2. Listar productos";
        cout <<"\n3. Salir";

        cout<<"\n\nSeleccione una opcion: ";
        cin>>opcion;

        switch(opcion) {

            case 1:
                registrarProducto();
                break;
            case 2:
                listarProductos();
                break;
            case 3:
                cout << "\nPrograma finalizado.\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
        }

    }while(opcion!=3);
}

void registrarProducto(){
    Producto producto;
    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo){
        cout<<"\nError al abrir el archivo.\n";
        return;
    }

    cout<<"\n-----Ingreso de productos-----\n";

    cout<<"Codigo: ";
    cin>>producto.codigo;
    cin.ignore();

    cout<<"Nombre: ";
    cin.getline(producto.nombre, 40);

    cout<<"Categoria: ";
    cin.getline(producto.categoria, 30);

    cout<<"Stock: ";
    cin>>producto.stock;

    cout<<"Precio: ";
    cin>>producto.precio;

    producto.activo=true;

    archivo.write((char*)&producto, sizeof(producto));

    archivo.close();

    cout<<"\nSe registro el producto correctamente.\n";

    pausarSistema();
}

void listarProductos() {
    Producto producto;
    ifstream archivo("productos.dat", ios::binary);

    if(!archivo){
        cout<<"\nNo existe informacion almacenada.\n";
        return;
    }

    cout<<"\n--------Listado de Productos--------\n";

    while(archivo.read((char*)&producto, sizeof(producto))) {

        cout<<"\n-----------------------------------";
        cout<<"\nCodigo: " << producto.codigo;
        cout<<"\nNombre: " << producto.nombre;
        cout<<"\nCategoria: " << producto.categoria;
        cout<<"\nStock: " << producto.stock;
        cout<<"\nPrecio: Q" << producto.precio;
        cout<<"\nActivo: ";

        if(producto.activo==true) {
            cout<<"Si";
        }else{
            cout<<"No";
        }
        cout<<"\n-----------------------------------\n";
    }
    archivo.close();
    pausarSistema();
}

int main() {
	cout<<"\nDesarrollado por Emily de Leon 9941-25-13659\n";
    menu();
    return 0;
}
