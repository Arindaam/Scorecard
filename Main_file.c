#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "uthash.h"

typedef struct my_struct {
    int balls;
	int wickets;
	int run;
	char nam[30];
	UT_hash_handle hh;/* makes this structure hashable */
}bowler;

typedef struct node{
	struct node* plink;
	char name[30];
	int runs;
	int out;
	struct node* nlink;
}batsmen;
	
	
typedef struct bat_team{
	//int extras;
	int total;
	int twickets;
	batsmen* link;
	batsmen* str;
	batsmen* non_str;
}team;

int target;

void create_node(team* team_a){
	batsmen* plyr=(batsmen*)malloc(sizeof(batsmen));	
	scanf("%s",plyr->name);
	plyr->runs=0;
	plyr->nlink=NULL;
	plyr->out=0;
	if(team_a->link==NULL){
		plyr->plink=NULL;
		team_a->link=plyr;
	}
	else{
		batsmen* curr=team_a->link;
		while(curr->nlink!=NULL){
			curr=curr->nlink;
		}
		plyr->plink=curr;
		curr->nlink=plyr;
	}
}
			
float res(FILE* fp,int wickets){
	char ch[200]; 
	fgets(ch, 200,fp);
	if(wickets>=0 && wickets<10){		
		int c=0;
		char* ress;
		strtok(ch,",");
		while(c<wickets+1){
			ress=strtok(NULL,",");
			c++;
		}		
		return(target*(1-atof(ress)));
	}
	else{
		printf("INVALID");
		return;
	}
}	

bowler *users = NULL;

void create(){
    	bowler* bowl=(bowler*)malloc(sizeof(bowler));
    	scanf("%s",bowl->nam);
    	bowl->balls=0;
    	bowl->wickets=0;
	bowl->run=0;
    	HASH_ADD_INT( users, nam, bowl);
}

int main(){
	team* team_a=(team*)malloc(sizeof(team));
	team_a->link=NULL;
	team_a->total=team_a->twickets=0;
	team_a->str=team_a->non_str=0;
	printf("Enter the players in order: \n");
	for(int i=0; i<3;i++){
		printf("Enter Batsman Name %d: \n",i+1);			
		create_node(team_a);
	}

	FILE *fp = fopen("DLS.csv","r");
	char ch[100];
	int n;
	fgets(ch, 100,fp);
	fgets(ch, 100,fp);
	printf("Enter score of team 1: \n");	
	scanf("%d",&target);
	while(1){
		printf("Enter the no. of bowlers \n");
		scanf("%d",&n);
		if(n<11){
			break;
		}
		else{
			printf("INVALID \n");
		}
	}
 	for(int i=1;i<=n;i++){
        	printf("Enter Bowler %d: \n",i);
        	create();
	}
	printf("Start of Innings \n" );
	team_a->str=team_a->link;
	team_a->non_str=team_a->str->nlink;
	char bname[30];
	bowler* bvalues;
	int rain;
	int wicket,bruns;
	float dls_score=0;
	for(int j=1;j<51;j++){
		while(1){
			printf("Enter the bowler : ");
			scanf("%s",bname);
			HASH_FIND_INT(users, &bname, bvalues);
			if(bvalues!=NULL && bvalues->nam==bname){
				if(bvalues->balls<60){
					break;
				}
			}
			else{
				printf("INVALID \n");
			}
    		}
		for(int m=1;m<7;m++){
			while(1){
				printf("Enter 1 if its raining : ");
				scanf("%d",&rain);
				if(rain==1){
					break;
				}
				printf("Enter 1 if it is out : ");
				scanf("%d",&wicket);
				if(wicket==1){
					team_a->str->out = 1;
					batsmen* temp = team_a->link;
					while(temp->out==1){
						temp=temp->nlink;
					}
					temp = team_a->non_str->nlink;
					while(temp->out==1){
						temp=temp->nlink;
					}
					team_a->str = temp;
					bvalues->balls++;
					bvalues->wickets++;
					team_a->twickets++;
					break;
				}
				printf("Enter the number of runs : ");
				scanf("%d",&bruns);
				if(bruns>=0 && bruns<7){
					team_a->total = team_a->total + bruns;
					if(bruns%2==1){
						batsmen* btemp;
						btemp=team_a->str;
						team_a->str=team_a->non_str;
						team_a->non_str=btemp;
					}
					bvalues->balls++;
					bvalues->run=bvalues->run+bruns;
					team_a->str->runs=team_a->str->runs+bruns;
					break;
				}
				else{
					printf("INVALID");
				}
			}
			if(team_a->twickets==10 || team_a->total>=target || rain==1){
				break;
			}
		}
		if(rain==1){
			if(team_a->total>dls_score){
				printf("Batting team wins by %d wickets /n",10-team_a->twickets);
				break;
			}
           		 else{
                		printf("Bowling team won by %f runs /n",dls_score-team_a->total);
				break;
            		}
        	}    
		else if(team_a->twickets==10){
			printf("Bowling team wins by %d runs",target-team_a->total);
			break;
		}
		else if(team_a->total>=target){
        	    	printf("Batting team wins by %d wickets",10-team_a->twickets);
			break;
		}
       		else {
            		dls_score=res(fp,team_a->twickets);
            		printf("%f is the dl par score /n",dls_score);
            		printf("Batting team score is %d for the loss of %d wickets /n",team_a->total,team_a->twickets);
            		printf("Required runs is %d /n",target-team_a->total);
        	}
	}
}
















