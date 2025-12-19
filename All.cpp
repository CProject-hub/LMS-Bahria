#include "header.h"

using namespace std;

faculty::faculty()
	{

	//IMPORTING ACCOUNTS
	ifstream read_acc("total_acc.txt");

	int rows = 0;
	while (rows < 3)
	{
		read_acc >> acc[rows];
		rows++;
	}
	faculty_count = acc[0];
	teach_count = acc[1];
	student_count = acc[2];

		//IMPORTING TEACHER DATA
		ifstream read_teacher("teacher_data.txt");
		
		rows = 0;

		while (rows < teach_count &&
			read_teacher >> teach_data[rows][0]
			>> teach_data[rows][1]
			>> teach_data[rows][2]
			>> teach_data[rows][3]
			>> teach_data[rows][4]
			>> teach_data[rows][5]
			>> teach_data[rows][6])
		{
			rows++;
		}

		read_teacher.close();

		//IMPORTING FACULTY DATA
		ifstream read_faculty ("faculty_data.txt");

		 rows = 0;

		while (rows < faculty_count &&
			read_faculty >> faculty_id[rows][0]
			>> faculty_id[rows][1])
		{
			rows++;
		}

		read_faculty.close();

		//IMPORTING STUDENT DATA
		ifstream read_student("student_data.txt");

		 rows = 0;

		while (rows < student_count &&
			read_student >> student_data[rows][0]
			>> student_data[rows][1]
			>> student_data[rows][2]
			>> student_data[rows][3]
			>> student_data[rows][4]
			>> student_data[rows][5]
			>> student_data[rows][6])
		{
			rows++;
		}

		


	}
	
   
	int faculty::login()
	{
		string id;
		string pin;
		cout << "\n ENTER ID:";
		cin >> id;
		cout << "\n ENTER PIN: ";
		cin >> pin;

		for (int i = 0; i < faculty_count; i++)
		{
			if (id == faculty_id[i][0])
			{
				if (pin == faculty_id[i][1])
				{
					return 1;
				}
				

			}
		
		}
	}
	void faculty::write_announcement()
	{
		ofstream out("announcements.txt", ios::app);
		string msg;
		cin.ignore();
		cout << "\nEnter announcement: ";
		getline(cin, msg);
		out << msg << endl;
		out.close();
	}

	void faculty::read_announcement()
	{
		ifstream in("announcements.txt");
		string line;
		cout << "\n--- ANNOUNCEMENTS ---\n";
		while (getline(in, line))
			cout << line << endl;
		in.close();
	}

	//MANAGE TEACHER
	void faculty::diplay_teach()
	{
		cout << endl;
		for (int i = 0; i < teach_count; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << setw(15)<<teach_data[i][j] << setw(15);
			}
			cout << endl;
		}
	}
	void faculty::read_teach()
	{
		string id;
		cout << "\n ENTER ID: ";
		cin >> id;
		for (int i = 0; i < teach_count; i++)
		{
			if (id == teach_data[i][1])
			{
				cout << "\nPIN" << setw(15) << "ID" << setw(15) << "NAME" << setw(15) << "DEPARTMENT" << setw(15) << "COURSE1" << setw(15) << "COURSE2" << setw(15) << "COURSE3" << endl;

				for (int j = 0; j < 7; j++)
				{
					cout << teach_data[i][j] << setw(15);
				}
				cout << endl;
			}
		}
	}
	void faculty::add_teach()
	{
		teach_count++;
		acc[1] = teach_count;

		cout << "\n ENTER DETAILS:\n";
		cout << "PIN: ";
		cin >> teach_data[teach_count][0];
		cout << setw(15) << "ID";
		cin>> teach_data[teach_count][1];
		cout << setw(15) << "NAME";
		cin >> teach_data[teach_count][2];
		cout << setw(15) << "DEPARTMENT";
		cin >> teach_data[teach_count][3];
		cout << setw(15) << "COURSE1";
		cin >> teach_data[teach_count][4];
		cout << setw(15) << "COURSE2";
		cin >> teach_data[teach_count][5];
		cout << setw(15) << "COURSE3";
		cin >> teach_data[teach_count][6];

		//FILE UPDATE
		ofstream write_teach("teach_data.txt", ios::app);
		ofstream write("total_acc.txt");

		for (int i = 0; i < teach_count; i++) {
			for (int j = 0; j < 7; j++)
			{
				write_teach << setw(15) << teach_data[i][j] << setw(15);

			}
			write_teach << endl;
		}

		write << acc[0] << endl << acc[1] << endl << acc[2];

		write.close();
		write_teach.close();



	}
	void faculty::update_teach()
	{
		string id;
		int i,index;
		cout << "\n ENTER ID ( UPDATE ): ";
		cin >> id;
		for ( i = 0; i < teach_count; i++)
		{
			if (id == teach_data[i][1])
			{
				cout << "\nPIN" << setw(15) << "ID" << setw(15) << "NAME" << setw(15) << "DEPARTMENT" << setw(15) << "COURSE1" << setw(15) << "COURSE2" << setw(15) << "COURSE3" << endl;
				for (int j = 0; j < 7; j++)
				{
					
					cout << teach_data[i][j] << setw(15);
				}
				cout << endl;
				index = i;
			}
		}

		int choice;
		char c='n';
		do
		{
			cout << setw(15) << "\n UPDATE MENU:\n" << setw(15) << "1.PIN" << setw(15) << "2.ID" << setw(15) << "3.NAME";
			cout << setw(15) << "4.DEPARTMENT" << setw(15) << "5.COURSE1" << setw(15) << "6.COURSE2" << setw(15) << "7.COURSE3" << setw(15) << endl;
			cout << "\nOPTION:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "\n ENTER NEW PIN:";
				cin >> teach_data[index][0];
				cout << "\n UPDATED";
				break;

			case 2:
				cout << "\nENTER NEW ID: ";
				cin >> teach_data[index][1];
				cout << "\n UPDATED";

				break;

			case 3:
				cout << "\nENTER NEW NAME: ";
				cin >> teach_data[index][2];
				cout << "\n UPDATED";

				break;

			case 4:
				cout << "\nENTER NEW DEPARTMENT: ";
				cin >> teach_data[index][3];
				cout << "\n UPDATED";

				break;

			case 5:
				cout << "\nENTER NEW COURSE 1: ";
				cin >> teach_data[index][4];
				cout << "\n UPDATED";

				break;

			case 6:
				cout << "\nENTER NEW COURSE 2: ";
				cin >> teach_data[index][5];
				cout << "\n UPDATED";

				break;

			case 7:
				cout << "\nENTER NEW COURSE 3: ";
				cin >> teach_data[index][6];
				cout << "\n UPDATED";

				break;

			default:
				cout << "\nINVALID OPTION!\n";
				cout << "\n WANNA TRY AGAIN!!( Y/N ):";
				cin >> c;
			}
			
		} while (c == 'Y' || c == 'y');
		
		//FILE UPDATE
		ofstream write_teach("teacher_data.txt");

		for ( i = 0; i < teach_count; i++) {
			for (int j = 0; j < 7; j++) 
			{
				write_teach << setw(15)<<teach_data[i][j]<< setw(15);

			}
			write_teach << endl;
		}

		write_teach.close();
		
	}

	//MANAGE STUDENT
	void faculty::display_stud()
	{
		cout << endl;
		for (int i = 0; i < student_count; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << setw(15) << student_data[i][j] << setw(15);
			}
			cout << endl;
		}
	}
	void faculty::read_stud()
	{
		string enrol;
		cout << "\n ENTER ENROLLMENT: ";
		cin >> enrol;
		for (int i = 0; i < student_count; i++)
		{
			if (enrol == student_data[i][1])
			{
				cout << "\nENROLL" << setw(15) << "NAME" << setw(15) << "SEMESTER" << setw(15) << "SECTION" << setw(15) << "DEPT" << setw(15) << "FEECHALAN" << endl;
													

				for (int j = 0; j < 6; j++)
				{
					cout << student_data[i][j] << setw(15);
				}
				cout << endl;
			}
		}
	}
	void faculty::add_stud()
	{

		student_count++;
		acc[2] = student_count;
		cout << "\n ENTER DETAILS:\n";
		cout << "ENROLL: ";
		cin >> student_data[student_count-1][0];
		cout << setw(15) << "NAME";
		cin >> student_data[student_count-1][1];
		cout << setw(15) << "SEMESTER";
		cin >> student_data[student_count-1][2];
		cout << setw(15) << "SECTION";
		cin >> student_data[student_count-1][3];
		cout << setw(15) << "DEPT";
		cin >> student_data[student_count-1][4];
		cout << setw(15) << "FEECHALAN";
		cin >> student_data[student_count-1][5];
		

		//FILE UPDATE
		ofstream write_stud("student_data.txt",ios::app);
		ofstream out_acc("total_acc.txt");


		for (int i = 0; i < student_count; i++) {
			for (int j = 0; j < 6; j++)
			{
				write_stud  << student_data[i][j] << setw(15);

			}
			write_stud << endl;
		}
		out_acc << acc[0] << endl << acc[1] << endl << acc[2];
		out_acc.close();
		write_stud.close();

	}
	void faculty::update_stud()
	{
		string id;
		int i, index;
		cout << "\n ENTER ID ( UPDATE ): ";
		cin >> id;
		for (i = 0; i < student_count; i++)
		{
			if (id == student_data[i][1])
			{
				cout << "\nPIN" << setw(15) << "ID" << setw(15) << "NAME" << setw(15) << "DEPARTMENT" << setw(15) << "COURSE1" << setw(15) << "COURSE2" << setw(15) << "COURSE3" << endl;
				for (int j = 0; j < 7; j++)
				{

					cout << teach_data[i][j] << setw(15);
				}
				cout << endl;
				index = i;
			}
		}

		int choice;
		char c = 'n';
		do
		{
			cout << setw(15) << "\n UPDATE MENU:\n" << setw(15) << "1.ENROLL" << setw(15) << "2.NAME" << setw(15) << "3.SEMESTER";
			cout << setw(15) << "4.SECTION" << setw(15) << "5.DEPT" << setw(15) << "6.FEECHALAN" << endl;
			cout << "\nOPTION:";
			cin >> choice;
			switch (choice)
			{
													

			case 1:
				cout << "\n ENTER NEW ENROLL:";
				cin >> teach_data[index][0];
				cout << "\n UPDATED";
				break;

			case 2:
				cout << "\nENTER NEW NAME: ";
				cin >> teach_data[index][1];
				cout << "\n UPDATED";

				break;

			case 3:
				cout << "\nENTER NEW SEMESTER: ";
				cin >> teach_data[index][2];
				cout << "\n UPDATED";

				break;

			case 4:
				cout << "\nENTER NEW SECTION: ";
				cin >> teach_data[index][3];
				cout << "\n UPDATED";

				break;

			case 5:
				cout << "\nENTER NEW DEPT: ";
				cin >> teach_data[index][4];
				cout << "\n UPDATED";

				break;

			case 6:
				cout << "\nENTER NEW FEECHALAN: ";
				cin >> teach_data[index][5];
				cout << "\n UPDATED";

				break;
			
			default:
				cout << "\nINVALID OPTION!\n";
				cout << "\n WANNA TRY AGAIN!!( Y/N ):";
				cin >> c;
			}

		} while (c == 'Y' || c == 'y');

		//FILE UPDATE
		ofstream write_stud("student_data.txt");

		for (i = 0; i < student_count; i++) {
			for (int j = 0; j < 7; j++)
			{
				write_stud << setw(15) << student_data[i][j] << setw(15);

			}
			write_stud << endl;
		}

		write_stud.close();

	}
	void faculty::add_feechalan()
	{
		int choice;
		char op='n';
		string chalan;
		do
		{
			cout << "\n OPTIONS:\n1. ASSIGN TO ALL\t2. ASSIGN TO SPECIFIC" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "\n ENTER IN FORMAT ( EXP DATE DD/MM/YYYY, AMOUNT ): ";
				cin >> chalan;

				for (int i = 0; i < student_count; i++)
				{
					student_data[i][5] = chalan;
				}

			}
			else if (choice == 2)
			{
				cout << "\n ENTER ENROLLMENT: ";
				cin >> chalan;
				for (int i = 0; i < student_count; i++)
				{
					if (chalan == student_data[i][1])
					{

						cin >> student_data[i][5];


					}
				}
			}
			else
			{
				cout << "\n WANNA TRY AGAIN!! ( Y/N ): ";
				cin >> op;
			}
		} while (op == 'Y' || op == 'y');
		
		
		
	}



	teacher::teacher()
	{
	
	}

	string teacher::login()
	{
		string id, pin;
		cout << "\n ENTER ID:";
		cin >> id;
		cout << "\n ENTER PIN: ";
		cin >> pin;
		for (int i = 0; i <teach_count; i++)
		{
			if (id == teach_data[i][1] && pin == teach_data[i][0])
				return id;

			
		}

	}

	void teacher::show_profile(string id)
	{
		for (int i = 0; i < teach_count; i++)
		{
			if (teach_data[i][1] == id)
			{
				cout << "\nID: " << teach_data[i][1];
				cout << "\nName: " << teach_data[i][2];
				cout << "\nDepartment: " << teach_data[i][3];
				cout << "\nCourses: "
					<< teach_data[i][4] << ", "
					<< teach_data[i][5] << ", "
					<< teach_data[i][6] << endl;
			}
		}
	}

	void teacher::view_courses(string id)
	{
		for (int i = 0; i < teach_count; i++)
		{
			if (teach_data[i][1] == id)
			{
				cout << "\nAssigned Courses:\n";
				cout << teach_data[i][4] << endl;
				cout << teach_data[i][5] << endl;
				cout << teach_data[i][6] << endl;
			}
		}
	}

	void teacher::upload_marks()
	{
		ofstream out("marks.txt", ios::app);
		string enroll, course, type;
		int marks;

		cout << "\nENTER ENROLLMENT: ";
		cin >> enroll;
		cout << "COURSE: ";
		cin >> course;
		for (int i = 0; i < student_count; i++)
		{
			if (enroll == student_data[i][0])
			{
				cout << "Type (Quiz/Assignment/Paper): ";
				cin >> type;
				cout << "MARKS: ";
				cin >> marks;
				out << enroll << setw(15) << course << setw(15) << marks << setw(15) << type << endl;

			}
			
		}
		
		out.close();
	}

	void teacher::write_announcement()
	{
		faculty::write_announcement();
	}

	void teacher::read_announcement()
	{
		faculty::read_announcement();
	}



	student::student()
	{
		
	}
	
	string student::login()
	{
		string pass, enroll;
		cout << "\n ENTER ENROLLMENT: ";
		cin >> enroll;
		cout << "\n ENTER ID:";
		cin >> pass;
		
		for (int i = 0; i < student_count; i++)
		{
			if (enroll == student_data[i][0] && pass == student_data[i][6])
			{
				return enroll;
			}

		}
	}

	void student::show_profile(string enroll)
	{
		for (int i = 0; i < student_count; i++)
		{
			if (student_data[i][0] == enroll)
			{
				cout << "\nEnrollment: " << student_data[i][0];
				cout << "\nName: " << student_data[i][1];
				cout << "\nSemester: " << student_data[i][2];
				cout << "\nSection: " << student_data[i][3];
				cout << "\nDepartment: " << student_data[i][4];
			}
		}
	}

	void student::view_marks(string enroll)
	{
		ifstream in("marks.txt");
		string e, course, type;
		int marks;

		cout << "\n--- MARKS ---\n";
		while (in >> e >> course >> type >> marks)
		{
			if (e == enroll)
			{
				cout << course << " | " << type << " | " << marks << endl;
			}
		}
		in.close();
	}

	void student::read_announcement()
	{
		faculty::read_announcement();
	}




