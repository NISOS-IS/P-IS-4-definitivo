#Product Backlog

## (ANVERSO)
**ID:** 001 **Buscar alumno**

----

El profesor puede consultar uno o varios alumnos de la agenda, introduciendo en el sistema el DNI, el apellido o el número de grupo al que pertenece.

**Prioridad:** 1  
**Prioridad de implementación:** 0  
**Tiempo estimado de implementación:** 1h 30min  

----
## (REVERSO)
----

* Muestra los datos del usuario/s buscados.
* Muestra un mensaje de error si los campos requeridos quedan vacíos.
* Muestra un mensaje de error si el alumno/s no ha sido encontrado.
----

/*BUSCAR PROFESOR HAY QUE HACERLO*/

## (Anverso)
**ID:** 002 **Insertar Alumno**

----

El profesor podrá dar de alta a un nuevo alumno indicando de este tanto su información básica personal, así como cierta información académica. Toda la información debe ser ingresada de forma correcta, siendo la mayoría de campos obligatorios.

**Prioridad:** 2  
**Prioridad de implementación:** 1  
**Tiempo estimado de implementación:** 2h  

----
## (Reverso)
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
**Tiempo estimado de implementación:** 1h  

----
## (REVERSO)
----

+ Dar de alta a un profesor en el sistema.
+ Muestra un mensaje de error si los campos obligatorios están vacíos.
+ Muestra un mensaje de error si el profesor está ya registrado.
----

## (ANVERSO)  
**ID:** 005 **Mostrar Listado**  

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

## (Anverso)
**ID:** 006 **Mostrar Alumno**

---

Poder ver toda la información de un alumno o varios buscando por su DNI, apellidos o número de equipo.   

**Prioridad:** 2  
**Prioridad de implementación:** 2  
**Tiempo estimado de implementación:** 1h 30min  

---
## (Reverso)
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
**Tiempo estimado de implementación:** 1h  

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
**Tiempo estimado de implementación:** 1h  

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
**Tiempo estimado de implementación:** 1h  

----
## (REVERSO)
----

* Válida la existencia del usuario que se desea borrar.
* Muestra un mensaje satisfactorio cuando el alumno ha sido borrado correctamente.
* Muestra un mensaje de error si los campos requeridos quedan vacíos.
* Si existen varios alumnos con el mismo apellido, estos se muestran para elegir el que se desea eliminar.
----

## (ANVERSO)
**ID:** 004 **Borrar alumno**

----

El profesor puede borrar un alumno de la agenda introduciendo su DNI o su Apellido.

**Prioridad:** 3  
**Prioridad de implementación:** 4
**Tiempo estimado de implementación:** 1h  

----
## (REVERSO)
----

* Válida la existencia del usuario que se desea borrar.
* Muestra un mensaje satisfactorio cuando el alumno ha sido borrado correctamente.
* Muestra un mensaje de error si los campos requeridos quedan vacíos.
* Si existen varios alumnos con el mismo apellido, estos se muestran para elegir el que se desea eliminar.
----

## (ANVERSO)  
**ID:** 008 **Cargar copia de seguridad**  

----

Poder recuperar la información si ocurre algún fallo.  

**Prioridad:** 5  
**Prioridad de implementación:** 5  
**Tiempo estimado de implementación:** 1h  

-----  
## (REVERSO)
-----

- Cargará el fichero binario de copia de seguridad con todos los datos guardados en la base de datos.
-----
