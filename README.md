## Fract-ol

**Fract-ol** es un proyecto desarrollado en 42 Madrid que explora la representación gráfica de fractales mediante programación en C. Utilizando la biblioteca **MiniLibX**, este programa permite visualizar y explorar los conjuntos fractales de Mandelbrot y Julia con interacciones en tiempo real.

![Logo 42 Madrid](42-Madrid.jpeg)

### Descripción del Proyecto

El programa genera fractales en una ventana gráfica y permite al usuario interactuar con ellos mediante zoom, desplazamiento y personalización de parámetros. Se centra en la manipulación de números complejos y la optimización en gráficos por computadora.

#### Características Principales

* **Visualización de fractales:** Renderizado de los conjuntos de **Mandelbrot**, **Julia** y **Burning Ship**.
* **Interacción en tiempo real:** Zoom dinámico que sigue la posición del ratón y desplazamiento con las teclas de dirección.
* **Eventos dinámicos:** Cierre del programa con `ESC` o al cerrar la ventana.
* **Modificación de parámetros:** Personalización de los valores del conjunto de Julia a través de la CLI.
* **Esquemas de color personalizables:** Representación de la profundidad con degradados de color que cambian al pulsar la barra espaciadora.

#### Novedades

* 🌀 **Nuevo fractal:** Soporte para el conjunto **Burning Ship**.
* 🎨 **Cambio dinámico de colores:** Al pulsar la barra **espaciadora**, cambia el rango de colores del renderizado.
* 🖱️ **Zoom inteligente:** El zoom ahora sigue la posición del ratón para una exploración más precisa e intuitiva.

### Archivos Incluidos

* `main.c`: Función principal, gestiona la entrada de argumentos y llama a la inicialización.
* `init.c`: Inicialización de la estructura del fractal y configuración de la ventana.
* `render.c`: Renderizado de los fractales en la ventana.
* `events.c`: Manejo de eventos de teclado, ratón y cierre de ventana.
* `math_utils.c`: Funciones matemáticas para operaciones con números complejos y mapeo de valores.
* `aux_malloc.c`: Manejo de errores de asignación de memoria.
* `color.c`: Manejo del cambio de rango de color.
* `fractol.h`: Cabecera con definiciones, estructuras y prototipos de funciones.
* `Makefile`: Compila el proyecto y gestiona reglas como `all`, `clean`, `fclean`, `re`.

### Cómo Usarlo

1. **Compilación:**
   Usa el siguiente comando para compilar el proyecto:

   ```bash
   make
   ```

2. **Ejecución:**
   Llama al programa con los argumentos necesarios:

   ```bash
   ./fractol <nombre_del_fractal> [parámetros]
   ```

   Ejemplos:

   ```bash
   ./fractol mandelbrot
   ./fractol julia 0.285 0.01
   ./fractol burningship
   ```

   Si no se proporciona un argumento válido, el programa mostrará una lista de opciones disponibles.

### Controles

* `ESC`: Cierra la ventana y finaliza el programa.
* `← → ↑ ↓`: Desplaza la vista del fractal.
* `+ / -`: Aumenta o disminuye el número de iteraciones para mejorar la precisión.
* `Barra espaciadora`: Cambia el esquema de color.
* **Rueda del ratón**:

  * **Hacia arriba**: Zoom in (centrado en la posición del ratón).
  * **Hacia abajo**: Zoom out (centrado en la posición del ratón).

### Funciones Permitidas

El proyecto permite el uso de las siguientes funciones estándar de UNIX y librerías:

* `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
* **MiniLibX**: Funciones de manejo de gráficos y eventos
* **Libft**

### Aclaración

Este proyecto sigue los estándares de la **Norma de 42** y debe ejecutarse correctamente sin producir errores inesperados.
