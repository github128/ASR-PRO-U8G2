# ASR-PRO-U8G2
修改 asr_pro_sdk\projects\cwsl_sample\project_file\source_file.prj 添加 U8G2的源文件 头文件
在D:\天问Block\asrpro\asr_pro_sdk\U8G2 下添加U8G2文件夹及内容
引脚定义 VCC->VCC GND->GND 
PA
#define MOSI 5
#define SCK 6
#define DC 3
#define CS 2

在终端打开 ./rebuild 

make生成的文件地址为D:\天问Block\asrpro\asr_pro_sdk\projects\cwsl_sample\project_file\build
