void MC_idle_func(){
  usleep(33);
  glutPostRedisplay();
}

void MC_initialize(){
 glClearColor(0.0,0.0,0.0,0.0);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glEnable(GL_BLEND);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(60, 1,1,2000);
}
