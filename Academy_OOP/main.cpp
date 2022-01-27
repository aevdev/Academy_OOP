#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual std::ostream& print(std::ostream& os = cout)const
	{
		return os << last_name << " " << first_name << " " << age << " years" << endl;
	}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		os.left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age;
		return os;
	}
	virtual ifstream& scan(ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}

ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.scan(is);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os.width(25);
		os << speciality;
		os.width(10);
		os << group;
		os.width(5);
		os << rating;
		os.width(10);
		os << attendance;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality >> group >> rating >> attendance;
		return is;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//				Constructor
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//					Methods
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os.width(25);
		os << speciality;
		os.width(10);
		os << experience;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality >> experience;
		return is;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//						Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//						Methods:
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Student::print(os) << " ";
		os.width(10);
		os << subject;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Student::scan(is);
		is >> subject;
		return is;
	}

};

Human* HumanFactory(const string& type)
{
	if (type.find("Student") != std::string::npos) return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos) return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}
//Resharper

//#define INHERITANCE_CHECK
//#define SAVE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Connor", "John", 18);
	human.print();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
	stud.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();

	Graduate grad("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How to catch Heizenberg");
	grad.print();
#endif // INHERITANCE_CHECK

#ifdef SAVE_TO_FILE
	//int arr[] = { 3,5,8,13,21 };
//Generalisation (up-cast)
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How to catch Heizenberg"),
		new Student("Vercetti", "Tomas", 30, "City business", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 55, "Weapons distribution", 30),
		new Student("Montana", "Antonio", 30, "Cryminalistic", "Vice", 90, 80)
	};

	cout << sizeof(group)/*/sizeof(Human*)*/ << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;//TRRI - Runtime Type Information
		group[i]->print();
		cout << "\n-----------------------------------------------\n";
	}

	ofstream fout("file.txt");
	for (int i = 0; i < sizeof(group) / sizeof(Human*); ++i)
	{
		fout.left;
		fout.width(25);
		fout << string(typeid(*group[i]).name()) + ":";
		fout << *group[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");

	////////////////////////////////////////
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // SAVE_TO_FILE

	Human** group = nullptr;
	int n = 0;

	ifstream fin("file.txt");
	if (fin.is_open())
	{
		string human_type;
		for (; !fin.eof(); ++n)
		{
			getline(fin, human_type);
		}
		n--;

		group = new Human*[n] {};

		fin.clear();
		fin.seekg(0);

		for (int i = 0; i < n; ++i)
		{
			getline(fin, human_type, ':');
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
	}
	else
	{
		cerr << "Error: File not found!";
	}

	for (int i = 0; i < n; ++i)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		delete[] group[i];
	}
	delete[] group;
	fin.close();
}