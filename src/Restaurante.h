
#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_


class Restaurante {

	private:
		unsigned int cantidadDeMesas;
		float* cuentaPorMesa;
		float recaudacionTotal;

	public:

		/*
		 * pre : 'cantidadDeMesas' debe ser un valor mayor a 0.
		 * post: el Restaurante tiene tantas mesas como las indicadas por
		 * 		 'cantidadDeMesas'  libres, es decir lista para atender.
		 */
		Restaurante(unsigned int cantidadDeMesas);

		/*
		 * pre : 'consumo' es un monto en $ que tiene que ser mayor 0.0.
		 *       'mesa' identifica una mesa por su número, debe estar en el
		 *       rango [1..contarMesas()]
		 * post: agrega el consumo dado a la cuenta de la mesa indicada,
		 * 		 dejándola abierta.
		 */
		void adicionarConsumoEnMesa(float consumo, unsigned int mesa);

		/*
		 * post: devuelve la cantidad de mesas que tiene el restaurante.
		 */
		unsigned int contarMesas();

		/*
		 * pre : 'mesa' identifica una mesa por su número, debe estar en el
		 *       rango [1..contarMesas()].
		 * 		 La mesa indicada no está libre.
		 * post: hace la cuenta, devuelve el total y deja libre la mesa.
		 */
		float cerrarMesa(unsigned int mesa);

		/*
		 * post: devuelve la cantidad de mesas que en el restaurante están
		 * 		 libres, es decir no tienen cuentas abiertas.
		 */
		unsigned int contarMesasLibres();

		/*
		 * post: devuelve el monto de la suma de las cuentas de aquellas mesas
		 * 		 que fueron cerradas durante la vida del restaurante.
		 */
		float totalizarRecaudacion();

		/*
		 * post: libera los recursos pedidos por la instancia.
		 */
		~Restaurante();

	private:
		unsigned int posicionar(unsigned int mesa);
};


#endif /* RESTAURANTE_H_ */
