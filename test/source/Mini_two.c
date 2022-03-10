#include <stdio.h>
#include "local.h"
#include <time.h>
#include"Mini_plus.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void By_work(void)
{
	char* values = "NULL, 800, 'q', 69.11212 , 4215.134555666777";
	char* conditional = "TP='q'";
	char* set = "TP='c'";
	char* select_column = "code, number, TP, FLT, DBL";

	result* _result = NULL;
	result* find;
	int result_count = 0;
	workuse	WU;

	int Select = 0;
	char temp_int[20] = { 0 };
	char select_WU[100];
	char Parameter_Insert[1000] = { NULL };

	//�۾����� ���� ����
	if (initalizing("performance") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	print_data();		//������
	printf("\n");

	printf("\n�۾����ù�ȣ�� �������ּ���. : "); // �۾����� ��ȣ ���
	scanf("%s", &select_WU); 

	char select_num_work[100] = "work_order_num=";
	strcat(select_num_work, select_WU);		// ��� ����
		
	if (_select(select_num_work, "work_order_num, Product_num, Product_name,performance_num, LOT", &select_result_str) == -1) {	// ���� ����� ���� â����Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	} // �۾����ù�ȣ, ǰ��, ǰ��,�۾�������ȣ, LOT �޾ƿ�

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//Performance_number ���ù�ȣ
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->_string_data));
	strcat(Parameter_Insert, "\', ");

	//num_item
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	// name_item
	strcat(Parameter_Insert, "\'");						
	strcat(Parameter_Insert, *(_result->next->next->_string_data));	
	strcat(Parameter_Insert, "\', ");

	//Amountused ������
	int use = 0;
	printf("\n�������� �Է����ּ���.");
	scanf("%d", &use);

	itoa(use, temp_int, 10);
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ",");

	//Performanced_number
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ",");

	//LOT_NO
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->next->next->next->_string_data));
	

	printf("\n%s�� �Է��ϼ̽��ϴ�.\n", Parameter_Insert);

	if (initalizing("Work_Use") == -1) {		// �۾��� ���ڻ�� ���̺� ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert(Parameter_Insert) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	print_data();
	printf("\n\n");
	file_column_free();

	return ;
}

void Product(void)
{
	result* _result = NULL;
	result* find;
	int result_count = 0;
	workuse	WU;

	int Select = 0;
	char temp_int[20] = { 0 };
	char select_WU[100];
	char Parameter_Insert[1000] = { NULL };
	char Num_item[20] = { 0 };				//��ǰ��ȣ�� �Է¹��� ���ڿ� ����

	//�۾��������̺� ����
	if (initalizing("performance") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	print_data();		//������
	printf("\n");

	printf("\n�۾����ù�ȣ�� �������ּ���. : "); // �۾����� ��ȣ ���
	scanf("%s", &select_WU);

	char select_num_work[100] = "work_order_num=";
	strcat(select_num_work, select_WU);		// ��� ����

	if (_select(select_num_work, "work_order_num, Product_num, Product_name,indicated_quantity, LOT", &select_result_str) == -1) {	// ���� ����� ���� â����Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	} // �۾����ù�ȣ, ǰ��, ǰ��,�۾�������ȣ, LOTNO �޾ƿ�

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	//Performance_number ���ù�ȣ
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->_string_data));
	strcat(Parameter_Insert, "\', ");

	// name_item
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	//num_item
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	//���ü���
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ",");

	//LOT��ȣ
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->next->next->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	//result_free(_result, result_count);			// ����� ���� ���(�����Ҵ�)����
	file_column_free();


	//��ǰ���̺� ����
	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	print_data();				// ��ǰ ������
	printf("\n");

	printf("\n��ǰ�̸��� �Է����ּ���.");
	scanf("%s", Num_item);

	char num_item[100] = "item_NAME=";		//���ڿ� ��������
	strcat(num_item, Num_item);
	
	if (_select(num_item, " item_NAME, item_NUMBER, item_LOT", &select_result_str) == -1) {	// ���� ����� ���� â����Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	} // ��ǰ��, ��ǰ��ȣ, ��ǰlot��ȣ �޾ƿ�
	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	} //����ü ����


	//��ǰ��

	
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->_string_data));
	strcat(Parameter_Insert, "\', ");

	//��ǰ��ȣ
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	//��ǰlot�ѹ�
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->next->_string_data));
	strcat(Parameter_Insert, "\', ");


	//������
	//Amountused ������
	int use = 0;
	printf("\n�������� �Է����ּ���.");
	scanf("%d", &use);

	itoa(use, temp_int, 10);
	strcat(Parameter_Insert, temp_int);


	//��ǰ�� ����
	if (initalizing("Product_usage_status") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert(Parameter_Insert) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	printf("\n%s�� �Է��ϼ̽��ϴ�.\n", Parameter_Insert);

	print_data();
	printf("\n\n");
	file_column_free();
	
}

void Print_use(void)
{
	int two_menu = 0;
	printf("(1)��������Ȳ �۾���(2)��������Ȳ ��ǰ��\n");
	scanf("%d", &two_menu);

	if (two_menu == 1)
	{
		if (initalizing("Work_Use") == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		print_data();	
		printf("����Ϸ��� ���͸� �����ּ���~\n");
		printf("\n");
		_getch();
		file_column_free();

	}
	else if (two_menu == 2)
	{
		if (initalizing("Product_usage_status") == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		print_data();
		printf("����Ϸ��� ���͸� �����ּ���~\n");
		printf("\n");
		_getch();
		file_column_free();
		
	}

	return;
}
void Del(void)
{
	int submenu = 0;
	printf("\n===============================================================================================\n");
	printf("�����޴��Դϴ�. ������ �޴��� �������ּ���.\n");
	printf("(1)�۾��� ������ (2)��ǰ�� ������\n");
	printf("\n===============================================================================================\n");
	scanf("%d", &submenu);

	//������ ����
	if (submenu == 1)
	{
		char delnum[20] = { '\0' };

		if (initalizing("Work_Use") == -1)		//������ ���̺� ����
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		print_data();
		printf("���� �� �۾����ù�ȣ�� �Է����ּ���");
		scanf("%s", delnum);

		char conditional[26];
		sprintf(conditional, "work_order_num='%s'", delnum);		// ���ǹ�

		 if (_delete(conditional) == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		 print_data();
		 printf("\n");
		 file_column_free();

	}
	else if (submenu == 2)
	{
		char delnum[20] = { '\0' };

		if (initalizing("Product_usage_status") == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		print_data();
		printf("���� �� �۾����ù�ȣ�� �Է����ּ���");
		scanf("%s", delnum);

		char conditional[26];
		sprintf(conditional, "work_order_num='%s'", delnum);		// ���ǹ�

		if (_delete(conditional) == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		print_data();
		printf("\n");
		file_column_free();

	}
	
}