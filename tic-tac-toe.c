/* -----------------------------------
틱택토 (Tic-Tac-Toe) 게임 (근데 GUI를 덧붙인)
작성일 : 2022년 6월 9일
작성자 : 창의소프트웨어공학부 20223133 김시환
작성 환경 : Windows 11 x86_64, VS Code, MinGW-w64 GCC 8.1.0 SEH
----------------------------------- */


/* ----------- 전처리 ----------- */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //콘솔 윈도우 관련 처리
#include <conio.h> //getch()


/* ----------- 상수 및 변수 ----------- */
#define MAX_SIZE 3 //게임판의 최대 크기
#define NOTHING 0 //아무것도 없는 경우 0으로 기록
#define PLAYER1 1 //첫 번째 플레이어의 수는 1로 기록
#define PLAYER2 2 //두 번째 플레이어의 수는 2로 기록

int matrix[MAX_SIZE][MAX_SIZE];
int turn_count = 1; //플레이어 순서
int try_count = 0; //수를 놓은 횟수 (9-try_count == 남은 자리 수)


/* ----------- 함수 ----------- */
//자료구조(배열) 관리 함수
void PrintMatrix(); //배열 데이터를 읽어들여 현재 게임 상황을 출력
void WriteMatrix(); //플레이어가 놓은 수를 배열에 기록

//게임 화면 표시 관련 함수
void DrawInit(); //게임 판 출력 (아무것도 안 놓았을 때의 게임판)
void gotoxy(int x, int y); //지정된 위치로 텍스트 커서를 이동
void CursorShow(); //커서 위치에 기호를 표시
void RemoveGhost(int x, int y); //커서 이동 시 바로 전 위치에 있던 기호를 지움
void HideConCursor(); //콘솔 기본 커서를 숨김

//게임 진행 함수
void KeyPress(char keycode, int *x, int *y); //플레이어의 키 입력을 처리
void GameJudge(); //승리 및 무승부 판정을 확인 (0인 경우 한쪽이 승리함, 1인 경우 무승부, 2인 경우 진행)


/* ----------- 실행부 ----------- */
int main(void){
    char keycode;
    int x = 0, y = 0;

    HideConCursor(); //게임 시작 전 콘솔 커서를 숨긴다

    DrawInit(); //비어 있는 게임판을 그린다
    gotoxy(0,0); //초기 위치는 0,0으로 고정
    CursorShow(); //플레이어 순서에 맞는 커서를 표시한다
    try_count++; //게임 진행도 카운트수를 올린다

    do{
        keycode = getch(); //getch()를 통해 입력받은 키코드를 keycode에 저장
        RemoveGhost(x, y); //커서 이동 흔적을 지운다
        KeyPress(keycode, &x, &y); //키입력을 받고, 스페이스를 눌러 배열에 기록한다
        PrintMatrix(); //기록 직후 배열을 업데이트한다
        gotoxy(x, y);
        GameJudge();
        CursorShow();
        try_count++;
    }while(keycode != 27); //ESC키가 입력되기 전까지 반복한다

    return 0;
}

void PrintMatrix(){
    for(int x=0; x<MAX_SIZE; x++){ //이중 For문을 사용하여 X/Y축 모두 확인한다.
        for(int y=0; y<MAX_SIZE; y++){
            if(matrix[x][y] == PLAYER1){ //배열에 1이 있는 경우 == 플레이어 1이 놓은 수를 출력(동그라미)
                gotoxy(x,y);
                printf("○");
            }else if(matrix[x][y] == PLAYER2){ //배열에 2가 있는 경우 == 플레이어 2가 놓은 수를 출력(가위표)
                gotoxy(x,y);
                printf("×");
            }
        }
    }
}

void WriteMatrix(int x, int y){
	if (matrix[x][y] == 0){ //배열의 해당 요소가 비어 있는(0) 경우
		if (turn_count == 1){ //플레이어 1의 차례인 경우
			matrix[x][y] = PLAYER1; //커서 위치에 해당하는 요소에 1을 기록한다
			turn_count = PLAYER2; //차례를 플레이어 2한테 넘긴다

        }else{ //플레이어 2의 차례인 경우
			matrix[x][y] = PLAYER2; //커서 위치에 해당하는 요소에 2를 기록한다
			turn_count = PLAYER1; //차례를 플레이어 1한테 넘긴다
        }
    }
}

void DrawInit(){
    for(int i=0; i<3; i++)
            printf("〓〓〓\n"); //비어 있는 게임판을 출력한다 (글자 깨짐을 막기 위해 특수문자 사용)
}

void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorShow(){
	if (turn_count == PLAYER1) //전역변수 turn_count가 1일 경우 플레이어 1 기호를 출력한다
        printf("○");
	else //반대로 2일 경우에는 플레이어 2의 기호를 출력한다
		printf("×");
}

void RemoveGhost(int x, int y){
    gotoxy(x, y);
    printf("〓"); //지나간 자리에 아무것도 없음을 가리키는 기호를 그려 흔적을 없앤다
}

void HideConCursor(){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void KeyPress(char keycode, int *x, int *y){

    // 일반적인 윈도우 환경에서, row 1, Col 1 위치를 좌표계에 표시하면 (0,0)이고,
    // 좌로 이동할 때마다 X값이 +1, 아래로 이동할 때마다 Y값이 +1씩 더해진다. 반대의 경우에는 -1을 하면 된다.

    switch(keycode){ //main함수에서 getch()를 통해 받은 ASCII 코드를 기준으로 함.
	    case 72: //방향키 위
		    if (*y-1 < 0) //맨 윗줄인 경우 무시하고
			    break;
		    else //아닌 경우 한 칸 위로 이동한다.
			    *y -= 1;
		    break;
        case 80: //방향키 아래
            if (*y+1 > 2) //맨 아랫줄인 경우 무시하고
                break;
            else //아닌 경우 한 칸 아래로 이동한다.
                *y += 1;
            break;
        case 75: //방향키 왼쪽
            if (*x-1 < 0) //맨 왼쪽인 경우 무시하고
                break;
            else //아닌 경우 한 칸 왼쪽으로 이동한다.
                *x -= 1;
            break;
        case 77: //방향키 오른쪽
            if(*x+1 > 2) //맨 오른쪽인 경우 무시하고
                break;
            else //아닌 경우 한 칸 오른쪽으로 이동한다.
                *x += 1;
            break;
        case 32: //스페이스바를 입력하면
			WriteMatrix(*x, *y); //배열에 그 정보를 보낸다.
		    break;
        default:
            break;
	}
}

void GameJudge(){

    //대각선 승리
    if((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] == PLAYER1) || (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] == PLAYER1)){ //플레이어 1 대각선 일치
        gotoxy(1,5);
        printf("플레이어 1 승리\n");
        system("pause");
        exit(0);
    }else if((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] == PLAYER2) || (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] == PLAYER2)){ //플레이어 2 대각선 일치
        gotoxy(1,5);
        printf("플레이어 2 승리\n");
        system("pause");
        exit(0);

    //직선 승리
    }for(int i=0; i<2; i++){
        if((matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] == PLAYER1) || (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] == PLAYER1)){ //플레이어 1 가로, 세로줄 일치
            gotoxy(1,5);
            printf("플레이어 1 승리\n");
            system("pause");
            exit(0);
        }else if((matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] == PLAYER2) || (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] == PLAYER2)){ //플레이어 2 가로, 세로줄 일치
            gotoxy(1,5);
            printf("플레이어 2 승리\n");
            system("pause");
            exit(0);
        }
    }
}
