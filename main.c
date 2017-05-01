/* 
 * File:   main.c
 * Author: tapin13
 *
 * Created on May 1, 2017, 9:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutCreateWindow("Glew test");
    GLenum err = glewInit();
    if(GLEW_OK != err) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    
    //fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    
    int major = 2, minor = 0;
    char glVersion[50];
    
    while(1) {
        sprintf(glVersion, "GL_VERSION_%d_%d", major, minor);
        
        if(!glewIsSupported(glVersion)) {
            fprintf(stdout, "%s - NOT Supported\n\n", glVersion);
            major--;
            break;
        }
        
        fprintf(stdout, "%s - Supported\n", glVersion);
        
        major++;
    }
    
    while(1) {
        sprintf(glVersion, "GL_VERSION_%d_%d", major, minor);
        
        if(!glewIsSupported(glVersion)) {
            fprintf(stdout, "%s - NOT Supported\n\n", glVersion);
            minor--;
            break;
        }
        
        fprintf(stdout, "%s - Supported\n", glVersion);
        
        minor++;
    }
    
    sprintf(glVersion, "GL_VERSION_%d_%d", major, minor);
    printf("Finally %s - Supported\n", glVersion);
    
    return (EXIT_SUCCESS);
}

