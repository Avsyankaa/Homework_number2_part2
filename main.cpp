#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct Node {
  int znach;
  Node *next;
};
struct List {
  Node *head;
  Node *last;
};
void fill(List &list, int integer1) {
  Node *curr = new Node{integer1, nullptr};
  if (list.head == nullptr)
    list.head = curr;
  else {
    if (list.head->next == nullptr) list.head->next = curr;
    if (list.last != nullptr) list.last->next = curr;
    list.last = curr;
  }
}
void outputting(Node *&curr) {
  do {
    if (curr->next == nullptr)
      cout << curr->znach << endl;
    else
      cout << curr->znach << "->";
    curr = curr->next;
  } while (curr != nullptr);
}
void increase_count(List &list) {
  int k = 0;
  int integer1;
  string number_array;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, number_array);
  string integer_str;
  while (true) {
    for (int i = k; i < number_array.length(); i++) {
      if (number_array[i] == ' ') {
        k++;
        break;
      }
      integer_str = integer_str + number_array[i];
      k++;
    }
    if (integer_str == "") break;
    integer1 = atoi(integer_str.c_str());
    Node *curr = new Node{integer1, nullptr};
    if (list.head == nullptr) {
      list.head = list.last = curr;
    } else {
      list.last->next = curr;
      list.last = curr;
    };
    integer_str = "";
  }
}
void Menu(List &list) {
  Node *curr = nullptr;
  string exit;
  int choise;
  while ((exit != "y") && (exit != "yes") && (exit != "Y") && (exit != "Yes") &&
         (exit != "YES")) {
    cout << "Select one of the operations:" << endl;
    cout << "1.Print the list" << endl;
    cout << "2.Add items to the list" << endl;
    cout << "3.Delete item" << endl;
    cout << "4.Find positions of iteams" << endl;
    cout << "5.Replace the item on the other" << endl;
    cout << "6.Sort the list items" << endl;
    cout << "7.Сomplete the program" << endl;
    cin >> choise;
    switch (choise) {
      case 1:
        if (list.head == nullptr)
          cout << "List is empty" << endl;
        else {
          curr = list.head;
          outputting(curr);
          curr = nullptr;
        }
        break;
      case 2:
        cout << " Enter elements" << endl;
        increase_count(list);
        break;
      case 7:
        cout << "Do you want to leave program? ( yes, no )" << endl;
        cin >> exit;
        if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
            (exit == "Yes") || (exit == "YES"))
          cout << "Good by!";
        break;
    }
  }
}
int main(int argc, char *argv[]) {
  int integer1;
  List list;
  list.head = nullptr;
  list.last = nullptr;
  if (argc == 2) {
    int k = 0;
    string number_array;
    number_array = argv[1];
    string integer_str;
    while (true) {
      for (int i = k; i < number_array.length(); i++) {
        if (number_array[i] == ',') {
          k++;
          break;
        }
        integer_str = integer_str + number_array[i];
        k++;
      }
      if (integer_str == "") break;
      integer1 = atoi(integer_str.c_str());
      fill(list, integer1);
      integer_str = "";
    }
  } else {
    int n = 1;
    while (n < argc) {
      integer1 = atoi(argv[n]);
      fill(list, integer1);
      n++;
    }
  }
  Menu(list);
}
