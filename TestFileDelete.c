/**********************************************************************
* 版权所有 (C)2014, Zhou Zhaoxiong。
* 
* 文件名称： TestFileDelete.c
* 内容摘要： 用于演示Linux下过期文件的删除
* 其它说明： 无
* 当前版本： V1.0
* 作    者： Zhou Zhaoxiong
* 完成日期： 20140811
* 
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 数据类型
typedef unsigned char     UINT8;
typedef unsigned int      UINT32;
typedef signed   int      INT32;


/*---------------------------------------------------------------
* 功能描述: 主函数
* 输入参数: 无
* 输出参数: 无
* 返  回  值: 0-执行结束
* 其他说明: 无
* 修改日期      版本号      修改人        修改内容
* ---------------------------------------------------------------
* 20140811     V1.0     Zhou Zhaoxiong     创建
-----------------------------------------------------------------*/
INT32 main()
{
    UINT8   szCmdBuf[1024]           = {0};             // 用于存放Linux命令
    UINT8   szLocalFileSaveDir[1000] = {0};             // 用于存放本地目录  
    UINT32  iFileSaveDays            = 10;              // 文件保留天数, 可由配置项决定, 这里设为0


    memcpy(szLocalFileSaveDir, "/home/zhouzx/TestDir", strlen("/home/zhouzx/TestDir"));      // 文件的存放路径
    
    // 注意该删除命令的格式
    snprintf(szCmdBuf, sizeof(szCmdBuf) - 1, "find %s -name \"*.txt\" -ctime +%d -exec rm -f {} \\;", szLocalFileSaveDir, iFileSaveDays);       
    printf("Delete the file(s), exec: %s\n", szCmdBuf);


    system(szCmdBuf);          // 执行删除命令
    
    return 0;
}
