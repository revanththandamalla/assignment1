#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct input{
        char* keyword;
        int count;
    };
     void inputKeyAndCount(int argc,char **argv,struct input *in){
       int i;
        for(i=0;i<argc;i++){           
            printf(" %s ",argv[i]);
            in[i].keyword=argv[i];
            in[i].count=0;
        
         }
       }

         void scanningWords(char *textf,size_t max,ssize_t n,int argc,char **argv,struct input *in){
    int i;
         while ( (n = getline(&textf, &max, stdin)) > 0) {
            textf[strcspn(textf, "\n")] = 0;
            char remove[]=" ";
             char *ptr=strtok(textf,remove);
             while(ptr!=NULL){


			for(i=1;i<argc;i++){
	if(strcmp(ptr,argv[i])==0){
	in[i].count++;
	
    }          
                
             }

             	ptr=strtok(NULL,remove);
                         } 
         }
         }

         void displayCount(int argc,char **argv,struct input *in){
          int i;
         printf("the keywords and count \n");
         for(i=1;i<argc;i++){
             printf("%s  %d \n",in[i].keyword,in[i].count);
         }
   
         }
   
    int main(int argc, char** argv){
        char *textf=NULL;
	size_t max=1000;
    ssize_t n=1000;
        int i;
       struct input* in = malloc(argc* sizeof *in);
        inputKeyAndCount(argc,argv,in);
         scanningWords(textf,max,n,argc,argv,in);
         displayCount(argc,argv,in);
         free(textf);
    return 0;
    }

    
         
      
    	
	
    
    