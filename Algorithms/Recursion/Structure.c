#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player{
    char Player_Name[20];
    char Player_Team[15];
    int Player_runs_in_3_matches[3];
    int Player_wickets_in_3_matches[3];
    int Player_points_in_3_matches[3];
    int Total_Points;
};


int main(){
    struct Player teamBangladesh[2];
    int i,j,k;
    for(i=0; i<2; i++){
        
        printf("Name : ");
        fflush(stdin);
        gets(teamBangladesh[i].Player_Name);
        fflush(stdout);
        printf("\n");
        printf("Country : ");
        fflush(stdin);
        gets(teamBangladesh[i].Player_Team);
        fflush(stdout);
        printf("\n");
        printf("Runs in 3 matches : ");
        for(j=0; j<3; j++){
            scanf("%d", &teamBangladesh[i].Player_runs_in_3_matches[j]);
        }
        printf("\n");
        printf("Wickets in 3 matches : ");
        for(k=0; k<3 ; k++){
            scanf("%d", &teamBangladesh[i].Player_wickets_in_3_matches[k]);
        }
        printf("\n");
    }
    int totalRuns=0, totalWickets=0, MOTM=0;

    printf("Player points : \n");
    for(i=0 ; i<2; i++){
        printf("%s : ", teamBangladesh[i].Player_Name);
        for(j=0 , k=0; j<3, k<3 ; j++, k++){
            if(teamBangladesh[i].Player_runs_in_3_matches[j] >= 100){
                totalRuns = totalRuns + 20;
            }else if(teamBangladesh[i].Player_runs_in_3_matches[j] >= 75 && teamBangladesh[i].Player_runs_in_3_matches[j] <=100){
                totalRuns = totalRuns + 15;
            }else if(teamBangladesh[i].Player_runs_in_3_matches[j] >= 50 && teamBangladesh[i].Player_runs_in_3_matches[j] <=75){
                totalRuns = totalRuns + 10;
            }else if(teamBangladesh[i].Player_runs_in_3_matches[j] >= 25 && teamBangladesh[i].Player_runs_in_3_matches[j] <=50){
                totalRuns = totalRuns + 5;
            }
            
            totalWickets = totalWickets + (teamBangladesh[i].Player_wickets_in_3_matches[k] * 12);
        }
        teamBangladesh[i].Total_Points = (totalRuns + totalWickets);
    }

    int MOTS = teamBangladesh[0].Total_Points;
    for(i=0;i<2;i++){
        if(MOTS > teamBangladesh[i].Total_Points){
            MOTS = teamBangladesh[i].Total_Points;
        }
    }

}