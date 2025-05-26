// 헤더 선언
#include <stdio.h>
#include <string>
#include <fstream>
#include "SignUp.h"
#include "Login.h"
#include "Logout.h"
#include "Enroll.h"
#include "Rent.h"
#include "checkBike.h"
#include "Exit.h"
#include "FileManager.h"
using namespace std;

// 상수 선언`
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask(MemberCollection* membercollection, BikeCollection* bikecollection, RentalCollection* rentalcollection, FileManager* filemanager);

int main()
{
  // 파일 입출력을 위한 초기화
  FileManager filemanager("input.txt", "output.txt");
  MemberCollection membercollection(&filemanager);
  BikeCollection bikecollection(&filemanager);
  RentalCollection rentalcollection(&filemanager);

  doTask(&membercollection, &bikecollection, &rentalcollection, &filemanager);

  return 0;
}

void doTask(MemberCollection* membercollection, BikeCollection* bikecollection, RentalCollection* rentalcollection, FileManager* filemanager)
{
  ifstream& in_fp = filemanager->getInputStream();
  ofstream& out_fp = filemanager->getOutputStream();
  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0; 
  while(!is_program_exit)
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    in_fp >> menu_level_1 >> menu_level_2;
    
    // 메뉴 구분 및 해당 연산 수행
    switch(menu_level_1)
    {
      case 1:
      {
        switch(menu_level_2)
        {
          case 1:   // "1.1. 회원가입“ 메뉴 부분
          {
            SignUp signup(membercollection, filemanager);
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
            Login login(membercollection, filemanager);
            break;
          }
          case 2: // "2.2. 로그아웃"
          {
            Logout logout(membercollection, filemanager);
            break;
          }
        }
        break;
      }        
      case 3:
      {
        switch(menu_level_2)
        {
          case 1: // 3.1 자전거 등록
          Enroll enroll(membercollection, bikecollection, filemanager);
          break;
        }
        break;
      }
      case 4:
      {
        switch(menu_level_2)
        {
          case 1:
          Rent rent(membercollection, bikecollection, rentalcollection, filemanager);
          break;
        }
        break;
      }
      case 5:
      {
        switch(menu_level_2)
        {
          case 1:
          checkBike checkBike(membercollection, rentalcollection, filemanager);
        }
      }
      case 6:
      {
        switch(menu_level_2)
        {
          case 1:   // "6.1. 종료“ 메뉴 부분
            {
      	      Exit Exit(filemanager);
              is_program_exit = 1;
              break;
            }        
        }
        break;
      }
    }   
  }
  out_fp.close();
  in_fp.close();

}



