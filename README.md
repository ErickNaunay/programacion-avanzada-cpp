# Programación Avanzada en C++

Repositorio base del curso.

Aquí vive el ambiente de desarrollo estandarizado, los laboratorios y los PSets. Es la fuente de verdad: todo tu trabajo del semestre va aquí, no en otro lado.

## Antes de empezar:

No clones ni hagas push a este repositorio directamente. Cada estudiante trabaja en su propio fork:

1. Arriba a la derecha, clic en **"Fork"** y créalo en tu propia cuenta de GitHub.
2. Todo tu trabajo del semestre (laboratorios, PSets) va en tu fork, no aquí.

## Cómo abrir tu ambiente de desarrollo

En tu copia del repositorio: clic en el botón verde **"Code" → pestaña "Codespaces" → "Create codespace on main"**. Espera uno o dos minutos mientras se construye el contenedor la primera vez. Se abre VS Code en el navegador, ya con g++, gdb y cmake instalados.

Ambiente local: instala [Docker Desktop](https://www.docker.com/products/docker-desktop/) y la extensión **Dev Containers** de VS Code, clona tu copia del repositorio y usa "Reopen in Container".

## Verifica tu ambiente

Dentro del Codespace, abre una terminal y corre:

```
g++ --version    # debe decir "g++ (Ubuntu ...)"
gdb --version
cmake --version
g++ -std=c++20 -Wall -Wextra -g main.cpp -o bin/main
./bin/main
```

Si ves el "Ambiente de C++ funcionando correctamente.", tu ambiente está listo.

## Estructura del repositorio

```
.devcontainer/          Configuración del contenedor (no editar)
main.cpp                Programa de verificación del ambiente
laboratorios/           Laboratorio de cada clase, uno por carpeta
  semana-01-sesion-01/
  semana-01-sesion-02/
  ...
psets/                  Tus entregas de PSet, una carpeta por PSet
  pset-01/
  pset-02/
  ...
```

Cada carpeta de `laboratorios/` y `psets/` tiene su propio `README.md` con las instrucciones de esa entrega.

## Cómo actualizar tu fork cada semana

Cuando se agregue una semana nueva, sincroniza tu fork:

1. En la página de tu fork en GitHub: botón **"Sync fork" → "Update branch"**.
2. En tu Codespace o tu clon local, haz `git pull` para traer esos cambios.

Por terminal, en vez del botón:
```
git fetch upstream
git merge upstream/master
```
(la primera vez, agrega el remoto: `git remote add upstream https://github.com/ErickNaunay/programacion-avanzada-cpp.git`)

## Cómo trabajar aquí

- Compila y ejecuta siempre desde la terminal (no uses el botón "Run" del editor), dentro del Codespace o del contenedor local.
- Haz commit de tu avance seguido, con mensajes que digan qué hiciste, no `"cambios"` o `"fix"`.
- Los binarios compilados van a `bin/` y no se suben al repositorio (ver `.gitignore`).
