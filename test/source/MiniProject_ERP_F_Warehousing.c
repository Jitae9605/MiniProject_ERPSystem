#include <stdio.h>
#include "local.h"
#include <time.h>
#include"MiniProject_ERP_struct_warehousing.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void Insert_WarehousingData_from_BuyingList(void)	// �����԰� - ���������� �ҷ��ͼ� �Է�
{
	result* _result;
	result* find;
	int result_count;
	char Select_WH[10];

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	
	char Parameter_Insert[1000] = { NULL };				// �������� _insert�Լ��� �־��� ���ڿ� (sample.c������ value�� ����)
	char temp_int[20] = { 0 };							// int���� ���ڿ��� �ٲܶ� �� �ӽ� ���ڿ�
	char Select_BuyingList_num[20] = { 0 };				// ���ֹ�ȣ �Է¹��� �ӽ� ���ڿ�����

	// â����
	if (initalizing("D:\\1_IoT\\Server_test\\test\\WareHouse") == -1) {		// â������ ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();							// â���� ���
	printf("\n");

	printf("\nâ�� �������ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_WH);					// â���ȣ�� �Է¹޾� ����
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

	// ���ָ���Ʈ ��� �� ���� �޾ƿ���
	if (initalizing("D:\\1_IoT\\Server_test\\test\\Buy_item") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	print_data();
	printf("\n");

	printf("\n���ֹ�ȣ�� �������ּ��� : ");			// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_BuyingList_num);				// â���ȣ�� �Է¹޾� ����

	char select_num_BuyList[100] = "num_BuyList=";
	strcat(select_num_BuyList, Select_BuyingList_num);

	if (_select(select_num_BuyList, "name_item, num_item, date, name_responsible, num_responsible, num_buy, bill, pay_in, tax, pay_sum, rest_num_in", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	

	// name_item
	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

	//num_item
	itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

	//date
	itoa(*(_result->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����


	//name_responsible
	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->next->next->next->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

	//num_responsible
	itoa(*(_result->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");

	// �԰���� �Է�
	int num_InWarehouse = 0;
	printf("�԰������ �Է��ϼ��� : ");
	scanf("%d", &num_InWarehouse);

	itoa(num_InWarehouse, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");
	
	// bill = �ܰ�
	int bill = *(_result->next->next->next->next->next->next->_int_data);
	itoa(bill, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");
	
	// pay_in = ���ް�
	int pay_in = num_InWarehouse * bill;
	itoa(pay_in, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");
	
	// tax = ����
	int tax = pay_in / 10;
	itoa(tax, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");
	
	// pay_sum = ���� + ���ް�
	int pay_sum = pay_in + tax;
	itoa(pay_sum, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	

	// rest_num_in (�԰����� ��)
	int rest_num_for_Warehousing_after;
	int rest_num_for_Warehousing_before = *(_result->next->next->next->next->next->next->next->next->next->next->_int_data);
	
	// rest_num_in (�԰����� ��)
	rest_num_for_Warehousing_after = rest_num_for_Warehousing_before - num_InWarehouse;


	
	printf("\n\n");
	file_column_free();
	result_free(_result, result_count);
	

	if (initalizing("D:\\1_IoT\\Server_test\\test\\In_WareHouse") == -1) {
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

	if (initalizing("D:\\1_IoT\\Server_test\\test\\Buy_item") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char update_rest_num_BuyList_before[100] = "rest_num_in=";
	char update_rest_num_BuyList_after[100] = "rest_num_in=";

	itoa(rest_num_for_Warehousing_before, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(update_rest_num_BuyList_before, temp_int);				// ��ȯ�� ���ڿ��� Parameter_Insert�� ����

	itoa(rest_num_for_Warehousing_after, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(update_rest_num_BuyList_after, temp_int);				// ��ȯ�� ���ڿ��� Parameter_Insert�� ����

	if (_update(select_num_BuyList, update_rest_num_BuyList_after) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n �԰���� ���� ���� ���� ������ %d���Դϴ�.\n", rest_num_for_Warehousing_after);
	file_column_free();

	// name_item, num_item, date, name_responsible, num_responsible, num_buy, bill, pay_in, tax, pay_sum, rest_num_in
	
}

// rest_num_in
//itoa(*(_result->next->next->next->next->next->next->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
//strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
// 
// 
//if (_insert("1, 'SampleItem1', 19999, 20220304, 'SamplePerson1', 199, 10, 1000, 10000, 1000, 11000, 100") == -1)
//{
//	printf("%s\n", err_msg);
//
//	file_column_free();
//	return -1;
//}

void Insert_WarehousingData(void)		// �����԰� - ������ �ϳ��ϳ� �Է�
{
	result* _result;
	result* find;
	int result_count;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	char Select_WH[10];
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
	scanf("%s", Select_WH);				// â���ȣ�� �Է¹޾� ����
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
	scanf("%s", Select_Item);				// â���ȣ�� �Է¹޾� ����

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
	//printf("%s", Parameter_Insert);


	// ������Է�
	if (initalizing("D:\\1_IoT\\Server_test\\test\\Person_responsibe") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();		// ����ڸ�� ���
	printf("\n");

	printf("\n����ڸ� �������ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_Person);				// â���ȣ�� �Է¹޾� ����

	char select_num_person[100] = "num_responsible=";
	strcat(select_num_person, Select_Person);

	if (_select(select_num_person, "name_responsible, num_responsible", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
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

	// printf("%s", Parameter_Insert);

	printf("\n\n");
	result_free(_result, result_count);
	file_column_free();



	// �԰����,�ܰ��Է� �� ��갪 �Է�
	int num_InWarehouse = 0;
	printf("�԰������ �Է��ϼ��� : ");
	scanf("%d", &num_InWarehouse);

	itoa(num_InWarehouse, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

	int bill = 0;
	printf("�ܰ��� �Է��ϼ��� : ");
	scanf("%d", &bill);

	itoa(bill, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

	int pay_in = bill * num_InWarehouse;

	itoa(pay_in, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

	int tax = pay_in / 10;

	itoa(tax, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

	int pay_sum = pay_in + tax;

	itoa(pay_sum, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����

	// printf("%s", Parameter_Insert);
	printf("\n\n");

	// �԰����̺� �ϼ��� �Ķ���� �Է�
	if (initalizing("D:\\1_IoT\\Server_test\\test\\In_WareHouse") == -1) {
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
}