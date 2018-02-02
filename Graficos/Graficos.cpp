// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>

using namespace std;

GLfloat red, green, blue;
GLfloat angulo = 0.0f;

void actualizar()
{
	//Aquí está bien para cambiar los valores de las variables de mi programa
	
	if (angulo < 360)
	{
		angulo += 0.01;
	}
	else
	{
		angulo = 0.0f;
	}
	

	/*
	red += 0.001;
	green += 0.002;
	blue+= 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;
	*/

}

void dibujar()
{
	//TRIANGULO 1
	glPushMatrix();

	
	//glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.2f, 0.0f);
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.2f,0.2f,0.2f);

	glBegin(GL_TRIANGLES); //INICIA LA RUTINA

	
	

	

	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, -0.5f,0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);
	

	glEnd(); //FINALIZA LA RUTINA
	glPopMatrix();


	//TRIANGULO 2
	glPushMatrix();

	
	//glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	glTranslatef(-0.2f, 0.0f, 0.0f);
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.2f,0.2f,0.2f);

	glBegin(GL_TRIANGLES); //INICIA LA RUTINA






	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);


	glEnd(); //FINALIZA LA RUTINA
	glPopMatrix();

	//TRIANGULO

	glPushMatrix();

	
	//glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.2f, 0.0f, 0.0f);
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.2f,0.2f,0.2f);

	glBegin(GL_TRIANGLES); //INICIA LA RUTINA






	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);


	glEnd(); //FINALIZA LA RUTINA
	glPopMatrix();

}



int main()
{

	//Declaración de venta
	GLFWwindow *window;
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW

	if (!glfwInit())
	{
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//INICIALIZAR VENTANA

	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);


	//verificar si se creó la ventana
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);


	//se trae las funciones de OpenGL Moderno
	glewExperimental = true;

	//INICIALIZAR GLEW

	GLenum glewError = glewInit();

	//verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGl: " << version << endl;

	red = green = blue = 0.0f;

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window))
	{
			//ESTABLECER AREA DE RENDER
		glViewport(0, 0, ancho, alto);
		//ESTABLECER EL COLOR CON EL QUE SE VA A LIMPIAR LA PANTALLA



			glClearColor(red, green, blue, 1);
		


		//LIMPIAR PANTALLA
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		


		//rutina de dibujo
		actualizar();
		dibujar();

		//intercambio de buffers
		glfwSwapBuffers(window);

		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

