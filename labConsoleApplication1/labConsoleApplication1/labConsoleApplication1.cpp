#include<iostream>
using namespace std;
void mainmenu();
void add();
void sale();
void display();
void calculate(int a,int y);
void buy();
struct inventory_item
{
	string  item_name;
	int item_id;
	float price_per_item;
	int qty;
	inventory_item* nptr;
};
inventory_item* fptr = NULL;
int i = 1;
void deletion(inventory_item *notetodelete);
int soaps=0;
int main()
{

	mainmenu();
	return 0;
}
void mainmenu()
{
	int op;
	cout << endl << "---------Following services are available:-------------";
	cout << endl<<"press 1. Add new Inventory Item";
	cout << endl << "press 2. Make an Inventory Sale";
	cout << endl << "press 3. Buy Inventory from Supplier";
	cout << endl << "press 4. Check Stocks";
	cout << endl << "Enter your choice";
	cin >> op;
	switch (op)
	{
	case 1:
		add();
		mainmenu();
		break;
	case 2:
		sale();
		mainmenu();
		break;
	case 3:
		buy();
		mainmenu();
		break;
	case 4:
		display();
		mainmenu();
		break;
	}
}
void add()
{
	inventory_item* ptr;
	ptr = new inventory_item;
	if (fptr == NULL)
	{
		cout << endl << "--------------Enter your data:-------------";
		cout << endl<<"Enter item name:";
		cin >> ptr->item_name;
		cout << endl << "Enter item id:";
		cin >> ptr->item_id;
		cout << endl << "Enter price per item:";
		cin >> ptr->price_per_item;
		cout << endl << "Enter quantity:";
		cin >> ptr->qty;
		soaps = ptr->qty;
		ptr->nptr = NULL;
		fptr = ptr;
    }
	else
	{
		static int value[10],count=0;
		inventory_item* currentptr = fptr;
		while (currentptr->nptr!=NULL)
		{
			currentptr = currentptr->nptr;
		}
		i++;
		cout << endl << "Enter data for " << i << " item:";
		cout << endl << "Enter item name:";
		cin >> ptr->item_name;
		cout << endl << "Enter item id:";
		cin >> ptr->item_id;
		value[count] = ptr->item_id;
		count++;
		for (int i = 0;i < count;i++)
		{
			if (value[i] == ptr->item_id)
			{
				cout << endl << "You can not enter same id for both items sorry " << endl << "Enter again";
				add();
			}
			else
			{
				cout << endl << "ID is unique continue entering data:";
				break;
			}
		}
		cout << endl << "Enter price per item:";
		cin >> ptr->price_per_item;
		cout << endl << "Enter quantity:";
		cin >> ptr->qty;
		currentptr->nptr = ptr;
		ptr->nptr = NULL;
    }
}
void  sale()
{
	int id,q;
	inventory_item* ptr;
	ptr = new inventory_item;
    inventory_item* currentptr = fptr;
	cout << endl << "__________AVAILABLE STOCK IS:__________";
	while (currentptr != NULL)
	{
		cout << endl << currentptr->item_id;
		cout << endl << currentptr->item_name;
		currentptr = currentptr->nptr;
	}
	cout << endl << "Enter id of item you want to buy:";
	cin >> id;
	cout << endl << "Enter Quantity:";
	cin >> q;
	if (q > soaps)
	{
		cout << endl << "Sorry bro stock is less than your require less your require or visit another day:";
		sale();
	}
	calculate(id,q);
	
	
	
}
void calculate(int id, int q)
{
	soaps = soaps - q;
	float price;
	inventory_item* currentptr = fptr;
	while (currentptr != NULL)
	{
		if (currentptr->item_id == id)
		{
			cout << endl <<"Item id" << currentptr->item_id;
			cout<<endl<<"Item name" << currentptr->item_name;
			price=(currentptr->price_per_item)*(float)q;
			cout << endl << "You Have Total price is:" << price;
			break;
		}
		currentptr = currentptr->nptr;
	}
	inventory_item* temp;
	temp = new  inventory_item;
	temp = currentptr;
	deletion(temp);
}
void buy()
{
	int id,q;
	inventory_item* currentptr = fptr;
	cout << endl << "Enter id:";
	cin >> id;
	cout << endl << "Enter quantity:";
	cin >> q;
	while (currentptr != NULL)
	{
		if (id == currentptr->item_id)
		{
			cout << endl << "this id already exist add stock in another id ";
			buy();
			soaps = soaps + q;
			break;
		}
		else
		{
			currentptr = currentptr->nptr;
		}
	}
}
void display()
{
	inventory_item* currentptr = fptr;
	cout << endl << "_____________WELCOME TO OUR STOCK _______________";
	while (currentptr != NULL)
	{
		cout << endl<<"Name:" << currentptr->item_name;
		cout << endl<<"ID Number:" << currentptr->item_id;
		cout << endl<<"Price of per item :" << currentptr->price_per_item;
		cout << endl <<"Quantity of item is:" << currentptr->qty;
        currentptr = currentptr->nptr;
	}
}
void deletion(inventory_item* nodetodelete)
{
	delete nodetodelete;
}