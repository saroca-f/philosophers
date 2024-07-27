Philosophers
Este repositorio contiene la implementación del clásico problema de los filósofos comensales, un ejercicio fundamental en la programación concurrente y de sincronización, desarrollado como parte del currículo de la escuela 42.

Descripción
El problema de los filósofos comensales, planteado por Edsger Dijkstra, es una ilustración de los desafíos en la concurrencia y la sincronización. Cinco filósofos se sientan alrededor de una mesa circular. Cada filósofo tiene un plato de espaguetis y un tenedor a su izquierda y derecha. Los filósofos pueden estar en uno de los dos estados: comiendo o pensando. Para comer, un filósofo necesita ambos tenedores adyacentes, pero solo puede tomar un tenedor a la vez.

Objetivo
El objetivo de este proyecto es desarrollar una solución que evite condiciones de carrera, bloqueos y hambruna utilizando hilos (threads) y mecanismos de sincronización.

Características
Uso de hilos: Cada filósofo es representado por un hilo separado, lo que permite la ejecución concurrente de las acciones de comer y pensar.
Sincronización: Se implementan mecanismos de sincronización, como mutexes, para controlar el acceso a los recursos compartidos (tenedores).
Prevención de deadlocks: Se diseñan estrategias para evitar situaciones de bloqueo mutuo en las que los filósofos no puedan progresar.
Prevención de starvation: Aseguramos que ningún filósofo quede indefinidamente esperando para comer.
Compilación y Ejecución
Requisitos
GCC (o cualquier compilador compatible con C)
Make
Instrucciones
Clona este repositorio:

sh
Copy code
git clone https://github.com/tu-usuario/philosophers.git
cd philosophers
Compila el proyecto usando Make:

sh
Copy code
make
Ejecuta el programa:

sh
Copy code
./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
Ejemplo
sh
Copy code
./philosophers 5 800 200 200
Esto iniciará la simulación con 5 filósofos, donde cada filósofo morirá si no come en 800 ms, tarda 200 ms en comer y 200 ms en dormir.

Estructura del Proyecto
philosophers.c: Contiene la lógica principal del programa.
philosopher.h: Define las estructuras y funciones utilizadas en el programa.
Makefile: Facilita la compilación del proyecto.
