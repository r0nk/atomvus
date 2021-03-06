#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "callbacks.h"
#include "game.h"
#include "graphics.h"

char keys[NUMBER_OF_KEYS];/*boolean array of the input keys*/

void err_callback(int err, const char* description){
	printf("ERR CALLBACK[%i]:%s\n",err,description);
}

void key_callback(GLFWwindow * win, int key, int scanc, int action, int mods){
	if(key==256)/* ESC */
		exit(0);
	keys[key]=action;
}

void cursor_callback(GLFWwindow * win, double xpos, double ypos)
{
#define CAMERA_LOCK 1500
	if(ypos<-CAMERA_LOCK){
		glfwSetCursorPos(win,xpos,-CAMERA_LOCK);
		ypos=-CAMERA_LOCK;
	}
	if(ypos>CAMERA_LOCK){
		glfwSetCursorPos(win,xpos,CAMERA_LOCK);
		ypos=CAMERA_LOCK;
	}

	ypos*=-0.001;
	xpos*=-0.002;

	camera.rot.x=cos(ypos) * sin(xpos);
	camera.rot.z=cos(ypos) * cos(xpos);
	camera.rot.y=sin(ypos);
	camera.right.x=sin(xpos - 3.14f/2.0f);
	camera.right.z=cos(xpos - 3.14f/2.0f);
}

void cursor_button_callback(GLFWwindow * win, int button, int action, int mods)
{
	// 0 = left, 1 = right, 2 = middle
	;
}
