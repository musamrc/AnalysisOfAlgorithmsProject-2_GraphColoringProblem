#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    FILE *input;
    input = fopen("test4.txt","r+");
    char firstLine[1];
	int intinput1,intinput2;

    //Reading input file and making Graph
    if (input == NULL) {
        printf("Input file name should be input.txt");
        return;
    }
	else {
		fscanf(input,"%s %d %d", &firstLine[0], &intinput1, &intinput2);
		//printf("%s %d %d\n",firstLine,intinput1,intinput2);
		char pORe[intinput2-2];
		char adjMatrix[intinput1][intinput1];
		int j=0;
		int colorGraph[intinput1];
		int size = intinput1;
	//Set all values 0 in the adjacency matrix
	for(i=0;i<=intinput1-1;i++){
		for(j=0;j<=intinput1-1;j++){
			adjMatrix[i][j] = 0;
		}
	}//End of setting 0

    //Designing the adjacency matrix
	    i=0;
		while (!feof(input)) {
			fscanf(input,"%s %d %d", &pORe[i], &intinput1, &intinput2);
			adjMatrix[intinput1-1][intinput2-1] = 1;													
			i++;
		}	

		fclose(input);

		//Putting color graph default value as 0
		
		for(i=0;i<size;i++){
			colorGraph[i] = 0;
		}
		
        int value;      
		//Putting color values starting from 1
		for(i=0;i<size;i++){	
		j=-1;
		value = 1;

	    while(j<size){
		j++;
		if(adjMatrix[i][j] == 1){	
			if(colorGraph[j] == value){
				value++;
				j = -1;
			}
		}
		}	
		colorGraph[i] = value;	
		}//End of putting color values.
		
		//Finding how many different color used
		int max = 0;
		for(i=0;i<size;i++){
			if(colorGraph[i] > max){
				max = colorGraph[i];
			}
		}
		
		//Printing colorGraph
		printf("%d\n",max);
		for(i=0;i<size;i++){
			printf("%d ",colorGraph[i]-1);
		}
    //End of designing the adjacency matrix

    FILE * fp;

    fp = fopen ("output.txt", "w+");
    fprintf(fp, "%d\n",max);
    	for(i=0;i<size;i++){
			fprintf(fp,"%d ",(colorGraph[i]-1));
		}
    fclose(fp);	
    
    //Print the adjacency matrix
	/*
	printf("\n");
	for(i=0;i<=intinput1-1;i++){
		for(j=0;j<=intinput1-1;j++){
			printf("%d-",adjMatrix[i][j]);
		}
		printf("\n");
	}
	*/
	//End of printing function
    //End of reading File and Creating Graph

    return 0;
}}
