// Grace Choe, 2023
// Aline Normoyle, 2020
//
// This program opens a window with a solid colored background that changes in color every
// time the user clicks the right arrow button on the keyboard.
//
// For documentation about this code, see the glfw3 quick start guide
//   https://www.glfw.org/docs/3.3/quick.html

#include "AGL.h"
#include "AGLM.h"
#include <cmath>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
   } else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) { 
      //Animate for color
      double time = glfwGetTime();
      double red = (sin(time) + 1) * 0.5; // map sin value [-1,1] to color value [0,1]
      double blue = (cos(time) + 1) * 0.5; // map cos value [-1,1] to color value [0,1]
      glm::vec3 color(red, 0, blue);
      glClearColor(color.x, color.y, color.z, 1.0);
   }
}

int main(int argc, char** argv)
{
   GLFWwindow* window;

   if ( !glfwInit() )
   {
      return -1;
   }

#ifdef __APPLE__
   // Explicitly ask for a 4.0 context on OS X 
   glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 0);
   glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

   /* Create a windowed mode window and its OpenGL context */
   window = glfwCreateWindow( 1280, 720, "Hello World", NULL, NULL );
   if (!window)
   {
      glfwTerminate();
      return -1;
   }

   // Make the window's context current 
   glfwMakeContextCurrent(window);

   // Tell GLFW to call our callback fun when a key is pressed
   glfwSetKeyCallback(window, key_callback);

   //Animate for color so the screen opens with a color rather than just being empty
   double time = glfwGetTime();
   double red = (sin(time) + 1) * 0.5; // map sin value [-1,1] to color value [0,1]
   double blue = (cos(time) + 1) * 0.5; // map cos value [-1,1] to color value [0,1]
   glm::vec3 color(red, 0, blue);
   glClearColor(color.x, color.y, color.z, 1.0);

   // Loop until the user closes the window 
   while (!glfwWindowShouldClose(window))
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers

      // Calls back to the glfwSetKeyCallback to check if the right key is pressed
      // to prompt change of color, does so while the window is open
      glfwSetKeyCallback(window, key_callback);

      // Swap front and back buffers
      glfwSwapBuffers(window);

      // Poll for and process events
      glfwPollEvents();
   }

   glfwTerminate();
   return 0;
}