#include "local.h"
#include"MiniProject_ERP_struct_warehousing.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void Create_File(void)
{
	// �԰����̺� ������ ����
	_create("In_WareHouse", "num_In_WareHouse INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item VARCHAR(20) LOT_number VARCHAR(20)  date INT name_responsible VARCHAR(20) num_responsible INT num_in INT bill INT pay_in INT tax INT pay_sum INT");
							// �԰����				â���̸�						â���ȣ			ǰ���					ǰ��			ǰ���Ʈ�ѹ�				��¥		����ڸ�							����ڹ�ȣ		�԰����		�ܰ�		���ް�		����		�հ��
	
	// �������̺� ������ ����
	_create("Buy_item", "num_BuyList INT name_item VARCHAR(20) num_item VARCHAR(20) LOT_number VARCHAR(20) date INT name_responsible VARCHAR(20) num_responsible INT num_buy INT bill INT pay_in INT tax INT pay_sum INT rest_num_in INT");
	//						���ֹ�ȣ			ǰ���				ǰ��			ǰ���Ʈ�ѹ�				��¥			����ڸ�						����ڹ�ȣ		���ּ���		�ܰ�		���ް���		����			�հ��			�������ּ���
	
	// �ŷ�ó���̺� ������ ����
	_create("Buy_company", "name_buy_company VARCHAR(20) num_buy_company INT");
	//							�ŷ�ó��						�ŷ�ó��ȣ
	
	// ��������̺� ������ ����
	_create("Person_responsibe", "name_responsible VARCHAR(20) num_responsible INT");
	//								����ڸ�							����ڹ�ȣ
	
	// ǰ�����̺� ������ ����
	_create("item", "name_item VARCHAR(20) num_item VARCHAR(20) State VARCHAR(20) Daily_Output INT LOT_number VARCHAR(20)");
	//				ǰ���					ǰ��			��������				���ϻ��귮		�����Ʈ�ѹ�
	
	// â������̺� ������ ����
	_create("WareHouse", "name_warehouse VARCHAR(30) num_warehouse INT");
	//						â���̸�						â���ȣ
}

void Init_SampleData(void)
{
	// �԰����̺� ���õ����� ����
	if (initalizing("In_WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("1, 'Warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220305, 'SamplePerson1', 199, 100, 990, 99000, 9900, 108900") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("2, 'Warehouse2', 2999, 'SampleItem2', 29999, 'SU00001', 20220307,  'SamplePerson1', 199, 20, 1000, 20000, 2000, 22000") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("3, 'Warehouse1', 1999, 'SampleItem1', 19999, 'PR00001', 20220301,  'SamplePerson1', 199, 100, 100, 10000, 1000, 11000") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	int num_Warehousing_List = 3;
	//print_data();
	//printf("\n");
	
	file_column_free();


	// �������̺� ���õ����� ����
	if (initalizing("Buy_item") == -1) 
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("1, 'SampleItem1', 19999, RA00001, 20220304, 'SamplePerson1', 199, 100, 1000, 10000, 1000, 11000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("2, 'SampleItem2', 29999, SU00001, 20220304, 'SamplePerson2', 299, 200, 2000, 40000, 4000, 44000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("3, 'SampleItem3', 39999, PR00001, 20220304, 'SamplePerson1', 199, 300, 3000, 90000, 9000, 99000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	
	file_column_free();


	// �ŷ�ó���̺� ���õ����� ����
	if (initalizing("Buy_company") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Buyer1', 199999") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	file_column_free();



	// ��������̺� ���õ����� ����
	if (initalizing("Person_responsibe") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson1', 199") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson2', 299") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();
	

	// ǰ�����̺� ���õ����� ����
	if (initalizing("item") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SampleItem1', 19999, RawMaterial, 0, RA00001") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SampleItem2', 29999, Subsidiary, 0, SU00001") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SampleItem3', 39999, Product, 100, PR00001") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();

	// â�����̺� ���õ����� ����
	if (initalizing("WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse1', 1999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse2', 2999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse3', 3999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	//print_data();
	//printf("\n");
	file_column_free();
	
}