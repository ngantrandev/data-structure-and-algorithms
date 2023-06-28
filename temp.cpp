void inBangDiemTBKhoaHoc(int x_origin, int y_origin, PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC)
{
    PTRDK ptrDK = NULL;
    PTRSV ptrSV = NULL;
    PTRMH ptrMH = NULL;
    StudentListNode DSSV[so_sinh_vien_DSSV + 1];

    int stt = 0;
    int crt_index = -1; // chi so mang hien tai
    int index = 0;
    char maLopHoc[ClassID_Length] = {""};
    char nienkhoa[SchoolYear_Length] = "2020";
    int soSV = 0;

    int tabw = 85;
    int x_box = (128 - tabw) / 2;

    while (true)
    {

        crt_index = -1;
        soSV = 0;

        system("cls");
        gotoxy(45, y_origin);
        std::cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";

        std::string content[2] = {""};

        if (input_UI(44, y_origin + 2, 45, "NHAP THONG TIN LOP HOC CAN XET", 2, nhap_MALH_NIENKHOA, content, 20, "XAC NHAN XONG") == 1)
        {
            ConvertStringToChar(content[0], maLopHoc);
            ConvertStringToChar(content[1], nienkhoa);

            for (int i = 1; i <= dsLTC.currentIndex; i++)
            {
                if (lopTinChiTonTai(dsLTC.nodes[i]) == true && dsLTC.nodes[i]->enable == false && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
                {
                    ptrDK = dsLTC.nodes[i]->firstListRegister;
                    ptrMH = timMonHocTheoMa(Tree_monhoc, dsLTC.nodes[i]->courseCode);

                    while (ptrDK != NULL)
                    {
                        ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

                        if (strcmp(ptrSV->student.classID, maLopHoc) == 0)
                        {

                            index = timSinhVien_nodeDSSV(DSSV, crt_index, ptrSV);

                            if (index == -1)
                            { // khong tim thay
                                ++crt_index;
                                soSV++;
                                DSSV[crt_index].ptrSV = ptrSV;
                                DSSV[crt_index].tong_diem = ptrDK->regis.point * (ptrMH->course.STCLT + ptrMH->course.STCTH);
                                DSSV[crt_index].creditSum = ptrMH->course.STCLT + ptrMH->course.STCTH;
                            }

                            else
                            {
                                DSSV[index].tong_diem += ptrDK->regis.point * (ptrMH->course.STCLT + ptrMH->course.STCTH);
                                DSSV[index].creditSum += ptrMH->course.STCLT + ptrMH->course.STCTH;
                            }
                        }

                        ptrDK = ptrDK->next;
                    }
                }
            }

            // sap xep lai danh sach
            sapXep_nodeDSSV_SelectionSort(DSSV, crt_index);

            if (soSV == 0)
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG CO SINH VIEN THOA MAN", 1500);
                continue;
            }

            system("cls");
            gotoxy(45, y_origin);
            std::cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
            gotoxy(54, y_origin + 1);
            std::cout << "Ma lop: " << maLopHoc;

            veBangInDiemTB(x_box, y_origin + 3, tabw, soSV + 3);

            stt = 0; // reset stt
            for (int i = 0; i <= crt_index; i++)
            {
                stt++;

                gotoxy(x_box + 5, y_origin + stt + 5);
                std::cout << stt;
                gotoxy(x_box + 13, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.MASV;
                gotoxy(x_box + 28, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.HO;
                gotoxy(x_box + 55, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.TEN;
                gotoxy(x_box + 74, y_origin + stt + 5);
                std::printf("%0.2f", DSSV[i].tong_diem / DSSV[i].creditSum);
            }
            gotoxy(x_box, wherey() + 2);
            system("pause");
        }

        else
            break;
    }
}