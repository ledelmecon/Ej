/** \brief pide al usuario que elija una opcion de menu recibido como parametro
 *
 * \param textoMenu: el menu de opciones a mostrar al usuario para pedir y validar la opcion seleccionada
 * \return int: el numero de opcion validada
 *
 */
int menu(char TextoMenu[]); // Sirve para generar menues con pedido de opciones

//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese una cadena de texto y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return void
 *
 */
void pedirString(char retorno[], char mensajeIngreso[]);

//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese una cadena de texto, valida su tamaño y la asigna a una variable
 *
 * \param stringValido char*: puntero a char donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limite int: el límite para la cantidad de caracteres
 * \return int devuelve cero si no hubo error
 *
 */
void pedirStringValido(char* imput, char mensajeIngreso[], char mensajeDeError[], int max, int min);

//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero entero
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return int: el numero entero
 *
 */
int pedirNumInt(char mensajeIngreso[]);

//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero int y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  int: valor inferior válido
 * \param limiteSuperior  int: valor superior válido
 * \return int: el número validado
 *
 */
int pedirNumIntValido(int* imput,char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini);

//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero int y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  int: valor inferior válido
 * \param limiteSuperior  int: valor superior válido
 * \return int: el número validado
 *
 */
 int pedirNumIntValido2(char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini);//modificacion auxiliar de pedirnumintvalido
