#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
// -------- LIBRARIES FOR WORKING --------
#define STB_IMAGE_IMPLEMENTATION"
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "lib/stb/stb_image_write.h"
 #include "lib/stb/stb_image.h"
// ---------------------------------------
// - THESE ARE THE MAIN SOCKET VARIABLES -
// ---------------------------------------
#define PORT 8080                    // port address in which renderer must be called

int sockfd;                          // the socket
char buffer[2048];                   // received buffer
const char *retbuff = "&d";          // sent buffer
struct sockaddr_in servaddr, cliaddr;// address
socklen_t len;
int n;

void plog(std::string);              // log function
void nerror(std::string);            // error function
// -----------------------------------------------
// - THE RENDERER FOR OPENGL FUNCTIONS GOES HERE -
// -----------------------------------------------
#include "src/MC_Main.h"
// -----------------------------------------------
int main(int argc, char **argv){
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
    nerror("socket creation");
  }

  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr,  0,  sizeof(cliaddr));

 // ---------------------------------------
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);
 // ---------------------------------------

  if(bind (sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ){
    perror("Failed to connect address :(");
  }
 // ---------------------------------------
 /* socklen_t len;
  int n;
  len = sizeof(cliaddr);*/

 // ---------------------------------------
  MC_glut_init(argc,argv);
  glutIdleFunc(MC_idle_func);
  glutDisplayFunc(display);
  glutMainLoop();
  /*plog("waiting for actions...");
  n = recvfrom (sockfd, (char *)buffer, 2048, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
  buffer[n] = '\0';
  printf("Client: %s\n", buffer);
  sendto(sockfd, (const char *)retbuff, strlen(retbuff), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
  std::cout<<"buffer complete!"<<std::endl;*/
 // ---------------------------------------
 return 0;
}

void nerror (std::string _err){
 std::cout<<"[ERROR]: "<<_err<<std::endl;
 exit(1);
}

void plog(std::string _log){
 std::cout<<"[System]: "<<_log<<std::endl;
}
