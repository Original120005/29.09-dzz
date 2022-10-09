
#include <conio.h>
#include <iostream>
#include "Header.h"

using namespace std;

void Insert(Tree& tree)
{
    system("cls");
    cout << "¬ведите количество элементов дл€ добавлени€: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "¬ведите английское слово" << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "¬ведите русское слово " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu() {
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6. Save file\n7. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "¬ведите англиское слово дл€ удалени€:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "¬ведите английское слово дл€ поиска:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "—лово не найдено" << endl;
    }

    _getch();
}

void Edit(Tree& tree) {
    system("cls");

    char buffer[15];
    cout << "¬ведите какое слово вы хотите изменить: ";
    cin >> buffer;
    Node* node = tree.Search(tree.GetRoot(), buffer);

    Node* temp = new Node;
    cout << endl << "¬ведите новое английское слово " << endl;
    cin >> temp->GetEnglish();
    cout << endl << "¬ведите новое русское слово " << endl;
    cin >> temp->GetRussian();

    tree.Edit(temp);
}

void SaveFile(Tree& tree) {
    system("cls");

    Node* temp = tree.GetRoot();
    Node* node = tree.GetRoot();
    char buffer[15];

    FILE* fp;
    fp = fopen("", "");

    int count = 0;
    cout << "¬ведите количество слов: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "¬ведите слово: ";
        cin >> buffer;
        node = tree.Search(tree.GetRoot(), buffer);

        fputs(node->m_english, fp);
        fputs(" - ", fp);
        fputs(node->m_russian, fp);
        fputs("\n", fp);
    }
    getc(fp);

    cout << "‘айл сохранен" << endl;
    _getch();
}