# SNAKE

## Paradigmas de la programación
### Gonzalez Ceseña Adan
### Snake con listas enlazadas

# Inroducción

En este proyecto crearemos una réplica de un juego clásico, el juego de la serpiente, pero esta vez usaremos listas enlazadas para el cuerpo de la serpiente

# Desarrollo
### Requisitos
* Listas enlazadas
* No usar variables globales
* No usar código espagueti

### ¿Que usamos?
Usamos la librería de **raylib** en **c++** para poder crear el código
## Clases
### Apple.h
En esta clase definimos las funciones de la manzana, sus texturas, su estructura y su reposicionamiento
![Codigo de manzana 1](assetsMD/Captura%20de%20pantalla%202024-05-19%20140119.png)

![Codigo de manzana 2](assetsMD/Captura%20de%20pantalla%202024-05-19%20140307.png)

### Menu.h
En esta clase cargamos las imágenes de botones, iconos etc. Tambien aqui tenemos la funcion para dibujar el menú de inicio y la estructura de las imágenes
![Menu 1](assetsMD/Menu.h%201.png)

### Snake.h
Esta es la librería más importante del código, en esta librería está toda la lógica del movimiento de la serpiente, aquí tenemos la estructura del cuerpo de la serpiente, validaciones de movimiento, movimiento continuo, crecimiento del cuerpo, y colisiones.
![Snake.h 1](assetsMD/Snake%201.png)

![Snake.h 2](assetsMD/Snake%202.png)

![Snake.h 3](assetsMD/Snake%203.png)

![Snake.h 4](assetsMD/sNAKE%204.png)

### Sound.h
En esta libreria esta la funcion para reproducir la musica o sonidos
![Music 1](assetsMD/Musica%201.png) 

# Conclusión
Fue un dolor de cabeza al inicio, no sabia que podria hacer para hacer que la serpiente crezca en la direccion correcta, pero fuera de eso, fue una tarea bastante entretenida, me enseño una forma de implementar listas enlazadas en un escenario "real", y no en una tarea usando datos que no usaremos.