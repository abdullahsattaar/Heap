#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


class Employee
{
	int id;
	string name;
	float salary;
public:

	Employee()
	{
		id = 0;
		name = '\0';
		salary = 0;
	}

	Employee(int id, string name, float salary)
	{
		this->id = id;
		this->name = name;
		this->salary = salary;
	}

	int get_id()
	{
		return id;
	}

	string get_name()
	{
		return name;

	}

	float get_salary()
	{
		return salary;
	}

	void set_id(int id)
	{
		this->id = id;
	}

	void set_name(string name)
	{
		this->name = name;
	}

	void set_salary(float salary)
	{
		this->salary = salary;
	}

	friend ostream& operator << (ostream &out, Employee emp)
	{
		out << "id: " << emp.id << " name: " << emp.name << " salary: " << emp.salary << endl;
		return out;
	}
};

void read_employees(string file_name, vector<Employee>& emp)
{
	ifstream file;

	int num, id;
	float salary;
	string name;

	file.open(file_name);

	if (!file.is_open())
	{
		cout << " error while opening file " << endl;
	}

	file >> num;
	string input;
	for (int i = 0; i < num; i++)
	{
		// emp.push_back() /
		/*file >> id;
		file >> name;
		file >> salary;*/
		// getline(file, input, '\n'); /
		// file.getline(input, '\n'); /

		file >> id;
		file.ignore();
		getline(file, input);
		file >> salary;

		Employee temp;

		temp.set_id(id);
		temp.set_name(input);
		temp.set_salary(salary);

		emp.push_back(temp);

	}

	/*for (auto itr = emp.begin(); itr != emp.end(); ++itr)
	{
	cout << *itr;
	}*/
}

void print_employees(vector<Employee>& emp)
{
	for (auto itr = emp.begin(); itr != emp.end(); ++itr)
	{
		cout << *itr;
	}
}
void heapify(vector<Employee> &emp, int n, int i)
{
	int parent = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && emp[l].get_id() > emp[parent].get_id())
	{
		parent = l;
	}

	if (r < n && emp[r].get_id() > emp[parent].get_id())
	{
		parent = r;
	}

	if (parent != i)
	{
		swap(emp[i], emp[parent]);

		heapify(emp, n, parent);

	}
}
void max_to_min(int arr[], int n, int i)
{
	int parent = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && arr[l] < arr[parent])
	{
		parent = l;
	}

	if (r < n && arr[r] < arr[parent])
	{
		parent = r;
	}

	if (parent != i)
	{
		swap(arr[i], arr[parent]);

		max_to_min(arr, n, parent);

	}
}

void max_min(int arr[], int size)
{
	int index = size / 2 - 1;

	for (int i = index; i >= 0; i--)
	{
		max_to_min(arr, size, i);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

bool check_heap(int arr[], int index)
{
	if (index < 0)
	{
		return true;
	}
	if (arr[index] < arr[index * 2 + 1] || arr[index] < arr[index * 2 + 2])
	{
		return false;
	}
	else
	{
		check_heap(arr, index - 1);
	}

}
bool is_heap(int arr[], int size)
{
	int index = size / 2 - 1;

	/*for (int i = index; i >= 0; i--)
	{

	}*/
	bool flag = check_heap(arr, index);

	return flag;
}
void heap_sort(vector<Employee>& emp, int n)
{

	for (int i = n - 1; i >= 1; i--)
	{
		swap(emp[0], emp[i]);
		heapify(emp, i - 1, 0);
	}

}

void build_heap(vector<Employee>& emp, int n)
{
	int index = n / 2 - 1;

	for (int i = index; i >= 0; i--)
	{
		heapify(emp, n, i);
	}

	// print_employees(emp); /
}

void heapify_arr(int emp[], int n, int i)
{
	int parent = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && emp[l] > emp[parent])
	{
		parent = l;
	}

	if (r < n && emp[r] > emp[parent])
	{
		parent = r;
	}

	if (parent != i)
	{
		swap(emp[i], emp[parent]);

		heapify_arr(emp, n, parent);

	}
}

void max_heap_sort(int arr[], int n)
{

	for (int i = n - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);

		heapify_arr(arr, i - 1, 0);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int main()
{

	vector<Employee> emp;

	string file_name = "e.txt";

	read_employees(file_name, emp);

	build_heap(emp, emp.size());

	heap_sort(emp, emp.size());

	print_employees(emp);

	/*cout << emp[0];
	cout << emp[1];*/

	int arr1[9] = { 100, 19, 36, 17, 3, 25, 1, 2, 7 };
	int arr[9] = { 100, 19, 36, 17, 3, 25, 1, 2, 25 };

	bool check = is_heap(arr1, 9);
	cout << check << endl;
	check = is_heap(arr, 9);
	cout << check << endl;

	int arr2[10] = { 20, 18, 10, 12, 9, 9, 3, 5, 6, 8 };

	max_min(arr2, 10);

	int arr3[9] = { 100, 19, 36, 17, 3, 25, 1, 2, 7 };

	max_heap_sort(arr3, 9);

	system("pause");
	return 0;
}