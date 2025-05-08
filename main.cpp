#include <iostream>
#include <fstream>
#include <limits>//para limpiar chido el buffer
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

struct Nodo{
	int id;
	string prioridad;
	string valor;
	Nodo *sig;
	Nodo *ant;

	Nodo(int _id, string priori, string tarea){
		id = _id;
		prioridad = priori;
		valor = tarea;
		sig = nullptr;
		ant = nullptr;
	}
};

Nodo *cabeza;
Nodo *cola;

int idGlobal = 1;

void inicializar(){
	cabeza = nullptr;
	cola = nullptr;
}

bool empty(){
	return cabeza == nullptr;
}

void insertarTarea(string priori, string tarea, int id = -1) { //id= -1 para saber si se agrega del menu o del json
	if (id == -1) id = idGlobal++;
	else if (id >= idGlobal) idGlobal = id + 1;

	Nodo *nuevo = new Nodo(id, priori, tarea);

	int prioridad = (priori == "ALTA") ? 1 : (priori == "MEDIA") ? 2 : 3; //el tres es la BAJA

	if(empty()) {
		cabeza = nuevo;
		cola = nuevo;
		cout << "Tarea insertada correctamente." << endl;
		cout << "------------------------------------------------------" << endl;
		return;
	}

	Nodo *aux = cabeza;
	while (aux != nullptr) {
		int auxPriori = (aux->prioridad == "ALTA") ? 1 : (aux->prioridad == "MEDIA") ? 2 : 3;

		if (prioridad < auxPriori) {
			nuevo->sig = aux;
			nuevo->ant = aux->ant;

			if (aux->ant != nullptr) {
				aux->ant->sig = nuevo;
			}else {
				cabeza = nuevo;
			}
			aux->ant = nuevo;
			cout << "Tarea insertada correctamente." << endl;
			cout << "------------------------------------------------------" << endl;
			return;
		}
		aux = aux->sig;
	}

	//en caso de q haya q insertar una de prioridad baja "3" se inserta al final pq como no hay prioridad menor a 3 sale del while ;l
	cola->sig = nuevo;
	nuevo->ant = cola;
	cola = nuevo;
	cout << "Tarea insertada correctamente." << endl;
	cout << "------------------------------------------------------" << endl;
}

void eliminarTarea(string priori){
	if(empty()){
		cout << "No tienes tareas pendientes" << endl;
		return;
	}

	Nodo *aux = cabeza;
	while(aux != nullptr && aux->prioridad != priori){
		aux= aux->sig;
	}

	if(aux == nullptr){
		cout << "No hay tareas de prioridad " << priori << " en la lista" << endl;
		return;
	}

	if (aux == cabeza && aux == cola) {
		cabeza = nullptr;
		cola = nullptr;
	}else if(aux == cabeza){
		cabeza = aux->sig;
		if(cabeza != nullptr){
			cabeza->ant = nullptr;
		}
	}else if(aux == cola){
		cola = aux->ant;
		if(cola != nullptr){
			cola->sig = nullptr;
		}
	}else{
		aux->sig->ant = aux->ant;
		aux->ant->sig = aux->sig;
	}

	delete aux;
	aux = nullptr; //solo por si acaso para vitar uso accidental pq hace rato tenia bug xd
	cout << "Tarea eliminada exitosamente" << endl;
	cout << "------------------------------------------------------" << endl;
}

void eliminarTareaID(int idBuscado) {
	if (empty()) {
		cout << "No tienes tareas pendientes" << endl;
		return;
	}

	Nodo *aux = cabeza;
	while (aux != nullptr) {
		if (aux->id == idBuscado) {
			if (aux == cabeza && aux == cola) {
				cabeza = nullptr;
				cola = nullptr;
			}else if(aux == cabeza){
				cabeza = aux->sig;
				if(cabeza != nullptr){
					cabeza->ant = nullptr;
				}
			}else if(aux == cola){
				cola = aux->ant;
				if(cola != nullptr){
					cola->sig = nullptr;
				}
			}else{
				aux->sig->ant = aux->ant;
				aux->ant->sig = aux->sig;
			}

			delete aux;
			aux = nullptr; //solo por si acaso para vitar uso accidental pq hace rato tenia bug xd
			cout << "Tarea eliminada exitosamente" << endl;
			cout << "------------------------------------------------------" << endl;
			return;
		}

		aux = aux->sig;
	}

	cout << "No se encontro ninguna tarea con ID: " << idBuscado << endl;
}

void mostrar(){
	if(empty()){
		cout << "No tienes tareas pendientes" << endl;
	}else{
		Nodo *aux = cabeza;
		cout << "--------------------------TAREAS----------------------" << endl;
		while(aux != nullptr){
			cout << "ID: " << aux->id << " - " << "Prioridad: " << aux->prioridad << " - " << aux->valor << endl;
			aux = aux->sig;
		}
		cout << "------------------------------------------------------" << endl;
	}
}

void destruir(){
	Nodo *aux = cabeza;
	Nodo *siguiente;
	while(aux != nullptr){
		siguiente = aux->sig;
		delete aux;
		aux = siguiente;
		//cout << "nodo eliminado" << endl; // para saber que si se elimino
	}
	//cout << "lista destruida" << endl;
}

void modificarTarea(int idBuscado) {
	if (empty()) {
		cout << "No tienes tareas pendientes" << endl;
		return;
	}

	Nodo *aux = cabeza;
	while (aux != nullptr) {
		if (aux->id == idBuscado) {
			cout << "ID: " << aux->id << " - " << "Prioridad: " << aux->prioridad << " - " << aux->valor << endl;

			cout << endl << "Ingrese la nueva descripcion de la terea: " << endl;
			getline(cin, aux->valor);

			cout << "Tarea modificada correctamente" << endl;
			cout << "---------------------------------------------------------" << endl;
			return;
		}
		aux = aux->sig;
	}

	cout << "No se encontro ninguna tarea con ID: " << idBuscado << endl;
}

string prioridad() {
    int op = 0;
    string priori;

    do {
        cout << "------------------------------------------------------" << endl;
    	try {
    		cout << "1.- Alta" << endl;
    		cout << "2.- Media" << endl;
    		cout << "3.- Baja" << endl;
    		cout << "Â¿Que prioridad tiene la tarea?  ";
    		cin >> op;

    		if (cin.fail()) {
    			throw runtime_error("Entrada incorrecta: Por favor ingresa un numero.");
    		}
    		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //hace que el cin ignore pero de muchos caracteres hasta que encuentre el enter \n por si escribe mas de una palabra ps

    		if (op == 1){
    			priori = "ALTA";
    		}else if (op == 2){
    			priori = "MEDIA";
    		}else if (op == 3){
    			priori = "BAJA";
    		}else {
    			cout << "Opcion no valida, intenta de nuevo." << endl;
    		}
    	}catch (runtime_error &e) {
    		cout << e.what() << endl;
    		cin.clear(); //para limpiar el buffer
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	}
    } while (op < 1 || op > 3);
	cout << "------------------------------------------------------" << endl;

    return priori;
}

void guardarEnArchivo() {
	if (empty()){
		cout << "No hay tareas pendientes por guardar" << endl;
		return;
	}

	json jTareas = json::array();
	Nodo *aux = cabeza;
	while(aux != nullptr) {
		json tareaJson = {
			{"id", aux->id},
			{"prioridad", aux->prioridad},
			{"valor", aux->valor}
		};
		jTareas.push_back(tareaJson);
		aux = aux->sig;
	}

	ofstream archivo("tareas.json");
	archivo << jTareas.dump(4);
	archivo.close();
	cout << "...Tareas guardadas correctamente" << endl;
}

void cargarTareasDeArchivo() {
	ifstream archivo("tareas.json");

	if (!archivo.is_open()) {
		cout << "No se encontraron tareas previas. Empezando lista nueva..." << endl;
		return;
	}

	json jTareas;
	archivo >> jTareas;
	archivo.close();

	for (const auto& tareas : jTareas) {
		if (tareas.contains("id") && tareas.contains("prioridad") && tareas.contains("valor")) {
			int id = tareas["id"];
			string prioridad = tareas["prioridad"].get<string>();
			string valor = tareas["valor"].get<string>();

			insertarTarea(prioridad, valor, id);
		} else {
			cout << "Error: La tarea en el archivo JSON estÃ¡ incompleta o no tiene la estructura esperada." << endl;
		}
	}
	cout << "...Tareas previas cargadas correctamente" << endl;
}

int main(){
	inicializar();
	cargarTareasDeArchivo();
	string tarea, priori;
	int op = 0;

	cout << "BIENVENIDO A TU AGENDA DE TAREAS" << endl;

	while(op != 6){
		try {
			cout << endl;
			cout << "1.- Agregar Tarea" << endl;
			cout << "2.- Mostrar Tareas" << endl;
			cout << "3.- Modificar Tarea" << endl;
			cout << "4.- Eliminar Tareas" << endl;
			cout << "5.- Eliminar Tarea Por ID" << endl;
			cout << "6.- Salir" << endl;
			cout << "¿Que haremos primero?  ";
			cin >> op;

			if (cin.fail()) {
				throw runtime_error("Entrada incorrecta: Por favor ingresa un numero.");
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch(op){
				case 1: //agregar tarea
					cout << "TAREA:  ";
					getline(cin, tarea);

					priori = prioridad();

					insertarTarea(priori, tarea);
					break;
				case 2: //mostrar tareas
						mostrar();
					break;
				case 3: //modificar tareas
					int idModificar;
					try {
						cout << "Ingrese el ID de la tarea a modificar: ";
						cin >> idModificar;
						if (cin.fail()) {
							throw runtime_error("Entrada incorrecta: Por favor ingresa un ID valido.");
							break;
						}
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						modificarTarea(idModificar);
					}catch (runtime_error& e) {
						cout << e.what() << endl;
						cin.clear(); //para limpiar el buffer
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					break;
				case 4: //eliminar tareas
						priori = prioridad();
						eliminarTarea(priori);
						if (empty()) {
							remove("tareas.json");
						}else {
							guardarEnArchivo();
						}
					break;
				case 5: //eliminar tareas por ID
					int ideliminar;
					try {
						cout << "Ingrese el ID de la tarea a eliminar: ";
						cin >> ideliminar;
						if (cin.fail()) {
							throw runtime_error("Entrada incorrecta: Por favor ingresa un ID valido.");
							break;
						}
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						eliminarTareaID(ideliminar);
					}catch (runtime_error& e) {
						cout << e.what() << endl;
						cin.clear(); //para limpiar el buffer
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					break;
				case 6: //salir
					guardarEnArchivo();
					cout << "HASTA PRONTO!!" << endl;
					destruir();
					break;
				default:
					cout << "Opcion invalida, intente de nuevo..." << endl;
			}
		}catch (runtime_error& e) {
			cout << e.what() << endl;
			cin.clear(); //para limpiar el buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	destruir(); // por si acaso xd
	return 0;
}