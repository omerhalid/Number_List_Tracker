#include <iostream>
#include <vector>

using namespace std;


int main() {

  vector<int> list{};

  string start;
  bool is_started{ false };

  unsigned new_number{};
  unsigned sum{};
  double avg{};
  int smallest_number{ INT_MAX };
  int largest_number{INT_MAX};

  cout << "Do you want to start? ";
  cin >> start;

  if (start == "yes" || start == "Yes") {
    is_started = true;
  }

  while (is_started) {
    char selection{};

    cout << "\n-------------- Welcome --------------" << endl;;
    cout << "To display the entered numbers press 'D'" << endl;
    cout << "To add number press 'A'" << endl;
    cout << "To calculate the average of the entered numbers press 'M'" << endl;
    cout << "To find the smallest number in the list press 'S'" << endl;
    cout << "To find the largest number in the list press 'L'" << endl;
    cout << "To quit press 'Q'" << endl;
    cin >> selection;

    switch (selection) {
    case'd':
    case'D':
      if (list.size() < 1) {
        cout << "The list is empty, please add numbers!" << endl;
      }
      else {
        cout << "\nThe list = [ ";
        for (auto num : list) {
          cout << num << " ";
        }
        cout << "]";
      }
      break;
    case'a':
    case'A':
      cout << "Please enter the number you would like to add to the list: ";
      cin >> new_number;
      list.push_back(new_number);
      break;
    case'm':
    case'M':
      for (auto num : list) {
        sum = sum + num;
      }
      avg = static_cast<double>(sum) / list.size();
      cout << "The average = " << avg << endl;
      break;
    case's':
    case'S':
      smallest_number = list[0];
      for (auto num : list) {
        if (num < smallest_number) {
          smallest_number = num;
        }
      }
      cout << "The smallest number: " << smallest_number << endl;
      break;
    case'l':
    case'L':
      for (int i = 0; i < list.size();i++) {
        largest_number = list[0];
        if (list[i] > largest_number) {
          largest_number = list[i];
        }
      }
      cout << "The largest number = " << largest_number << endl;
      break;
    case'q':
    case'Q':
      cout << "Thank you for trying my code. Good bye!";
      is_started = false;
    }

  }

    

}
