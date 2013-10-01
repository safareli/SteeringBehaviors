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

    void color(Color c){
        double rgba[4];
        c.toDouble(rgba);
        glColor3f(rgba[0],rgba[1],rgba[2]);
        //glColor3f(0,0,0);
    }

    void circle (double cx, double cy, double r){
        glPushMatrix();
            int num_segments = 10 * sqrtf(r);
	        float theta = 2 * 3.1415926 / float(num_segments);
			float c = cosf(theta);//precalculate the sine and cosine
			float s = sinf(theta);
			float t;

			float x = r;//we start at angle = 0
			float y = 0;
            glBegin( GL_TRIANGLE_FAN  );
            //glBegin( GL_TRIANGLE_FAN );
            //glBegin(GL_LINE_LOOP);
               	for(int ii = 0; ii < num_segments; ii++) {
					glVertex2f(x + cx, y + cy);//output vertex

					//apply the rotation matrix
					t = x;
					x = c * x - s * y;
					y = s * t + c * y;
				}
            glEnd();
        glPopMatrix();
    }
}
