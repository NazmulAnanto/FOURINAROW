iDrawMain()
{
    char p[100][100]= {"bg 001.bmp","bg 002.bmp","bg 003.bmp","bg 004.bmp","bg 005.bmp","bg 006.bmp","bg 007.bmp","bg 008.bmp","bg 009.bmp","bg 010.bmp","bg 011.bmp","bg 012.bmp","bg 013.bmp","bg 014.bmp","bg 015.bmp","bg 016.bmp","bg 017.bmp","bg 018.bmp","bg 019.bmp","bg 020.bmp","bg 021.bmp","bg 022.bmp","bg 023.bmp","bg 024.bmp","bg 025.bmp","bg 026.bmp","bg 027.bmp","bg 028.bmp","bg 029.bmp","bg 030.bmp","bg 031.bmp","bg 032.bmp","bg 033.bmp","bg 034.bmp","bg 035.bmp","bg 036.bmp","bg 037.bmp","bg 038.bmp","bg 039.bmp","bg 040.bmp","bg 041.bmp","bg 042.bmp","bg 043.bmp","bg 044.bmp","bg 045.bmp","bg 046.bmp","bg 047.bmp","bg 048.bmp","bg 049.bmp","bg 050.bmp","bg 051.bmp","bg 052.bmp","bg 053.bmp","bg 054.bmp","bg 055.bmp","bg 056.bmp","bg 057.bmp","bg 058.bmp","bg 059.bmp","bg 060.bmp","bg 061.bmp","bg 062.bmp","bg 063.bmp","bg 064.bmp","bg 065.bmp","bg 066.bmp","bg 067.bmp","bg 068.bmp","bg 069.bmp","bg 070.bmp","bg 071.bmp","bg 072.bmp","bg 073.bmp","bg 074.bmp","bg 075.bmp","bg 076.bmp","bg 077.bmp","bg 078.bmp","bg 079.bmp","bg 080.bmp","bg 081.bmp","bg 082.bmp","bg 083.bmp","bg 084.bmp",
    "bg 085.bmp","bg 086.bmp","bg 087.bmp","bg 088.bmp","bg 089.bmp","bg 090.bmp","bg 091.bmp","bg 092.bmp","bg 093.bmp","bg 094.bmp","bg 095.bmp","bg 096.bmp","bg 097.bmp","bg 098.bmp","bg 099.bmp","bg 100.bmp",};

    pic+=0.125;
    if(pic>=100)pic=0;

    iShowBMP(0,0,p[(int)pic]);

    iShowBMP2(850,550,"TITLE01.bmp",0xFFFFFF);

    for(int i=0;i<7;i++){
            iSetColor(0,0,0);
            iRectangle(50, 50+i*80, 245, 50);
    }

    iSetColor(255,255,255);
    if(menuKey == 0){
        iFilledRectangle(49,530,246,51);
    }
    else if(menuKey == 1){
        iFilledRectangle(49,450,246,51);
    }
    else if(menuKey == 2){
        iFilledRectangle(49,370,246,51);
    }
    else if(menuKey == 3){
        iFilledRectangle(49,290,246,51);
    }
    else if(menuKey == 4){
        iFilledRectangle(49,210,246,51);
    }
    else if(menuKey == 5){
        iFilledRectangle(49,130,246,51);
    }
    else if(menuKey == 6){
        iFilledRectangle(49,50,246,51);
    }

    iSetColor(0,0,0);
    iText(70,545,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,465,"CONTINUE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,385,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,305,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,225,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,145,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,65,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);


    if(playerNameInput){
        iSetColor(0,0,0);
        iRectangle(500,90,600,260);
        iLine(295,530,500,350);
        iLine(295,580,1100,350);

        iText(640,310,"INPUT PLAYERS' NAMES",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(640,100,"(not more than 10 letters in a name)",GLUT_BITMAP_8_BY_13);

        iSetColor(255,0,0);
        iText(550,228,"Player 1 :");
        iRectangle(680,217,350,30);
        iText(685,228,player01);

        iSetColor(255,255,0);
        iText(550,178,"Player 2 :");
        iRectangle(680,167,350,30);
        iText(685,178,player02);
    }

    iSetColor(0,0,0);
    if(playerNameInput==1 && cursor){
        iFilledRectangle(685+len*8,220,8,5);
    }
    else if(playerNameInput==2 && cursor){
        iFilledRectangle(685+len*8,170,8,5);
    }

}


void cursorBlink()
{
    cursor = (cursor+1)%2 ;
}

iDrawSet()
{

    char s[20][100]= {"t 01.bmp", "t 02.bmp","t 03.bmp","t 04.bmp","t 05.bmp","t 06.bmp","t 07.bmp","t 08.bmp","t 09.bmp","t 10.bmp","t 11.bmp","t 12.bmp","t 13.bmp","t 14.bmp","t 15.bmp","t 16.bmp","t 17.bmp","t 18.bmp","t 19.bmp","t 20.bmp"};
    pic2+=0.15;
    if(pic2>=20)pic2=0;
    iShowBMP(0,0,s[(int)pic2]);

    for(int i=0;i<7;i++){
            iSetColor(0,0,0);
            iRectangle(50, 50+i*80, 245, 50);
    }

    iSetColor(219,225,211);
    iFilledRectangle(49,370,246,51);

    iSetColor(255,255,255);
    iText(20,670," Press ESC to return Main Menu");

    iText(800,565,"(Press s to change sound)");
    iSetColor(0,0,0);
    if(music)
        iText(1020,565, "MUSIC :ON", GLUT_BITMAP_TIMES_ROMAN_24);
    else
        iText(1020,565, "MUSIC :OFF", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0,0,0);
    iText(70,545,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,465,"CONTINUE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,385,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,305,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,225,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,145,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,65,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(128,128,128);
    iFilledRectangle(572, 152, 450,30);


    iSetColor(255,255,255);
    iText(900,500,"CHOOSE YOUR MODE",GLUT_BITMAP_TIMES_ROMAN_24);

    for(int i=0;i<5;i++){
        iSetColor(0,0,0);
        iRectangle(800, 100+i*80, 350, 50);
    }

//    iSetColor(51,153,255);
    iSetColor(219,225,211);
    if(mode == 0){
        iFilledRectangle(800-1,420,350+1,51);
    }
    else if(mode == 1){
        iFilledRectangle(800-1,340,350+1,51);
    }
    else if(mode == 2){
        iFilledRectangle(800-1,260,350+1,51);
    }
    else if(mode== 3){
        iFilledRectangle(800-1,180,350+1,51);
    }
    else if(mode == 4){
        iFilledRectangle(800-1,100,350+1,51);
    }


    iSetColor(0,0,0);
    iText(860,440-3,"UNDER THE NIGHT SKY",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(860,360-3," COME FLOAT WITH ME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(860,280-3,"          DEAL THE BLOCKS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(860,200-3,"          WHITE LIKE SNOW",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(860,120-3,"                    AN OLD TALE",GLUT_BITMAP_TIMES_ROMAN_24);


    iSetColor(0,0,0);
    iText(550,50,"BACK TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);

}


iDrawRules()
{

    char go[100][100]={"fox 001.bmp" ,"fox 002.bmp" ,"fox 003.bmp" ,"fox 004.bmp" ,"fox 005.bmp" ,"fox 006.bmp" ,"fox 007.bmp" ,"fox 008.bmp" ,"fox 009.bmp" ,"fox 010.bmp" ,"fox 011.bmp" ,"fox 012.bmp" ,"fox 013.bmp" ,"fox 014.bmp" ,"fox 015.bmp" ,"fox 016.bmp" ,"fox 017.bmp" ,"fox 018.bmp" ,"fox 019.bmp" ,
    "fox 020.bmp" ,"fox 021.bmp" ,"fox 022.bmp" ,"fox 023.bmp" ,"fox 024.bmp" ,"fox 025.bmp" ,"fox 026.bmp" ,"fox 027.bmp" ,"fox 028.bmp" ,"fox 029.bmp" ,"fox 030.bmp" ,"fox 031.bmp" ,"fox 032.bmp" ,"fox 033.bmp" ,"fox 034.bmp" ,"fox 035.bmp" ,"fox 036.bmp" ,"fox 037.bmp" ,"fox 038.bmp" ,"fox 039.bmp" ,
    "fox 040.bmp" ,"fox 041.bmp" ,"fox 042.bmp" ,"fox 043.bmp" ,"fox 044.bmp" ,"fox 045.bmp" ,"fox 046.bmp" ,"fox 047.bmp" ,"fox 048.bmp" ,"fox 049.bmp" ,"fox 050.bmp" ,"fox 051.bmp" ,"fox 052.bmp" ,"fox 053.bmp" ,"fox 054.bmp" ,"fox 055.bmp" ,"fox 056.bmp" ,"fox 057.bmp" ,"fox 058.bmp" ,
    "fox 059.bmp" ,"fox 060.bmp" ,"fox 061.bmp" ,"fox 062.bmp" ,"fox 063.bmp" ,"fox 064.bmp" ,"fox 065.bmp" ,"fox 066.bmp" ,"fox 067.bmp" ,"fox 068.bmp" ,"fox 069.bmp" ,"fox 070.bmp" ,"fox 071.bmp" ,"fox 072.bmp" ,"fox 073.bmp" ,"fox 074.bmp" ,"fox 075.bmp" ,"fox 076.bmp" ,
    "fox 077.bmp" ,"fox 078.bmp" ,"fox 079.bmp" ,"fox 080.bmp" ,"fox 081.bmp" ,"fox 082.bmp" ,"fox 083.bmp" ,"fox 084.bmp" ,"fox 085.bmp" ,"fox 086.bmp" ,"fox 087.bmp" ,"fox 088.bmp" ,"fox 089.bmp" ,"fox 090.bmp" ,"fox 091.bmp" ,"fox 092.bmp" ,"fox 093.bmp" ,"fox 094.bmp" ,"fox 095.bmp" ,"fox 096.bmp" ,"fox 097.bmp" ,"fox 098.bmp" ,"fox 099.bmp" ,"fox 100.bmp" };
    over+=0.8;
    if(over>=100)over=0;

    iShowBMP(0,0,go[(int)over]);

        for(int i=0;i<7;i++){
            iSetColor(0,0,0);
            iRectangle(50, 50+i*80, 245, 50);
    }

    iSetColor(219,225,211);
    iFilledRectangle(49,290,246,51);

    iSetColor(255,255,255);
    iText(20,670," Press ESC to return Main Menu");

    iSetColor(0,0,0);
    iText(70,545,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,465,"CONTINUE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,385,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,305,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,225,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,145,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,65,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0,0,0);
    iText(640,rulesY,"HOW TO PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
    iLine(630,rulesY-10,817,rulesY-10);

    iText(400,rulesY-50,"This is a two player game where each of the player try to get four of there",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-80,"buttons in a line.",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-120,"The game starts with a board having 6x7 holes. Players put there buttons from",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-150,"the top of the board and it gets down until there's another button or it's",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-180,"the end of the column. The first player gets to play with red buttons and",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-210,"the second one gets yellow ones.",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-250,"Now, one of the players win if they can get four of there buttons in a",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-280,"horizontal, vertical or diagonal line before the other one does.",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-310,"Let's check out the modes ~",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-350,"1. This is the basic mode where things stated above are going to happen only,",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-380,"no extra surprise!",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-420,"2. The game has to be finished in a certain amount of time. There'll be a level",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-450,"sliding upward and once it gets passed a whole row of the holes,all the buttons",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-480,"of both of the players will move one row higher. Thus, the game will end when",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-510,"the level crosses the whole board or one of the two players win.",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-550,"3. There's going to be some blocks in some of the holes. Buttons cannot pass",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-580,"them and will stuck over them. So, players will certainly not have all of the",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-610,"board to play and that's why have to use there vision in order to win.",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-650,"4. The game is so simple and normal but don't blame me if some of the buttons",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-680,"get freezed all of a sudden!",GLUT_BITMAP_9_BY_15);

    iText(400,rulesY-720,"5. Aaron and Julian are playing Four In A Row in this wonderful evening.",GLUT_BITMAP_9_BY_15);
    iText(400,rulesY-750,"Let's see who wins!",GLUT_BITMAP_9_BY_15);

    double xx[3]={1150,1160,1170};
    double yy1[3]={70,90,70};
    iPolygon(xx,yy1,3);
    double yy2[3]={60,40,60};
    iPolygon(xx,yy2,3);


}


iDrawHighScores()
{

    char go[100][100]={"fox 001.bmp" ,"fox 002.bmp" ,"fox 003.bmp" ,"fox 004.bmp" ,"fox 005.bmp" ,"fox 006.bmp" ,"fox 007.bmp" ,"fox 008.bmp" ,"fox 009.bmp" ,"fox 010.bmp" ,"fox 011.bmp" ,"fox 012.bmp" ,"fox 013.bmp" ,"fox 014.bmp" ,"fox 015.bmp" ,"fox 016.bmp" ,"fox 017.bmp" ,"fox 018.bmp" ,"fox 019.bmp" ,
    "fox 020.bmp" ,"fox 021.bmp" ,"fox 022.bmp" ,"fox 023.bmp" ,"fox 024.bmp" ,"fox 025.bmp" ,"fox 026.bmp" ,"fox 027.bmp" ,"fox 028.bmp" ,"fox 029.bmp" ,"fox 030.bmp" ,"fox 031.bmp" ,"fox 032.bmp" ,"fox 033.bmp" ,"fox 034.bmp" ,"fox 035.bmp" ,"fox 036.bmp" ,"fox 037.bmp" ,"fox 038.bmp" ,"fox 039.bmp" ,
    "fox 040.bmp" ,"fox 041.bmp" ,"fox 042.bmp" ,"fox 043.bmp" ,"fox 044.bmp" ,"fox 045.bmp" ,"fox 046.bmp" ,"fox 047.bmp" ,"fox 048.bmp" ,"fox 049.bmp" ,"fox 050.bmp" ,"fox 051.bmp" ,"fox 052.bmp" ,"fox 053.bmp" ,"fox 054.bmp" ,"fox 055.bmp" ,"fox 056.bmp" ,"fox 057.bmp" ,"fox 058.bmp" ,
    "fox 059.bmp" ,"fox 060.bmp" ,"fox 061.bmp" ,"fox 062.bmp" ,"fox 063.bmp" ,"fox 064.bmp" ,"fox 065.bmp" ,"fox 066.bmp" ,"fox 067.bmp" ,"fox 068.bmp" ,"fox 069.bmp" ,"fox 070.bmp" ,"fox 071.bmp" ,"fox 072.bmp" ,"fox 073.bmp" ,"fox 074.bmp" ,"fox 075.bmp" ,"fox 076.bmp" ,
    "fox 077.bmp" ,"fox 078.bmp" ,"fox 079.bmp" ,"fox 080.bmp" ,"fox 081.bmp" ,"fox 082.bmp" ,"fox 083.bmp" ,"fox 084.bmp" ,"fox 085.bmp" ,"fox 086.bmp" ,"fox 087.bmp" ,"fox 088.bmp" ,"fox 089.bmp" ,"fox 090.bmp" ,"fox 091.bmp" ,"fox 092.bmp" ,"fox 093.bmp" ,"fox 094.bmp" ,"fox 095.bmp" ,"fox 096.bmp" ,"fox 097.bmp" ,"fox 098.bmp" ,"fox 099.bmp" ,"fox 100.bmp" };
    over+=0.4;
    if(over>=100)over=0;

    iShowBMP(0,0,go[(int)over]);


    for(int i=0;i<7;i++){
            iSetColor(0,0,0);
            iRectangle(50, 50+i*80, 245, 50);
    }

    iSetColor(219,225,211);
    iFilledRectangle(49,210,246,51);

    iSetColor(255,255,255);
    iText(20,670," Press ESC to return Main Menu");

    iSetColor(0,0,0);
    iText(70,545,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,465,"CONTINUE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,385,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,305,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,225,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,145,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(70,65, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(219,225,211);
    iRectangle(440,100,600,440);
    iRectangle(440,460,600,80);
    iRectangle(440,400,600,60);
    iRectangle(440,340,600,60);
    iRectangle(440,280,600,60);
    iRectangle(440,220,600,60);
    iRectangle(440,160,600,60);
    iRectangle(440,100,600,60);

    double xx1[3]={450,470,470};
    double yy[3]={500,490,510};
    iPolygon(xx1,yy,3);
    double xx2[3]={1030,1010,1010};
    iPolygon(xx2,yy,3);

    char ch[20];

    iSetColor(255,255,255);
    if(highScoreSlide==0)
        iText(640,490,"UNDER THE NIGHT SKY",GLUT_BITMAP_HELVETICA_18);
    else if(highScoreSlide==1)
        iText(640,490,"COME FLOAT WITH ME",GLUT_BITMAP_HELVETICA_18);
    else if(highScoreSlide==2)
        iText(640,490,"     DEAL THE BLOCKS",GLUT_BITMAP_HELVETICA_18);
    else if(highScoreSlide==3)
        iText(640,490,"     WHITE LIKE SNOW",GLUT_BITMAP_HELVETICA_18);
    else if(highScoreSlide==4)
        iText(640,490,"           AN OLD TALE",GLUT_BITMAP_HELVETICA_18);

    iText(460,420,"Rank            Name                                      Moves           Time",GLUT_BITMAP_HELVETICA_18);

    for(int i=0;i<5;i++){
        sprintf(ch,"0%d", i+1);
        iText(470,360-60*i,ch,GLUT_BITMAP_HELVETICA_18);

        iText(560,360-60*i,highScore[highScoreSlide][i].name,GLUT_BITMAP_HELVETICA_18);

        sprintf(ch,"%d",highScore[highScoreSlide][i].moves);
        iText(800,360-60*i,ch,GLUT_BITMAP_HELVETICA_18);

        sprintf(ch,"%0.2f",highScore[highScoreSlide][i].winningTime);
        iText(910,360-60*i,ch,GLUT_BITMAP_HELVETICA_18);
    }

}


iDrawCredit()
{

//    char go[100][100]={"fox 001.bmp" ,"fox 002.bmp" ,"fox 003.bmp" ,"fox 004.bmp" ,"fox 005.bmp" ,"fox 006.bmp" ,"fox 007.bmp" ,"fox 008.bmp" ,"fox 009.bmp" ,"fox 010.bmp" ,"fox 011.bmp" ,"fox 012.bmp" ,"fox 013.bmp" ,"fox 014.bmp" ,"fox 015.bmp" ,"fox 016.bmp" ,"fox 017.bmp" ,"fox 018.bmp" ,"fox 019.bmp" ,
//    "fox 020.bmp" ,"fox 021.bmp" ,"fox 022.bmp" ,"fox 023.bmp" ,"fox 024.bmp" ,"fox 025.bmp" ,"fox 026.bmp" ,"fox 027.bmp" ,"fox 028.bmp" ,"fox 029.bmp" ,"fox 030.bmp" ,"fox 031.bmp" ,"fox 032.bmp" ,"fox 033.bmp" ,"fox 034.bmp" ,"fox 035.bmp" ,"fox 036.bmp" ,"fox 037.bmp" ,"fox 038.bmp" ,"fox 039.bmp" ,
//    "fox 040.bmp" ,"fox 041.bmp" ,"fox 042.bmp" ,"fox 043.bmp" ,"fox 044.bmp" ,"fox 045.bmp" ,"fox 046.bmp" ,"fox 047.bmp" ,"fox 048.bmp" ,"fox 049.bmp" ,"fox 050.bmp" ,"fox 051.bmp" ,"fox 052.bmp" ,"fox 053.bmp" ,"fox 054.bmp" ,"fox 055.bmp" ,"fox 056.bmp" ,"fox 057.bmp" ,"fox 058.bmp" ,
//    "fox 059.bmp" ,"fox 060.bmp" ,"fox 061.bmp" ,"fox 062.bmp" ,"fox 063.bmp" ,"fox 064.bmp" ,"fox 065.bmp" ,"fox 066.bmp" ,"fox 067.bmp" ,"fox 068.bmp" ,"fox 069.bmp" ,"fox 070.bmp" ,"fox 071.bmp" ,"fox 072.bmp" ,"fox 073.bmp" ,"fox 074.bmp" ,"fox 075.bmp" ,"fox 076.bmp" ,
//    "fox 077.bmp" ,"fox 078.bmp" ,"fox 079.bmp" ,"fox 080.bmp" ,"fox 081.bmp" ,"fox 082.bmp" ,"fox 083.bmp" ,"fox 084.bmp" ,"fox 085.bmp" ,"fox 086.bmp" ,"fox 087.bmp" ,"fox 088.bmp" ,"fox 089.bmp" ,"fox 090.bmp" ,"fox 091.bmp" ,"fox 092.bmp" ,"fox 093.bmp" ,"fox 094.bmp" ,"fox 095.bmp" ,"fox 096.bmp" ,"fox 097.bmp" ,"fox 098.bmp" ,"fox 099.bmp" ,"fox 100.bmp" };
//    over+=0.4;
//    if(over>=100)over=0;
//
//    iShowBMP(0,0,go[(int)over]);

//    for(int i=0;i<7;i++){
//            iSetColor(0,0,0);
//            iRectangle(50, 50+i*80, 245, 50);
//    }
//
//    iSetColor(219,225,211);
//    iFilledRectangle(49,130,246,51);
//
//    iSetColor(0,0,0);
//    iText(70,545,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,465,"CONTINUE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,385,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,305,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,225,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,145,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(70,65,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

        iShowBMP(0,0,"grey.bmp");

        iSetColor(255,255,255);
        iText(70,45, "Press ESC to back to Main Menu");
        //iText(600,650, "ABOUT US",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iRectangle(100,400,700,200);
        iRectangle(99,399,699,199);
        iRectangle(98,398,698,198);

        iRectangle(400,100,700,200);
        iRectangle(399,99,699,199);
        iRectangle(398,98,698,198);

        iRectangle(100,400,200,200);
        iRectangle(99,399,199,199);
        iRectangle(900,100,200,200);
        iRectangle(899,99,199,199);

        iShowBMP(100,400,"boy.bmp");
        iShowBMP(900,100,"girl.bmp");


}

void iDrawOver()
{

        if(gameOver==1){
            iSetColor(255,0,0);
            iFilledRectangle(500,300,300,100);
            iSetColor(255,255,255);
            char player01won[20]="";
            sprintf(player01won,"%s WON",player01);
            iText(558,340,player01won,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(gameOver==2){
            iSetColor(255,255,0);
            iFilledRectangle(500,300,300,100);
            iSetColor(0,0,200);
            char player02won[20]="";
            sprintf(player02won,"%s WON",player02);
            iText(558,340,player02won,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(gameOver==3){
            iSetColor(255,165,0);
            iFilledRectangle(500,300,300,100);
            iSetColor(0,0,0);
            iText(580,340,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        }

}


