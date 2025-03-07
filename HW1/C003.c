#include <stdio.h>
#include <stdlib.h>

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);
int findRoom(int persons[5]);

int main(){
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");

    int cmd;
    char name[20] = {0};
    int room;

    char m_name[10][20];
    int m_room[10] = {0};
    int mr_status[5] = {0};
    int m_count = 0;

    char w_name[10][20];
    int w_room[10] = {0};
    int wr_status[5] = {0};
    int w_count = 0;

    while(1){
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &cmd);
        if(cmd == 1){
            if(m_count >= 10){
                printf("남학생 호실이 가득 찼습니다.\n");
            }
            else{
                printf("학생 이름은? > ");
                scanf("%s", m_name[m_count]);
                room = findRoom(mr_status);
                m_room[m_count] = 101+room;
                printf("%s 학생 %d호실 배정되었습니다.\n", m_name[m_count], m_room[m_count]);
                m_count ++;
            }
        }
        else if(cmd == 2){
            if(w_count >= 10){
                printf("여학생 호실이 가득 찼습니다.\n");
            }
            else{
                printf("학생 이름은? > ");
                scanf("%s", w_name[w_count]);
                room = findRoom(wr_status);
                w_room[w_count] = 201+room;
                printf("%s 학생 %d호실 배정되었습니다.\n", w_name[w_count], w_room[w_count]);
                w_count ++;
            }
        }
        else if(cmd == 0){
            printReport(m_name, m_room, m_count, w_name, w_room, w_count);
            break;
        }
        else{
            printf("잘못된 명령어 입니다.\n");
        }
    }
}

int findRoom(int persons[5]){
    int random;
    while(1){
        random = rand()%5;
        if(persons[random] != 2){
            persons[random] += 1;
            break;
        }
    }
    return random;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    
    printf("남학생 명단 (%d명)\n", mc);
    for(int i=0; i<mc; i++){
        printf("%d. %s [%d호]\n", i+1, mn[i], mr[i]);
    }
    printf("\n");
    
    printf("여학생 명단 (%d명)\n", wc);
    for(int i=0; i<wc; i++){
        printf("%d. %s [%d호]\n", i+1, wn[i], wr[i]);
    }
    printf("\n");

    printf("호실별 배정 명단\n");
    for(int i=101; i<=105; i++){
        printf("%d호 : ", i);
        for(int j=0; j<mc; j++){
            if(mr[j] == i){
                printf("%s ", mn[j]);
            }
        }
        printf("\n"); 
    }
    for(int i=201; i<=205; i++){
        printf("%d호 : ", i);
        for(int j=0; j<wc; j++){
            if(wr[j] == i){
                printf("%s ", wn[j]);
            }
        }
        printf("\n");
    }
}
