void gamesound(){

    if(play && !menu && mode==0 && music) PlaySound("cartoon_song.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!play || !music) PlaySound(NULL,NULL,SND_ASYNC);

    if(play && !menu && mode==1 && music)  PlaySound("pirate.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!play || !music) PlaySound(NULL,NULL,SND_ASYNC);

    if(play && !menu && mode==2 && music)  PlaySound("unblock.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!play || !music) PlaySound(NULL,NULL,SND_ASYNC);

    if(play && !menu && mode==3 && music)  PlaySound("beachmusic.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!play || !music) PlaySound(NULL,NULL,SND_ASYNC);

    if(play && !menu && mode==4 && music)  PlaySound("vio.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!play || !music) PlaySound(NULL,NULL,SND_ASYNC);
}

void menumusic(){
    if((menu||settings) && music) PlaySound("music_rocks.wav",NULL,SND_ASYNC | SND_LOOP);
    if(!(menu || settings) || !music) PlaySound(NULL,NULL,SND_ASYNC);

}


