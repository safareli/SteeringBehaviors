#include "../include/gl.h"
#include "../include/Base.h"
#include "../include/Color.h"
#include <GL/gl.h>
#include <GL/glu.h>
using namespace GL;
namespace GL{

    void init(){
		glMatrixMode(GL_PROJECTION);
			glOrtho(0,Base::WIDTH,Base::HEIGHT,0,-1,1);
		glMatrixMode(GL_MODELVIEW);
		glClearColor(0,0,0,1);
    }

    void update(){
    	glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
    }

    void background(Color c){
        double rgba[4];
        c.toDouble(rgba);
        glClearColor(rgba[0],rgba[1],rgba[2],1);
    }

}
