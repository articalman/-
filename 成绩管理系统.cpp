
#include <bits/stdc++.h> // ����ͷ�ļ�
using namespace std;
int amount = 0; // ����
struct student{
    string name; //����
    double num; //ѧ��
    double Math;
    double Chineses;
    double English;
    double Major; // רҵ�γɼ�
    double sum;   // ����sum�ֶ� �� ���سɼ���
    student *next;
};

void InitList(student *&L); // �����ʼ��
inline void Next(student *&p, student *&pr);
// ���������������ظ�ʹ����������Ĵ���
inline void forDelete(student *&p , student *&pr , int &flag);
// ����������Ϊɾ�������ṩɾ��������
void Ins(student *&L, int n);       // ���뺯��
void Display(student *L);           // �������
void Destroy(student *&L);          // �������������ս�㣬����ռ��˷�
void Delete(student *&L, double num , int n);    // ɾ������������ѧ��/�ɼ�
void Delete(student *&L, string s);    //ɾ���������أ���������ɾ��
void show(student *p); //���modify��������ʾ�޸ĺ�Ľ��
void modify(student *&L, double n);    // �޸ĺ����������޸ļ�¼��ֵ
void IsExcellent(student *&L);    // ���Ҹ���>90������ѧ�� �����
void PassOrnot(student *&L);     // ��ʾ�������������
void exchange(student *&p, student *&pr);  // ��������������sort����ʹ�� 
void Sort(student *&L, int n); // �����������ܷ�����n=1���� n=0����
void Menu();  // ��ӡϵͳ����
void about();  //��ʾ����ҳ��

int main(){
    student *head;
    InitList(head);
    system("title ѧ���ɼ�����ϵͳV2.0");//���ÿ���̨����
    system("color 0B");// ���ÿ���̨��ɫ��������ɫ��������ɫ
    int n, m;
    
    while (1){ //����ϵͳ��ִ�в���
        Menu();
        cout << "��������Ҫ���еĲ�����";
        cin >> m;
        switch (m){
            case 0:{
                system("cls");
                about();
                break;
            }
            case 1:{
                system("cls");
                cout << "���������������� ";
                cin >> n;
                if (n < 0){
                    cout << "\n��������\n";
                }else{
                    Ins(head, n);
                    cout << "\n¼�����" << endl;
                    Display(head);
                }
                break;
            }
            case 2:{ // ����ѡ��ɾ���ķ�ʽ
                system("cls");
                cout << "��ѡ��ɾ���ķ�ʽ��\n";
                cout << "1.����\n";
                cout << "2.ѧ��\n";
                cout << "3.����\n";
                cout << "4.��ѧ\n";
                cout << "5.Ӣ��\n";
                cout << "6.רҵ��\n";
                cout << "7.�ܳɼ�" << endl;
                cin >> n;
                if(n == 1){ // name��string���͵ģ���Ҫ��������
                    string s; 
                    cout << "�õģ���Ҫ�������Ӧ��ѧ��������";
                    cin >> s;
                    Delete(head,s);
                }else if(n > 1 && n <= 6){
                    double n1;
                    cout << "�õģ���Ҫ�������Ӧ��ѧ��ѧ�Ż�ɼ���";
                    cin >> n1;
                    Delete(head,n1,n);
                }else{
                    cout << "\nɾ��ʧ�ܣ���������Ч������\n";
                }
                cout << "ɾ������Ϊ��" << endl;
                Display(head);
                break;
            }
            case 3:{
                system("cls");
                cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
                cin >> n;
                modify(head, n);
                break;
            }
            case 4:{
                system("cls");
                Display(head);
                break;
            }
            case 5:{
                system("cls");
                PassOrnot(head);
                break;
            }
            case 6:{
                system("cls");
                IsExcellent(head);
                break;
            }
            case 7:{
                system("cls");
                cout << "����������ʽ��\n";
                cout << "1���� 0����\n";
                cin >> n;
                if(n != 0 && n != 1)
                    break;
                Sort(head,n);
                Display(head);
                break;
            }
            default:{
                exit(0);
            }
        }
        char ch;
        cout << endl;
        cout << "----------------------------------------------------------\n";
        cout << "                      �Ƿ����(y/n)��";
        cin >> ch;
        if (ch == 'y'){
            system("cls");
            continue;
        }
        else
            exit(0); // �˳�ѭ�����������
    }
    Destroy(head);
    system("pause");
    return 0;
}

void InitList(student *&L){
    L = new student;
    L->next = NULL;
}
inline void Next(student *&p, student *&pr){
    pr = p; // ���������������ظ�ʹ����������Ĵ���
    p = p->next;
}
inline void forDelete(student *&p , student *&pr ,int &flag){
    pr->next = p->next; // ����һ��������ӵ�ǰһ�����
    //delete[]p;
    amount--;
    flag = 1;
}
void Ins(student *&L, int n){         // ����β�巨ʵ��
    student *p = L->next, *pr = L; //pr����ֵ����������׽���ʱ��ѭ������ִ��
    while (p != NULL){
        Next(p, pr);
    } // ��λ������ĩβ
    while (n--){
        student *p1 = new student;
        string name;
        double chinese, math, english, major,num;
        cout << "������ѧ����Ϣ ��" << endl;
        cout << "����    ѧ��    ����    ��ѧ    Ӣ��   רҵ��" << endl;
        cin >> name >> num >> chinese >> math >> english >> major;
        if (chinese < 0 || chinese > 100 || math < 0 || math > 100 ||
            english < 0 || english > 100 || major < 0 || major > 100)
        {  // ���������޶����� 0<�ɼ�<100 
            cout << "\n��ȷ���������ݵ���ȷ�ԣ�\n";
            break;
        }
        amount++;

        p1->name = name;
        p1->num = num;
        p1->Chineses = chinese;
        p1->English = english;
        p1->Math = math;
        p1->Major = major;
        p1->sum = p1->Chineses + p1->English + p1->Major + p1->Math;

        pr->next = p1; // ��ǰ��Ľڵ�����
        //pr = p1;   // ָ��ǰ�ڵ�
        pr = pr->next; //ָ���̽��
        p1->next = NULL;
        puts(""); //������п��Ƹ�ʽ
    }
}
void Display(student *L){
    if (L->next == NULL){
        cout << "�ɼ�����ϵͳΪ��" << endl;
    }
    while (L->next != NULL){
        L = L->next;
        cout << "����    ѧ��    ����    ��ѧ    Ӣ��   רҵ��    �ܳɼ�" << endl;
        cout << L->name;
        printf("\t%.lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t\n", L->num, L->Chineses, L->Math, L->English, L->Major,L->sum);
    }
    cout << "\n�����������ƣ�" << amount << "��\n";
}
void Destroy(student *&L){
    student *p = L->next, *pr = L;
    while (p != NULL){
        Next(p, pr);
        delete[] pr;
    }
    //delete[] p;
}
void Delete(student *&L, double num , int n){
    // num��ʾ���ݵ�ֵ  ����n��ѡ��ִ���Ĳ��ж�
    student *p = L->next, *pr = L;
    int flag = 0; // �жϱ�־
    if (p == NULL)
        cout << "\nѧ������û���κ�ѧ����¼��\n";
    else{
        while (p != NULL){
            switch (n){
                case 2:{
                    if (p->num == num){  
                        forDelete(p,pr,flag);
                        break; // breakֻ���ڱ��ʽ�ڣ����ܷ�����������
                    }
                }
                case 3:{
                    if (p->Chineses == num){
                        forDelete(p,pr,flag);
                        break; 
                    }
                }
                case 4:{
                    if (p->Math == num){
                        forDelete(p, pr,flag);
                        break;
                    }
                }
                case 5:{
                    if (p->English == num){
                        forDelete(p, pr, flag);
                        break;
                    }
                }
                case 6:{
                    if (p->Major == num){
                        forDelete(p, pr, flag);
                        break;
                    }
                }
                case 7:{
                    if (p->sum == num){
                        forDelete(p , pr , flag);
                        break;
                    }
                }
                default:{ //��ʵ�ڲ�����������ǰ���Ѿ��жϹ��ˣ����Բ���д
                    break;
                }
            }
            Next(p, pr); // ����ָ���̽ڵ�
        }
    }
    if (p == NULL && flag == 0)
        cout << "��Ǹ�����޴���" << endl;
}
void Delete(student *&L, string s){
    student *p = L->next, *pr = L;
    if (p == NULL)
        cout << "\nѧ������û���κ�ѧ����¼��\n";
    else
    {
        while (p != NULL)
        {
            if (p->name == s)
            {
                pr->next = p->next; // ����һ��������ӵ�ǰһ�����
                //delete[]p;
                amount--;
                break;
            }
            Next(p, pr); // ����ָ���̽ڵ�
        }
    }
    if (p == NULL)
        cout << "��Ǹ�����޴���" << endl;
}
void show(student *p){ // ��ӡ�޸ĺ�Ľ��
    cout << "\n�޸ĳɹ�!\n�޸ĺ�ĳɼ�Ϊ��" << endl;
    cout << "����    ѧ��    ����    ��ѧ    Ӣ��   רҵ��    �ܳɼ�" << endl;
    cout << p->name;
    printf("\t%.lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t\n", p->num, p->Chineses, p->Math, p->English, p->Major,p->sum);
}
void modify(student *&L, double n){
    student *p = L->next, *pr = L;
    while (p != NULL){
        if (p->num == n){
            cout << "\nѧ�š���>n\nChinese����>c\nMath����>m\nEnglish����>e\nMajor����>M" << endl;
            cout << "\n��ѡ���޸ĵ����ԣ�";
            char ch;
            double grade,num;
            cin >> ch;
            cout << "�������޸ĺ�ĳɼ�/ѧ�ţ�";
            if (ch == 'n'){
                cin >> num;
            }else{
                cin >> grade;
            }
            switch (ch){
                case 'n':{
                    p->num = num;
                    show(p);
                    break;
                }
                case 'c':{
                    p->Chineses = grade;
                    show(p); //���ú�����ӡ�޸ĺ�Ľ��
                    break;
                }
                case 'm':{
                    p->Math = grade;
                    show(p);
                    break;
                }
                case 'e':{
                    p->English = grade;
                    show(p);
                    break;
                }
                case 'M':{
                    p->Major = grade;
                    show(p);
                    break;
                }
                default:{
                    cout << "\n�޸�ʧ�ܣ���������Ч�ļ�ֵ��" << endl;
                    break;
                }
            }
        }
        Next(p, pr);
    }
}
void IsExcellent(student *&L){
    student *p = L->next, *pr = L;
    int flag = 0;
    while(p != NULL){
        if(p->Chineses >= 90 && p->English >= 90 && p->Major >= 90 && p->Math >= 90){
            cout << "ѧ��Ϊ" << p->num << "��" << p->name << "ͬѧ��һ��������\n";
            printf("���ģ�%.2lf\t��ѧ��%.2lf\tӢ�%.2lf\tרҵ�Σ�%.2lf\t�ܳɼ�:%.2lf\t\n", p->Chineses, p->Math, p->English, p->Major,p->sum);
            flag = 1;
        }
        Next(p,pr);
    }
    if(flag == 0)
        cout << "һ����û�������ѧ��Ҳ̫�Ѵ��˰�\n";
}
void PassOrnot(student *&L){
    student *p = L->next, *pr = L;
    int flag = 1; // �ж�ѧ��������ı��
    while(p != NULL){
        if(p->Chineses < 60){
            flag = 0;
            cout << p->name << "�����ĳɼ��ǣ�" << p->Chineses << ",���ϸ�\n";
        }
        if(p->English < 60){
            flag = 0;
            cout << p->name << "��Ӣ��ɼ��ǣ�" << p->English << ",���ϸ�\n";
        }
        if(p->Major < 60){
            flag = 0;
            cout << p->name << "��רҵ�γɼ��ǣ�" << p->Major << ",���ϸ�\n";
        }
        if(p->Math < 60){
            flag = 0;
            cout << p->name << "����ѧ�ɼ��ǣ�" << p->Math << ",���ϸ�\n";
        }
        Next(p, pr);
    }
    if(p == NULL && flag == 1)
        cout << "����ѧ���������㣬�ٽ�������\n";
}
void exchange(student *&p , student *&pr){
    student *t = new student;
    t->next = NULL;
    t->Chineses = p->Chineses;
    t->English = p->English;
    t->Major = p->Major;
    t->Math = p->Math;
    t->name = p->name;
    t->num = p->num;
    t->sum = p->sum;

    p->Chineses = pr->Chineses;
    p->English = pr->English;
    p->Major = pr->Major;
    p->Math = pr->Math;
    p->name = pr->name;
    p->num = pr->num;
    p->sum = pr->sum;

    pr->Chineses = t->Chineses;
    pr->English = t->English;
    pr->Major = t->Major;
    pr->Math = t->Math;
    pr->name = t->name;
    pr->num = t->num;
    pr->sum = t->sum;

    //delete [] t; t�Ѿ�ָ���˱�ĵط�������ϵͳ�ͷţ��ֶ��ͷŻ���ɶ���ͷŵ��³���
}
void Sort(student *&L , int n){  // ����ð������
    student *pr = L->next , *p; //����ͷ�ڵ㣬���׽ڵ㿪ʼ
    while(pr != NULL){
        p = pr->next; // pʼ��ָ��pr���¸��ڵ� 
        while (p != NULL){  //���κͺ�̽ڵ�Ƚ�
            if(n == 1){   // ����
                if(pr->sum > p->sum){
                    exchange(pr,p);
                }
            }else if(n == 0){ //����
                if(pr->sum < p->sum){
                    exchange(pr,p);
                }
            }
            p = p->next;
        }
        pr = pr->next;
    }
}
void Menu(){
    cout << "\n\n";
    cout << "\t\t\t\t��ӭʹ�óɼ�����ϵͳ\n";
    cout << "\t*******************************************************************\n";
    cout << "\t*                        1.�ɼ�¼��                               *\n";
    cout << "\t*                        2.ɾ��ѧ����¼                           *\n";
    cout << "\t*                        3.�޸�ѧ����¼                           *\n";
    cout << "\t*                        4.��ӡ��¼                               *\n";
    cout << "\t*                        5.��ʾ��������                           *\n";
    cout << "\t*                        6.��������ѧ��                           *\n";
    cout << "\t*                        7.���ɼ�����                             *\n";
    cout << "\t*                        *.�˳�ϵͳ                               *\n";
    cout << "\t*                        0.����                                   *\n";
    cout << "\t*                                                                 *\n";
    cout << "\t*                                   								 *\n";
    cout << "\t*******************************************************************\n";
    cout << "��ѡ������ķ�ʽ" << endl;
    cout << "1.�ֶ�����    2.�ļ�����\n";
    int f;
    cin >> f;
    if (f == 2) //�������2����1.txt���ı��ж���������(����ǰ׼��)
        freopen("1.txt", "r", stdin);
}

