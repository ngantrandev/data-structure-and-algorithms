#include "loadDataAPI.h"
#include "setDataAPI.h"
// nhap thong tin tung mon hoc tu file
Course loadCourseInfo(FILE *filein)
{
    Course monhoc;

    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly
    fgets(monhoc.courceCode, maxLengthString, filein);
    fgets(monhoc.courceName, maxLengthString, filein);
    fgets(temp_line, maxLengthString, filein);

    sscanf(temp_line, "%d %d", &monhoc.STCLT, &monhoc.STCTH);

    loaiBoDauXuongDong(monhoc.courceCode);
    loaiBoDauXuongDong(monhoc.courceName);

    return monhoc;
}
// nhap danh sach mon hoc tu file vao chuong trinh
PTRMH loadCourseList(char File_Name[maxLengthString])
{
    FILE *filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file danh sach mon hoc that bai\n";
        return;
    }

    PTRMH treeCourse = NULL;

    Course monhoc;
    int soMonHoc = 0;
    char temp_line[maxLengthString]; // chua chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &soMonHoc);

    for (int i = 1; i <= soMonHoc; i++)
    {
        monhoc = loadCourseInfo(filein);
        addCourseToList(treeCourse, monhoc);
    }

    return treeCourse;
}

Student loadStudentInfo(FILE *filein)
{
    Student sinhvien;
    fgets(sinhvien.studentID, maxLengthString, filein);
    fgets(sinhvien.firstName, maxLengthString, filein);
    fgets(sinhvien.name, maxLengthString, filein);
    fgets(sinhvien.sex, maxLengthString, filein);
    fgets(sinhvien.classID, maxLengthString, filein);
    fgets(sinhvien.phoneNum, maxLengthString, filein);

    loaiBoDauXuongDong(sinhvien.studentID);
    loaiBoDauXuongDong(sinhvien.firstName);
    loaiBoDauXuongDong(sinhvien.name);
    loaiBoDauXuongDong(sinhvien.sex);
    loaiBoDauXuongDong(sinhvien.phoneNum);
    loaiBoDauXuongDong(sinhvien.classID);

    return sinhvien;
}

// nhap danh sach sinh vien tu file vao chuong trinh
PTRSV loadStudentList(char File_Name[maxLengthString])
{
    FILE *filein = NULL;
    filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return;
    }

    PTRSV firstStudent = NULL;

    Student sinhvien;
    int soSinhVien = 0;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein); // lay thong tin so luong sinh vien
    sscanf(temp_line, "%d", &soSinhVien);

    for (int i = 1; i <= soSinhVien; i++)
    {
        sinhvien = loadStudentInfo(filein);
        addStudentToList(firstStudent, sinhvien);
    }

    return firstStudent;
}

PTRLH loadClassList(char File_Name[maxLengthString])
{
    FILE *filein = NULL;
    filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file ma lop hoc that bai\n";
        return;
    }

    PTRLH firstCourseList = NULL;
    int somaLopHoc = 0;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein); // lay thong tin so luong sinh vien
    sscanf(temp_line, "%d", &somaLopHoc);

    for (int i = 1; i <= somaLopHoc; i++)
    {
        fgets(temp_line, maxLengthString, filein);
        loaiBoDauXuongDong(temp_line);

        addNewClassID(firstCourseList, temp_line);
    }

    return firstCourseList;
}

PTRDK loadRegisStudentList(FILE *filein)
{
    PTRDK firstRegisStudent = NULL;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly
    int soSVDK = 0;
    Registration dangky;

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &soSVDK);

    for (int i = 1; i <= soSVDK; i++)
    {
        fgets(dangky.studentID, maxLengthString, filein);

        fgets(temp_line, maxLengthString, filein); // nhap dong chua DIEM
        sscanf(temp_line, "%f", &dangky.point);

        fgets(temp_line, maxLengthString, filein); // nhap dong chua bien TRUE/FALSE ( ma hoa owr dang 0 / 1);
        sscanf(temp_line, "%d", &dangky.isRegistered);

        loaiBoDauXuongDong(dangky.studentID);

        addStudentToRegisList(firstRegisStudent, dangky);
    }

    return firstRegisStudent;
}

Credit *loadCreditClassInfo(FILE *filein)
{
    Credit *creditClass = new Credit;
    char temp_line[maxLengthString];

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &creditClass->creditCode);

    fgets(creditClass->courseCode, maxLengthString, filein);
    fgets(creditClass->schoolYear, maxLengthString, filein);
    loaiBoDauXuongDong(creditClass->courseCode);
    loaiBoDauXuongDong(creditClass->schoolYear);

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d %d %d %d", &creditClass->semester, &creditClass->group, &creditClass->studentMin, &creditClass->studentMax);

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &creditClass->enable);

    creditClass->firstListRegister = loadRegisStudentList(filein);
    return creditClass;
}
// Chuc nang: nhap danh sach lop tin chi tu file vao chuong trinh
LIST_LTC loadStudentCreditClassList(char File_Name[maxLengthString])
{
    FILE *filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file danh sach lop tin chi that bai\n";
        return;
    }

    LIST_LTC creditClassList;
    char temp_line[maxLengthString];
    int index = 0;

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d %d", &creditClassList.currentIndex);

    for (int i = 1; i <= creditClassList.currentIndex; i++)
    {
        Credit *loptinchi = NULL; // cap phat bo nho cho node moi
        loptinchi = loadCreditClassInfo(filein);
        index = loptinchi->creditCode; // index store credit code
        creditClassList.nodes[index] = loptinchi;
    }

    return creditClassList;
}