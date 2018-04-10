	//			||	4_EDAI_2018II_A1	||	Práctica: 04 Almacenamiento en tiempo de ejecución

/*
	------------------------------------------------------------------------------------------
	Descripción del archivo.
	
	Uso de variables:
	
		Las variables se nombran de la siguiente manera: 
				
				(Tipo-de-variable)(Tipo-dato)_(palabra_en_funcion_del_uso_de_la_variable)  
	
				Global  = g		int   = i	* Al momento de declararla se requiere hacer una	
				funcion = f 	float = f		descripción de su uso dentro del programa.
								char  = c
				
		Al momento de declararla, por ejemplo:
					
						int fi_contadorUsuario 	// Contador del número que ingresa el usuario 
						int fi_contadorPc;	// Contador del número génerado por el pc.
				
		* Las variables que tienen la finalidad de actuar cómo contadores dentro de un 
		ciclo, son i, j, k y l. (En ese orden conforme se este trabajando).
			
	Uso de funciónes:
	
		Las funciónes se nombran de acuerdo con el siguiente criterio:
		
			(Tipo-de-funcion)_(descripción_Cada_palabra_inicil_con_mayuscula)
			
			void	= v			* Al momento de declararla se requiere hacer una
			int		= i				descripción de su uso dentro del programa.
				
		Al momento de declararla, por ejemplo:
		
						i_SumaDatos , v_RestaResultados , i_ImprimirDatos 	
	-------------------------------------------------------------------------------------------	
		
		Actividad:
		
	 	Implementar un TDA para un polígono el cual queda definido por el número de puntos y
	 	cada una de sus coordenadas, donde el orden en que los ingresa el usuario define la
 		conectividad de los mismos.
 		Crear las funciones es_cuadrado, es_rectangulo, es_triangulo.
 		
	------------------------------------------------------------------------------------------
*/

/*		1- Librerias		*///--------------------------------------------------------------

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <conio.h>
	#include <time.h>
	#include <stdbool.h>
	#include <string.h>

/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------
	
	typedef struct
	{
   		/** X coordinate */
   		float x;
    	/** Y coordinate */
    	float y;
	}Point;
	
	union entradaDeUsuario
	{
		//	-------------------------------------------------------------------------------------------------------------
		char c_caracter;							//	|	   ( 0 ) 	   | 	char				 |		  1			|	
		unsigned char unc_caracter ;				//	|	   ( 1 )	   |	unsigned char		 |		  1			|
		short int shi_num;							//	|	   ( 2 )	   |	short int			 |		  2			|
		unsigned short int unshi_num;				//	|	   ( 3 )	   |	unsigned short int	 |		  2			|
		int i_num;									//	|	   ( 4 )	   |	int					 |		  4			|
		unsigned int uni_num;						//	|	   ( 5 )	   |	unsigned int		 |		  4			|
		long int loi_num;							//	|	   ( 6 )	   |	long int			 |		  4			|
		unsigned long int unloi_num;				//	|	   ( 7 )	   |	unsigned long int	 |		  4			|
		char array_fifty[50];						//	|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|																
		//	-------------------------------------------------------------------------------------------------------------							
	} ;
	
	struct Color
	{
		short configuracionRapida;
		short texto;
		short fondo;
		short espacio;
		char tituloDelPrograma[50];
		char autor[40];	
	};
 
/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------

	void print(Point *p);
	float distance(Point *a, Point *b);	
	void v_ImprimirMaquetacion ( struct Color *as_Color_Maqueta ); 	
	void v_IdentificadorDeFigura ( Point *Puntos , short i_numeroDePuntos );
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces );			

/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal	*///----------------------------------------------------------

	int main()
	{
		/*----------------------------------------------------------------------------------*/
		struct Color Color_Maqueta;
		short sh_i;
		/*----------Asignar doble espacio al final del c_tituloPrograma y c_nombreAutor-----*/
		char c_tituloPrograma[50] = "Almacenamiento en tiempo de ejecucion  ";
		char c_nombreAutor[40] = "Jose Luis Bautista Rodriguez  " ;
		/*-------------Configuracion Rapida---------------------------------------------------
			Programado:						0	(Usará los valores de titulo y fondo)
			Normal:							1	Texto Blanco	Fondo Negro
			Nocturno:						2	Texto Gris 		Fondo Negro
			Papel:							3	Texto Negro		Fondo Blanco
			Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
			Claro:							5	Texto Gris		Fondo Blanco
			Clasico 1:						6	Texto Verde		Fondo Negro
			Clasico 2:						7	Texto Negro		Fondo Verde
			Todo esta bien:					8	Texto Verde	Cl	Fondo Verde
			Advertencia:					9	Texto Amarillo	Fondo Rojo
		------------------------------------------------------------------------------------*/
		Color_Maqueta.configuracionRapida = 4 ;
		Color_Maqueta.fondo   = 0 ;
		Color_Maqueta.texto   = 3 ;
		Color_Maqueta.espacio = 80 ;
		
		for ( sh_i = 0 ; sh_i < 50 ; sh_i++) Color_Maqueta.tituloDelPrograma[sh_i] = c_tituloPrograma[sh_i];
		for ( sh_i = 0 ; sh_i < 40 ; sh_i++) Color_Maqueta.autor[sh_i] = c_nombreAutor[sh_i];
		
		v_ImprimirMaquetacion( &Color_Maqueta );
		/*-----------------------------------------------------------------------------------*/		
		union entradaDeUsuario DatosDeEntrada;
		//DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3 );
 		/*-----------------------------------------------------------------------------------*/		
 
    	short num_puntos, cont;
    	Point *P;
 
    	printf("\n\t%cCu%cntos puntos tiene el poligono? %c ",168,160, 219 );
    	DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3 );
    	
    	P = (Point *)malloc (DatosDeEntrada.unc_caracter * sizeof(Point));
 		num_puntos = DatosDeEntrada.unc_caracter ;
   	// Imprime la direccion donde empieza la memoria solicitada dinamicamente.-----------------
   	
   		for ( sh_i = 0 ; sh_i < Color_Maqueta.espacio ; sh_i++ ) printf( "%c" , 219 );
  		printf("\n\tLa direccion inicial de la memoria reservada es:  %p \n", P );
  		for ( sh_i = 0 ; sh_i < Color_Maqueta.espacio ; sh_i++ ) printf( "%c" , 219 );
 
    // verifica si se asigno satisfactoriamente la memoria.------------------------------------
    
    	if (P!=NULL)
    	 {
 			// Solicita las coordenadas de cada punto del poligono y lo almacena por medio de apuntadores
       		 printf("\n\n \tIngrese las coordenadas de cada punto:\n\t");
        	
        	for (cont=0 ; cont<num_puntos ; cont++)
        	{
            	printf("\n\t%c Coordenada %d en X  %c\t ", 219 , cont+1, 219 );
            	scanf("%f",&(P+cont)->x);
            	//DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3 );
				fflush(stdin);
            	
            	printf("\t%c Coordenada %d en Y  %c\t ", 219 , cont+1, 219 );
            	scanf("%f",&(P+cont)->y);
            	fflush(stdin);
            }
 
       		 // Accede a la memoria separada por medio de apuntadores para obtener los puntos almacenados
       		 // Se imprime en pantalla las coordenadas de cada punto y la direccion donde se encuentra almacenado
        	//Sleep(2500);
        	system("cls");
        	v_ImprimirMaquetacion( &Color_Maqueta );
        	
        	for ( cont = 0 ; cont < num_puntos ; cont++)
        	{
            	printf("\n\n\t%c El punto %0.2f es: ", 219, cont+1);
            	print((P+cont));
            	printf("\t%c esta almacenado en la direccion %p.", 219, (P+cont));
            	printf("\n\t%c La coordenada x del punto %d es: ", 219, cont+1);
   	         	printf("%f \n\t%c y esta almacenado en la direccion %p.", ((P+cont)->x) , 219,&(P+cont)->x);
   	         	printf("\n\t%c La coordenada y del punto %d es: ", 219, cont+1);
   	         	printf("%f \n\t%c y esta almacenado en la direccion %p.",((P+cont)->y), 219, &(P+cont)->y);
   	     	}
   	     	
   	    	printf("\n\n");
			for ( sh_i = 0 ; sh_i < Color_Maqueta.espacio ; sh_i++ ) printf( "%c" , 219 );
   	     	
   	     	v_IdentificadorDeFigura ( P , num_puntos );	
   	     	
   	     	
   	     	printf("\n\n");
			for ( sh_i = 0 ; sh_i < Color_Maqueta.espacio ; sh_i++ ) printf( "%c" , 219 );
   	     	printf("\n\t\t\t\t\t\tSe libera el espacio reservado.\n");
			for ( sh_i = 0 ; sh_i < Color_Maqueta.espacio ; sh_i++ ) printf( "%c" , 219 );
			printf("\n");
   	     	
   	     	//printf("\n\ttermiino el programa antes del free\n\t");
   	     	/**if (num_puntos < 5 )*/free(P);
   	     	//printf("\n\ttermiino el programa antes del fi\n\t");
	    }
		//printf("\n\ttermiino el programa en despues del if\n\t");
		system("pause");
	  return 0;
 
	}

/*--	4- Función principal 	--*/

/*		5- Manejo de funciones F-01	*///------------------------------------------------------
	
	float distance(Point *a, Point *b)
	{
   	 	float dx = a->x - b->x;
    	float dy = a->y - b->y;
   		
   		return sqrt(dx*dx + dy*dy);
	}

/*--	5- Manejo de funciones F-01	  --*/

/*		6- Manejo de funciones F-02	*///------------------------------------------------------

	void print(Point *p)
	{
   		printf("(%0.2f, %0.2f) \n", p->x, p->y);
	
	}

/*--	6- Manejo de funciones F-02	  --*/

/*		7- Manejo de funciones F-03	*///------------------------------------------------------

	void v_ImprimirMaquetacion (  struct Color *as_Color_Maqueta  )
	{
		/*------------------------------------------------------------------------------------		
		system("color FondoTexto");

		0 = Black  | Negro			   8 = Gray
		1 = Blue   | Azul			   9 = Light Blue
		2 = Green  | Verde			10 A = Light Green
		3 = Aqua   | Aguamarina		11 B = Light Aqua
		4 = Red	   | Rojo			12 C = Light Red
		5 = Purple | Púrpura		13 D = Light Purple
		6 = Yellow | Amarillo		14 E = Light Yellow					
		7 = White  | Blanco			15 F = Bright White	 	

		Ejemplo:

			Sí quieres un fondo Blanco y un texto Azul Claro entonces debes codificar:

			system("color 09"); 

		-------------------------------------------------------------------------------------*/
		
		short sh_controlDeUs = 0 , contador_a= 0, contador_b = 0, contador_c = 0 , sh_espacioParaTitulo, sh_espacioParaAutor, metrica = as_Color_Maqueta->espacio ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->tituloDelPrograma[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->tituloDelPrograma[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaTitulo = contador_b ;
		contador_b = 0 ;
		contador_c = 0 ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->autor[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->autor[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaAutor = contador_b ;
		
		if ( as_Color_Maqueta->fondo == as_Color_Maqueta->texto )
		{
			printf ("\n\t\tAdvertencia:\n");
			printf ("\n\tLos valores de color del fondo y el texto son iguales.\n");
			printf ( "\tSe les ha reasignado un color." );
			system("color 47");
			sh_controlDeUs ++;
		} 
		
		if ( as_Color_Maqueta->configuracionRapida != 0 )
		{
			switch( as_Color_Maqueta->configuracionRapida )
			{
				case 1 : //Normal:							1	Texto Blanco	Fondo Negro
					as_Color_Maqueta->texto = 7 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 2 : //Nocturno:						2	Texto Gris 		Fondo Negro
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 3 : //Papel:							3	Texto Negro		Fondo Blanco
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 4 : //Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
					as_Color_Maqueta->texto = 4 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 5 : //Claro:							5	Texto Gris		Fondo Blanco
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 6 : //Clasico 1:						6	Texto Verde		Fondo Negro
					as_Color_Maqueta->texto = 2 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 7 : //Clasico 2:						7	Texto Negro		Fondo Verde
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 8 : //Todo esta bien:					8	Texto verde		Fondo Verde
					as_Color_Maqueta->texto = 10 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 9 : //Advertencia:						9	Texto Amarillo	Fondo Rojo
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;
				default : //Advertencia:					9	Texto Amarillo	Fondo Rojo
					printf("\n\t Valor en Color Configuracion Rapida no valido\n");
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;																										
			}
		}
		
		if ( as_Color_Maqueta->fondo != as_Color_Maqueta->texto )
		{
			if ( as_Color_Maqueta->fondo < 16 && as_Color_Maqueta->texto < 16 )
			{
				
				if ( as_Color_Maqueta->fondo > -1 && as_Color_Maqueta->texto > -1 )
				{
					
					switch ( as_Color_Maqueta->fondo )
					{
						case 0 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 00");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 01");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 02");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 03");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 04");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 05");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 06");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 07");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 08");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 09");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 0A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 0B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 0C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 0D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 0E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 0F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 1 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 10");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 11");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 12");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 13");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 14");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 15");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 16");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 17");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 18");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 19");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 1A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 1B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 1C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 1D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 1E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 1F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 2 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 20");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 21");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 22");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 23");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 24");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 25");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 26");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 27");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 28");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 29");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 2A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 2B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 2C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 2D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 2E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 2F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 3 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 30");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 31");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 32");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 33");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 34");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 35");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 36");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 37");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 38");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 39");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 3A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 3B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 3C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 3D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 3E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 3F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 4 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 40");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 41");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 42");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 43");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 44");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 45");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 46");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 47");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 48");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 49");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 4A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 4B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 4C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 4D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 4E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 4F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 5 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 50");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 51");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 52");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 53");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 54");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 55");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 56");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 57");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 58");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 59");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 5A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 5B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 5C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 5D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 5E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 5F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 6 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 60");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 61");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 62");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 63");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 64");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 65");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 66");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 67");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 68");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 69");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 6A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 6B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 6C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 6D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 6E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 6F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 7 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 70");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 71");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 72");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 73");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 74");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 75");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 76");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 77");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 78");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 79");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 7A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 7B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 7C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 7D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 7E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 7F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 8 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 80");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 81");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 82");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 83");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 84");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 85");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 86");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 87");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 88");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 89");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 8A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 8B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 8C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 8D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 8E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 8F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 9 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 90");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 91");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 92");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 93");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 94");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 95");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 96");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 97");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 98");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 99");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 9A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 9B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 9C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 9D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 9E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 9F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 10 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color A0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color A1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color A2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color A3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color A4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color A5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color A6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color A7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color A8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color A9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color AA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color AB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color AC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color AD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color AE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color AF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 11 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color B0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color B1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color B2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color B3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color B4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color B5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color B6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color B7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color B8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color B9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color BA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color BB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color BC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color BD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color BE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color BF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 12 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color C0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color C1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color C2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color C3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color C4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color C5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color C6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color C7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color C8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color C9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color CA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color CB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color CC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color CD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color CE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color CF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 13 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color D0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color D1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color D2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color D3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color D4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color D5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color D6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color D7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color D8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color D9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color DA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color DB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color DC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color DD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color DE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color DF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 14 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color E0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color E1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color E2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color E3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color E4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color E5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color E6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color E7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color E8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color E9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color EA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color EB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color EC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color ED");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color EE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color EF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 15 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color F0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color F1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color F2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color F3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color F4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color F5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color F6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color F7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color F8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color F9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color FA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color FB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color FC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color FD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color FE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color FF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						default : 
							printf("\n\tFuncion v_ImprimirMaquetacion no funciono como se esperaba. \n ");
							system( "color 47" );
							break;		  																																																																																					
					}
					
				}
				else if ( as_Color_Maqueta->fondo < 0 && as_Color_Maqueta->texto < 0 )
				{
					printf ("\n\t\tAdvertencia:\n");
					printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
					printf ( "\tSe les ha reasignado un color." );
					system("color 47");
					sh_controlDeUs ++;
				}
			}
			else if ( as_Color_Maqueta->fondo > 16 && as_Color_Maqueta->texto > 16 ) 
			{
				printf ("\n\t\tAdvertencia:\n");
				printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
				printf ( "\tSe les ha reasignado un color." );
				system("color 47");
				sh_controlDeUs ++;
			}
		}
		
		short i, i_espacio, i_imprimir, espacio_Imprimir;
		
		if ( sh_controlDeUs == 1 )
		{
			if ( sh_espacioParaAutor > sh_espacioParaTitulo ) espacio_Imprimir = sh_espacioParaAutor ;
			else if ( sh_espacioParaTitulo > sh_espacioParaAutor ) espacio_Imprimir = sh_espacioParaTitulo ;
			
			espacio_Imprimir = metrica - espacio_Imprimir;
			espacio_Imprimir = espacio_Imprimir - 2 ;
			if ( espacio_Imprimir < 0 )
			{
				printf("\n\tEl tama%co del titulo o nombre es demaciado largo \n");
				espacio_Imprimir = 10 ;	
			}
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf("%c" , 219 ); 
			printf(" ");
			for( i = 0; i < 50; i++)printf("%c" ,  as_Color_Maqueta->tituloDelPrograma[i] );
			
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf( "%c" , 219 );
			printf( " " );			
			for( i = 0; i < 40; i++)printf("%c" ,  as_Color_Maqueta->autor[i] );
			printf("\n");
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			//printf("\n");	
		}
	}
	

/*--	7- Manejo de funciones F-03	  --*/

/*		8- Manejo de funciones F-04	*///------------------------------------------------------
	
	/*
		La Función  determina:
		
		1	 Sí los puntos no pertenecen a un sólo punto.
		2	 Sí no forman una línea.
		3	 Sí Forman un triangulo.
		4	 Sí es un rectangulo.
		5	 Sí es un cuadrado.
		6	 Sí corresponden a otro tipo de figura. 
	
	*/
	
	
	void v_IdentificadorDeFigura ( Point *Puntos , short i_numeroDePuntos )
	{
		short sh_i, sh_j, condicion, facto;
		bool b_esUnTriangulo = false;
		bool b_unSoloPunto = false;
		
		// 1 Determinar que los puntos no sean iguales.
		float *f_distanciaDePuntos, f_distanciasEntrePuntos[7], constante, constante2;
		
		if ( i_numeroDePuntos > 2 && i_numeroDePuntos < 5 )
		{
			if ( i_numeroDePuntos == 4 )
			{
				f_distanciasEntrePuntos[0] = 4;
				
				for ( sh_i = 0 ; sh_i < 3 ; sh_i++ )f_distanciasEntrePuntos[1 + sh_i] = distance( &Puntos[0] , &Puntos[1 + sh_i] );
				for ( sh_i = 0 ; sh_i < 2 ; sh_i++)f_distanciasEntrePuntos[5 + sh_i] = distance( &Puntos[1] , &Puntos[2 + sh_i] );
				f_distanciasEntrePuntos[7] = distance( &Puntos[2] , &Puntos[3] );
				
				for ( sh_i = 0 ; sh_i < 7 ; sh_i++ ) if ( f_distanciasEntrePuntos[1 + sh_i] == 0 )
				{
					//printf("\nAlgo paso %i , distancia = %f ",  sh_i+1, f_distanciasEntrePuntos[1+sh_i]);
					b_unSoloPunto = true ;	
				 } 
									
			}else if ( i_numeroDePuntos == 3 )
			{
				f_distanciasEntrePuntos[0] = 3;
				f_distanciasEntrePuntos[1] = distance( &Puntos[0] , &Puntos[1] );
				f_distanciasEntrePuntos[2] = distance( &Puntos[0] , &Puntos[2] );
				f_distanciasEntrePuntos[3] = distance( &Puntos[1] , &Puntos[2] );
				
				for ( sh_i = 0 ; sh_i < 3 ; sh_i++ ) if ( f_distanciasEntrePuntos[1 + sh_i] == 0 ) b_unSoloPunto = true ;
			}
			
		}
		
		else if ( i_numeroDePuntos == 2 )
		{
			f_distanciasEntrePuntos[0] = 2 ;
			f_distanciasEntrePuntos[1] = distance( &Puntos[0] , &Puntos[1] );
			if ( f_distanciasEntrePuntos[1] == 0 ) b_unSoloPunto = true ;	
		}
		
		else if ( i_numeroDePuntos == 1 ) b_unSoloPunto = false;
		else if ( i_numeroDePuntos > 4 )
		{
			f_distanciaDePuntos = (float *)malloc (i_numeroDePuntos * sizeof(float));
			condicion = 0 ;
			
			facto = i_numeroDePuntos - 1 ;
			short facto_2 = facto ;
			
			
			//printf("\nFacto vale = %i ", facto);
			//printf("\nFacto_2 Vale %i ", facto_2);
			
			for ( sh_i = 0 ; sh_i < facto ; sh_i++ )
			{
				for ( sh_j = 0 ; sh_j < facto_2 ; sh_j++ )
				{
					f_distanciaDePuntos[condicion] = distance( &Puntos[sh_i] , &Puntos[ facto - sh_j] ); 
					//printf("\nLa distancia %i es de %f, para el punto: ( %.2f , %.2f ) y el punto: ( %.2f , %.2f )  ", (condicion+1) , f_distanciaDePuntos[condicion], Puntos[sh_i].x , Puntos[sh_i].y, Puntos[facto - sh_j].x , Puntos[ facto - sh_j].y );
					condicion++;
				}
				facto_2--;
				//printf("\nFacto_2 Vale %i ", facto_2);
			}

			//if( condicion == i_numeroDePuntos ) condicion = 0;
			
			constante = ( i_numeroDePuntos * i_numeroDePuntos );
			constante = constante/2 ;
			constante2 = ( i_numeroDePuntos * 0.5 );
			constante = constante - constante2 ;
			
			for ( sh_i = 0 ; sh_i < constante ; sh_i++) if ( f_distanciaDePuntos[sh_i] == 0 ) b_unSoloPunto = true ;
			
		 } 
		 
		if( b_unSoloPunto ) printf ( "\n\tHay puntos que son iguales.\n" );
		
		//-2	 Sí no forman una línea.--------------------------------------------------------
		
		
		
		
		
		printf("\n\tFuncion IdentificadorDeFigura");
	}
	
/*--	8- Manejo de funciones F-04	  --*/

/*		9- Manejo de funciones		*///------------------------------------------------------
	
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces )
	{
		/*
			Configuración de la función de entrada:
			
			| Valor de entrada | 	Valor que devuelve	 |	Tamaño 	(bytes)	|
			-----------------------------------------------------------------
			|	   ( 0 ) 	   | 	char				 |		  1			|	
			|	   ( 1 )	   |	unsigned char		 |		  1			|
			|	   ( 2 )	   |	short int			 |		  2			|
			|	   ( 3 )	   |	unsigned short int	 |		  2			|
			|	   ( 4 )	   |	int					 |		  4			|
			|	   ( 5 )	   |	unsigned int		 |		  4			|
			|	   ( 6 )	   |	long int			 |		  4			|
			|	   ( 7 )	   |	unsigned long int	 |		  4			|
			|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|															
			-----------------------------------------------------------------						
		
		*/
		short i, sh_parametroDeSalida = 0, sh_numeroDeVecesIngresadas = 0, s_cortaFuego;
		union entradaDeUsuario AnalisisDeEntrada;
		char c_textoDePaso[20];
		int paso, dio;
		
		do{
		
		// Se resive el valor de entrada del usuario como texto:		
			fgets( c_textoDePaso, 20, stdin );
			fflush(stdin);
			
				switch( sh_configuracion )
				{
					case 0  : // | 	char				 |-----------------------------------------
						// Se analizá que el valor sea el correcto.
						
						if( (int)c_textoDePaso[1] > 33  )
						{
							printf("\n\t%c Se ha ingresado m%cs de un c%cracter.", 219, 160, 160);
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intentos) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intento) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.c_caracter = 'X';
							break;	
						}
						else if ( (int)c_textoDePaso[0] > 32 )
						{
							AnalisisDeEntrada.c_caracter = c_textoDePaso[0];
							// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						}else printf("\n\t%c Valor no valido", 219);
						
						AnalisisDeEntrada.c_caracter = 'X';						
						break;
						
					case 1  : // |	unsigned char		 | -----------------------------------------
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						int i_paso = atoi(c_textoDePaso);
						unsigned char unc_paso = atoi(c_textoDePaso);
						
						for ( i = 0 ; i < 3 ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							//printf("El paso es de %i", paso);

							if ( paso > 57 || paso < 48 && paso > 10 )
							{
								printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
								s_cortaFuego++;
								break;
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else 	if ( i_paso > 255 || i_paso < 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unc_caracter = unc_paso;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						}
						break;	
				
					case 2  : // |	short int			 |-----------------------------------------
						//  RANGO -32768 a 32767 
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						long int loi_paso = atoi(c_textoDePaso);
						short int si_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.shi_num = si_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						}
						break;
						
					case 3  : // |	unsigned short int	 |-----------------------------------------
							  // 0 a 65535
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned short int unshi_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unshi_num = unshi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						}
						break;
						
					case 4  : // |	int					 |-----------------------------------------	
						// -32768 a 32767
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						i_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.i_num = i_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						}
						break;

					case 5  :  //|	unsigned int		 |-----------------------------------------
							   //|  0 a 65535			 |
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned int uni_paso = atoi(c_textoDePaso);
						short j;
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.uni_num = uni_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						}
						break;
						
					case 6  : // |	long int			 |-----------------------------------------
						      // | -2147483648 a 2147483647
						      //   12345678901   1234567890
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						double d_paso = atoi(c_textoDePaso);
						loi_paso = atoi(c_textoDePaso);
						unsigned char uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
												
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i = 0;
							
							char ca_paso[3];
							for ( i = 1 ;  i < 4 ; i++ ) ca_paso[i-1] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[10] > 47 && (int)c_textoDePaso[10] < 58 )
							{
								if ( up > 214 )uc_i++; 
								else if ( up == 214 )
								{
									j = 0 ;
									for ( i = 4 ;  i < 7 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 748 )uc_i++;
									else if ( up == 748 )
									{
										j = 0 ;
										for ( i = 7 ;  i < 10 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 364 ) uc_i++;
										else if ( up == 364 ) if ( (int)c_textoDePaso[10] - 48 > 8 ) uc_i++;
									}
								}
							
							}
																				
							if ( uc_i == 0 )for ( i = 1 ; i < 11 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									//break;
								}							
							}							
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
									if ( up > 214 )uc_i++; 
									else if ( up == 214 )
									{
										j = 0 ;
										for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 748 )uc_i++;
										else if ( up == 748 )
										{
											j = 0 ;
											for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
											up = atoi(ca_paso);
											
											if ( up > 364 ) uc_i++;
											else if ( up == 364 ) if ( (int)c_textoDePaso[9] - 48 > 7 ) uc_i++;
										}
									}
																
								}
								
								
							for ( i = 0 ; i < 10 ; i++)
								{
									paso = (int)c_textoDePaso[i] ;
		
									if ( paso > 57 || paso < 48 && paso > 32 )
									{
										printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
										s_cortaFuego++;
										break;
									}							
								}
									
							}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
							
						//-2147483648
							
						} else 	if ( uc_i > 0 || d_paso > 2147483647 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.loi_num = loi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						}
						break;
						
					case 7  :  // |	unsigned long int	 |-----------------------------------------
						//   0 a 4294967295
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						d_paso = atoi(c_textoDePaso);
						unsigned long int unloi_paso = atoi(c_textoDePaso);
						uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i ++;
														
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);// 429 496 729 5
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
								if ( up > 429 )uc_i++; 
								else if ( up == 429 )
								{
									j = 0 ;
									for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 496 )uc_i++;
									else if ( up == 496 )
									{
										j = 0 ;
										for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 729 ) uc_i++;
										else if ( up == 729 ) if ( (int)c_textoDePaso[9] - 48 > 5 ) uc_i++;
									}
								}
							}
							
							for ( i = 0 ; i < 10 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
							
						} else 	if ( uc_i > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unloi_num = unloi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						}						
						break;
					case 8 : 
						
						dio = strlen( c_textoDePaso );
						
						c_textoDePaso[dio-1] = '\0' ;

						strcpy( AnalisisDeEntrada.array_fifty , c_textoDePaso );
						sh_parametroDeSalida = sh_numeroDeVeces;
						
						break;
						
					default : 
					
						printf("\t\nFuncion eDU_AnalizarEntrada: Valor ingresado en sh_configuracion no valido");

						break;
				}
		
			sh_numeroDeVecesIngresadas++;
			if( sh_numeroDeVecesIngresadas == sh_numeroDeVeces ) sh_parametroDeSalida = sh_numeroDeVeces;
						
		}while( sh_parametroDeSalida != sh_numeroDeVeces );		
		
		return AnalisisDeEntrada;
	}
								
/*--	9- Manejo de funciones 	  --*/

/*
		||		Datos Generales del archivo:		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	1227 Estructura de Datos y Algoritmos 1
	Docente: Ing. Jonathan Roberto Torres Castillo
	Grupo: 09
	
	Práctica: 04 Almacenamiento en tiempo de ejecución
	 
	Autor: José Luis Bautista Rodríguez
	Fecha de inicio: 19/03/2018
	Lugar: AV. UNIVERSIDAD Nº 3000, UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO, C.U., CIUDAD DE 
	MÉXICO, 04510
	------------------------------------------------------------------------------------------
*/
