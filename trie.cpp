*
 
Practice는 표준 입출력을 사용합니다. 
파일 입출력을 사용하지 않음에 주의하세요.
In Practice, You should use the statndard input/output
in order to receive a score properly.
Do not use file input and output. Please be very careful. 
 
*/
 
#include <stdio.h>
 
int T;
int N;
int M;
char I[1000001];
int Answer;
int A[1000001];
int B[500001];
 
// Iterate version
int f_c(int a, int b, int n)
{
    int i, c;
    c=0;
    for (i=n; i>=0; i--) {
        if (i==0) { c++; c = (c%M); break;}
        if (i==1 && ((a==0 && b==2) || (a==2 && b==0))) { c++; c = (c%M); break; }
        if (a==1 && b==0 && I[N-i+1]=='L') { a=2; b=0; continue; }
        if (a==1 && b==0 && I[N-i+1]=='P') {
            c += B[(i-1)/2];
            c = (c%M);
            a=0; b=1;
            continue;
        }
        if (a==0 && b==1 && I[N-i+1]=='L') { a=1, b=0; continue; }
        if (a==0 && b==1 && I[N-i+1]=='P') {
            c += A[i-1];
            c = (c%M);
            a=0; b=2;
            continue;
        }
        if (a==0 && b==2 && I[N-i+2]=='L') { a=2; b=0; i--; continue; }
        if (a==0 && b==2 && I[N-i+2]=='P') {
            c += B[(i-2)/2];
            c = (c%M);
            a=0; b=2; i--;
            continue;
        }
        if (a==2 && b==0 && I[N-i+2]=='L') { a=2; b=0; i--; continue; }
        if (a==2 && b==0 && I[N-i+2]=='P') {
            c += B[(i-2)/2];
            c = (c%M);
            a=0;
            b=2;
            i--;
            continue;
        }
    }
    return c;
}
 
// Recursive version
int f_b(int a, int b, int n)
{
    if (n==0) return 1;
    if (n==1 && ((a==0 && b==2) || (a==2 && b==0))) return 1;
    if (a==1 && b==0 && I[N-n+1]=='L') return f_b(2, 0, n-1);
    if (a==1 && b==0 && I[N-n+1]=='P') return (B[(n-1)/2] + f_b(0, 1, n-1))%M;
    if (a==0 && b==1 && I[N-n+1]=='L') return f_b(1, 0, n-1);
    if (a==0 && b==1 && I[N-n+1]=='P') return (A[n-1]+f_b(0, 2, n-1))%M;
    if (a==0 && b==2 && I[N-n+2]=='L') return f_b(2, 0, n-2);
    if (a==0 && b==2 && I[N-n+2]=='P') return (B[(n-2)/2]+f_b(0, 2, n-2))%M;
    if (a==2 && b==0 && I[N-n+2]=='L') return f_b(2, 0, n-2);
    if (a==2 && b==0 && I[N-n+2]=='P') return (B[(n-2)/2]+f_b(0, 2, n-2))%M;
}
 
void f_a()
{
    int i;
    A[0]=1;
    A[1]=2%M;
    B[0]=1;
    B[1]=2%M;
 
    // 2^x % M
    for (i=2; i<=N/2; i++)
        B[i]=(B[i-1]*2)%M;
 
    for (i=2; i<=N; i++) {
        A[i]=(A[i-1]+B[(i-1)/2])%M;
    }
 
    if (I[1]=='L') Answer = f_c(1, 0, N-1);
    else if (I[1]=='P') {
        Answer = (A[N-1] + f_c(0, 1, N-1))%M;
    }
}
 
int main(void)
{
    int test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using scanf function.
       You may remove the comment symbols(//) in the below statement and use it.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
     //freopen("input.txt", "r", stdin);
 
    /*
       If you remove the statement below, your program's output may not be rocorded
       when your program is terminated after the time limit.
       For safety, please use setbuf(stdout, NULL); statement.
     */
    setbuf(stdout, NULL);
 
    scanf("%d ", &T);
 
    for(test_case = 1; test_case <= T; test_case++)
    {
        int i;
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%s", &I[1]);
 
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////
        f_a();
 
        printf("#%d %d\n", test_case, Answer);
 
        // Print the answer to standard output(screen).
    }
 
    return 0;//Your program should return 0 on normal termination.
}
