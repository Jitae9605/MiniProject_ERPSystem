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
	today_date = ((t->tm_year + 1900)*10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	printf("%d", today_date);

	//���̺���� �� �ʱⵥ���� ����
	Create_File();
	Init_SampleData();

	//========================================= ����� ===========================================


	while (1)
	{
		char temp_insert[100];
		int Select = 0;
		printf("�԰������� �������ּ��� : \n\n");
		printf("1. �����԰�\t2. �����԰�\t3. �ڷΰ���\n");
		scanf("%d", &Select);
		//getchar();

		if (Select == 1)	// 1.�����԰�
		{
			char Select_WH[100];

			if (initalizing("D:\\1_IoT\\Server_test\\test\\WareHouse") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			print_data();
			printf("\n");

			printf("\nâ�� �������ּ��� : ");
			scanf("%s", &Select_WH);	// â���ȣ�� �Է¹���

			char select[100] = "num_warehouse=";
			strcat(select, Select_WH);

			if (_select(select, "name_warehouse, num_warehouse", &select_result_str) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			else {
				printf("%s\n\n", select_result_str);
			}
			
			
			/*if (_insert("'Warehouse1', 1999, 'SampleItem1', 19999, 20220304, 'SamplePerson1', 199, 99, 100, 0, 0, 0") == -1)
			{
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}*/
		/*	if (_insert(temp_insert) == -1)
			{
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}*/

			/*print_data();*/
			/*file_column_free();
			printf("\n");*/
		}

		else if (Select == 2)	// 2.�����԰�
		{

		}

		else if (Select == 3)	// 3.�ڷΰ���
		{
			printf("���� �޴��� ���ư��ϴ�.");
			break;
		}

		else
		{
			printf("�߸��� ���Դϴ�.\n");
		}
	}


	file_column_free();

	return 0;
}
