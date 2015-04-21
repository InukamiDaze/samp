#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define max 10


void *half1(void *arg);
void *half2(void *arg2);
void *all(void *arg3);

main(){
	pthread_t t1, t2, t3;
	
	int loopctr;
	
	int *arr = (int*) malloc((max)*sizeof(int));
	
	//accept user inputs and store to initial array
	for(loopctr=0; loopctr < max; loopctr++){
		printf("Enter number: ");
		scanf("%d", &arr[loopctr]);
	}
	
	pthread_create(&t1, NULL, half1, (void *)arr);
	pthread_create(&t2, NULL, half2, (void *)arr);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	
	pthread_create(&t3, NULL, all, (void *)arr);
	pthread_join(t3, NULL);
	
	printf("Sorted: ");
	for(loopctr=0; loopctr < max; loopctr++){
		printf("%d ", arr[loopctr]);
	}
	printf("\n");
	
	free(arr);
	pthread_exit(NULL);
}
// sort elements 0-4
void *half1(void *arg){
	int i, j, temp;
	int *array = (int *)arg;
	
	for(i=0; i < max/2; i++){
		for(j=i+1; j < max/2; j++){
			if(array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	pthread_exit(NULL);
}

//sort elements 5-9
void *half2(void *arg2){
	int i, j, temp;
	int *array = (int *)arg2;
	
	for(i=max/2; i < max; i++){
		for(j=i+1; j < max; j++){
			if(array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	pthread_exit(NULL);
}

//sort all elements
void *all(void *arg3){
	int i, j, temp;
	int *array = (int *)arg3;
	
	for(i=0; i < max; i++){
		for(j=i+1; j < max; j++){
			if(array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	pthread_exit(NULL);
}


