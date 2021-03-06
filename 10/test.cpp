 #include <stdio.h>  /* defines FILENAME_MAX */ 
 // #define WINDOWS  /* uncomment this line to use it for windows.*/  
 #ifdef WINDOWS 
 #include <direct.h> 
 #define GetCurrentDir _getcwd 
 #else 
 #include <unistd.h> 
 #define GetCurrentDir getcwd 
 #endif 
 #include<iostream> 
 #include <string>
 
std::string GetCurrentWorkingDir() { 
   char buff[FILENAME_MAX]; 
   GetCurrentDir(buff, FILENAME_MAX); 
   std::string current_working_dir(buff); 
   return current_working_dir; 
 }
 
 int main(){ 
   std::cout << GetCurrentWorkingDir() << std::endl;
   char cc = '"';
   std::cout << cc << std::endl;
   return 1; 
 } 