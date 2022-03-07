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

	// printf("%d", today_date);

	//���̺���� �� �ʱⵥ���� ����
	Create_File();					// ���ϻ����Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )
	Init_SampleData();				// ���ϳ��ο� ��������(�ʱ�����)�� insert�ϴ� �Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )

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
			char Select_Item[100];
			char Select_Person[100];
			char Parameter_Insert[1000] = { NULL };
			char temp_int[20] = { 0 };

			
			// â����
			if (initalizing("D:\\1_IoT\\Server_test\\test\\WareHouse") == -1) {		// â������ ����
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			print_data();				// â���� ���
			printf("\n");

			printf("\nâ�� �������ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
			scanf("%s", &Select_WH);				// â���ȣ�� �Է¹޾� ����
													// ex) 1999�� �Է��� = [Select_WH = 1999](���ڿ����� ����)

			char select_num_warehouse[100] = "num_warehouse=";		
			strcat(select_num_warehouse, Select_WH);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
														// ex) ������� [select_num_warehouse = num_warehouse=1999]
			if (_select(select_num_warehouse, "name_warehouse, num_warehouse", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}


			if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}


			strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
			strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
			strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

																	// ex) ������� [Parameter_Insert = 'warehouse1', ]
				
			itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
			strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
			strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

																	// ex) ������� [Parameter_Insert = 'warehouse1', 1999, ]

			printf("\n\n");
			result_free(_result, result_count);
			file_column_free();
			

			//ǰ����
			if (initalizing("D:\\1_IoT\\Server_test\\test\\item") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			print_data();		// ǰ���� ���
			printf("\n");

			printf("\nǰ���� �������ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
			scanf("%s", &Select_Item);				// â���ȣ�� �Է¹޾� ����

			char select_num_item[100] = "num_item=";
			strcat(select_num_item, Select_Item);
			
			if (_select(select_num_item, "name_item, num_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}


			if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
			strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
			strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

																	// ex) ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', ]

			itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
			strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
			strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����
																	
																	// // ex) ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', 19999, ]
			// printf("%s", Parameter_Insert);

			printf("\n\n");
			result_free(_result, result_count);
			file_column_free();


			// ��¥�Է�
			itoa(today_date, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
			strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
			strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����
			printf("%s", Parameter_Insert);


			// ������Է�
			if (initalizing("D:\\1_IoT\\Server_test\\test\\Person_responsibe") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			
			print_data();		// ����ڸ�� ���
			printf("\n");

			printf("\n����ڸ� �������ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
			scanf("%s", &Select_Person);				// â���ȣ�� �Է¹޾� ����

			char select_num_person[100] = "num_responsible=";
			strcat(select_num_person, Select_Person);
			
			if (_select(select_num_item, "name_responsible, num_responsible", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}


			if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
			strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
			strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

																	// ex) ������� [Parameter_Insert = 'warehouse1' ]

			itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
			strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
			strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

			printf("%s", Parameter_Insert);

			printf("\n\n");
			result_free(_result, result_count);
			file_column_free();
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