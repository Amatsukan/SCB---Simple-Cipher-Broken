#include "afim_braker.c"

char * temp;

void subs(char a, char b){
	for (int i = 0; i < strlen(text); ++i)
	{
		if(text[i] == a){
			temp[i] = b;
		}
	}
}

int main(){
	// go();
	const char * BUFF = "emglosudcgdncuswysfhnsfcykdpumlwgyicoxysipjck";
    textSize = strlen(BUFF);
    text =(char *) calloc(textSize, sizeof(char));
    strcpy(text, BUFF);
    temp = (char *) calloc(textSize, sizeof(char));
    strcpy(temp, BUFF);
    subs('f', 'w');
    subs('c', 'e');
    subs('g', 't');
    printf("%s\n", temp);

 }