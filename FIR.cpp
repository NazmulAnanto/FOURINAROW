#include "iGraphics.h"
#include "gl.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "ctype.h"

#define BLOCKS 4
#define PLAYED 8
#define FREEZE 2

int x[50] = {0}, y[50] = {0};
int turn = 0;
int index[6][7] = {0};
int yStop[50] = {0};
int column = 3;
//int rgb[500000][3] = {0};
int mode = 0;
int blockX[BLOCKS];
int blockY[BLOCKS];
int waterLevel = 0;
int waterRising = 0;
int freezeX[FREEZE];
int freezeY[FREEZE];
int ballsFreezing = 0;

int gameOver = 0;
int saveFile = 0;
int saveFileKey = 0;
int playerNameInput = 0, len = 7;
char player01[10] = "Player1";
char player02[10] = "Player2";
int cursor = 0;

int menu = 1;
int play = 0;
int settings = 0;
int showHighScore = 0;
int rules = 0;
int credit = 0;
int music = 1;

int menuKey = 0;
int rulesY = 620;
int highScoreSlide = 0;
double pic = 0, d=0 , pic2=0,aqua=0, snow=0 , forest=0, old=0, over=0,water=0, menuanime=0,menuslide=0;
float timer = 0.00;
char showTimer[20] = "0.00 seconds";

//char str[200]="", str2[200]="";

typedef struct {
    char name[10]="";
    int moves=0;
    float winningTime=0.00;
} _highScore;
_highScore highScore[3][5], current, tempScore;


#include"mainmenu.h"
#include"sound.h"

int check(void);
void updateHighScore(void);

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

void iMouse(int button, int state, int mx, int my)
{
    if(menu){
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

            //NEW GAME
            if(mx>50 && mx<295 && my>530 && my<580){
                menuKey = 0;
                playerNameInput=1;
                strcpy(player01,"Player1");
                strcpy(player02,"Player2");

            }

            //CONTINUE GAME
            else if(mx>50 && mx<295 && my>450 && my<500){
                menuKey = 1;
                menu=0;
                play=1;
                gamesound();
                iResumeTimer(0);
                iResumeTimer(1);
                gameOver=0;


                FILE* fp2;
                if(mode==0||mode==3||mode==4){
                    fp2 = fopen("SavedGame1.txt","r");
                }
                else if(mode==1){
                    fp2 = fopen("SavedGame2.txt","r");
                }
                else if(mode==2){
                    fp2 = fopen("SavedGame3.txt","r");
                }

                for(int i=5;i>=0;i--){                              //Loading the INDEX
                    for(int j=0;j<7;j++){
                        fscanf(fp2,"%d",&index[i][j]);
                    }
                }
                fscanf(fp2,"%f",&timer);                           //Loading the TIME and TURN
                fscanf(fp2,"%d",&turn);
                fscanf(fp2,"%s",player01);
                fscanf(fp2,"%s",player02);

                for(int i=0;i<turn;i++){
                    fscanf(fp2,"%d %d %d",&x[i],&y[i],&yStop[i]);   //Loading x, y & yStop
                }
                if(mode==1){
                    fscanf(fp2,"%d",&waterLevel);
                }
                if(mode==2){
                    for(int i=0;i<BLOCKS;i++){
                        fscanf(fp2,"%d %d",&blockX[i],&blockY[i]);
                    }
                }

                fclose(fp2);
            }

            //SETTINGS
            else if(mx>50 && mx<295 && my>370 && my<420){
                menuKey = 2;
                settings=1;
                menu=0;
            }

            //RULES
            else if(mx>50 && mx<295 && my>290 && my<340){
                menuKey = 3;
                rules = 1;
                menu = 0;
                settings=0;
            }

            //HALL OF FAME
            else if(mx>50 && mx<295 && my>210 && my<260){
                menuKey = 4;
                showHighScore = 1;
                menu = 0;
            }

            //ABOUT
            else if(mx>50 && mx<295 && my>130 && my<180){
                menuKey = 5;
                credit = 1;
                menu = 0;
            }
            //EXIT
            else if(mx>50 && mx<295 && my>50 && my<100){
                menuKey = 6;
                exit(0);
            }
        }
    }

    //select mode
    else if(settings){
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
            //going back to main menu
            if(mx>550 && mx<850 && my>50 && my<100){
                settings=0;
                menu=1;
            }
            //Music ON/OFF
            else if(mx>1020 && mx<1200 && my>550 && my<600){
                music = (music+1)%2;
                gamesound();
                menumusic();
            }
            //selecting different modes
            else if(mx>800 && mx<1150 && my>420 && my<470){
                mode=0;
                settings=0;
                menu=1;
            }
            else if(mx>800 && mx<1150 && my>340 && my<390){
                mode=1;
                settings=0;
                menu=1;
            }
            else if(mx>800 && mx<1150 && my>260 && my<310){
                    mode=2;
                    settings=0;
                    menu=1;
            }
            else if(mx>800 && mx<1150 && my>180 && my<230){
                    mode=3;
                    settings=0;
                    menu=1;
            }
            else if(mx>800 && mx<1150 && my>100 && my<150){

                    mode=4;
                    settings=0;
                    menu=1;
            }
        }
    }

    else if (play){
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !gameOver && !saveFile && y[turn-1]==yStop[turn-1] && !ballsFreezing){

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

                if(turn>0 && turn%5==0 && !gameOver && !saveFile){
                    ballsFreezing = 1;
                    for(int i=0;i<FREEZE;i++){                     //n for row, m for column
                        int n = rand()%3;
                        int m = rand()%7;
                        index[n][m] = 0;
                        freezeX[i] = 350+m*100;
                        freezeY[i] = 75+n*100;
                    }
                    iResumeTimer(4);
                }

                turn++;
            }
        }

        if(saveFile){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
                if(mx>790 && mx<860 && my>320 && my<360){
                    menu=1;
                    play=0;
                    menumusic();

                    FILE* fp;
                    if(mode==0||mode==3||mode==4){
                        fp = fopen("SavedGame1.txt","w");
                    }
                    else if(mode==1){
                        fp = fopen("SavedGame2.txt","w");
                    }
                    else if(mode==2){
                        fp = fopen("SavedGame3.txt","w");
                    }

                    for(int i=5;i>=0;i--){                  //Saving the INDEX
                        for(int j=0;j<7;j++){
                            fprintf(fp,"%d ",index[i][j]);
                        }
                        fprintf(fp,"\n");
                    }

                    fprintf(fp,"%0.2f\n",timer);            //Saving TIME
                    fprintf(fp,"%d\n",turn);                //Saving TURN
                    fprintf(fp,"%s\n",player01);            //Saving Player Name
                    fprintf(fp,"%s\n",player02);

                    for(int i=0;i<turn;i++){                //Saving x, y & yStop
                        fprintf(fp,"%d %d %d\n",x[i],y[i],yStop[i]);
                    }

                    if(mode==1){
                        fprintf(fp,"%d\n",waterLevel);
                    }
                    if(mode==2){
                        for(int i=0;i<BLOCKS;i++){
                            fprintf(fp,"%d %d\n",blockX[i],blockY[i]);
                        }
                    }


                    saveFile = 0;
                    fclose(fp);
                }

                else if(mx>900 && mx<970 && my>320 && my<360){
                    saveFile = 0;
                    menu=1;
                    play=0;
                    menumusic();
                }
            }
        }
    }
}

void iMouseMove(int mx, int my)
{
	if(menu){
        if(mx>50 && mx<295 && my>530 && my<580)
            menuKey = 0;
        else if(mx>50 && mx<295 && my>450 && my<500)
            menuKey = 1;
        else if(mx>50 && mx<295 && my>370 && my<420)
            menuKey = 2;
        else if(mx>50 && mx<295 && my>290 && my<340)
            menuKey = 3;
        else if(mx>50 && mx<295 && my>210 && my<260)
            menuKey = 4;
        else if(mx>50 && mx<295 && my>130 && my<180)
            menuKey = 5;
        else if(mx>50 && mx<295 && my>50 && my<100)
            menuKey = 6;
	}

	if(play){
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
}

void iKeyboard(unsigned char key)
{
    int temp=1;

	if(menu){
        if(!playerNameInput && key == '\r'){
            //NEW GAME
            if(menuKey == 0 && temp){
                playerNameInput=1;
                strcpy(player01,"Player1");
                strcpy(player02,"Player2");
                temp=0;
            }

            //CONTINUE GAME
            else if(menuKey == 1 && temp){
                menu=0;
                play=1;
                gamesound();
                temp=0;
                gameOver=0;

                FILE* fp2;
                if(mode==0||mode==3||mode==4){
                    fp2 = fopen("SavedGame1.txt","r");
                }
                else if(mode==1){
                    fp2 = fopen("SavedGame2.txt","r");
                }
                else if(mode==2){
                    fp2 = fopen("SavedGame3.txt","r");
                }

                for(int i=5;i>=0;i--){                              //Loading the INDEX
                    for(int j=0;j<7;j++){
                        fscanf(fp2,"%d",&index[i][j]);
                    }
                }
                fscanf(fp2,"%f",&timer);                            //Loading the TIME and TURN
                fscanf(fp2,"%d",&turn);
                fscanf(fp2,"%s",player01);                          //Loading Player Name
                fscanf(fp2,"%s",player02);

                for(int i=0;i<turn;i++){
                    fscanf(fp2,"%d %d %d",&x[i],&y[i],&yStop[i]);   //Loading x, y & yStop
                }
                if(mode==1){
                    fscanf(fp2,"%d\n",&waterLevel);
                }
                if(mode==2){
                    for(int i=0;i<BLOCKS;i++){
                        fscanf(fp2,"%d %d\n",&blockX[i],&blockY[i]);
                    }
                }

                fclose(fp2);

                iResumeTimer(0);
                iResumeTimer(1);
            }

            //SETTINGS
            else if(menuKey == 2 && temp){
                settings=1;
                menu=0;
                temp=0;
            }

            //RULES
            else if(menuKey == 3 && temp){
                rules=1;
                menu=0;
                temp=0;
            }

            //HALL OF FAME
            else if(menuKey == 4 && temp){
                showHighScore = 1;
                menu = 0;
                temp = 0;
            }

            //ABOUT
            else if(menuKey == 5 && temp){
                credit = 1;
                menu = 0;
                temp = 0;
            }

            //EXIT
            else if(menuKey == 6 && temp){
                temp=0;
                exit(0);
            }
        }

        //Player Name Input
        else if(playerNameInput==1){
            if(key == 27 && temp){
                len=7;
                playerNameInput=0;
                temp=0;
            }
            else if(key!='\r' && key!=8 && temp){
//                if(islower((int)key))
//                    player01[len] = key&95;
//                else
                    player01[len] = key;
                if(len<10) len++;
                temp=0;
            }
            else if(key == 8 && temp){
                player01[len] = ' ';
                if(len>0) len--;
                temp = 0;
            }
            else if(key == '\r' && temp){
                len=7;
                temp=0;
                playerNameInput=2;
            }
        }

        else if(playerNameInput==2){
            if(key == 27 && temp){
                len=7;
                playerNameInput=0;
                temp=0;
            }
            else if(key!='\r' && key!=8 && temp){
//                if(islower((int)key))
//                    player02[len] = key&95;
//                else
                    player02[len] = key;
                if(len<10)
                    len++;
                temp=0;
            }
            else if(key == 8 && temp){
                player02[len] = ' ';
                if(len>0) len--;
                temp = 0;
            }
            else if(key == '\r' && temp){
                len=7;
                temp=0;
                playerNameInput=0;
                menu=0;
                play=1;
                gamesound();
                timer=0;
                iResumeTimer(0);
                iResumeTimer(1);
                turn = 0;
                gameOver = 0;

                for(int i=0;i<50;i++){
                    x[i]=0;
                    y[i]=0;
                    yStop[i]=0;
                }

                for(int i=0; i<6; i++){
                    for(int j=0; j<7; j++){
                        index[i][j] = 0;
                    }
                }

                if(mode==1){
                    waterLevel = 0;
                }

                else if(mode==2){
                    for(int i=0;i<BLOCKS;i++){
                        int m = rand()%7;           //n for row, m for column
                        int n = rand()%3;
                        blockX[i] = m;
                        blockY[i] = n;
                        index[n][m] = 3;            //index 3 means Blocks
                    }
                }

                else if(mode==4){
                    turn = PLAYED;

                    while(1){

                    for(int i=0;i<turn;i++){
                        int col = rand()%7;

                        x[i]=350+col*100;
                        y[i]=675;

                        for(int j=5;j>=0;j--){
                            if( index[j][col] ){
                                yStop[i] = 75+100*(j+1);
                                if(i%2==0)
                                    index[j+1][col] = 1;
                                else
                                    index[j+1][col] = 2;
                                break;
                            }
                            if(j==0 && index[j][col]==0){
                                yStop[i] = 75;
                                if(i%2==0)
                                    index[j][col] = 1;
                                else
                                    index[j][col] = 2;
                                break;
                            }
                        }
                    }
                    if(check()==0) break;

                    }

                }
            }
        }
    }

    else if(settings){
        if(key==27 && temp){
            settings=0;
            menu=1;
            temp=0;
        }
        if(key==13 && temp){
            settings=0;
            menu=1;
            temp=0;
        }
        if(key=='s' && temp){
            music = (music+1)%2;
            gamesound();
            menumusic();
            temp=0;
        }
    }

    else if(rules){
        if(key==27 && temp){
            rules=0;
            menu=1;
            temp=0;
        }
    }

    else if(showHighScore){
        if(key == 27 && temp){
            showHighScore = 0;
            menu = 1;
            temp = 0;
        }
    }

    else if(credit){
        if(key == 27 && temp){
            credit = 0;
            menu = 1;
            temp = 0;
        }
    }

    else if(play){
        if(key == ' ' && !gameOver && y[turn-1]==yStop[turn-1] && !saveFile && !ballsFreezing && temp){

            if(index[5][column]==0){
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

                if(turn>0 && turn%5==0 && !gameOver && !saveFile){
                    ballsFreezing = 1;
                    for(int i=0;i<FREEZE;i++){                     //n for row, m for column
                        int n = rand()%3;
                        int m = rand()%7;
                        index[n][m] = 0;
                        freezeX[i] = 350+m*100;
                        freezeY[i] = 75+n*100;
                    }
                    iResumeTimer(4);
                }

                turn++;
            }
            temp=0;
        }

        else if(key == 27 && temp){
            iPauseTimer(0);
            iPauseTimer(1);
            if(!gameOver)
                saveFile=1;
            else{
                menu=1;
                play=0;
                menumusic();
            }

            if(gameOver==1 || gameOver==2){
                updateHighScore();
            }

            temp = 0;
        }

        else if(key == '\r' && saveFile == 1 && temp){
            if(saveFileKey == 0){
                menu=1;
                play=0;
                menumusic();

                FILE* fp;
                if(mode==0||mode==3||mode==4){
                    fp = fopen("SavedGame1.txt","w");
                }
                else if(mode==1){
                    fp = fopen("SavedGame2.txt","w");
                }
                else if(mode==2){
                    fp = fopen("SavedGame3.txt","w");
                }


                for(int i=5;i>=0;i--){                  //Saving the INDEX
                    for(int j=0;j<7;j++){
                        fprintf(fp,"%d ",index[i][j]);
                    }
                    fprintf(fp,"\n");
                }

                fprintf(fp,"%0.2f\n",timer);            //Saving TIME
                fprintf(fp,"%d\n",turn);                //Saving TURN
                fprintf(fp,"%s\n",player01);            //Saving Player Name
                fprintf(fp,"%s\n",player02);

                for(int i=0;i<turn;i++){                //Saving x, y & yStop
                    fprintf(fp,"%d %d %d\n",x[i],y[i],yStop[i]);
                }

                if(mode==1){
                    fprintf(fp,"%d\n",waterLevel);
                }
                if(mode==2){
                    for(int i=0;i<BLOCKS;i++){
                        fprintf(fp,"%d %d\n",blockX[i],blockY[i]);
                    }
                }

                saveFile = 0;
                fclose(fp);
            }
            else if(saveFileKey == 1){
                saveFile = 0;
                menu=1;
                play=0;
                menumusic();
            }
        }
    }

    temp=1;
}

void iSpecialKeyboard(unsigned char key)
{
    //Main menu by Keyboard
	if(menu){
	    if(key == GLUT_KEY_DOWN){
            menuKey==6 ?
                       : menuKey++;
	    }
	    if(key == GLUT_KEY_UP){
            menuKey==0 ?
                       : menuKey--;
	    }

	    if(playerNameInput){
            if(key == GLUT_KEY_RIGHT){
                if(len<9) len++;
            }
            else if(key == GLUT_KEY_LEFT){
                if(len>0) len--;
            }
	    }
	}

	else if(settings){
        if(key == GLUT_KEY_DOWN){
            if(mode<4)
                mode++;
        }
        if(key == GLUT_KEY_UP){
            if(mode>0)
                mode--;

        }
	}

	else if(rules){
        if(key == GLUT_KEY_DOWN){
            if(rulesY<800) rulesY = rulesY + 10;
        }
        else if(key == GLUT_KEY_UP){
            if(rulesY>600) rulesY = rulesY - 10;
        }
	}

	else if(showHighScore){
        if(key == GLUT_KEY_RIGHT){
            if(highScoreSlide<4) highScoreSlide = highScoreSlide+1;
        }
        if(key == GLUT_KEY_LEFT){
            if(highScoreSlide>0) highScoreSlide = highScoreSlide-1;
        }
	}

	else if(play){
        if(key == GLUT_KEY_RIGHT && !saveFile){
            if(column<6)
                column++;
        }
        if(key == GLUT_KEY_LEFT && !saveFile){
            if(column>0)
                column--;
        }
        if(saveFile==1){
            if(key == GLUT_KEY_RIGHT){
                if(saveFileKey<1) saveFileKey++;
            }
            else if(key == GLUT_KEY_LEFT){
                if(saveFileKey>0) saveFileKey--;
            }
        }
	}

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
}

void moveBalls(void)
{
    for(int i=0;i<turn;i++){
        if(y[i]>yStop[i]){
            y[i] = y[i]-20;
        }
        else if(waterRising && y[i]<yStop[i]){
            y[i] = y[i]+10;
        }
    }
    if(y[turn-1]==yStop[turn-1]){
        waterRising=0;
        if(gameOver==0 & waterRising==0) gameOver = check();
    }
}

void Timer(void)
{
    if(play && !gameOver){
        timer = timer + 0.02;
    }
    sprintf(showTimer, "%0.2f seconds", timer);
}

void waterRise(void)
{
    if(mode == 1 && !gameOver && !saveFile){
        waterLevel = waterLevel + 1;

        if(waterLevel>25 && (waterLevel-25)%100==0){
            waterRising = 1;
            for(int i=5;i>0;i--){
                for(int j=0;j<7;j++){
                    index[i][j] = index[i-1][j];              //moving index one step higher
                }
            }
            for(int i=0;i<7;i++){
                index[0][i] = 4;                              //4 means that hole is under water
            }
            for(int i=0;i<turn;i++){
                if(yStop[i] < 575){
                    yStop[i] = yStop[i]+100;                  //Lifting up balls by one hole
                }
                else{
                    y[i] = 800;
                    yStop[i] = 800;                           //as the screen is only 700 in height
                }
            }
        }
    }
}

void freezeBalls(void)
{
    if(mode == 3 && !gameOver && ballsFreezing){
//        for(int i=0;i<FREEZE;i++){                     //n for row, m for column
//            int n = rand()%3;
//            int m = rand()%7;
//            index[n][m] = 0;
//            freezeX[i] = 350+i*100;
//            freezeY[i] = 75+i*100;
//        }
        for(int i=0;i<turn;i++){                       //Here I am moving those freezed holes/balls outside of the window
            int a = (x[i]-350)/100;
            int b = (yStop[i]-75)/100;
            if(index[b][a] == 0){
                x[i] = 1300;
                y[i] = 500;
                yStop[i] = 500;
            }
            if(b!=0 && index[b-1][a] == 0){            //moving the balls above the newly freed holes down
//                y[i] -= 100;
                yStop[i] -= 100;
                index[b-1][a] = index[b][a];
                index[b][a] = 0;
            }
        }
    }
    ballsFreezing = (ballsFreezing+1)%2;
    iPauseTimer(4);
}

void updateHighScore(void)
{
    if(gameOver==1){
        strcpy(current.name, player01);
        current.moves = ((turn-1)/2)+1;
        current.winningTime = timer;
    }

    else if(gameOver==2){
        strcpy(current.name, player02);
        current.moves = turn/2;
        current.winningTime = timer;
    }

    for(int i=0; i<5; i++){

        if( (current.moves < highScore[mode][i].moves) || highScore[mode][i].moves==0 ){
            tempScore = current;
            current = highScore[mode][i];
            highScore[mode][i] = tempScore;
        }

        else if( current.moves == highScore[mode][i].moves ){
            if(current.winningTime < highScore[mode][i].winningTime){
                tempScore = current;
                current = highScore[mode][i];
                highScore[mode][i] = tempScore;
            }
        }
    }


    FILE *fp3;
    if(mode == 0)
        fp3 = fopen("HighScore0.txt","w");
    else if(mode == 1)
        fp3 = fopen("HighScore1.txt","w");
    if(mode == 2)
        fp3 = fopen("HighScore2.txt","w");
    if(mode == 3)
        fp3 = fopen("HighScore3.txt","w");
    if(mode == 4)
        fp3 = fopen("HighScore4.txt","w");

    for(int i=0;i<5;i++){
        fprintf(fp3,"%s\n",highScore[mode][i].name);
        fprintf(fp3,"%d ",highScore[mode][i].moves);
        fprintf(fp3,"%f\n",highScore[mode][i].winningTime);
    }

    fclose(fp3);
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

void iDraw()
{
    iClear();

    if(menu){
        iDrawMain();
    }

    else if(settings)
        iDrawSet();

    else if(play){

        if(mode==0){
            char a[20][100]={"d 01.bmp", "d 02.bmp","d 03.bmp","d 04.bmp","d 05.bmp","d 06.bmp","d 07.bmp","d 08.bmp","d 09.bmp","d 10.bmp","d 11.bmp","d 12.bmp","d 13.bmp","d 14.bmp","d 15.bmp","d 16.bmp","d 17.bmp","d 18.bmp","d 19.bmp","d 20.bmp" };
            d+=0.1;
            if(d>=20)d=0;
            iShowBMP(0,0,a[(int)d]);
        }

        else if(mode==1){
            char b[20][100]={"aqua 01.bmp","aqua 02.bmp","aqua 03.bmp","aqua 04.bmp","aqua 05.bmp","aqua 06.bmp","aqua 07.bmp","aqua 08.bmp","aqua 09.bmp","aqua 10.bmp","aqua 11.bmp","aqua 12.bmp","aqua 13.bmp","aqua 14.bmp","aqua 15.bmp","aqua 16.bmp","aqua 17.bmp","aqua 18.bmp","aqua 19.bmp","aqua 20.bmp"};
            aqua+=0.2;
            if(aqua>=20)aqua=0;
            iShowBMP(0,0,b[(int)aqua]);
//            iShowBMP(0,0,"aqua 01.bmp");
            iSetColor(255,255,255);
            iLine(0,waterLevel,1200,waterLevel);

            if(waterLevel>=125){
                int k = (waterLevel-25)/100;
                for(int i=0;i<k;i++){
                    for(int j=0;j<7;j++){
                        iShowBMP2(307+j*100,30+i*100,"octopus2.bmp",0xFFFFFF);
                    }
                }
            }

//            for(int i=295;i<1000;i++){
//                for(int j=1;j<100;j++){
//                    iGetPixelColor(i,j,rgb);
//                    iSetColor(rgb[0]*0.5+37*0.5,rgb[1]*0.5+109*0.5,rgb[2]*0.5+123*0.5);
//                    iSetColor(rgb[0]*0.5+255*0.5,rgb[1]*0.5+0*0.5,rgb[2]*0.5+0*0.5);
//                    iPoint(i,j,1);
//                }
//            }
//            iGetPixelColor (200,250,rgb[3]){
//                    rgb[0] = pixel[0];
//                    rgb[1] = pixel[1];
//                    rgb[2] = pixel[2];
//
//    printf("%d %d %d\n",pixel[0],pixel[1],pixel[2]);
//
//            iSetColor(51*0.4+255*0.6,153*0.4+255*0.6,255*0.4+255*0.6);
//            iPoint(500,600,50);
//
//            char l[5][100]={"W 01.bmp","W 02.bmp","W 03.bmp","W 04.bmp","W 05.bmp"};
//            water+=1;
//            if(water>=5)water=0;
//        iShowBMP2( 200, 0+menuanime ,l[(int)water],0x006633 );
//        iSetColor(25, 255, 255);
//        iFilledRectangle(295,20,710,610);
//        iShowBMP(295,18,"aq.bmp");
//      iShowBMP2(295,20+menuanime,"aq.bmp", 0x19FFAFF);
//        if( menuanime<700)
//        {
//            menuanime+=0.5;
//        }
//            int k=0;
//            for(int j=0;j<2;j++){
//                for(int i=295;j<1005;i++){
//                    iSetColor(rgb[k][0]*0.5+37*0.5,rgb[k][1]*0.5+109*0.5,rgb[k][2]*0.5+123*0.5);
//                    iPoint(i,j,1);
//                    k++;
//                }
//            }
        }

        else if(mode==2){
            char c[30][100]={"for 03.bmp","for 03.bmp","for 03.bmp","for 04.bmp","for 05.bmp","for 06.bmp","for 07.bmp","for 08.bmp","for 09.bmp","for 10.bmp","for 11.bmp","for 12.bmp","for 13.bmp","for 14.bmp","for 15.bmp","for 16.bmp","for 17.bmp","for 16.bmp","for 15.bmp","for 14.bmp","for 13.bmp","for 12.bmp","for 11.bmp","for 10.bmp","for 09.bmp","for 08.bmp","for 07.bmp","for 06.bmp","for 05.bmp","for 04.bmp" };
            forest+=0.2;
            if(forest>=30)forest=0;
            iShowBMP(0,0,c[(int)forest]);

            for(int i=0;i<BLOCKS;i++){
//                iSetColor(193,154,107);
//                iFilledCircle(350+blockX[i]*100, 75+blockY[i]*100, 45);
               iShowBMP2(350-47+blockX[i]*100, 75-47+blockY[i]*100,"wood.bmp",0xFFFFFF);

            }
        }


        else if(mode==3){
            char d[20][100]={"snow 01.bmp", "snow 02.bmp","snow 03.bmp","snow 04.bmp","snow 05.bmp","snow 06.bmp","snow 07.bmp","snow 08.bmp","snow 09.bmp","snow 10.bmp","snow 11.bmp","snow 12.bmp","snow 13.bmp","snow 14.bmp","snow 15.bmp","snow 16.bmp","snow 17.bmp","snow 18.bmp","snow 19.bmp","snow 20.bmp",};
            snow+=0.2;
            if(snow>=20) snow=0;
            iShowBMP(0,0,d[(int)snow]);
        }

        else if(mode==4){
            char e[20][100]={"old 01.bmp","old 02.bmp","old 03.bmp","old 04.bmp","old 05.bmp","old 06.bmp","old 07.bmp","old 08.bmp","old 09.bmp","old 10.bmp","old 11.bmp","old 12.bmp","old 13.bmp","old 14.bmp","old 15.bmp","old 16.bmp","old 17.bmp","old 18.bmp","old 19.bmp","old 20.bmp", };
            old+=0.2;
            if(old>=20) old=0;
            iShowBMP(0,0,e[(int)old]);
        }

        for(int i=0; i<turn; i++){
            if(i%2==0)
                drawBall_01(x[i],y[i]);
            else
                drawBall_02(x[i],y[i]);
        }

        if(mode==3 && ballsFreezing){
//            iSetColor(255,255,255);
            for(int i=0;i<FREEZE;i++){
//                iFilledCircle(freezeX[i],freezeY[i],45);
                iShowBMP2(freezeX[i]-45,freezeY[i]-45,"sflake2.bmp",0xFFFFFF);
            }
        }

        drawBoard();

        //showing which column he selected
        if(turn%2==0)
            iSetColor(255,0,0);
        else
            iSetColor(255,255,0);
        double xx[3]={340+(double)column*100, 350+(double)column*100, 360+(double)column*100};
        double yy[3]={665,645,665};
        iFilledPolygon(xx,yy,3);

        //showing which player to take the next turn
        iSetColor(255,255,255);
        if(turn%2 == 0)
            iFilledRectangle(18,50,132,38);
        else
            iFilledRectangle(18,10,132,38);

        //declaring player ball color
        iSetColor(0,0,0);
        iText(25,65,player01);
        iText(25,25,player02);
        iSetColor(255,0,0);
        iFilledCircle(124,70,15);
        iSetColor(255,255,0);
        iFilledCircle(124,30,15);


//        iText(25,500,str);
//        iText(25,450,str2);

        //showing moves
        char showMoves01[20] = "";
        char showMoves02[20] = "0";
        turn==0 ? sprintf(showMoves01,"%s : %d",player01,0)
                : sprintf(showMoves01,"%s : %d",player01,((turn-1)/2)+1);
        sprintf(showMoves02,"%s : %d",player02,(turn/2));

        iSetColor(255,255,255);
        iText(50,300,"Moves ");
        iText(50,280,showMoves01);
        iText(50,260,showMoves02);
        iText(50,185,showTimer);

        iSetColor(255,255,255);
        iText(20,670," Press ESC to return Main Menu", GLUT_BITMAP_9_BY_15);

        if(gameOver)
            iDrawOver();

        if(saveFile){
            iSetColor(255,255,255);
            iFilledRectangle(0,285,1200,115);
            iSetColor(0,0,0);
            iText(320,335,"Do you want to save the progress?",GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(790,320,70,40);
            iRectangle(900,320,70,40);
            iSetColor(128,128,128);
            if(!saveFileKey) iFilledRectangle(789,320,71,41);
            else             iFilledRectangle(899,320,71,41);
            iSetColor(0,0,0);
            iText(801,330,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(910,330," NO",GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }

    else if(rules)
        iDrawRules();

    else if(showHighScore)
        iDrawHighScores();

    else if(credit)
        iDrawCredit();

}


int main()
{
    int horizontal=1200;
    int vertical=700;

    iSetTimer(1, moveBalls);
    iSetTimer(10, Timer);
    iSetTimer(250, cursorBlink);
    iSetTimer(200, waterRise);
    iSetTimer(2000, freezeBalls);
    iPauseTimer(4);

    FILE* fp4= fopen("HighScore0.txt","r");
    for(int i=0;i<5;i++){
        fscanf(fp4,"%s",highScore[0][i].name);
        fscanf(fp4,"%d",&highScore[0][i].moves);
        fscanf(fp4,"%f",&highScore[0][i].winningTime);
    }
    fclose(fp4);

    FILE* fp5= fopen("HighScore1.txt","r");
    for(int i=0;i<5;i++){
        fscanf(fp5,"%s",highScore[1][i].name);
        fscanf(fp5,"%d",&highScore[1][i].moves);
        fscanf(fp5,"%f",&highScore[1][i].winningTime);
    }
    fclose(fp5);

    FILE* fp6= fopen("HighScore2.txt","r");
    for(int i=0;i<5;i++){
        fscanf(fp6,"%s",highScore[2][i].name);
        fscanf(fp6,"%d",&highScore[2][i].moves);
        fscanf(fp6,"%f",&highScore[2][i].winningTime);
    }
    fclose(fp6);

    FILE* fp7= fopen("HighScore3.txt","r");
    for(int i=0;i<5;i++){
        fscanf(fp7,"%s",highScore[3][i].name);
        fscanf(fp7,"%d",&highScore[3][i].moves);
        fscanf(fp7,"%f",&highScore[3][i].winningTime);
    }
    fclose(fp7);

    FILE* fp8= fopen("HighScore4.txt","r");
    for(int i=0;i<5;i++){
        fscanf(fp8,"%s",highScore[4][i].name);
        fscanf(fp8,"%d",&highScore[4][i].moves);
        fscanf(fp8,"%f",&highScore[4][i].winningTime);
    }
    fclose(fp8);


    menumusic();

    iInitialize(horizontal, vertical, "Four in a row");

    return 0;
}
