#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char userSentence[201]; // Maximum 200 symbols plus a null terminator
    char word[201];    // Same size as the sentence buffer

    // Step 1: Prompt the user to enter a sentence
    printf("Please Enter Your Sentence: ");
    fgets(userSentence, sizeof(userSentence), stdin);

    // Step 2: Split the sentence into words and display them

    int i, j = 0;
    for (i = 0; i <= strlen(userSentence); i++) {
	    // if any of the below found , null-terinate the word
        if (userSentence[i] == ' ' || userSentence[i] == '\0' || userSentence[i] == '\n') {
            word[j] = '\0'; // Null-terminate the word
            if (j > 0) {
                printf("%s\n", word);
                // Write the word to a file
                FILE *file = fopen("Output.txt", "a");
                if (file != NULL) {
                    fprintf(file, "%s\n", word);
                    fclose(file);
                } else {
                    printf("Error writing to the file.\n");
                }
            }
            j = 0; // Reset word buffer index
        } else {
            word[j++] = userSentence[i];
        }
    }
    return 0;
}

































// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc , char* argv[]){

// // array to store string taken as input
//  char sentence[201]; // 1 extra character for null terminating character /n"
//  printf("Please Enter Your Sentence : ");
 
//  fgets(sentence , sizeof(sentence), stdin);
//  const char d[2]= " ";
//  // Spliting the sentence into multiple words.
//  char *words[201];
//  int numOfWords = 0;
//  //sentence[strcspn(sentence, " \t\n")] = '\0';
 
//  char *word = strtok(sentence, d);
 
//   while (word != NULL) {
//    	printf( "%s\n",word);
//    	word = strtok(NULL, d);
// 	numOfWords++;
	
//   }
// //   word = strtok(NULL, "\0");
// //  // Display the words on the screen.
// //  for (int i =0 ; i< numOfWords; i++) {
// // 	printf("%s\n" , words[i]);
// //  }
//  // Place the words in a new file.

//  FILE *filePointer = fopen("Output.txt" , "w");
//  if(filePointer == NULL) {
// 	printf("Error opening fie.\n");
// 	exit(1);
//  }
//  for(int i =0 ; i < numOfWords; i++){
// 	fprintf(filePointer, "%s\n" , word[i]);
//  }
//  fclose(filePointer);

//  return 0;
	
// }

