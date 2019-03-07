#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define row 20
#define col 20

struct queue{
    int x,y;
}que[1000];


int brow = 0, bcol = 0,front = -1,rear = -1,life = 3,score = 0,rear2 = -1,level = 1;
struct queue track[500];

void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void print(char frontend[row][col]){
    int i,j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%c",frontend[i][j]);
        }
        printf("\n");
    }
    printf("\n\nLIFE : %d     SCORE : %d\n\n",life,score);
    printf("\n    LEVEL : %d  \n",level);
}

struct queue deque(){
    front++;
    return que[front-1];
}

void queuefill(char backend[row][col]){
    struct queue temp;
    int i = 0;
    if(front == -1){
        front = 0;
    }
    rear++;
    que[rear].x = 0;
    que[rear].y = 0;
    backend[que[rear].x][que[rear].y] = '*';
    while((front != -1)&&(front <= rear)){
        temp = deque();
        if((temp.x == row-1)&&(temp.y == col-1)){
            break;
        }
        if((backend[temp.x+1][temp.y] == ' ')&&((temp.x+1 > -1)&&(temp.x+1 < row))&&((temp.y > -1)&&(temp.y < col))){
            rear++;
            que[rear].x = temp.x+1;
            que[rear].y = temp.y;
            backend[que[rear].x][que[rear].y] = '*';
        }
        if((backend[temp.x-1][temp.y] == ' ')&&((temp.x-1 > -1)&&(temp.x-1 < row))&&((temp.y > -1)&&(temp.y < col))){
            rear++;
            que[rear].x = temp.x-1;
            que[rear].y = temp.y;
            backend[que[rear].x][que[rear].y] = '*';
        }
        if((backend[temp.x][temp.y+1] == ' ')&&((temp.x > -1)&&(temp.x < row))&&((temp.y+1 > -1)&&(temp.y+1 < col))){
            rear++;
            que[rear].x = temp.x;
            que[rear].y = temp.y+1;
            backend[que[rear].x][que[rear].y] = '*';
        }
        if((backend[temp.x][temp.y-1] == ' ')&&((temp.x > -1)&&(temp.x < row))&&((temp.y-1 > -1)&&(temp.y-1 < col))){
            rear++;
            que[rear].x = temp.x;
            que[rear].y = temp.y-1;
            backend[que[rear].x][que[rear].y] = '*';
        }
    }
}

void up(char frontend[row][col],char backend[row][col]){
    int i;
    if(backend[brow - 1][bcol] == '*'){
        brow = brow - 1;
        rear2++;
        track[rear2].x = brow;
        track[rear2].y = bcol;
        score++;
        frontend[brow][bcol] = '*';
    }
    else{
        system("cls");
        score = 0;
        for(i = rear2; i > rear2-5; i--){
            if(i < 0){
                break;
            }
            frontend[track[i].x][track[i].y] = ' ';
        }
        if(i < 0){
            i = 0;
        }
        rear2 = i;
        brow = track[i].x;
        bcol = track[i].y;
        frontend[brow][bcol] = '*';
        life--;
    }
}

void down(char frontend[row][col],char backend[row][col]){
    int i;
    if(backend[brow + 1][bcol] == '*'){
        brow = brow + 1;
        rear2++;
        track[rear2].x = brow;
        track[rear2].y = bcol;
        score++;
        frontend[brow][bcol] = '*';
    }
    else{
        system("cls");
        score = 0;
        for(i = rear2; i > rear2-5; i--){
            if(i < 0){
                break;
            }
            frontend[track[i].x][track[i].y] = ' ';
        }
        if(i < 0){
            i = 0;
        }
        rear2 = i;
        brow = track[i].x;
        bcol = track[i].y;
        frontend[brow][bcol] = '*';
        life--;
    }
}

void left(char frontend[row][col],char backend[row][col]){
    int i;
    if(backend[brow][bcol-1] == '*'){
        bcol = bcol - 1;
        rear2++;
        track[rear2].x = brow;
        track[rear2].y = bcol;
        score++;
        frontend[brow][bcol] = '*';
    }
    else{
        system("cls");
        score = 0;
        for(i = rear2; i > rear2-5; i--){
            if(i < 0){
                break;
            }
            frontend[track[i].x][track[i].y] = ' ';
        }
        if(i < 0){
            i = 0;
        }
        rear2 = i;
        brow = track[i].x;
        bcol = track[i].y;
        frontend[brow][bcol] = '*';
        life--;
    }
}

void right(char frontend[row][col],char backend[row][col]){
    int i;
    if(backend[brow][bcol+1] == '*'){
        bcol = bcol + 1;
        rear2++;
        track[rear2].x = brow;
        track[rear2].y = bcol;
        score++;
        frontend[brow][bcol] = '*';
    }
    else{
        system("cls");
        score = 0;
        for(i = rear2; i > rear2-5; i--){
            if(i < 0){
                break;
            }
            frontend[track[i].x][track[i].y] = ' ';
        }
        if(i < 0){
            i = 0;
        }
        rear2 = i;
        brow = track[i].x;
        bcol = track[i].y;
        frontend[brow][bcol] = '*';
        life--;
    }
}
int main(){

for(level = 1; level <=2; level++){
system("cls");
char backend[row][col] =  {' ',' ',220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
                         219,' ',219,' ',' ',219,' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,
                         219,' ',219,' ',' ',219,' ',' ',' ',' ',' ',' ',220,220,220,' ',' ',' ',' ',219,
                         219,' ',219,220,220,219,220,220,220,220,220,' ',219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',219,' ',' ',' ',219,' ',219,' ',219,' ',219,' ',' ',219,
                         219,' ',' ',220,220,220,219,220,220,220,219,' ',219,' ',219,' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,220,220,220,220,220,220,219,
                         219,' ',' ',' ',' ',' ',' ',220,220,220,219,' ',219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',219,' ',' ',220,220,219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219,
                         219,220,219,219,220,220,220,220,220,220,220,220,220,220,219,' ',219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',219,' ',' ',' ',' ',219,220,220,220,219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',219,' ',' ',' ',' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',219,220,220,220,219,220,220,219,' ',219,' ',' ',' ',219,220,220,219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',220,220,220,220,219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,
                         219,220,220,220,220,220,220,220,220,220,219,220,219,220,220,220,220,219,' ',' '};

char frontend[row][col] =  {' ',' ',220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
                         219,' ',219,' ',' ',219,' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,
                         219,' ',219,' ',' ',219,' ',' ',' ',' ',' ',' ',220,220,220,' ',' ',' ',' ',219,
                         219,' ',219,220,220,219,220,220,220,220,220,' ',219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',219,' ',' ',' ',219,' ',219,' ',219,' ',219,' ',' ',219,
                         219,' ',' ',220,220,220,219,220,220,220,219,' ',219,' ',219,' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,220,220,220,220,220,220,219,
                         219,' ',' ',' ',' ',' ',' ',220,220,220,219,' ',219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',219,' ',' ',220,220,219,' ',' ',' ',' ',' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219,
                         219,220,219,219,220,220,220,220,220,220,220,220,220,220,219,' ',219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',219,' ',' ',' ',' ',219,220,220,220,219,' ',' ',219,
                         219,' ',' ',219,' ',' ',' ',219,' ',' ',' ',' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',219,220,220,220,219,220,220,219,' ',219,' ',' ',' ',219,220,220,219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',220,220,220,220,219,' ',' ',219,
                         219,' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,
                         219,220,220,220,220,220,220,220,220,220,219,220,219,220,220,220,220,219,' ',' '};

char input;
    queuefill(backend);
    frontend[brow][bcol] = '*';
    rear2++;
    track[rear2].x = brow;
    track[rear2].y = bcol;
    print(frontend);
    while(1){
    input = getch();
    if(input == 'w'){
        up(frontend,backend);
    }
    else if(input == 's'){
        down(frontend,backend);
    }
    else if(input == 'a'){
        left(frontend,backend);
    }
    else if(input == 'd'){
        right(frontend,backend);
    }
    if(life != 0){
    clearscreen();
    print(frontend);
    if((brow == row-1)&&(bcol == col-1)){
        system("cls");
        if(level == 1){
        printf("\n\nLIFE : %d     SCORE : %d\n\n",life,score);
        printf("\n\nCONGRATULATIONS YOU ARE LEVEL UP!\n\n");
        printf("\n\nPress any key to continue\n\n");
        getch();
        }
        else{
        printf("\n\nLIFE : %d     SCORE : %d\n\n",life,score);
        printf("\n\nCONGRATULATIONS YOU WIN!\n\n");
        }
        break;
    }
    }
    else{
        system("cls");
        printf("\n\nLIFE : %d     SCORE : %d\n\n",life,score);
        printf("\n\nGAME OVER!\n\n");
        exit(1);
        }
    }
    brow = 0;
    bcol = 0;
    front = -1;
    rear = -1;
    life = 3;
    rear2 = -1;
}
    return 0;
}
