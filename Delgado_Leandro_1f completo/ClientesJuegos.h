typedef struct{
 int dia;
 int mes;
 int anos;
}eFecha;

typedef struct{
 int codJuego;
 char descripcion[51];
 int importe;
}eJuegos;

typedef struct {
    int codCliente;
    char name[31];
    char lastname[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int contador;
    int isEmpty;
}eClientes;

typedef struct{
int codAlquiler;
int codJuego;
int codCliente;
eFecha fechas;
}eAlquileres;

//-----------------------------------------------------------------------------------------------//
/** \brief inicia el isempty de los clientes
 *
  * \param cadena de clientes
  * \param maximo de la cadena
 */
void initClientes(eClientes clientes[], int maxi);
//-----------------------------------------------------------------------------------------------//
/** \brief busca los clientes acivos y los lista
 *
  * \param cadena de clientes
  * \param maximo de la cadena
  * \return retorna error en caso de no encontrar activos
 */
int buscaClienteOperar(eClientes clientes[],int maxi);

//-----------------------------------------------------------------------------------------------//
/** \brief busca el primer espacion libre del cliente
 *
  * \param cadena de clientes
  * \param maximo de la cadena
  * \return retorna espacio libre
 */
int buscaLibre(eClientes clientes[], int maxi);

//-----------------------------------------------------------------------------------------------//
/** \brief pide datos de la estructura cliente y los carga con la funcion carga
 *  \param cadena de clientes
  * \param cliente axuliar para manipular
  * \param pide espacio libre
  *
 */
void pedirDatosPersona(eClientes clientes[],eClientes cliente,int espaciolibre);

//-----------------------------------------------------------------------------------------------//
/** \brief carga el cliente axuliar al cliente definitivo como prevencion
 *  \param cadena de clientes
  * \param cliente axuliar para manipular
  * \param pide espacio libre
  *\return error
  *
 */
int cargaPersona(eClientes clientes[],eClientes clienteAux,int espacioLibre);

//-----------------------------------------------------------------------------------------------//
/** \brief pide un numero de cliente activo. si encuentra permite modificar campos
 *  \param cadena de clientes
  * \return error
 */
int buscarClienteModificar (eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief busca clientes isempty==1 para poder darlos de baja
 *  \param cadena de clientes
  * \return error
 */
int darBajaCliente(eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief ordena nombres con burbujeo
 *  \param cadena de clientes
 */
void ordenarNombreAscendente(eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief lista desde el indice 0 a numero determinado
 *  \param cadena de clientes
 */
void listarPersonas(eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief ordena nombre con burbujeo
 *  \param cadena de juegos
 */
void ordenarJuegosAscendente(eJuegos juegos[]);

//-----------------------------------------------------------------------------------------------//
/** \brief lista desde el indice 0 a numero determinado
 *  \param cadena de juegos
 */
void listarJuegos(eJuegos juegos[]);

//-----------------------------------------------------------------------------------------------//
/** \brief inicia fechas en 0 de los alquileres
 *
  * \param cadena de clientes
  * \param maximo de la cadena
 */
void initAlquiler(eAlquileres alquileres[]);

//-----------------------------------------------------------------------------------------------//
/** \brief genera un alquiler relacionando ids
 *  \param cadenas de alquileres,juegos,clientes
  * \return error
 */
int generarAlquilerJuegos(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief busca ocurrencias de muchos a muchos
 *  \param cadenas de alquileres,juegos,clientes
 */
void buscarOcurrencia(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[]);

//-----------------------------------------------------------------------------------------------//
/** \brief promedio del costo de los juegos
 *  \param cadenas de alquileres,juegos
 */
void promedioTotalJuegos(eAlquileres alquileres[],eJuegos juegos[]);
//-----------------------------------------------------------------------------------------------//
/** \brief busca los juegos que no superan el promedio de juegos alquilados
 *  \param cadenas de alquileres,juegos
 */
void  juegosNoSUperanPromedio(eAlquileres alquileres[],eJuegos juegos[]);


//-----------------------------------------------------------------------------------------------//
/** \brief lista clientes que alquilaron juegos
 *  \param cadenas de alquileres,juegos,clientes
 */
void listarClientesQueAlquilaron(eAlquileres alquileres[],eClientes clientes[],eJuegos juegos[]);

//-----------------------------------------------------------------------------------------------//
/** \brief lista juegos de cliente
 *  \param cadenas de alquileres,juegos,clientes
 */
void listarJuegosDeCliente(eClientes clientes[],eAlquileres alquileres[],eJuegos juegos[]);

//-----------------------------------------------------------------------------------------------//
/** \brief lista juegos menos alquilados
 *  \param cadenas de alquileres,juegos
 */
void listarJuegosMenosAlquilados(eAlquileres alquileres[],eJuegos juegos[]);


//-----------------------------------------------------------------------------------------------//
/** \brief lista clientes que alquilaron mas
 *  \param cadenas de alquileres,juegos,clientes
 */
void listarClientesQAlquilaronMas(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[]);


//-----------------------------------------------------------------------------------------------//
/** \brief ingresas una fecha y lista si hay coincidencia
 *  \param cadenas de alquileres,juegos
 */
void listarJuegosenEnUnaFecha(eAlquileres alquileres[],eJuegos juegos[]);
//-----------------------------------------------------------------------------------------------//

/** \brief ingresas una fecha y lista si hay coincidencia(cliente)
 *  \param cadenas de alquileres,clientes
 */
void listarCLientesEnUnaFecha(eAlquileres alquileres[],eClientes clientes[]);
//-----------------------------------------------------------------------------------------------//


/** \brief lista juegos de la manera mas eficiente
 *  \param cadenas de juegos
 */
void listarJuegosImporteDescendente(eJuegos juegos[]);



//-----------------------------------------------------------------------------------------------//


/** \brief lista apellidos por insercion
 *  \param cadenas de juegos
 */
void listarPorInsercion(eClientes clientes[]);




