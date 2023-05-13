#include "saveDataAPI.h"

void xuatDanhSachSinhVien_File_Txt(PTRSV FirstSv, char File_Name[maxLengthString])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return;
    }

    PTRSV p = FirstSv;
    int so_sinh_vien_DSSV = Reccount_SV(FirstSv);

    fprintf(fileout, "%d", so_sinh_vien_DSSV);

    while (p != NULL)
    {

        fputs("\n", fileout);
        fputs(p->student.studentID, fileout);
        fputs("\n", fileout);
        fputs(p->student.firstName, fileout);
        fputs("\n", fileout);
        fputs(p->student.name, fileout);
        fputs("\n", fileout);
        fputs(p->student.sex, fileout);
        fputs("\n", fileout);
        fputs(p->student.classID, fileout);
        fputs("\n", fileout);
        fputs(p->student.phoneNum, fileout);

        p = p->next;
    }

    fclose(fileout);
}

void xuatDanhSachMonHoc_LNR_File_Txt(PTRMH Tree_monhoc, FILE *fileout)
{
    if (Tree_monhoc != NULL)
    {

        xuatDanhSachMonHoc_LNR_File_Txt(Tree_monhoc->pLeft, fileout);

        fputs("\n", fileout);
        fputs(Tree_monhoc->course.courceCode, fileout);
        fputs("\n", fileout);
        fputs(Tree_monhoc->course.courceName, fileout);
        fputs("\n", fileout);
        fprintf(fileout, "%d %d", Tree_monhoc->course.STCLT, Tree_monhoc->course.STCTH);

        xuatDanhSachMonHoc_LNR_File_Txt(Tree_monhoc->pRight, fileout);
    }
}
void xuatDanhSachMonHoc_File_Txt(PTRMH Tree_monhoc, char File_Name[50])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Luu file danh sach mon hoc that bai";
        return;
    }

    int so_mon_hoc_DSMH = 0;
    Reccount_MH(Tree_monhoc, so_mon_hoc_DSMH);

    fprintf(fileout, "%d", so_mon_hoc_DSMH); // in so luong vao file

    xuatDanhSachMonHoc_LNR_File_Txt(Tree_monhoc, fileout);

    fclose(fileout);
}

void xuatDanhSachSVDK_File_Txt(PTRDK First_DSSVDK, FILE *fileout)
{

    fprintf(fileout, "%d", Reccount_DSDK(First_DSSVDK));

    PTRDK p = First_DSSVDK;
    while (p != NULL)
    {
        fputs("\n", fileout);
        fputs(p->regis.studentID, fileout);
        fputs("\n", fileout);
        fprintf(fileout, "%0.6f", p->regis.point);
        fputs("\n", fileout);
        fprintf(fileout, "%d", p->regis.isRegistered);
        p = p->next;
    }
}
void xuatThongTinLopTinChi_File_Txt(Credit *loptinchi, FILE *fileout)
{
    fprintf(fileout, "%d", loptinchi->creditCode);
    fputs("\n", fileout);
    fputs(loptinchi->courseCode, fileout);
    fputs("\n", fileout);
    fputs(loptinchi->schoolYear, fileout);
    fputs("\n", fileout);
    fprintf(fileout, "%d %d %d %d", loptinchi->semester, loptinchi->group, loptinchi->studentMin, loptinchi->studentMax);
    fputs("\n", fileout);
    fprintf(fileout, "%d", loptinchi->enable);
    fputs("\n", fileout);

    xuatDanhSachSVDK_File_Txt(loptinchi->firstListRegister, fileout);
}
void xuatDanhSachLopTinChi_File_Txt(LIST_LTC dsLTC, char File_Name[maxLengthString])
{
    FILE *fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach lop tin chi that bai\n";
        system("pause");
        return;
    }

    int so_lop_hien_tai_LTC = Reccount_CreditClass(dsLTC);

    fprintf(fileout, "%d %d", so_lop_hien_tai_LTC, dsLTC.currentIndex);

    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
        {
            fputs("\n", fileout);
            xuatThongTinLopTinChi_File_Txt(dsLTC.nodes[i], fileout);
        }
    }

    fclose(fileout);
}

void xuatDanhSachSinhVien_File_Csv(PTRSV FirstSv, char File_Name[maxLengthString])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return;
    }

    PTRSV p = FirstSv;

    fprintf(fileout, "%d\n", Reccount_SV(FirstSv));
    fputs("Ma sinh vien,Ho,Ten,Gioi tinh,Ma lop,So dien thoai", fileout);

    while (p != NULL)
    {

        fputs("\n", fileout);

        fputs(p->student.studentID, fileout);
        fputs(",", fileout);
        fputs(p->student.firstName, fileout);
        fputs(",", fileout);
        fputs(p->student.name, fileout);
        fputs(",", fileout);
        fputs(p->student.sex, fileout);
        fputs(",", fileout);
        fputs(p->student.classID, fileout);
        fputs(",", fileout);

        fputs(p->student.phoneNum, fileout);

        p = p->next;
    }

    fclose(fileout);
}
void xuatDanhSachMonHoc_LNR_File_Csv(PTRMH Tree_monhoc, FILE *fileout)
{
    if (Tree_monhoc != NULL)
    {
        xuatDanhSachMonHoc_LNR_File_Csv(Tree_monhoc->pLeft, fileout);
        fputs("\n", fileout);

        fputs(Tree_monhoc->course.courceCode, fileout);
        fputs(",", fileout);
        fputs(Tree_monhoc->course.courceName, fileout);
        fputs(",", fileout);
        fprintf(fileout, "%d,%d", Tree_monhoc->course.STCLT, Tree_monhoc->course.STCTH);

        xuatDanhSachMonHoc_LNR_File_Csv(Tree_monhoc->pRight, fileout);
    }
}
void xuatDanhSachMonHoc_File_Csv(PTRMH Tree_monhoc, char File_Name[50])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Luu file danh sach mon hoc that bai";
        return;
    }

    int soLuongMonHoc = 0;

    Reccount_MH(Tree_monhoc, soLuongMonHoc); // dem so luong mon hoc
    fprintf(fileout, "%d\n", soLuongMonHoc); // in so luong vao file
    fputs("Ma mon hoc,Ten mon hoc,STCLT,STCTH", fileout);
    xuatDanhSachMonHoc_LNR_File_Csv(Tree_monhoc, fileout);

    fclose(fileout);
}
