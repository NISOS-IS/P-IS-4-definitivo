#Product Backlog

## (ANVERSO)
**ID:** 001 **Buscar alumno**

----

El profesor puede consultar uno o varios alumnos de la agenda, introduciendo en el sistema el DNI, el apellido o el número de grupo al que pertenece.

**Prioridad:** 1  
**Prioridad de implementación:** 0  
**Tiempo estimado de implementación:** 3h  

----
## (REVERSO)
----

+ Devuelve el alumno/s buscados.
+ Muestra un mensaje de error si el alumno/os no ha sido encontrado.
+ Muestra un mensaje de error si los campos a buscar no tienen el formato correcto.
----

## (ANVERSO)
**ID:** 011 **Buscar Profesor**

---

Para poder registarse, primero se debe poder comproba que no exista ya ese profesor registrado, buscando por su DNI.

**Prioridad:** 1  
**Prioridad de implementación:** 0  
**Tiempo estimado de implementación:** 1h 30min    
---

## (REVERSO)
---
-Si el profesor no esta ya guardado, se realiza el registro
-Muestra un mensaje de error si el DNI no tiene un formato correcto.
-Muestra un aviso si el profesor ya esta registrado.
-Muestra un mensaje de error si ocurre algún fallo al registrarlo.


## (ANVERSO)
**ID:** 002 **Insertar Alumno**

----

El profesor podrá dar de alta a un nuevo alumno indicando de este tanto su información básica personal, así como cierta información académica. Toda la información debe ser ingresada de forma correcta, siendo la mayoría de campos obligatorios.

**Prioridad:** 2  
**Prioridad de implementación:** 1  
**Tiempo estimado de implementación:** 2h  

----
## (REVERSO)
---

+ Da de alta correctamente un usuario y verifica que sea registrado.
+ Muestra un error si los campos obligatorios están vacíos.
+ Muestra un error si se quiere insertar un usuario con un DNI o email ya registrados.
+ Muestra un error si ya hay 150 alumnos en la agenda.
+ Muestra un error si el DNI y/o el email no tienen el formato correcto.
----

## (ANVERSO)
**ID:** 009 **Registrar profesor**

----

El profesor podrá registrarse en el sistema. Sus datos se guardarán en un fichero externo binario.

**Prioridad:** 1  
**Prioridad de implementación:** 1  
**Tiempo estimado de implementación:** 2h  

----
## (REVERSO)
----

+ Dar de alta a un profesor en el sistema.
+ Muestra un mensaje de error si los campos obligatorios están vacíos.
+ Muestra un mensaje de error si el profesor está ya registrado.
----

## (ANVERSO)  
**ID:** 005 **Mostrar Lista**  

----

Guarda en un archivo con formato HTML el listado de todos los alumnos de la agenda, solo con su DNI y su nombre completo, y los muestra por pantalla.  

**Prioridad:** 1  
**Prioridad de implementación:** 2  
**Tiempo estimado de implementación:** 1h 30min  

-----  
## (REVERSO)
-----

+ Crea un fichero HTML con el DNI y el nombre completo de todos los alumnos.
+ Muestra el listado de alumnos por pantalla.
+ Si la agenda está vacío muestra un mensaje.
-----

## (ANVERSO)
**ID:** 006 **Mostrar Alumno**

---

Poder ver toda la información de un alumno o varios buscando por su DNI, apellidos o número de equipo.   

**Prioridad:** 2  
**Prioridad de implementación:** 2  
**Tiempo estimado de implementación:** 1h 30min  

---
## (REVERSO)
---

+  El usuario podrá ver todos los datos de un alumno, indicando si quiere buscar por el campo DNI o por el campo apellidos.
+  También podrá listar todos los datos de varios alumnos buscando por el número de equipo al que pertenecen. 
---

## (ANVERSO)
**ID:** 010 **Login profesor**

----

El profesor podrá iniciar sesión.

**Prioridad:** 1  
**Prioridad de implementación:** 2  
**Tiempo estimado de implementación:** 3h  

----
## (REVERSO)
----

+ Abrirá la sesión de un profesor.
+ Mostrará un error si los datos del login no son correctos.
+ Mostrará un error si el profesor no está registrado.
----

## (ANVERSO)  
**ID:** 003 **Modificar Alumno**  

----

El profesor podrá modificar los datos de un alumno. Toda la información debe ser ingresada de forma correcta, siendo la mayoría de campos obligatorios.

**Prioridad:** 3  
**Prioridad de implementación:** 3  
**Tiempo estimado de implementación:** 1h 30min  

-----  
## (REVERSO)
-----

+ Modifica correctamente un usuario y verifica que los cambios se hayan registrado.
+ Muestra un error si los campos obligatorios están vacíos.
+ El DNI no se puede modificar ya que único para cada persona.
+ Muestra un error si se quiere modificar el email de un usuario y dicho email ya está registrado.
+ Muestra un error si el email no tienen el formato correcto.
-----

## (ANVERSO)
**ID:** 004 **Borrar alumno**

----

El profesor puede borrar un alumno de la agenda introduciendo su DNI o su Apellido.

**Prioridad:** 3  
**Prioridad de implementación:** 3  
**Tiempo estimado de implementación:** 2h  

----
## (REVERSO)
----

* Válida la existencia del usuario que se desea borrar.
* Muestra un mensaje satisfactorio cuando el alumno ha sido borrado correctamente.
* Muestra un mensaje de error si los campos requeridos quedan vacíos.
* Si existen varios alumnos con el mismo apellido, estos se muestran para elegir el que se desea eliminar.
----

## (ANVERSO)
**ID:** 007 **Guardar copia de seguridad**  

----

Hacer una copiar de seguridad de todos los alumnos.

**Prioridad:** 4
**Prioridad de implementación:** 4
**Tiempo estimado de implementación:** 2h

----
## (REVERSO)
----

- El programa podrá realizar una copia de seguridad de todos los datos de los alumnos almacenados en la agenda guardándola en un fichero binario.
- Si hay dos ficheros con el mismo nombre se sobreescribe la información.
----

## (ANVERSO)  
**ID:** 008 **Cargar copia de seguridad**  

----

Poder recuperar la información si ocurre algún fallo.  

**Prioridad:** 5  
**Prioridad de implementación:** 5  
**Tiempo estimado de implementación:** 2h  

-----  
## (REVERSO)
-----

- Cargará el fichero binario de copia de seguridad con todos los datos guardados en la base de datos.
-----

##FUNCIONES AUXILIARES
- **comprobarExistenciaDNI**  
>- **Prioridad de implementación:** 0  
>- **Tiempo estimado de implementación:** 1h  

- **getCurso**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setCurso**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getEquipo**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setEquipo**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getLider**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setLider**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getDNI**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setDNI**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getNombre**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setNombre**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getApellidos**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setApellidos**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getTelefono**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setTelefono**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getDireccion**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setDireccion**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **getEmail**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setEmail**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getFechaNacimiento**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setFechaNacimiento**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getRol**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setRol**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getUsuario**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setUsuario**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **getContrasena**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 5 min  

- **setContrasena**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **comprobarLider**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **comprobarEmail**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **escribirDatos**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 2h  

- **leerlinea**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **letraDNI**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 30 min  

- **verificaDNI**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **compruebaFecha**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **validarEmail**  
>- **Prioridad de implementación:** 1  
>- **Tiempo estimado de implementación:** 1h  

- **mostrarListado**  
>- **Prioridad de implementación:** 2  
>- **Tiempo estimado de implementación:** 1h  

- **modificarDatos**  
>- **Prioridad de implementación:** 3  
>- **Tiempo estimado de implementación:** 1h 30min  

- **convertirBool**  
>- **Prioridad de implementación:** 4  
>- **Tiempo estimado de implementación:** 30 min  

- **convertirBoolLider**  
>- **Prioridad de implementación:** 4  
>- **Tiempo estimado de implementación:** 30 min  

- **convertirStringLider**  
>- **Prioridad de implementación:** 4  
>- **Tiempo estimado de implementación:** 30 min  
