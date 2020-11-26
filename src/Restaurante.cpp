
#include <string>
#include "Restaurante.h"

using namespace std;

Restaurante::Restaurante(unsigned int cantidadDeMesas) {

	if (cantidadDeMesas < 1) {
		throw string("La cantidad de mesas tiene que ser mayor a 0");
	}

	this->cantidadDeMesas = cantidadDeMesas;
	this->recaudacionTotal = 0;
	this->cuentaPorMesa = new float[this->cantidadDeMesas];
	for (unsigned int i = 0; i < this->cantidadDeMesas; i++) {
		this->cuentaPorMesa[i] = 0.0;
	}
}

Restaurante::~Restaurante() {

	delete[] this->cuentaPorMesa;
}

void Restaurante::adicionarConsumoEnMesa(float consumo, unsigned int mesa) {

	if (consumo <= 0.0) {

		throw string("El consumo debe ser mayor a $ 0");
	}

	this->cuentaPorMesa[posicionar(mesa)] += consumo;
}

unsigned int Restaurante::contarMesas() {

	return this->cantidadDeMesas;
}

float Restaurante::cerrarMesa(unsigned int mesa) {

	unsigned int posicionMesa = posicionar(mesa);

	float totalMesa = this->cuentaPorMesa[posicionMesa];

	this->cuentaPorMesa[posicionMesa] = 0.0;

	this->recaudacionTotal += totalMesa;

	return totalMesa;
}

unsigned int Restaurante::posicionar(unsigned int mesa) {

	if ((mesa < 1) || (mesa > this->cantidadDeMesas)) {

		throw string("La mesa indica no existe");
	}

	return mesa - 1;
}

unsigned int Restaurante::contarMesasLibres() {

	unsigned int libres = 0;

	for (unsigned int i = 0; i < this->cantidadDeMesas; i++) {

		if (this->cuentaPorMesa[i] == 0) {
			libres++;
		}
	}

	return libres;
}


float Restaurante::totalizarRecaudacion() {

	return this->recaudacionTotal;
}








