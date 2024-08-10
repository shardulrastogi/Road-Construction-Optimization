/*PROGRAM IN C++ */
/// 21103226 Shardul Rastogi
/// 21103288 Abhi Srivastava
/// 21103292 Kulchandra Bhatt
/// 21103292 Anup Ghimire
#include <iostream>
#include <climits>
using namespace std;
#include <stdio.h>
int curt = 0;


int pred[20];
int max(int a[], int n)
{
    int max = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            x = i;
        }
    }
    return x;
}
#define SIZE 20

#define NUM 20


class QUEUE
{
    int front;
    int rear;
    int queue[SIZE];

public:
   
    QUEUE()
    {
        front = -1;
        rear = -1;
    }
    
    void enqueue(int a)
    {
        if (rear > SIZE)
        {
            cout << "OVERFLOW CONDITION:" << endl;
            return;
        }
        else
        {
            if (front == -1)
                front++;
            rear++;
            queue[rear] = a;
        }
    }
    
    int dequeue(void)
    {
        if (front == -1 || front > rear)
        {
            cout << "UNDERFLOW CONDITION" << endl;
        }
        else
        {
            int a = queue[front];
            front++;
            return a;
        }
    }
    
    bool IsEmpty(void)
    {
        if (front == -1 || front > rear)
            return true;
        else
            return false;
    }
    
    int pop(int a)
    {
        int x = queue[a];
        for (int i = a; i > front; i--)
        {
            queue[i] = queue[i - 1];
        }
        front++;
        return x;
    }
    
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
};

int minimum(int arr[], int n)
{
    int minu = INT_MAX;
    int minuI = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minu)
        {
            minu = arr[i];
            minuI = i;
        }
    }
    return minuI;
}

int Dijakstra(int data[NUM][NUM], int n, int start, int END)
{
    
    QUEUE Q;
  
    int distance[n];
  
    int dummy[n];
   
    for (int i = 0; i < n; i++)
    {
        Q.enqueue(i);
        distance[i] = 1000000;
        dummy[i] = 1000000;
    }
  
    bool visit[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = true;
    }
  
    dummy[start] = 0;
    distance[start] = 0;
    while (!Q.IsEmpty())
    {
        
        int Index = minimum(dummy, n);
        Q.pop(Index);
        visit[Index] = false;
   
        for (int i = 0; i < n; i++)
        {
            if (distance[i] > data[Index][i] + distance[Index])
            {
    
                distance[i] = data[Index][i] + distance[Index];
                pred[i] = Index;
            }
        }

        if (Index == END)
        {
          
            return distance[Index];
        } 
        for (int i = 0; i < n; i++)
        {
            if (visit[i])
            {
                dummy[i] = distance[i];
            }
            else
                dummy[i] = 1000000;
        }
    }
}
int main()
{
    printf("IMPLEMENTATION OF PRIORITY SCHEDULING ALGORITHM\n\n");
    int bt[100], tat[100], wt[100], ct[100], pri[100], cppri[100], dl[100], size[100], utility[100], traffic[100], prisum[100], totalsum = 0;
    int n;
    int flag = 0;
    int x, copybt[20];
    int SUMTAT = 0, SUMWT = 0;
    int path[20];
    printf("ENTER THE NUMBER OF ROADS:");
    scanf("%d", &n);
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------" << endl;
        printf("Enter The Values For Road-%d:\n", i + 1);
        cout << "--------------------------------" << endl;
      

        int data[NUM][NUM];
        for (int i = 0; i < NUM; i++)
        {
            path[i] = 0;
            for (int j = 0; j < NUM; j++)
            {
                if (i == j)
                {
                    data[i][j] = 0;
                }
                else
                    data[i][j] = 1000000;
            }
        }
    
        cout << "FORMATION OF STRUCTURE OF MAP->" << endl;
        cout << "--------------------------------" << endl;
        int Nodes;
        int Edges;
        int end2, end1, weight, END, ans;
        int start;
        cout << "ENTER NUMBER OF CITIES(NUMBER THEM FROM 0):";
        cin >> Nodes;
        cout << "ENTER NUMBER OF ROUTES:";
        cin >> Edges;
 
        for (int i = 0; i < Edges; i++)
        {
            cout << "ENTER THE ROUTE NUMBER " << i + 1 << " CITY <space> CITY <space> DISTANCE IN KM:";
            cin >> end2 >> end1 >> weight;
            if (end2 != end1 && data[end2][end1] == 1000000)
            {
                data[end2][end1] = weight;
                data[end1][end2] = weight;
            }
            else if (data[end2][end1] != 1000000)
            {
                if (data[end2][end1] > weight)
                {
                    data[end2][end1] = weight;
                    data[end1][end2] = weight;
                }
            }
        }
        /*   int data[NUM][NUM] = {
              {0,4,1000,1000,8,1000,1000,1000,1000},
              {4,0,8,1000,11,1000,1000,1000,1000},
              {1000,8,0,7,1000,1000,4,1000,2},
              {1000,1000,7,0,1000,1000,14,9,1000},
              {8,11,1000,1000,0,1,1000,1000,7},
              {1000,1000,1000,1000,1,0,2,1000,6},
              {1000,1000,4,14,1000,2,0,10,1000},
              {1000,1000,1000,9,1000,1000,10,0,1000},
              {1000,1000,2,1000,7,6,1000,1000,0},
           };*/
        /*
            QUEUE Q;
            for(int i=0;i<8;i++){
                Q.enqueue(i);
            }
            for(int i=0;i<8;i++){
                cout<<Q.pop(i)<<endl;
                Q.display();cout<<"\n";
                cout<<Q.IsEmpty()<<"\n";
            }*/
        cout << "--------------------------" << endl;
        cout << "MAP FORMED SUCCESSFULLY" << endl;
        cout << "--------------------------" << endl;
        cout << "ENTER THE START CITY FROM WHERE THE MINIMUM DISTANCE SHOULD BE FOUND:";
        cin >> start;
        cout << "ENTER THE DESTINATION CITY TO WHICH THE MINIMUM DISTANCE SHOULD BE FOUND:";
        cin >> END;
        ans = Dijakstra(data, Nodes, start, END);
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "SHORTEST PATH BETWEEN SOURCE AND DESTINATION CITY BY DIJKSTRA'S ALGORITHM->" << ans << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        size[i] = ans;
        int k = END;
        int m = 0;
        do
        {
            k = pred[k];
            path[m] = k;
            m++;
        } while (k != start);
        printf("SHORTEST PATH FOLLOWED IS:");
        for (int n = m - 1; n > -1; n--)
        {
            printf(" %d -> ", path[n]);
        }
        printf("%d", END);
        cout << "\n"
             << "------------------------------------------------------------------------------" << endl;
        printf("\nEnter Utility Of The Road(In days):\t");
        scanf("%d", &utility[i]);
        printf("Enter Traffic Of The Road(In days):\t");
        scanf("%d", &traffic[i]);
        printf("Enter Estimated Finish Time For Road(In days):\t");
        scanf("%d", &bt[i]);
        printf("Enter The Dead Line For Road(In days):\t");
        scanf("%d", &dl[i]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        prisum[i] = size[i] + utility[i] + traffic[i];
        totalsum = totalsum + prisum[i];
    }
    for (int i = 0; i < n; i++)
    {
        pri[i] = (prisum[i] * 100) / totalsum;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (pri[i] == pri[j])
                {
                    if (utility[i] > utility[j])
                    {
                        ++pri[i];
                    }
                    else if (utility[j] > utility[i])
                    {
                        ++pri[j];
                    }
                    else if (traffic[i] > traffic[j])
                    {
                        ++pri[i];
                    }
                    else if (traffic[j] > traffic[i])
                    {
                        ++pri[j];
                    }
                    else if (size[i] > size[j])
                    {
                        ++pri[i];
                    }
                    else if (size[j] > size[i])
                    {
                        ++pri[j];
                    }
                    else
                    {
                        ++pri[i];
                    }
                }
            }
        }
    }
    printf("THE OBTAINED PRIORITIES ARE:\n");
    for (int i = 0; i < n; i++)
        printf("Priority of Road%d=%d\n", i + 1, pri[i]);
    for (int i = 0; i < n; i++)
        cppri[i] = pri[i];
    for (int k = 0; k < n; k++)
    {
        x = max(pri, n);
        SUMWT += bt[x];
        ct[x] = SUMWT;
        pri[x] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = ct[i] - bt[i];
    }

    printf("HIGHER THE PRIORITY GREATER WILL BE THE PREFERENCE\n");
    printf("Solution: \n\n");
    printf("ROAD\t PRIORITY_OBTAINED    ETIMATED TIME   WAITING TIME   TOTAL TIME\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Road%d\t %d              \t%d days   \t%d days       %d days\n", i + 1, cppri[i], bt[i], wt[i], ct[i]);
    }
    SUMTAT = 0;
    SUMWT = 0;
    for (int i = 0; i < n; i++)
    {
        SUMTAT = SUMTAT + ct[i];
        SUMWT = SUMWT + wt[i];
    }
    printf("\n\nAverage TURNAROUND TIME = %d days\n", SUMTAT / n);
    printf("Average WAITING TIME = %d days\n\n", SUMWT / n);

    for (int i = 0; i < n; i++)
    {
        if (dl[i] < ct[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("DEADLINE NEEDS TO BE COMPROMISED\n");
    }
    else
        printf("NO PROBLEMS WITH THE SEQUENCE:\n");
    for (int i = 0; i < n; i++)
    {
        x = max(cppri, n);
        printf("Road%d,", x + 1);
        cppri[x] = -1;
    }
    printf("\n\n");
    printf("IMPLEMENTATION OF BANKER'S ALGORITHM\n");
    int m, i, j, k;
  
    printf("\nENTER NUMBER OF ROADS:");
    scanf("%d", &n);
    printf("\nENTER NUMBER OF RESOURCES:");
    scanf("%d", &m);
    int alloc[n][m];
    printf("\nENTER VALUES FOR ALLOCATION MATRIX:");
    for (int i = 0; i < n; i++)
    {
        printf("\nENTER VALUES OF ALLOCATION FOR ROAD R%d:", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    int max[n][m];
    printf("\nENTER VALUES FOR MAXIMUM NEED MATRIX:");
    for (int i = 0; i < n; i++)
    {
        printf("\nENTER VALUES OF MAXIMUM NEED FOR ROAD R%d:", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    int avail[m];
    printf("\nENTER VALUES FOR AVAILABILITY:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
   
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    printf("\nNEED MATRIX:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d,", need[i][j]);
        }
        printf("\n");
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
             
                if (flag == 0)
                {
                   
                    ans[ind++] = i;
                    printf("\nR%d is allocated\n", i);
                    printf("\nAvailability is:");
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                        printf("%d,", avail[y]);
                    }
                    printf("\n");
                    f[i] = 1;
                }
            }
        }
    }
   
    if (ind == n)
    {
        printf("SAFE Sequence Exists Which Is:\n");
        for (i = 0; i < n - 1; i++)
            printf(" R%d ->", ans[i]);
        printf(" R%d\n", ans[n - 1]);
    }
  
    else
        printf("SAFE Sequence Does Not Exist\n");
    return (0);
}
