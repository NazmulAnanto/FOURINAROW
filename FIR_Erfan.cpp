
#include"iGraphics.h"
#include"glut.h"
#include<stdio.h>

int turn = 0;
int index[6][7] = {0};
int index2[6][7]= {0};
int yStop[50] = {0};
int gameOver=0;
int x[50] = {0}, y[50] = {0};

int red=1,yellow=0;
int rx,ry=750;
int column;
int check(void);

void drawBall_01(int p, int q)
{
    iSetColor(255,0,0);
    iFilledCircle(p,q,45);
//    iSetColor(219,225,211);
//    iFilledCircle(p,q,4);
}

void drawBall_02(int p, int q)
{
    iSetColor(255,255,0);
    iFilledCircle(p,q,45);
}

void drawBoard(void)
{
    iSetColor(255,255,255);
    iRectangle(295,20,710,610);
    iRectangle(296,21,708,608);
    iRectangle(297,22,706,606);
//    iRectangle(298,23,704,604);

    for(int i=0;i<7;i++){
        for(int j=0;j<6;j++){
            iCircle(350+i*100, 75+j*100, 44);
            iCircle(350+i*100, 75+j*100, 45);
            iCircle(350+i*100, 75+j*100, 46);
//            iCircle(350+i*100, 75+j*100, 47);
        }
    }
}
void moveBalls(void)
{
    for(int i=0;i<turn;i++){
        if(y[i]>yStop[i]){
            y[i] = y[i]-20;
        }
    }
    if(y[turn-1]==yStop[turn-1]){
        if(gameOver==0) gameOver = check();
    }
}

int check(void)
{
    //vertical check
    for(int row=0;row<3;row++){
        for(int col=0;col<7;col++){
            if( (index[row][col] != 0) && (index[row][col] != 3) && (index[row][col] != 4) && (index [row][col] == index[row+1][col]) && (index [row][col] == index[row+2][col]) && (index [row][col] == index[row+3][col]) ){
                return index[row][col];
            }
        }
    }

    //horizontal check
    for(int col=0;col<4;col++){
        for(int row=0;row<6;row++){
            if( (index[row][col] != 0) && (index[row][col] != 3) && (index[row][col] != 4) && (index [row][col] == index[row][col+1]) && (index [row][col] == index[row][col+2]) && (index [row][col] == index[row][col+3]) ){
                return index[row][col];
            }
        }
    }

    //diagonal check
    for(int col=0;col<4;col++){
        //right and up
        for(int row=0;row<3;row++){
            if( (index[row][col] != 0) && (index[row][col] != 3) && (index[row][col] != 4) && (index [row][col] == index[row+1][col+1]) && (index [row][col] == index[row+2][col+2]) && (index [row][col] == index[row+3][col+3]) ){
                return index[row][col];
            }
        }
        //right and down
        for(int row=5;row>2;row--){
            if( (index[row][col] != 0) && (index[row][col] != 3) && (index[row][col] != 4) && (index [row][col] == index[row-1][col+1]) && (index [row][col] == index[row-2][col+2]) && (index [row][col] == index[row-3][col+3]) ){
                return index[row][col];
            }
        }
    }

    if(index[5][0] && index[5][1] && index[5][2] && index[5][3] && index[5][4] && index[5][5] && index[5][6] && !gameOver)
        return 3;

    return 0;
}
int check2(void)
{
    //vertical check
    for(int row=0;row<3;row++){
        for(int col=0;col<7;col++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row+1][col]) && (index2 [row][col] == index2[row+2][col]) && (index2 [row][col] == index2[row+3][col]) ){
                return index2[row][col];
            }
        }
    }

    //horizontal check
    for(int col=0;col<4;col++){
        for(int row=0;row<6;row++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row][col+1]) && (index2 [row][col] == index2[row][col+2]) && (index2 [row][col] == index2[row][col+3]) ){
                return index2[row][col];
            }
        }
    }

    //diagonal check
    for(int col=0;col<4;col++){
        //right and up
        for(int row=0;row<3;row++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row+1][col+1]) && (index2 [row][col] == index2[row+2][col+2]) && (index2 [row][col] == index2[row+3][col+3]) ){
                return index2[row][col];
            }
        }
        //right and down
        for(int row=5;row>2;row--){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row-1][col+1]) && (index2 [row][col] == index2[row-2][col+2]) && (index2 [row][col] == index2[row-3][col+3]) ){
                return index2[row][col];
            }
        }
    }

    if(index2[5][0] && index2[5][1] && index2[5][2] && index2[5][3] && index2[5][4] && index2[5][5] && index2[5][6] && !gameOver)
        return 3;

    return 0;
}

int check3(void)
{
    //vertical check
    for(int row=0;row<3;row++){
        for(int col=0;col<7;col++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row+1][col]) && (index2 [row][col] == index2[row+2][col]) ){
                return index2[row][col];
            }
        }
    }

    //horizontal check
    for(int col=0;col<4;col++){
        for(int row=0;row<6;row++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row][col+1]) && (index2 [row][col] == index2[row][col+2])){
                return index2[row][col];
            }
        }
    }

    //diagonal check
    for(int col=0;col<4;col++){
        //right and up
        for(int row=0;row<3;row++){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row+1][col+1]) && (index2 [row][col] == index2[row+2][col+2])){
                return index2[row][col];
            }
        }
        //right and down
        for(int row=5;row>2;row--){
            if( (index2[row][col] != 0) && (index2 [row][col] == index2[row-1][col+1]) && (index2 [row][col] == index2[row-2][col+2])){
                return index2[row][col];
            }
        }
    }

    if(index2[5][0] && index2[5][1] && index2[5][2] && index2[5][3] && index2[5][4] && index2[5][5] && index2[5][6] && !gameOver)
        return 3;

    return 0;
}


void iDraw(){
    iClear();
    for(int i=0; i<turn; i++){
            if(i%2==0)
                drawBall_01(x[i],y[i]);
            else
                drawBall_02(x[i],y[i]);
    }
    drawBoard();
}

void iKeyboard(unsigned char key){

}

void iSpecialKeyboard(unsigned char key){}

void AI(){
    int l=0,d=0;

    for(int i=0;i<7;i++){
            int k=0;
        for(int j=0;j<6;j++){
            if(index2[j][i]==0){
                index2[j][i]=2;
                int m=check2();
                if(m==2){index2[j][i]=0;column=i;k=1;l=1;/*printf("2\n");*/}
                index2[j][i]=0;
                break;
            }
        }
        if(k)break;
    }
    if(!l){
        for(int i=0;i<7;i++){
            int k=0;
            for(int j=0;j<6;j++){
                if(index2[j][i]==0){
                    index2[j][i]=1;
                    int m=check2();
                    if(m==1){index2[j][i]=0;column=i;k=1;d=1;/*printf("1\n");*/}
                    index2[j][i]=0;
                    break;
                }
            }
            if(k)break;
        }
    }

    if(!l && !d){
        l=0;d=0;
        //printf("rand\n");
    again:
        for(int i=0;i<7;i++){
                int k=0;
            for(int j=0;j<6;j++){
                if(index2[j][i]==0){
                    index2[j][i]=1;
                    int m=check3();
                    if(m==1){index2[j][i]=0;column=i;k=1;l=1;/*printf("2\n");*/}
                    index2[j][i]=0;
                    break;
                }
            }
            if(k)break;
        }
        if(!l){
            for(int i=0;i<7;i++){
                int k=0;
                for(int j=0;j<6;j++){
                    if(index2[j][i]==0){
                        index2[j][i]=2;
                        int m=check3();
                        if(m==2){index2[j][i]=0;column=i;k=1;d=1;/*printf("1\n");*/}
                        index2[j][i]=0;
                        break;
                    }
                }
                if(k)break;
            }
        }
//         if(!l2 && !d2){
//        //printf("rand\n");
//        again:
//        column=(rand()%(rand()%100+rand()%150+rand()%300))%6;
        int row;
        for(int i=0;i<6;i++){
            //printf("%d ",i);
            if(index2[i][column]==0){
                row=i;
                //printf("\n");
                break;
            }
        }
        if(row==6)goto again;
        index2[row][column]=2;
        index2[row+1][column]=1;
        int m=check2();
        index2[row][column]=2;
        index2[row+1][column]=0;
        if(m==1)goto again;
    }
//    for(int i=5;i>=0;i--){
//        for(int j=6;j>=0;j--){
//            printf("%d ",index[i][j]);
//        }
//        printf("\n");
//    }
    x[turn]=350+column*100;
    y[turn]=675;

    for(int i=5; i>=0; i--){
        if( index[i][column] ){
            yStop[turn] = 75+100*(i+1);
            index[i+1][column] = 2;
            break;
        }
        if(i==0 && index[i][column]==0){
            yStop[turn] = 75;
            index[i][column] = 2;
            break;
        }
    }
    turn++;
}

void iMouse(int button, int state, int mx,int my){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !gameOver && y[turn-1]==yStop[turn-1]){

//	        itoa(mx,str,10);
//	        itoa(my,str2,10);

            if(295<mx && mx<400 && index[5][0]==0){
                column=0;
            }
            else if(400<mx && mx<500 && index[5][1]==0){
                column=1;
            }
            else if(500<mx && mx<600 && index[5][2]==0){
                column=2;
            }
            else if(600<mx && mx<700 && index[5][3]==0){
                column=3;
            }
            else if(700<mx && mx<800 && index[5][4]==0){
                column=4;
            }
            else if(800<mx && mx<900 && index[5][5]==0){
                column=5;
            }
            else if(900<mx && mx<1005 && index[5][6]==0){
                column=6;
            }

            if(mx>295 && mx<1005 && index[5][column]==0){
                x[turn]=350+column*100;
                y[turn]=675;

                for(int i=5; i>=0; i--){
                    if( index[i][column] ){
                        yStop[turn] = 75+100*(i+1);
                        if(turn%2==0)
                            index[i+1][column] = 1;
                        else
                            index[i+1][column] = 2;
                        break;
                    }
                    if(i==0 && index[i][column]==0){
                        yStop[turn] = 75;
                        if(turn%2==0)
                            index[i][column] = 1;
                        else
                            index[i][column] = 2;
                        break;
                    }
                }
                turn++;
                if(check()!=1){

                for(int i=5;i>=0;i--){
                    for(int j=6;j>=0;j--){
                        index2[i][j]=index[i][j];
                        //printf("%d ",index[i][j]);
                    }
                    //printf("\n");
                }
                if(turn%2!=0)AI();
                }
            }
        }
}

void iMouseMove(int mx,int my){
        if(mx>295 && mx<400)
            column = 0;
        else if(mx>400 && mx<500)
            column = 1;
        else if(mx>500 && mx<600)
            column = 2;
        else if(mx>600 && mx<700)
            column = 3;
        else if(mx>700 && mx<800)
            column = 4;
        else if(mx>800 && mx<900)
            column = 5;
        else if(mx>900 && mx<1000)
            column = 6;
}

int main(){
    iSetTimer(1, moveBalls);
    iInitialize(1366,768,"4 in a Row");
}
