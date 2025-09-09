#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "Inventory.h"

#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "Drake.h"
#include "Ghoul.h"
#include "Hydra.h"
#include "Skeleton.h"

using namespace std;


// 반영? 
// 메인 함수
int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 구현

    char name[20];
    bool hasSpace = true;

    Inventory inv;
    string item;
    int count;

    cout << "------[unkindRPG]------" << endl;
    cout << "\n[ 당신의 이름을 입력해주세요 ]" << endl;

    while (hasSpace) // 입력받은 이름에 공백이 있는지 체크
    {
        cin.getline(name, 20);
        int namelen = strlen(name);

        for (int i = namelen; i >= 0; i--)
        {
            if (name[i] == ' ')
            {
                hasSpace = true;
                break;
            }
            else
            {
                hasSpace = false;
            }
        }

        if (strlen(name) == 0) // 아무것도 입력하지 않은 것도 진행 할 수 없음
        {
            hasSpace = true;
        }

        if (hasSpace)
        {
            cout << "\n다시 입력해주세요";
            cout << "\n!!!이름에는 공백이 들어갈 수 없습니다!!!" << endl;
        }
        else
        {
            cout << "\n반갑습니다 " << name << "님!" << endl;

        }
    } // 이름 설정 종료

    // 행동 반복하기
    cout << "\n";
    string place = "마을";
    char actionChoice;

    // 몬스터 전투 구현
    int Monster_choice = 1 + rand() % 8; // 랜덤으로 몬스터를 조우
    Monster* monster = nullptr;


    while (true)
    {
        cout << "\n\n<무엇을 하시겠습니까?>" << endl;
        cout << "\n[ 현재 위치 : " << place << " ]" << endl;
        cout << "\n[1] 몬스터 토벌" << endl;
        cout << "[2] 상점 이동" << endl;
        cout << "[3] 나의 상태 확인" << endl;
        cout << "[4] 인벤토리 확인" << endl;
        cout << "[5] 게임 종료 \n" << endl;
        cin >> actionChoice;

        cout << "\n\n";


        switch (actionChoice)
        {
        case '1':
        {
            while (actionChoice == '1') // 연속전투시 반복
            {
                place = "마을 외곽";

                cout << " <몬스터 시스템> " << endl;
                cout << "\n무작위 몬스터 등장!! " << endl;

                switch (Monster_choice)
                {
                case 1:
                    monster = new Goblin(name);
                    break;
                case 2:
                    monster = new Orc(name);
                    break;
                case 3:
                    monster = new Slime(name);
                    break;
                case 4:
                    monster = new Ghoul(name);
                    break;
                case 5:
                    monster = new Drake(name);
                    break;
                case 6:
                    monster = new Ghoul(name);
                    break;
                case 7:
                    monster = new Hydra(name);
                    break;
                case 8:
                    monster = new Skeleton(name);
                    break;
                }

                monster->printMonsterStatus();

                int Exp = 50; // 50 경험치
                int Gold = 10 + rand() % 11; // 10 ~ 20 골드 
                cout << "보상을 얻었다!! " << endl;
                cout << "경험치 : " << Exp << endl;
                cout << "골드 : " << Gold << endl;

                for (const string& d : monster->Droptable()) //드랍 테이블
                    cout << "드랍 아이템 : " << d << endl; // 드랍 테이블
                //// 작업해야되는 부분
                // 1. 몬스터 처치시 드랍테이블에 있는 아이템 중 1가지만 string 또는 char 타입으로 받을 것
                // 2. 아이템 드랍 확률을 조정 할 것.
                // -> 1) 아이템이 드랍됐는가? (y/n)
                // -> 2) 소비아이템 또는 전리품 중 1가지 랜덤으로 결정 (난수)
                // -> 3) 최종 드랍아이템이 정해졌으면 인벤토리에 넣을 것.

                delete monster;

                cout << "\n\n[ 몬스터 토벌을 종료합니다 ]" << endl;

                cout << "\n[ 더 사냥하시겠습니까? ]" << endl;
                cout << "[1] 네 / [2] 아니오" << endl;
                cin >> actionChoice;

                switch (actionChoice)
                {
                    case '1':
                    {
                        cout << "\n\n[ 이어서 전투합니다 ]" << endl;
                        break;
                    }
                    case '2':
                    {
                        cout << "\n\n[ 마을로 돌아갑니다 ]" << endl;
                        actionChoice = 0;
                        break;
                    }
                    default :
                    {
                        cout << "[ 잘못입력하셨습니다 ] " << endl;
                        cout << "[ 마을로 돌아갑니다 ] " << endl;
                        actionChoice = 0;
                        break;
                    }
                }
            }

            place = "마을";
            break;
        } // 몬스터 토벌 종료

        case '2': // 상점 이동
        {
            cout << "\"반갑습니다, 어서오세요!\"" << endl;

            while (actionChoice)
            {
                
                cout << "[1] 아이템 구매\n[2] 아이템 판매\n[3]나가기" << endl;
                cin >> actionChoice;
                cout << "\n";

                switch (actionChoice)
                {
                    case '1' :
                    {
                        cout << "[ 추가할 아이템 입력 ] (임시)" << endl;
                        cin >> item;
                        count = 1;
                        inv.addItem(item, count);

                        cout << "\n" << item << "을(를) 구매하였습니다." << endl;
                        cout << "\n\"감사합니다\"" << endl;
                        cout << "\"또 필요한 것이 있으실까요?\"\n" << endl;
                        break;
                    }
                    case '2' :
                    {
                        cout << "[ 판매할 아이템 입력 ] (임시)" << endl;
                        cin >> item;
                        count = 1;
                        inv.removeItem(item, count);
                        cout << "\n" << item << "을(를) 판매하였습니다." << endl;
                        cout << "\n\"감사합니다!\"" << endl;
                        cout << "\"또 필요한 것이 있으실까요?\"\n" << endl;
                        break;

                    }
                    case '3' :
                    {
                        cout << "\"감사합니다, 또 오세요!\"" <<endl;
                        actionChoice = 0;
                        break;
                    }
                    default :
                    {
                        cout << "다시 입력해주세요" << endl;
                    }

                }
                

                
            }
             
            break;

        } // 상점 나가기

        case '4': // 인벤토리 확인
        {
            cout << "=======[ 인벤토리 ]=======" << endl;
            inv.showInventory();
            
        }

        } // 행동 반복문 중단

}
    
    return 0;
    }






    // 이쪽은 임시로 메모해둔 것
    // 인벤토리 구현 관련해서 나중에 활용하고 완성시 지울 예정.
    // 
    //    while (true) {
    //    actionChoice = 0;

    //    cout << "뭐줘? " << endl;
    //    cout << "[1]추가 [2]제거 [3]볼래 [4]나가" << endl;
    //    cin >> actionChoice;

    //    if (actionChoice == '1') {
    //        cin >> item >> count;
    //        inv.addItem(item, count);
    //    }
    //    else if (actionChoice == '2') {
    //        cin >> item >> count;
    //        inv.removeItem(item, count);
    //    }
    //    else if (actionChoice == '3') {
    //        inv.showInventory();
    //    }
    //    else if (actionChoice == '4') {
    //        break;
    //    }
    //    else {
    //        cout << "알 수 없는 명령어입니다.\n";
    //    }
    //}
