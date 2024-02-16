# Reporte Git y Github
## Paradigmas de Programación

### Crear cuenta de Github

-   Abre [Github.com](https://github.com/) e inicia sesion
-   Si no tienes cuenta registrate y crea tu cuenta

### Instalar / Verificar Git

-   Abre un cmd de tu computadora y ejecuta el siguiente comando "git --version" Te lanzara que version de git tienes
![img](https://cdn.discordapp.com/attachments/1088654568218443926/1207946584919117824/image.png?ex=65e17eec&is=65cf09ec&hm=763524d11e8fd284c1eafdeab707232efbec14e8b15ec91bc6ca854dd89fbf1d&)
-   Si lanza algo diferente de seguro no tienes git instalado, descárgalo e instálalo desde [git-scm.com](https://git-scm.com/).

### Comandos Git
-   En la terminal de git bash puedes utilizar los siguientes comandos

```bash
$mkdir proyect/new1         // Crear carpetas
$cd proyect/new1            // Cambiar directorio
$touch prueba.md            // Crear archivo
$nano prueba.md             // Abrir archivo en editor de texto
$cat prueba.md              // Leer archivo en terminal
$rm pureba.md               // Eliminar archivo
$code README.md             // Abrir archivo en VSCode
```

### Crear repositorio en Github

-   Haz clic en el signo más en la esquina superior derecha y selecciona "New repository" o "Nuevo Repositorio".
-   Dale un nombre a tu repositorio, establece la visibilidad y otras configuraciones según tu preferencia.
-   Generalo.

### Inicializar repositorio local

-   Abre Git Bash o una terminal de git bash
-   Navega hasta la carpeta de tu proyecto usando el comando "cd".
-   Ejecuta "git init" para inicializar un nuevo repositorio Git en la carpeta actual.

```bash
$cd ..                           // Volver al directorio anterior
$git init                        // Inicializar repositorio local de git
$git status                      // Checar el estado de los archivos en el repositorio
$git add README.md               // Añadir archivo a los archivos rastreados
$git add .                       // Añadir todos los archivos de la carpeta
$git commit -m "primer commit"   // Crear una captura de los cambios hasta el momento
```

### Repositorio en la nube

-   Para hacer un repo en la nube primero debes de Hacer un repositorio desde github
-   Una vez hecho deberias copiar el link del repositorio y ejecutar lo siguiente (Despues de hacer el repositorio local)

```bash
$git branch -M main     //Hace que la rama principal se renombre a main
$git remote add origin "Sin comillas el link de tu repo" //Agrega la direccion del repositorio en la nube
$git push -u origin main    //Sube la informacion al repo
```

### Crear llave pública / privada

-   Si aún no tienes una llave SSH, genera una usando el comando **`ssh-keygen`**.
-   Localizar el archivo creado y leerlo usando el comando `cat`.

```bash
$ssh-keygen
$ls ~/.ssh
$cat ~/.ssh/id_rsa.pub
```

### Agregar llave a Github

-   Copia el contenido de tu llave pública creada anteriormente.
-   Ve a la configuración de tu cuenta de Github haciendo clic en tu avatar en la esquina superior derecha y seleccionando "Settings".
-   En el menú de la izquierda, haz clic en "SSH and GPG keys".
-   Haz clic en "New SSH key".
-   Pega el contenido de tu llave pública en el campo "Key" y dale un nombre descriptivo.
-   Haz clic en "Add SSH key" para guardar.
