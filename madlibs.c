//Users: Nathan Farinas, James Palmquist, Collette Ponce
#include <stdio.h>
//Defining macros and text pointers
#define ROW 50
#define COL 50
#define PROMPT1 "madlib1.txt"
#define PROMPT1LEN 24
#define PROMPT2LEN 20
#define PROMPT2 "madlib2.txt"
#define madlibFinal "madlibFinal.txt"
//Initializing function prototypes
void text(char *file, char madlib[ROW][COL]);
void userInput(char madlib[ROW][COL]);
void getAdjective(int*, char words[][COL], char madlib[][COL] );
void getNoun(int *, char words[][COL], char madlib[][COL]);
void getVerb(int *, char words[][COL], char madlib[][COL]);
void changeline(char madlib[ROW][COL]);
//Main function
int main(){
	//Declaring our 2D array which will contain the text prompt
	char madlib[ROW][COL];
	//Variable for the user to select which prompt to do
	int choice;

	printf("Prompt 1 or 2: ");
	scanf("%d", &choice);
    	//Selects the prompt depending on the user's input
	if(choice == 1){
		//Calling each function that: grabs the text, gets the user's input for each noun, verb, and adjective, then the last function which allows us to navigate through each line in the madlib
        	text(PROMPT1, madlib);
   	 
        	userInput(madlib);
       	 
        	changeline(madlib);

        	for(int rowI = 0;rowI < PROMPT1LEN;rowI++){
		    	for(int colI = 0;madlib[rowI][colI] != '\0';colI++){
		        	printf("%c",madlib[rowI][colI]);
		    	}
          	}
	}
    
	else{
	//Calling each function that: grabs the text, gets the user's input for each noun, verb, and adjective, then the last function which allows us to navigate through each line in the madlib
		text(PROMPT2, madlib);
	   	 
	    	userInput(madlib);
	   	 
	    	changeline(madlib);
	   	 
		for(int rowI = 0;rowI < PROMPT2LEN;rowI++){
		    	for(int colI = 0;madlib[rowI][colI] != '\0';colI++){
		        	printf("%c",madlib[rowI][colI]);
		    		}
			}
    	}
   	 
    	printf("\n");
   	 
	return 0;
}

void text(char *file, char madlib[ROW][COL]){
	//Function to open the file using file pointer and sets our madlib array equal to the text
	FILE* fp;
	fp = fopen(file, "r");
        if(fp == NULL){
            	printf("Can't open file");
        }
    
	int i = 0;
	while(fgets(madlib[i], ROW, fp) != NULL){
    		i++;
	}
    
	fclose(fp);
}


void userInput(char madlib[ROW][COL]){
	//Declares array which will be used for other functions
    	char words[ROW][COL];
    	//Declares our pointer variable which will be used for other functions
    	int rowN;
	for(int row = 0; row < ROW; row++){
		//Switch which calls each function depending on the letter that is encountered 
    		switch(madlib[row][0]){
		    	case 'A':
		        	rowN=row;
		            	getAdjective(&rowN, words, madlib);
		           	 
		            	break;
	       	 
			case 'N':
		        	rowN=row;
		            	getNoun(&rowN, words, madlib);

		            	break;

			case 'V':
		          	rowN=row;
		            	getVerb(&rowN, words, madlib);

		            	break;
			}
	}
}

void getAdjective(int *row, char words[][COL], char madlib[][COL]){
	//Function that is used when A is encountered in the prompt
	//Declaring string used for the user's word
	char adjective[COL];
    	int a=0;
    	//Prompts the user to enter a word then grabs it and inserts it into the 2d array madlib
	printf("Enter an Adjective: ");
    	scanf(" %s", adjective);
   	for(int i=0;adjective[i] != '\0';i++){
           	words[i][0] = adjective[i];
           	madlib[*row][i]=words[i][0];
           	a++;
   	}
  	//If else statement used to get rid of spaces for visual clarity
    	if(madlib[*row+1][0] == '.' || madlib[*row+1][0] == ',' || madlib [*row+1][0] == '!'){
        	madlib[*row][a]='\0';
	}
	//Else if statement to end a line at the end of the string in the 2d array
   	else if(madlib[*row][a+1] != '.' && madlib[*row][a+1] != ',' && madlib [*row][a+1] != '!'){
        	madlib[*row][a]=' ';
    		madlib[*row][a+1]='\0';
	}
    
	else{
    		madlib[*row][a]='\0';
	}
}
   

void getNoun(int *row, char words[][COL], char madlib[][COL]){
	//Function that is used when N is encountered in the prompt
	//Declaring string used for the user's word
	char noun[COL];
	int a=0;
	//Prompts the user to enter a word then grabs it and inserts it into the 2d array madlib
	printf("Enter a Noun: ");
    	scanf(" %s", noun);
    	for(int i=0;noun[i] != '\0';i++){
           	words[i][0] = noun[i];
           	madlib[*row][i]=words[i][0];
           	a++;
   	}
  	//If else statement used to get rid of spaces for visual clarity
   	if(madlib[*row+1][0] == '.' || madlib[*row+1][0] == ',' || madlib [*row+1][0] == '!'){
        	madlib[*row][a]='\0';
	}
	//Else if statement to end a line at the end of the string in the 2d array	
   	else if(madlib[*row][a+1] != '.' && madlib[*row][a+1] != ',' && madlib [*row][a+1] != '!'){
        	madlib[*row][a]=' ';
    		madlib[*row][a+1]='\0';
	}
    	
	else{
    		madlib[*row][a]='\0';
	}
}

void getVerb(int *row, char words[][COL], char madlib[][COL]){
	//Function that is used when V is encountered in the prompt
	//Declaring string used for the user's word
	char verb[COL];
    	int a=0;
    	//Prompts the user to enter a word then grabs it and inserts it into the 2d array madlib
	printf("Enter a Verb: ");
    	scanf(" %s", verb);
    	for(int i=0;verb[i] != '\0';i++){
           	words[i][0] = verb[i];
           	madlib[*row][i]=words[i][0];
           	a++;
   	}
  	//If else statement used to get rid of spaces for visual clarity  	 
  	if(madlib[*row+1][0] == '.' || madlib[*row+1][0] == ',' || madlib [*row+1][0] == '!'){
        	madlib[*row][a]='\0';
	}
	//Else if statement to end a line at the end of the string in the 2d array		
   	else if(madlib[*row][a+1] != '.' && madlib[*row][a+1] != ',' && madlib [*row][a+1] != '!'){
        	madlib[*row][a]=' ';
    		madlib[*row][a+1]='\0';
	}
    
	else{
    		madlib[*row][a]='\0';
	}
}


void changeline(char madlib[ROW][COL]){
	//Function which puts the different rows in the 2D array together for more visual clarity 
	for(int j = 0; j < ROW; j++){
    	for(int i=0; madlib[j][i] != '\0';i++){
               	if(madlib[j][i] == '\n'){
                   	madlib[j][i] = ' ';
               	}    
       	}
    	}
}

