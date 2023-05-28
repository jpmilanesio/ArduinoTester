#include <cstdio>

class serial_port
{
public:
	void begin(unsigned long baud) {
		// inicializa el puerto
	}

	void print(bool boolean) {
		// imprime un boolean "true" o "false" en la ventana de comandos
		if (boolean) {
			printf("true");
		}
		else {
			printf("false");
		}
	}

	void print(char character) {
		// imprime un solo caracter en la ventana de comandos
		printf("%c", character);
	}

	void print(const char* str) {
		// imprime una cadena de caracteres en la ventana de comandos
		printf(str);
	}

	void print(int integer) {
		// Imprime un entero en la ventana de comandos
		printf("%d", integer);
	}

	void print(long integer) {
		// Imprime un entero en la ventana de comandos
		printf("%ld", integer);
	}

	void print(unsigned int integer) {
		// Imprime un entero en la ventana de comandos
		printf("%u", integer);
	}

	void print(unsigned long integer) {
		// Imprime un entero en la ventana de comandos
		printf("%lu", integer);
	}

	void print(long long int integer) {
		// Imprime un entero en la ventana de comandos
		printf("%lld", integer);
	}

	void print(double decimal) {
		// Imprime un decimal en el puerto serial y deja una linea
		printf("%.2f", decimal);
	}

	void print(double decimal, int digits) {
		// Imprime un decimal con los digitos de parametro en la ventana de comando
		printf("%.*f", digits, decimal);
	}

	void println(bool boolean) {
		// imprime un boolean "true" o "false" en la ventana de comandos y deja una linea

		if (boolean) {
			printf("true");
		} else {
			printf("false");
		}
	}

	void println(char character) {
		// imprime un solo caracter en la ventana de comandos y deja una linea
		printf("%c\n", character);
	}

	void println(const char* str) {
		// imprime un string en la ventana de comandos y deja una linea
		printf(str);
		printf("\n");
	}

	void println(int integer) {
		// Imprime un entero en la ventana de comandos y deja una linea
		printf("%d\n", integer);
	}

	void println(long integer) {
		// Imprime un entero en la ventana de comandos y deja una linea
		printf("%ld\n", integer);
	}

	void println(unsigned int integer) {
		// Imprime un entero en la ventana de comandos y deja una linea
		printf("%u\n", integer);
	}

	void println(unsigned long integer) {
		// Imprime un entero en la ventana de comandos y deja una linea
		printf("%lu\n", integer);
	}

	void println(long long int integer) {
		// Imprime un entero en la ventana de comandos y deja una linea
		printf("%lld\n", integer);
	}

	void println(double decimal) {
		// Imprime un decimal con solo 2 digitos de parte fraccionaria
		// en la ventana de comandos y deja una linea 
		printf("%.2f\n", decimal);
	}
	void println(double decimal, int digits) {
		// Imprime un decimal con los digitos de parametro
		// en la ventana de comandos y deja una linea 
		printf("%.*f\n", digits, decimal);
	}
};

serial_port Serial;