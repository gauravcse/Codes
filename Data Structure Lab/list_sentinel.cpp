#include<stdio.h>
#include<limits.h>
#define MAX_SIZE 100
int check_empty(int *list){
	if (list[0]==INT_MAX)
		return 1;
	else return 0;	
}
int length(int *list){
	int i=0;
	while (list[i]!=INT_MAX)
		i++;
	return i;	
}
void insert(int *list,int i,int data){
	int j;
	if (i>length(list) || i<0)
		fprintf(stderr,"Index out of range");
	j=length(list)+1;
	while (j>i){
		list[j]=list[j-1];
		j--;
	}
	list[i]=data;
	
}
void del(int *list,int i){
	if (i>=length(list)-1 || i<0)
		fprintf(stderr,"Index out of range");
	while (i<=length(list)){
		list[i]=list[i+1];
		i++;
	}
	
}
int search(int *list,int key){
	int i=0,found=0;
	while (i<length(list)){
		if (list[i]==key){
			found=1;
			break;
		}
	}
	if (found)
		return i;
	else return (-1);
}
int read(int *list,int n){
	if (n<0 || n>length(list)-1)
		fprintf(stderr,"index out of range");
	return list[n];
}
int write(int *list,int n,int data){
	if (n<0 || n>length(list)-1)
		fprintf(stderr,"index out of range");
	list[n]=data;
}

void sort(int *list){
	int len=length(list);
	int i,j,t;
	for (i=1;i<len;i++){
		t=list[i];
		j=i-1;
		while (j>=0 && t<list[j]){
			list[j+1]=list[j];
			j--;
		}
		list[j+1]=t;
	}
	
}
main(){
	int list1[MAX_SIZE];
	int choice,data,pos,key;
	list1[0]=INT_MAX;

	printf("1.Check the list is empty or not\n");
	printf("2.Length of the list\n");
	printf("3.Insert an elemet to the list\n");
	printf("4.Delete an element from the list\n");
	printf("5.Search an element\n");
	printf("6.Read an element\n");
	printf("7.Write an element\n");
	printf("8.Sort the list\n\n");
	
	
	while (1){
		printf("Enter your choice or -1 to exit\n");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:
				if (check_empty(list1)==1)
					printf ("The list is empty\n");
				else printf ("The list is not empty\n");
				break;
			case 2:
				printf("Length of the list is %d\n",length(list1));
				break;
			case 3:
				printf("Enter the element you want to enter: ");
				scanf("%d",&data);
				printf("Enter the position at which you want to insert: ");
				scanf("%d",&pos);
				insert(list1,pos,data);
				break;
			case 4:
				printf("Enter the position from which you want to delete: ");
				scanf("%d",&pos);
				del(list1,pos);
				break;
			case 5:
				printf("Enter the key you want to search: ");
				scanf("%d",&key);
				if (search(list1,key)>=0)
					printf("Data found at %d position\n",search(list1,key));
				else printf ("data not found!\n");
				break;
			case 6:
				printf("Enter the position you want to retrieve: ");
				scanf("%d",&pos);
				printf("Data at that position is %d\n",read(list1,pos));
				break;
			case 7:
				printf("Enter the data you want to write: ");
				scanf("%d",&data);
				printf("Enter the position where you want to write the data: ");
				scanf("%d",&pos);
				write(list1,pos,data);	
				break;
			case 8:
				sort(list1);
				break;	
			case -1:
				return 0;
		}
			
	}
	
}

