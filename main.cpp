#include <iostream>
#include <string>
#include <vector>
#include<math.h>

using namespace std;

string display();
void display_list(string n, vector<int>& list);
void enter_number(string n, vector<int>& list);
void mean(string n, vector<int>& list);
void smallest_number(string n, vector<int>& list);
void largest_nubmer(string n, vector<int>& list);
void quit(bool& is_started);



string display_menu() {

  cout << "\n-------------- Welcome --------------" << endl;;
  cout << "To display the entered numbers press 'D'" << endl;
  cout << "To add number press 'A'" << endl;
  cout << "To calculate the average of the entered numbers press 'M'" << endl;
  cout << "To find the smallest number in the list press 'S'" << endl;
  cout << "To find the largest number in the list press 'L'" << endl;
  cout << "To search for a specific number in the list press 'F'" << endl;
  cout << "To quit press 'Q'" << endl;

  string selection;
  cin >> selection;

  return selection;
}

void display_list(string n, vector<int> &list) {
  if (n == "d" || n == "D") {
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
  }
}

void enter_number(string n, vector<int> &list) {
  unsigned new_number{};
  if (n == "a" || n == "A") {
    cout << "Please enter the number you would like to add to the list: ";
    cin >> new_number;
    list.push_back(new_number);
  }

}

void mean(string n, vector<int> &list) {

  unsigned sum{};
  double avg{};
  for (auto num : list) {
    sum = sum + num;
  }
  avg = static_cast<double>(sum) / list.size();
  cout << "The average = " << avg << endl;

}

void smallest_number(string n, vector<int> &list) {
  int smallest_number{ INT_MAX };
  smallest_number = list[0];
  for (auto num : list) {
    if (num < smallest_number) {
      smallest_number = num;
    }
  }
  cout << smallest_number;
}

void largest_nubmer(string n, vector<int> &list) {
  int largest_number{ INT_MIN };
  for (int i = 0; i < list.size(); i++) {
    largest_number = list[0];
    if (list[i] > largest_number) {
      largest_number = list[i];
    }
  }
  cout << largest_number;
}

void quit(bool &is_started) {

  cout << "Thank you for trying my code. Good bye!";
  is_started = false;
}

void find_number(vector<int>& list) {
  int required_number;
  cout << "What number you want to look for?: ";
  cin >> required_number;

  for (auto num : list) {
    if (num == required_number) {
      cout << "Found! " << required_number << " is in the list." << endl;
    }
    else if (list.size() < 1) {
      cout << "List is empty." << endl;
    }
    else {
      cout << required_number << " is not in the list" << endl;
    }
  }
}


int main() {


  vector<int> list{};

  string start;
  bool is_started{ false };

  string choice_for_main;


  cout << "Do you want to start? ";
  cin >> start;

  if (start == "yes" || start == "Yes") {
    is_started = true;
  }

  while (is_started) {
    choice_for_main = display_menu();

    if (choice_for_main == "d" || choice_for_main == "D") {
      display_list(choice_for_main, list);
    }
    else if (choice_for_main == "a" || choice_for_main == "A") {
      enter_number(choice_for_main, list);
    }
    else if (choice_for_main == "m" || choice_for_main == "M") {
      mean(choice_for_main, list);
    }
    else if (choice_for_main == "s" || choice_for_main == "S") {
      smallest_number(choice_for_main, list);
    }
    else if (choice_for_main == "l" || choice_for_main == "L") {
      largest_nubmer(choice_for_main, list);
    }
    else if (choice_for_main == "f" || choice_for_main == "F") {
      find_number(list);
    }
    else if (choice_for_main == "q" || choice_for_main == "Q") {
      quit(is_started);
    }
  }



}
