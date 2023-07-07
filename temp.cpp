

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "src/lib/view/drawBoard.h"
#include "src/lib/basic/basic_function.h"
#include "src/lib/data_manager/data_manager.h"
#include "src/lib/view/my_show.h"

int main()
{
    float t = 0;
    std::cout<<std::to_string(t)<<std::endl;


    getch();


    PTRMH treeMH = loadCourseList(fileDsMonhoc);

    int x = 0, y = 0;
    int key = 0;
    std::string keyType = "NONE";
    std::vector<PTRMH> dsMH;
    getListTreeNode(treeMH, dsMH);

    bool reDraw = true;

    int step = 10;

    ShowCur(0);
    while (true)
    {
        system("cls");
        

        drawFinalScoreBoard(x,y, dsMH.size(), dsMH);
        

        key = getch();
        keyType = getKeyType(key);
        if (keyType == "LEFT")
        {

            x += step;
        }
        else if (keyType == "RIGHT")
        {

            x -= step;
        }
        else if (keyType == "UP")
        {

            y -= step;
        }
        else if (keyType == "DOWN")
        {

            y += step;
        }
        else if (keyType == "NHAP_VAN_BAN")
        {
            if (key == 'a' || key == 'A')
            {
                reDraw = true;
                x += SCROOL_STEP;
            }
            else if (key == 'd' || key == 'D')
            {
                reDraw = true;
                x -= SCROOL_STEP;
            }
        }
    }

    return 0;
}