#include <GL/glut.h>

#include "modules/MC_global.h" // these are the global variables
#include "modules/MC_auxfnc.h" // these are the auxiliar functions
//#include "modules/MC_voxvmc.h" // these are the interpreter functions
#include "modules/MC_render.h" // this is where drawing is done

void MC_glut_init(int argc, char **argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 glutInitWindowSize(MC_W, MC_H);
 glutCreateWindow("MineCart Renderer v 1.0");
 glClearDepth(1.0f);
 glDepthFunc(GL_LEQUAL);
 MC_initialize();
}
