
#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>

int main()
{
	std::fstream fs;
	fs.open("debug_lib.txt",std::ios::app);

	//Ŀ���ļ���·��
	std::string inPath = "D:\\works\\opencv\\library\\X64_Debug\\lib\\*.lib";//�����ļ����µ�����.lib�ļ�
	//���ڲ��ҵľ��
	long handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	do
	{
		//�ҵ����ļ����ļ���
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
	std::string dirPath = "E:\\test";	//�ļ���·��
	cv::Directory dir;			//�ļ��������
	std::vector<std::string> fileNames = dir.GetListFiles(dirPath, "*.bmp", false);	//��ȡ�ļ������ļ�������
	for(size_t i = 0; i < fileNames.size(); i++)
	{
		std::string fileName = fileNames[i];			//ȡ����ǰ�ļ���
		std::string fileFullPath = dirPath + fileName;	//��ȡ��ǰ�ļ�����·��
		std::cout << "file name: " << fileName << endl;	//��ӡ��ǰ�ļ���
		std::cout << "file paht: " << fileFullPath << endl;	//��ӡ��ǰ�ļ�·��
	}
	system("pause");
	return 0;

}
*/