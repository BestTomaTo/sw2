// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "allClasses.h"
using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask(MemberCollection* membercollection);
void join();
void program_exit();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

int main()
{
  // 파일 입출력을 위한 초기화
  in_fp.open(INPUT_FILE_NAME);
  out_fp.open(OUTPUT_FILE_NAME);

  MemberCollection membercollection;

cout << "debug1" << endl;
  doTask(&membercollection);
cout << "debug1_enddotask()" << endl;

  out_fp.close();
  in_fp.close();

  return 0;
}

void doTask(MemberCollection* membercollection)
{
  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;
cout << "debug doTask" << endl;    
  while(!is_program_exit)
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    in_fp >> menu_level_1 >> menu_level_2;
cout << "debug in_fp"<< menu_level_1 << menu_level_2 << endl;
    
    // 메뉴 구분 및 해당 연산 수행
    switch(menu_level_1)
    {
      case 1:
      {
        switch(menu_level_2)
        {
          case 1:   // "1.1. 회원가입“ 메뉴 부분
          {
cout << "debug 1.1 SignUp" << endl;
            SignUp signup(membercollection);
            break;
          }
        }
        break;
      }
      case 2:
      {
        switch(menu_level_2)
        {
          case 1: // "2.1. 로그인"
          {
cout << "debug 2.1 Login" << endl;
            Login login(membercollection);
            break;
          }
          case 2: // "2.2. 로그아웃"
          {
cout << "debug 2.1 Login" << endl;
            Logout logout(membercollection);
            break;
          }
        }
        break;
      }        
      case 3:
      {
        switch(menu_level_2)
        {
          case 1:
          break;
          case 2:
          break;
        }
        break;
      }
      case 6:
      {
        switch(menu_level_2)
        {
          case 1:   // "6.1. 종료“ 메뉴 부분
            {
      	      is_program_exit = 1;
              break;
            }        
        }
        break;
      }
    }   
  }
}



