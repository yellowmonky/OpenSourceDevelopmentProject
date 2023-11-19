#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int GameBoard[8][8];
int (*SetGameboard())[8][8]; //게임보드 만들기
void PrintGameBoard(int GameBoard[][8]);
int AvailabeCheck(int GameBoard[][8]); //게임보드 가능성 확인


int main(void) {
  int (*GameBoardPtr)[8][8] = SetGameboard();
  
  while(AvailabeCheck(*GameBoardPtr)==0){  
   GameBoardPtr = SetGameboard();
  }
  PrintGameBoard(*GameBoardPtr);

  free(GameBoardPtr); // malloc으로 할당된 메모리 해제
  return 0;
}





int (*SetGameboard())[8][8]{
  srand((unsigned)time(NULL));

  // 동적으로 할당된 가변 길이 배열
  int (*GameBoard)[8][8] = (int (*)[8][8])malloc(sizeof(int[8][8]));
  
  for(int i = 0;i<8;i++){
    for(int j = 0;j<8;j++){
     (*GameBoard)[i][j] = rand()%8;
    }
  }  
  return GameBoard;
  
}

void PrintGameBoard(int GameBoard[][8]){
    for(int i = 0; i<8; i++){
        for(int j=0;j<8;j++){
            if(GameBoard[i][j]==0)
                printf("🟡");
            else if(GameBoard[i][j]==1)
                printf("🟨");
            else if(GameBoard[i][j]==2)
                printf("⭐");
            else if(GameBoard[i][j]==3)
                printf("☂");
            else if(GameBoard[i][j]==4)
                printf("🔺");
            else if(GameBoard[i][j]==5)
                printf("🎂 ");
            else if(GameBoard[i][j]==6)
                printf("🍭 ");
            else if(GameBoard[i][j]==7)
                printf("🥧 ");
        }
        printf("\n");
    }
}

int AvailabeCheck(int GameBoard[][8]){ //게임보드 가능성 확인
  int check =0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(j+1>=0 && j+1<8 && GameBoard[i][j]==GameBoard[i][j+1]){
        if(i-1>=0 && i-1<8 && j-1>=0 && j-1<8 && GameBoard[i][j]==GameBoard[i-1][j-1])
          check ++;
        else if(i+1>=0 && i+1<8 && j-1>=0 && j-1<8 &&GameBoard[i][j]==GameBoard[i+1][j-1])
          check ++;
        else if(j-2>=0 && j-2<8 &&GameBoard[i][j]==GameBoard[i][j-2])
          check ++;  //왼쪽
        if(i-1>=0 && i-1<8 && j+2>=0 && j+2<8 && GameBoard[i][j]==GameBoard[i-1][j+2])
          check ++;
        else if(i+1>=0 && i+1<8 && j+2>=0 && j+2<8 && GameBoard[i][j]==GameBoard[i+1][j+2])
          check ++;
        else if(j+3>=0 && j+3<8 && GameBoard[i][j]==GameBoard[i][j+3])
          check ++;  //오른쪽
      } //가로
        
      else if(i+1>=0 && i+1<8 && GameBoard[i][j]==GameBoard[i+1][j]){
        if(j-1>=0 && j-1<8 && i-1>=0 && i-1<8 && GameBoard[i][j]==GameBoard[i-1][j-1])
          check ++;
        else if(i-1>=0 && i-1<8 && j+1>=0 && j+1<8 && GameBoard[i][j]==GameBoard[i-1][j+1])
          check ++;
        else if(j-2>=0 && j-2<8 && GameBoard[i][j]==GameBoard[i-2][j])
          check ++;    //위쪽

        
        if(i-2>=0 && i-2<8 && i-1>=0 && i-1<8 && GameBoard[i][j]==GameBoard[i-2][j-1])
          check ++;
        else if(i-2>=0 && i-2<8 && j+1>=0 && j+1<8 && GameBoard[i][j]==GameBoard[i-2][j+1])
          check ++;
        else if(i-3>=0 && i-3<8 && GameBoard[i][j]==GameBoard[i-3][j])
          check ++;  //아래쪽
      } //가로

    
    if(j+1>=0 && j+1<8 && GameBoard[i][j]==GameBoard[i][j+1] && GameBoard[i][j+1]==GameBoard[i][j+2])
      return 0;

    if(i+1>=0 && i+1<8 && GameBoard[i][j]==GameBoard[i+1][j] && GameBoard[i+1][j]==GameBoard[i+2][j])
      return 0;
    }
  }
  
  if (check>0){
    return 1;
  }
  
  return 0;
}