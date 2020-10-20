# Práctica 3: Productos Capicúa

En este repositorio se encuentra los distintos códigos fuentes relativos a la Práctica 3 de CyA

## Aclaraciones
A continuación, se muestra una serie de aclaraciones sobre la compilación y ejecución del código.

### Compilacion: 
Situandonos en el directorio de la práctica, podemos hacer uso del programa Make. Bastaria con escribir por pantalla: 

  ```make```

Ademas de esta, tenemos la opcion de compilar:

 ```$ g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cc```

### Ejecución:
Una vez compilado, procedemos a ejecutar el programa de la siguiente manera: 

  ```./palindrome [N Cifras] [*.txt]```

### Lind de Python para C++Style
Este programa nos ayudará a controlar las posibles diferencias de nuestro código respecto a la [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

```python cpplint.py [fichero.cc]```
