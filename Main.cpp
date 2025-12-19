#include "header.h"


int main()
{
	int role,inv=0;
	faculty f;
	do
	{
		cout << "\n===== LMS SYSTEM =====";
		cout << "\n1. Faculty";
		cout << "\n2. Teacher";
		cout << "\n3. Student";
		cout << "\nSelect Role: ";
		cin >> role;

		if (role == 1)
		{
			
			int choice;
			int i = f.login();
			if (i == 1)
			{
				inv = 1;
				do
				{
					cout << "\n--- FACULTY MENU ---";
					cout << "\n1. View Announcements";
					cout << setw(15) << "\t2. Write Announcement";
					cout << setw(15) << "\t3. Display Teachers";
					cout << setw(15) << "\n4. Read Teacher";
					cout << setw(15) << "\t5. Add Teachers";
					cout << setw(15) << "\n6. Update Teachers";
					cout << setw(15) << "\t7. Display Students";
					cout << setw(15) << "\t8. Read Student";
					cout << "\n9. Add Student";
					cout << setw(15) << "\t10. Update Student";
					cout << setw(15) << "\n11. Add Feechalan";
					cout << setw(15) << "\n0. Logout";
					cout << "\nChoice: ";
					cin >> choice;

					switch (choice)
					{
					case 1:
						f.read_announcement();
						break;
					case 2:
						f.write_announcement();
						break;
					case 3:
						f.diplay_teach();
						break;
					case 4:
						f.read_teach();
						break;
					case 5:
						f.add_teach();
						break;
					case 6:
						f.update_teach();
						break;
					case 7:
						f.display_stud();
						break;
					case 8:
						f.read_stud();
						break;
					case 9:
						f.add_stud();
						break;
					case 10:
						f.update_stud();
						break;
					case 11:
						f.add_feechalan();
						break;
					case 0:
						cout << "\nLogging out...\n";
						break;
					default:
						cout << "\nInvalid option!\n";
					}

				} while (choice != 0);
			}
			else
				cout << "\n INVALID PASSWORD!! ";

		}

		else if (role == 2)
		{
			teacher t;
			int choice;
			string id = t.login();
			if (!(id == "0"))
			{
				inv = 1;
				do
				{
					cout << "\n--- TEACHER MENU ---";
					cout << "\n1. View Profile";
					cout << "\n2. View Assigned Courses";
					cout << "\n3. Upload Marks";
					cout << "\n4. Read Announcements";
					cout << "\n5. Write Announcement";
					cout << "\n0. Logout";
					cout << "\nChoice: ";
					cin >> choice;

					switch (choice)
					{
					case 1:
						t.show_profile(id);
						break;
					case 2:
						t.view_courses(id);
						break;
					case 3:
						t.upload_marks();
						break;
					case 4:
						t.read_announcement();
						break;
					case 5:
						t.write_announcement();
						break;
					case 0:
						cout << "\nLogging out...\n";
						break;
					default:
						cout << "\nInvalid option!\n";
					}

				} while (choice != 0);
			}
			else
				cout << "\n INCORRECT PASSWORD!!!";


		}

		else if (role == 3)
		{
			student s;
			string enroll = s.login();
			if (!(enroll == "0"))
			{
				int choice;
				inv = 1;

				do
				{
					cout << "\n--- STUDENT MENU ---";
					cout << "\n1. View Profile";
					cout << "\n2. View Marks";
					cout << "\n3. Read Announcements";
					cout << "\n0. Logout";
					cout << "\nChoice: ";
					cin >> choice;

					switch (choice)
					{
					case 1:
						s.show_profile(enroll);
						break;
					case 2:
						s.view_marks(enroll);
						break;
					case 3:
						s.read_announcement();
						break;
					case 0:
						cout << "\nLogging out...\n";
						break;
					default:
						cout << "\nInvalid option!\n";
					}

				} while (choice != 0);
			}

		}

		else
		{
			cout << "\nInvalid role selection!\n";
			
		}

}while (inv == 0);
	

	return 0;
}