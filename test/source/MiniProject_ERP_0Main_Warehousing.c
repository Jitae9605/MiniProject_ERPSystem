#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)



int main(void)
{
	result* _result;
	result* find;
	int result_count;
	warehouse WH;
	workuse	WU;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0; 
	today_date = ((t->tm_year + 1900)*10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	// printf("%d", today_date);

	//���̺���� �� �ʱⵥ���� ����
	Create_File();												// ���ϻ����Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )
	Init_SampleData();				// ���ϳ��ο� ��������(�ʱ�����)�� insert�ϴ� �Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )
	
	//========================================= ����� ===========================================



	while (1)
	{
		int Select_main_menu = 0;

		printf("\n ==== < ���ϴ� �޴����� > ====\n\n");
		printf("\t1. ����\n\t2. �԰�/����\n\t3. ����\n\t4.���α׷� ����\n");
		scanf("%d", &Select_main_menu);

		if (Select_main_menu == 1)
		{
			system("cls");
			int Select_make_menu = 0;
			printf("\n ==== < ���ϴ� �޴����� > ====\n\n");
			printf("\t1. ���������\n\t2. ������� �� ����ǰ�԰�\n\t3. �ڷΰ��� \n");
			scanf("%d", &Select_make_menu);

			if (Select_make_menu == 1)
			{
				while (1)
				{
					system("cls");
					int memunum, menu = 0;

					printf("\n=======================================�޴� ����===============================================\n");
					printf("                      (1)��ȸ(2)�����Ȳ���(3)����(4)������\n");
					printf("\n==================================��ȣ�� �Է����ּ���==========================================\n");
					scanf("%d", &menu);

					if (menu == 1)
					{
						system("cls");
						Print_use();
					}
					else if (menu == 2)
					{
						system("cls");
						printf("\n=======================================�޴� ����===============================================\n");
						printf("                       (1)�۾�����������Ȳ(2)��ǰ����������Ȳ\n");
						printf("\n==================================��ȣ�� �Է����ּ���==========================================\n");
						scanf("%d", &memunum);

						if (memunum == 1)	// �۾����úκ� ����
						{
							system("cls");
							By_work();
							system("pause");
						}

						else if (memunum == 2)
						{
							system("cls");
							Product();
							system("pause");

						}
					}
					else if (menu == 3)
					{
						system("cls");
						Del();
						system("pause");
					}
					else if (menu == 4)
					{
						break;
					}

				}
			}
			else if (Select_make_menu == 2)
			{
				int select;
				while (1) {
					printf("(1)�۾�������� (2)����ǰâ���԰�ó�� : ");
					scanf("%d", &select);
					switch (select) {
					case 1:
						system("cls");
						Registration_work_performance();
						break;
					case 2: 
						system("cls");
						Production_warehousing();
						break;
					default:
						break;
					}
					break;
				}
			}

			else if (Select_make_menu == 3)
			{
				break;
			}

		}

		else if (Select_main_menu == 2)
		{


			int Select = 0;
			printf(" ���ϴ� �޴�����\n");
			printf("1. ����\t2. �԰�\t3. �ڷΰ���\n");
			scanf("%d", &Select);

			if (Select == 1) // ����
			{
				while (1)
				{
					system("cls");
					int Select_balju = 0;
					printf(" ���ָ޴��Դϴ�.\n ���ϴ� �޴��� �������ּ���\n");
					printf(" 1. ���ֵ��\t2. ������ȸ\t3. ���ֻ���\t4. �ڷΰ���\n");
					scanf("%d", &Select_balju);

					if (Select_balju == 1) // 1-1.���ֵ��
					{
						system("cls");
						insertOrderData();
						system("pause");
					}
					else if (Select_balju == 2)// 1-2.������ȸ
					{
						system("cls");
						orderList();
						system("pause");

					}
					else if (Select_balju == 3) // 1-3. ���ֻ���
					{
						system("cls");
						deleteOrderData();
						system("pause");
					}
					else if (Select_balju == 4) // 1-4. �ڷΰ���
					{
						system("cls");
						break;
					}
					else
					{
						printf(" �߸��� �Է°��Դϴ�.\n");
						while (getchar() != '\n');
					}
				}
			}

			else if (Select == 2)	// �԰�
			{

				while (1)
				{
					system("cls");
					int Select_ibgo = 0;
					printf(" �԰�޴��Դϴ�.\n ���Ͻô� �޴��� �������ּ��� : \n\n");
					printf(" 1. �����԰�\t2. �����԰�\t3. �԰���Ȳ\t4. �ڷΰ���\n");
					//printf(" 1. �����԰�\t2. �����԰�\t3. �԰���Ȳ\t4. �԰����\t5. �ڷΰ���\n");
					scanf("%d", &Select_ibgo);

					if (Select_ibgo == 1)	// 2-1.�����԰�
					{
						system("cls");
						Insert_WarehousingData();
						system("pause");
					}

					else if (Select_ibgo == 2)	// 2-2.�����԰�
					{
						system("cls");
						Insert_WarehousingData_from_BuyingList();
						system("pause");
					}

					else if (Select_ibgo == 3)	// 2-3.�԰���Ȳ
					{
						system("cls");
						print_Warehousing_state();
						system("pause");

					}

					else if (Select_ibgo == 4)	// 2-4.�ڷΰ���
					{
						system("cls");
						break;
					}
					/*
					else if (Select_ibgo == 4)	// 2-4.�԰����
					{
						system("cls");
						delete_Warehousing();
					}

					else if (Select_ibgo == 5)	// 2-5.�ڷΰ���
					{
						system("cls");
						break;
					}
					*/
					else
					{
						printf(" �߸��� ���Դϴ�.\n");
						while (getchar() != '\n');
					}
				}
			}
			else if (Select == 3)	// �ڷΰ���
			{
				break;
			}

			else
			{
				printf(" �߸��� �Է°� �Դϴ�\n");
				while (getchar() != '\n');
			}
		}

		else if (Select_main_menu == 3)	// ����
		{
			while (1)
			{
				int option1, option2, option3;

				system("cls");


				printf("\t������\n");
				printf("1.�� ��� ��Ȳ 2.��� �̵� \n");
				printf("======================================\n");

				scanf("%d", &option1);

				system("cls");

				switch (option1)
				{

				case 1:
					printf("\t�� ��� ��Ȳ\n");
					printf("======================================\n");
					jaego_print();
					break;

				case 2:
					printf("\t��� ����ϱ� \n");
					printf("======================================\n");
					//����� ��� �Է� 
					// (��� ���� �˻��ؼ� �ϳ��� ������ �����Ϸ����� ���� �ϳ��� ���̱�)
					//��� 0 �̸� ���ַ� ������ �԰� ���� ����ȣ �޾Ƽ� update




					 //jogun();

					//if (jaego_item <= 0)
					//{
					//	printf("�����Ϸ� ������\n");
					//	printf("\n");

					//ibgo_jaego_print();

					//	printf("\n");
					//	printf("\n");
					//	break;
					//}

					int a = chulgo_jaego_print();
					if (a > 0)
					{
						printf("======================================\n");
						printf("�����Ϸ�������\n");
						printf("======================================\n");
						system("pause");

					}
					else
					{
						printf("======================================\n");
						printf("�����Ϸ�������\n");
						printf("======================================\n");
						insertOrderData();
					}
					//else
					//{
					//	printf("\n");
					//	printf("�����Ϸ� ������\n");
					//	printf("\n");

					break;

				default:
					break;
				}
				break;
			}
		}
		else if (Select_main_menu == 4)	// ����
		{
		exit(-1);
		}

 
		
	}

	file_column_free();
	return 0;
}