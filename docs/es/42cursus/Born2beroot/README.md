# Born2beroot
![Banner](../../../../img/42cursus/Born2beroot/bob_ross.png)

## 📋 Tabla de contenidos
- [Born2beroot](#born2beroot)
	- [📋 Tabla de contenidos](#-tabla-de-contenidos)
	- [👨🏻‍💻 Hipervisor](#-hipervisor)
	- [💿 Sistema operativo](#-sistema-operativo)
	- [💻 Configuración de la máquina](#-configuración-de-la-máquina)
	- [📥 Instalación](#-instalación)
		- [🌍 Localización](#-localización)
		- [🧑🏻 Ajustes de usuario](#-ajustes-de-usuario)
		- [📦 Software](#-software)
		- [💾 Sistema](#-sistema)
	- [💯 Parte obligatoria](#-parte-obligatoria)
		- [SELinux (Security-Enhanced Linux)](#selinux-security-enhanced-linux)
			- [Configuración](#configuración)
		- [LVM (Logical Volume Manager)](#lvm-logical-volume-manager)
			- [Configuración](#configuración-1)
		- [SSH (Secure Shell)](#ssh-secure-shell)
			- [Configuración](#configuración-2)
		- [Firewalld](#firewalld)
			- [Configuración](#configuración-3)
		- [Hostname](#hostname)
			- [Configuración](#configuración-4)
		- [Política de contraseñas](#política-de-contraseñas)
			- [Configuración](#configuración-5)
	- [🅱️ Parte bonus](#️-parte-bonus)

## 👨🏻‍💻 Hipervisor
[Oracle VM Virtualbox](https://www.virtualbox.org/)

## 💿 Sistema operativo
Se ha decidido realizar este proyecto con [Rocky Linux v9.4](https://rockylinux.org/) utilizando la `minimal.iso` como imagen del sistema operativo.

## 💻 Configuración de la máquina
Se recomienda configurar 2GB (2048 MB) de RAM y 2 CPUs como mínimo.
![Hardware Settings](../../../../img/42cursus/Born2beroot/hw_settings.png)
El disco se reserva de manera dinámica.
![Disk Settings](../../../../img/42cursus/Born2beroot/disk_settings.png)

## 📥 Instalación
Los ajustes de localización se dejarán a gusto del estudiante, sin embargo, el resto de ajustes, se deben dejar como se muestra en la imagen, siendo el nombre del usuario el login del estudiante.
![Installation Settings](../../../../img/42cursus/Born2beroot/install_settings.png)

### 🌍 Localización
Estos ajustes se dejarán a gusto del estudiante.

### 🧑🏻 Ajustes de usuario
Deberemos configurar el usuario root y otro con el login como nombre.

### 📦 Software
Mantendremos la configuración por defecto.

### 💾 Sistema
Deberemos seleccionar el disco que hayamos configurado previamente como disco por defecto.

## 💯 Parte obligatoria
### SELinux (Security-Enhanced Linux)
SELinux es un sistema de control de acceso obligatorio integrado en el núcleo de Linux. Este añade una capa adicional de control que define qué operaciones pueden realizar cada usuario, proceso o aplicación en el sistema, independientemente de los permisos tradicionales. Para ello, utiliza políticas predefinidas o personalizadas que describen cómo deben comportarse las aplicaciones y los usuarios, definiendo qué procesos pueden acceder a qué recursos del sistema, esto lo realiza aplicando una etiqueta, o contexto, de seguridad que es evaluada antes de permitir el acceso.

Puede funcionar en tres distintos modos:
-	Enforcing (Aplicación). Aplica estrictamente las políticas de seguridad, bloqueando cualquier acceso no permitido.
-	Permissive (Permisivo). Registra pero no bloquea las violaciones de las políticas.
-	Disabled (Deshabilitado). Como bien indica el nombre, SELinux no realiza ninguna acción de seguridad en este modo.

En resumen, SELinux otorga una mayor seguridad frente a las amenazas con respecto a las ACL comunes, pues cada proceso y usuario, aún con permisos, puede o no realizar cambios dependiendo de las etiquetas que tenga definidas, limitando los daños que un ataque pueda provocar al sistema.

#### Configuración
Para configurar SELinux, deberemos acceder al archivo `/etc/sysconfig/selinux`. Una vez dentro, nos aseguraremos de que los siguientes parámetros aparecen como se muestra a continuación:
-	SELINUX=enforcing
-	SELINUXTYPE=targeting

> [!NOTE]
> Se recomienda configurar el modo de funcionamiento en *permissive* durante la configuración inicial, ya que el sistema puede tener recursos mal iniciados que no permitan el proceso de arranque.

Para confirmar los cambios, será necesario guardar el archivo y reiniciar el sistema. Una vez este arranque de nuevo, ya tendremos nuestra política de seguridad activa.

> [!TIP]
> Puedes consultar la política que se está ejecutando en todo momento con el comando `getenforce`.

### LVM (Logical Volume Manager)
El almacenamiento tradicional se basa en el espacio individual de cada disco. LVM, sin embargo, administra el espacio combinando la capacidad de los discos disponibles. De esta manera, LVM considera el almacenamiento de todos los discos como una capacidad total. Esto se consigue designando los discos de almacenamieno como *Volúmenes Físicos (PV)*, o capacidad que puede usar LVM. A continuación, estos PVs son añadidos a uno o más *Grupos de Volúmenes (VG)*. Por último, estos VGs son añadidos a uno o más *Volúmenes Lógicos (LV)*, los cuales son tratados como particiones tradicionales.
![LVM Example](../../../../img/42cursus/Born2beroot/basic-lvm-volume.png)

#### Configuración

### SSH (Secure Shell)
#### Configuración

### Firewalld
#### Configuración

### Hostname
El hostname es el nombre por el que se conoce un equipo dentro de una red. Esto se utiliza con el fin de identificar más fácilmente un equipo dentro de una red.

#### Configuración
Tenemos dos maneras de poder cambiar el nombre del equipo:
-	Modificando el fichero `/etc/hostname`
-	Usando el comando `hostnamectl set-hostname <nombre>`
En el caso de Born2beroot, el hostname deberá ser el login del estudiante seguido de 42 (ej.: sede-san42).

Fuente: [https://www.geeksforgeeks.org/hostnamectl-command-in-linux-with-examples/]()

### Política de contraseñas

#### Configuración
-	Tu contraseña debe expirar cada 30 días.
	-	`/etc/login.defs` => PASS_MAX_DAYS 30
-	El número mínimo de días permitido antes de modificar una contraseña deberá ser 2.
	-	`/etc/login.defs` => PASS_MIN_DAYS 2
-	El usuario debe recibir un mensaje de aviso 7 días antes de que su contraseña expire.
	-	`/etc/login.defs` => PASS_WARN_AGE 7
-	Tu contraseña debe tener como mínimo 10 caracteres de longitud. Debe contener una mayúscula, una minúscula y un número. Por cierto, no puede tener más de 3 veces consecutivas el mismo carácter.
	-	`/etc/security/pwquality.conf` => minlen = 10
	-	`/etc/security/pwquality.conf` => ucredit = -1
	-	`/etc/security/pwquality.conf` => lredit = 10
	-	`/etc/security/pwquality.conf` => maxclassrepeat = 3
-	La contraseña no puede contener el nombre del usuario.
-	La contraseña debe tener al menos 7 caracteres que no sean parte de la antigua contraseña. *Esta regla no se aplica para root*.

Una vez cambiada la política de contraseñas, deberemos actualizar las contraseñas de todos los usuarios con el comando `passwd usuario`.

Fuente: [https://www.server-world.info/en/note?os=Rocky_Linux_8&p=pam&f=1]()

## 🅱️ Parte bonus