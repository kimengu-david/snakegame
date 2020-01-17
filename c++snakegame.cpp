#include <iostream>
#include<cstdlib>
#include<curses.h>
#include<windows.h>
#include<ctime>

 bool gameover;
const int width=20;
const int height=20;
  int x,y,fruitx,fruity,score;
 int tailx[100],taily[100];
 int ntail=0;
enum Direc{stop=0,left, right, up, down};
 Direc dir;

void setup(){
gameover=false;
dir=stop;
x=width/2;
y=height/2;
srand(time(0));
fruitx=rand()%width;
fruity=rand()%height;
score=0;}
void draw(){
system("cls");
for(int j=0;j<height; j++){
for(int i=0;i<width;i++){
        if(i==0||i<width-1&&j==0||j==(height-1)){
        std::cout<<"#";}
        else if(i==width-1){
        std::cout<<"#";}
        else if(i==x&&j==y){std::cout<<"O";}
        else if(i==fruitx&&j==fruity){
        std::cout<<"@";}
        else{
        for(int k=0;k<ntail;k++){
        if(tailx[k]==j&&taily[k]==i){
        std::cout<<"o";
            }}
        std::cout<<" ";}
        }
        std::cout<<std::endl;
        }
        }
void input(){
     if(_kbhit()){
     switch(_getch()){
     case 'a':
     dir=left;
     break;
     case 'd':
     dir=right;
     break;
     case 'w':
    dir=up;
    break;
    case 's':
    dir=down;
    break;
    case 'x':
    gameover=true;
    break;
   }
   }
    }
void logic(){
    int previousx=tailx[0];
    int previousy=taily[0];
    int previous2x,previous2y;
    for(int i=1;i<ntail;i++){
            previous2x=tailx[i];
            previous2y=taily[i];
            tailx[i]=previousx;
            taily[i]=previousy;
            previousx=previous2x;
            previousy=previous2y;}

           switch(dir){
           case left:
           x--;
           break;
           case right:
           x++;
           break;
           case up:
           y--;
           break;
           case down:
           y++;
           break;}
if(x>width||x<0||y>height||y<0){
        gameover=true;}
if(x==fruitx&&y==fruity){
        srand(time(0));
        fruitx=rand()%width;
        fruity=rand()%height;
        ntail++;
        }
        }


int main(){
    setup();
while(!gameover){
          draw();
         input();
         logic();
     Sleep(150);
}
return 0;
}



