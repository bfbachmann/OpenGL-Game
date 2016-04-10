#include <iostream>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GameObject.hpp"
#include "Location.hpp"

using namespace std;


void render(GameObject **objects, int numObjects);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);



int main(int argc, char** argv) {
    
    // Create game objects.
    GameObject *mainCharacter = new GameObject();
    GameObject **objects = (GameObject **) malloc(sizeof(GameObject *));
    objects[0] = mainCharacter;
    int numObjects = 1;
    
    // Set mainCharacter locaiton.
    mainCharacter->getLocation()->set(5, 5);
	
    
    // Initialize GLFW library.
    if (!glfwInit()) {
        cout << "Could not initialize GLFW." << endl;
        return 1;
    }
    
    // Create GLFW window
    GLFWwindow *window = glfwCreateWindow(640, 480, "Skydiver", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        cout << "Could not create GLFW window." << endl;
        return 1;
    }
    
    // Make GLFW's context current.
    glfwMakeContextCurrent(window);
    
    // Set key callbacks.
    glfwSetKeyCallback(window, key_callback);
    
    
    // Game loop.
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        render(objects, numObjects);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }

    
    // End program.
    glfwTerminate();
    free(objects);
	return 0;
}



void render(GameObject** objects, int numObjects) {
    for (int i = 0; i < numObjects; i++) {
        objects[i]->render();
    }
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}