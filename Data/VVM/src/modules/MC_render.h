int rot = 0;

void display(){
 // --------------------------------------------------------------------------------
  plog("waiting for actions...");
  n = recvfrom (sockfd, (char *)buffer, 2048, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
  buffer[n] = '\0';
  printf("Client: %s\n", buffer);
  sendto(sockfd, (const char *)retbuff, strlen(retbuff), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
  std::cout<<"buffer complete!"<<std::endl;
 // ---------------------------------------------------------------------------------
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(2,1,2, 0,0,0, 0,1,0);

  glPushMatrix();
   glRotatef(rot,0,rot,1);
   glColor3f(1,1,1);
   glutWireCube(1);
  glPopMatrix();
 plog("writing data...");
 static GLubyte* datazz = new GLubyte[3 * MC_W * MC_H];

 memset(datazz, 0, 3 * MC_W * MC_H);

 glPixelStorei(GL_PACK_ALIGNMENT, 1);
 glReadPixels(0, 0, MC_W, MC_H, GL_RGB, GL_UNSIGNED_BYTE, datazz);

 stbi_write_png("buffer.png", MC_W, MC_H, 3, datazz, MC_W*3);

 //free(datazz);

 glFlush();
 glutSwapBuffers();
/* plog("writing image...");
 static GLubyte* datazz = new GLubyte[3 * MC_W * MC_H];
 memset(datazz, 0, 3 * MC_W * MC_H);

 glPixelStorei(GL_PACK_ALIGNMENT, 1);
 glReadPixels(0, 0, MC_W, MC_H, GL_RGB, GL_UNSIGNED_BYTE, datazz);

 stbi_write_png("buffer.png", MC_W, MC_H, 3, datazz, MC_W*3);
*/
 rot+=10;
}
