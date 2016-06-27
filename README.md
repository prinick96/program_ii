# Program II Documentación Principal en C++

**core/**: Directorio de todos los headers.

  **core.cpp**: Contendrá las funciones más reutilizables y enrutador de todo lo demás.

  **classes/**: Directorio con las classes.

    **Lista.cpp**: Clase Lista, que crea Listas doblemente enlazadas para cada entidad.

    **Node.cpp**: Clase Node que define un Nodo y a su vez todas las seis entidades.

**main.cpp**: Programa principal.

**data/**: Ruta de archivos para la carga de data inicial.

**alumnos.txt**:  [cedula] _ [expediente] _ [nombre alumno] _ [fecha nacimiento] _ [indice academico] _ [creditos extras] _ [semestre]

**materias_inscritas.txt**: [codigo materia] _ [codigo seccion inscrita] _ [cedula alumno que inscribio]

**materias.txt**: [codigo materia] _ [nombre materia] _ [creditos] _ [semestre]

**secciones.txt**: [codigo seccion] _ [codigo_materia] _ [numero de seccion] _ [cedula profesor] _ [profesor] _ [max alumnos] _ [turno] _ [dia_semana] _ [hora entrada] _ [hora salida] _ [cantidad de alumnos ya inscritos]

**semestres.txt**: [numero de semestre] _ [creditos dados en este semestre]

**planillas.txt**: [codigo materia solicitada] _ [codigo seccion solicitada] _ [cedula alumno que solicita]

**record.txt**: [cedula] _ [codigo_materia] _ [nota] _ [time] _ [semestral] _ [estado]
