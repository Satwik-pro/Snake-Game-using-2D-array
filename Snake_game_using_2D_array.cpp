#include<bits/stdc++.h>
using namespace std;
char arena[1000][1000];
bool find_food(char arena[1000][1000], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(arena[i][j] == 'F')
        return 1;
    return 0;
}
int find_snake_len(char arena[1000][1000], int n)
{
    int i,j,len = 0;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(arena[i][j] == 'T' || arena[i][j] == 'H')
    len++;
    return len;
}
int find_snake_tail_i(char arena[1000][1000], int n)
{
    int i,j,ti,zeros, maxzeros = INT_MIN;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            zeros = 0;
            if(arena[i][j] == 'T')
            {
                if(i-1 < 0)
                zeros++;
                if(j-1 < 0)
                zeros++;
                if(i+1 >= n)
                zeros++;
                if(j+1 >= n)
                zeros++;
                if(i-1 < 0 && j-1 < 0)
                zeros++;
                if(i-1 < 0 && j+1 >= n)
                zeros++;
                if(i+1 >= n && j-1 < 0)
                zeros++;
                if(i+1 >= n && j+1 >= n)
                zeros++;
                if(i-1 >= 0 && j-1 >=0 && i+1 < n && j+1 < n)
                {
                    if(arena[i-1][j-1] == '0')
                    zeros++;
                    if(arena[i-1][j] == '0')
                    zeros++;
                    if(arena[i-1][j+1] == '0')
                    zeros++;
                    if(arena[i][j-1] == '0')
                    zeros++;
                    if(arena[i][j+1] == '0')
                    zeros++;
                    if(arena[i+1][j-1] == '0')
                    zeros++;
                    if(arena[i+1][j] == '0')
                    zeros++;
                    if(arena[i+1][j+1] == '0')
                    zeros++;
                }
                if(zeros > maxzeros)
                {
                    maxzeros = zeros;
                    ti = i;
                }
            }
        }
    }
    return ti;
}
int find_snake_tail_j(char arena[1000][1000], int n)
{
    int i,j,tj,zeros, maxzeros = INT_MIN;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            zeros = 0;
            if(arena[i][j] == 'T')
            {
                if(i-1 < 0)
                zeros++;
                if(j-1 < 0)
                zeros++;
                if(i+1 >= n)
                zeros++;
                if(j+1 >= n)
                zeros++;
                if(i-1 < 0 && j-1 < 0)
                zeros++;
                if(i-1 < 0 && j+1 >= n)
                zeros++;
                if(i+1 >= n && j-1 < 0)
                zeros++;
                if(i+1 >= n && j+1 >= n)
                zeros++;
                if(i-1 >= 0 && j-1 >=0 && i+1 < n && j+1 < n)
                {
                    if(arena[i-1][j-1] == '0')
                    zeros++;
                    if(arena[i-1][j] == '0')
                    zeros++;
                    if(arena[i-1][j+1] == '0')
                    zeros++;
                    if(arena[i][j-1] == '0')
                    zeros++;
                    if(arena[i][j+1] == '0')
                    zeros++;
                    if(arena[i+1][j-1] == '0')
                    zeros++;
                    if(arena[i+1][j] == '0')
                    zeros++;
                    if(arena[i+1][j+1] == '0')
                    zeros++;
                }
                if(zeros > maxzeros)
                {
                    maxzeros = zeros;
                    tj = j;
                }
            }
        }
    }
    return tj;
}
bool is_full_arena(char arena[1000][1000], int n)
{
    int i,j,len = 0;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(arena[i][j] == 'H' || arena[i][j] == 'T')
    len++;
    if(len == n*n)
    return 1;
    return 0;
}
int find_head_i(char arena[1000][1000], int n)
{
    int i,j,ti = -1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arena[i][j] == 'H')
            {
                ti = i;
                break;
            }
        }
        if(ti != -1)
        break;
    }
    return ti;
}
int find_head_j(char arena[1000][1000], int n)
{
    int i,j,tj = -1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arena[i][j] == 'H')
            {
                tj = j;
                break;
            }
        }
        if(tj != -1)
        break;
    }
    return tj;
}
int main()
{
    int n,i,j,hx=0,hy=0,score = 0;
    cout<<"Enter size of the square grid : ";
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    arena[i][j] = '0';
    arena[0][0] = 'H';
    while(1)
    {
        if(is_full_arena(arena, n))
        {
            cout<<"YOU WIN !!! :D\n";
            break;
        }
        cout<<"Current arena : \n";
        for(int xi=0;xi<n;xi++)
        {
            for(int xj=0;xj<n;xj++)
            cout<<arena[xi][xj]<<" ";
            cout<<"\n";
        }
        int x;
        cout<<"1. Continue playing ?\n2. Place food ?\n3. Exit game ?\n";
        cin>>x;
        if(x == 3)
        break;
        else if(x == 2 && find_food(arena, n) == 0)
        {
            int y,z;
            cin>>y>>z;
            if(y>=0 && y<n && z>=0 && z<n)
            {
                if(arena[y][z] == '0')
                arena[y][z] = 'F';
                else
                cout<<"You can't place the food on your snake !!\n";
            }
            else
            cout<<"Wrong Food placement !!\n";
        }
        else if(x == 2 && find_food(arena, n) == 1)
        cout<<"Food is already placed !!\n";
        else if(x!=1 && x!=2 && x!=3)
        cout<<"Wrong Input !!\n";
        else
        {
            cout<<"Which position you wanna move ?\n";
            char c;
            cin>>c;
            int i = find_head_i(arena, n);
            int j = find_head_j(arena, n);
            int ti, tj;
            if(c!='U' && c!='u' && c!='D' && c!='d' && c!='L' && c!='l' && c!='R' && c!='r')
            cout<<"Wrong move !!\n";
            else
            {
                if(c == 'U' || c == 'u')
                {
                    if(i-1 < 0)
                    {
                        cout<<" GAME OVER !! You touched the borders !!\n";
                        break;
                    }
                    else
                    {
                        if(arena[i-1][j] == 'T')
                        {
                            cout<<" GAME OVER !! You ate your tail !!\n";
                            break;
                        }
                        else if(arena[i-1][j] == 'F' && find_snake_len(arena, n) == 1)
                        {
                            ti = i;
                            tj = j;
                            arena[i][j] = 'T';
                            arena[i-1][j] = 'H';
                        }
                        else if(arena[i-1][j] == 'F')
                        {
                            arena[i][j] = 'T';
                            arena[i-1][j] = 'H';
                        }
                        else if(find_snake_len(arena, n) == 1)
                        {
                            arena[i][j] = '0';
                            arena[i-1][j] = 'H';
                        }
                        else
                        {
                            int ti = find_snake_tail_i(arena, n);
                            int tj = find_snake_tail_j(arena, n);
                            arena[ti][tj] = '0';
                            arena[i][j] = 'T';
                            arena[i-1][j] = 'H';
                        }
                    }
                }
                else if(c == 'D' || c == 'd')
                {
                    if(i+1 >= n)
                    {
                        cout<<" GAME OVER !! You touched the borders !!\n";
                        break;
                    }
                    else
                    {
                        if(arena[i+1][j] == 'T')
                        {
                            cout<<" GAME OVER !! You ate your tail !!\n";
                            break;
                        }
                        else if(arena[i+1][j] == 'F' && find_snake_len(arena, n) == 1)
                        {
                            ti = i;
                            tj = j;
                            arena[i][j] = 'T';
                            arena[i+1][j] = 'H';
                        }
                        else if(arena[i+1][j] == 'F')
                        {
                            arena[i][j] = 'T';
                            arena[i+1][j] = 'H';
                        }
                        else if(find_snake_len(arena, n) == 1)
                        {
                            arena[i][j] = '0';
                            arena[i+1][j] = 'H';
                        }
                        else
                        {
                            int ti = find_snake_tail_i(arena, n);
                            int tj = find_snake_tail_j(arena, n);
                            arena[ti][tj] = '0';
                            arena[i][j] = 'T';
                            arena[i+1][j] = 'H';
                        }
                    }
                }
                else if(c == 'L' || c == 'l')
                {
                    if(j-1 < 0)
                    {
                        cout<<" GAME OVER !! You touched the borders !!\n";
                        break;
                    }
                    else
                    {
                        if(arena[i][j-1] == 'T')
                        {
                            cout<<" GAME OVER !! You ate your tail !!\n";
                            break;
                        }
                        else if(arena[i][j-1] == 'F' && find_snake_len(arena, n) == 1)
                        {
                            ti = i;
                            tj = j;
                            arena[i][j] = 'T';
                            arena[i][j-1] = 'H';
                        }
                        else if(arena[i][j-1] == 'F')
                        {
                            arena[i][j] = 'T';
                            arena[i][j-1] = 'H';
                        }
                        else if(find_snake_len(arena, n) == 1)
                        {
                            arena[i][j] = '0';
                            arena[i][j-1] = 'H';
                        }
                        else
                        {
                            int ti = find_snake_tail_i(arena, n);
                            int tj = find_snake_tail_j(arena, n);
                            arena[ti][tj] = '0';
                            arena[i][j] = 'T';
                            arena[i][j-1] = 'H';
                        }
                    }
                }
                else if(c == 'R' || c == 'r')
                {
                    if(j+1 >= n)
                    {
                        cout<<" GAME OVER !! You touched the borders !!\n";
                        break;
                    }
                    else
                    {
                        if(arena[i][j+1] == 'T')
                        {
                            cout<<" GAME OVER !! You ate your tail !!\n";
                            break;
                        }
                        else if(arena[i][j+1] == 'F' && find_snake_len(arena, n) == 1)
                        {
                            ti = i;
                            tj = j;
                            arena[i][j] = 'T';
                            arena[i][j+1] = 'H';
                        }
                        else if(arena[i][j+1] == 'F')
                        {
                            arena[i][j] = 'T';
                            arena[i][j+1] = 'H';
                        }
                        else if(find_snake_len(arena, n) == 1)
                        {
                            arena[i][j] = '0';
                            arena[i][j+1] = 'H';
                        }
                        else
                        {
                            int ti = find_snake_tail_i(arena, n);
                            int tj = find_snake_tail_j(arena, n);
                            arena[ti][tj] = '0';
                            arena[i][j] = 'T';
                            arena[i][j+1] = 'H';
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(arena[i][j] == 'T' || arena[i][j] == 'H')
    score++;
    cout<<"Your score is : "<<score;
    return 0;
}
