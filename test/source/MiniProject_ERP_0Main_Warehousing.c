#include <stdio.h>
#include "local.h"
#include <time.h>

#include"MiniProject_ERP_struct_warehousing.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)



int main(void)
{
	char* values = "NULL, 800, 'q', 69.11212 , 4215.134555666777";
	char* conditional = "TP='c'";
	char* set = "TP='c'";
	char* select_column = "code, number, TP, FLT, DBL";

	result* _result;
	result* find;
	int result_count;
	warehouse WH;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0; 
	today_date = ((t->tm_year + 1900)*10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// 오늘 날짜( 20220304 꼴 )

	// printf("%d", today_date);

	//테이블생성 및 초기데이터 삽입
	Create_File();					// 파일생성함수 ( MiniProject_ERP_initSampleData 에 정의 - 선언은 헤더파일 )
	Init_SampleData();				// 파일내부에 샘플정보(초기정보)를 insert하는 함수 ( MiniProject_ERP_initSampleData 에 정의 - 선언은 헤더파일 )

	//========================================= 실행부 ===========================================


	while (1)
	{
		int Select = 0;


		printf("입고유형을 선택해주세요 : \n\n");
		printf("1. 예외입고\t2. 발주입고\t3. 뒤로가기\n");
		scanf("%d", &Select);
		//getchar();

		if (Select == 1)	// 1.예외입고
		{
			Insert_WarehousingData();
		}

		else if (Select == 2)	// 2.발주입고
		{
			Insert_WarehousingData_from_BuyingList();
		}

		else if (Select == 3)	// 3.뒤로가기
		{
			printf("이전 메뉴로 돌아갑니다.");
			break;
		}

		else
		{
			printf("잘못된 값입니다.\n");
		}

	}


	// file_column_free();

	return 0;
}

//if (_insert("'Warehouse1', 1999, 'SampleItem1', 19999, 20220304, 'SamplePerson1', 199, 99, 100, 0, 0, 0") == -1)
//{
//	printf("%s\n", err_msg);
//
//	file_column_free();
//	return -1;
//}