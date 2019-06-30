
#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>

int main()
{
	std::fstream fs;
	fs.open("debug_lib.txt",std::ios::app);

	//目标文件夹路径
	std::string inPath = "D:\\works\\opencv\\library\\X64_Debug\\lib\\*.lib";//遍历文件夹下的所有.lib文件
	//用于查找的句柄
	long handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	do
	{
		//找到的文件的文件名
		fs << fileinfo.name << std::endl;
		printf("%s\n", fileinfo.name);

	} while (!_findnext(handle, &fileinfo));

	fs.close();

	_findclose(handle);
	system("pause");
	return 0;

}

/*

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	std::string dirPath = "E:\\test";	//文件夹路径
	cv::Directory dir;			//文件夹类对象
	std::vector<std::string> fileNames = dir.GetListFiles(dirPath, "*.bmp", false);	//获取文件夹下文件名序列
	for(size_t i = 0; i < fileNames.size(); i++)
	{
		std::string fileName = fileNames[i];			//取出当前文件名
		std::string fileFullPath = dirPath + fileName;	//获取当前文件完整路径
		std::cout << "file name: " << fileName << endl;	//打印当前文件名
		std::cout << "file paht: " << fileFullPath << endl;	//打印当前文件路径
	}
	system("pause");
	return 0;

}
*/