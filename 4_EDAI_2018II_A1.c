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

/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------
	
	typedef struct
	{
   		/** X coordinate */
   		float x;
    	/** Y coordinate */
    	float y;
	}Point;
 
/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------

	void print(Point *p);
	float distance(Point *a, Point *b);					

/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal	*///----------------------------------------------------------

	int main()
	{
 
    	unsigned short num_puntos, cont;
    	Point *P;
 
    	printf("%cCu%cntos puntos tiene el poligono?\n",168,160);
    	scanf("%d",&num_puntos);
    	P = (Point *)malloc (num_puntos * sizeof(Point));
 
   	// Imprime la direccion donde empieza la memoria solicitada dinamicamente.
  		printf("\nLa direccion inicial de la memoria reservada es:  %p",P);
 
    // verifica si se asigno satisfactoriamente la memoria.
    	if (P!=NULL)
    	 {
 			// Solicita las coordenadas de cada punto del poligono y lo almacena por medio de apuntadores
       		 printf("\n\tIngrese las coordenadas de cada punto:\n\t");
        	
        	for (cont=0 ; cont<num_puntos ; cont++)
        	{
            	printf("\n\tCual es la coordenada x del punto %d?\n\t",cont+1);
            	scanf("%f",&(P+cont)->x);
            	printf("\n\tCual es la coordenada y del punto %d?\n\t",cont+1);
            	scanf("%f",&(P+cont)->y);
            }
 
       		 // Accede a la memoria separada por medio de apuntadores para obtener los puntos almacenados
       		 // Se imprime en pantalla las coordenadas de cada punto y la direccion donde se encuentra almacenado
        	
        	for (cont=0 ; cont<num_puntos ; cont++)
        	{
            	printf("\n\n\tEl punto %d es: ",cont+1);
            	print(&((P+cont)->x));
            	printf("\testa almacenado en la direccion %p.",(P+cont));
            	printf("\n\tLa coordenada x del punto %d es: ",cont+1);
   	         	printf("%f \n\ty esta almacenado en la direccion %p.",((P+cont)->x),&(P+cont)->x);
   	         	printf("\n\tLa coordenada y del punto %d es: ",cont+1);
   	         	printf("%f \n\ty esta almacenado en la direccion %p.",((P+cont)->y),&(P+cont)->y);
   	     	}
   	     
   	     	printf("\n\nSe libera el espacio reservado.\n");
   	     	free(P);
	    }
 
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

/*--	6- Manejo de funciones F-01	  --*/

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
	Fecha de inicio: 16/03/2018
	Lugar: AV. UNIVERSIDAD Nº 3000, UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO, C.U., CIUDAD DE 
	MÉXICO, 04510
	------------------------------------------------------------------------------------------

*/
