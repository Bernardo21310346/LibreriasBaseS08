# StartUp Librerias Base
Para poder hacer uso de las librerías escritas en este repositorio se deben tener algúnos parámetros y archivos en el proyecto para poder funcionar correctamente, a lo largo de este documento se explicará el propósito y forma de uso de cada uno

## S08_Board
El archivo __"S08_Board.h"__ contendrá varias de las configuraciones de las librerías existentes, cómo la familia, periféricos, declaraciones, etc...; Este deberá estár en la raíz de las librerías del proyecto para evitar conflictos y debe ser incluido en el __"Main.c"__, este archivo debe contener la siguiente librería:
```C
    #include "S08_Common/S08_Families.h"
```
Esto incluye las definiciones de las familias soportadas, para definir la familia con la cual se trabajará se debe realizar modificar la siguiente declaración
```C
    #define MCU_ON_BOARD S08_QE
```
Dónde se debe reemplazar el valor `S08_QE` por una de las familias disponibles, ej. PT, PB, QG...

Aquí mismo se agregarán más definiciones de acuerdo a las necesidades de la tarjeta y proyecto, cada librería tendrá su descripción y forma de uso.

## Configurar el proyecto para poder usar las librerías
Para poder incluir los archivos al proyecto se deben modificar algúnas cosas antes de iniciar.

1. Descargar _LibreriasBaseS08_ dentro de la carpeta __Project_Heders__
   
   ![Carpeta Librerias Base en proyecto](/docs/img/S08StartUp/Download_Lib.png)
2. Ir a Propiedades del proyecto
   
   ![Propiedades del proyecto](/docs/img/S08StartUp/Goto_Properties.png)
3. En Propiedades ir a "C/C++ Build" -> Settings -> HCS08 Compiler -> Input
   
   ![Opciones del compilador](/docs/img/S08StartUp/CompilerSettings_Input.png)
4. Agregar la ruta raíz de las librerías en el sector de "Include File Path", usando la opción de Workspace
   
   ![Agregar la carpeta desde workspace](/docs/img/S08StartUp/CompilerSettings_Input_AddPath.png)
5. Agregar la misma ruta en el apartado "Recursive Include File Path"
   
   ![Direcciones agregadas](/docs/img/S08StartUp/CompilerSettings_Input_AddedPath.png)

Este proceso solo tiene que hacerse una vez al crear el proyecto, posteriormente solo es necesario actualizar el repositorio recurrentemente para recibir las ultimas novedades