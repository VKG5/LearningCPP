#include <cstdio>
#include <algorithm>

using namespace std;

class Job
{
public:
    int deadline, length;

    bool operator < (const Job& x) const
    {
        return deadline < x.deadline;
    }
} *jobs;

int main()
{
    // Assuming start to be at 0
    int N, i, last_finished, s=0, lateness, temp;

    scanf("%d", &N); // Number of jobs
    jobs = new Job[N];
    for (i = 0; i < N; i++) // deadline and length of each job
        scanf("%d %d", &jobs[i].deadline, &jobs[i].length);

    // sort jobs in earliest deadline first order
    sort(jobs, jobs + N);

    // print the optimal solution
    printf("Optimal schedule :\n");
    for (i = 0, last_finished = s, lateness = 0; i < N; i++)
    {
    	temp = last_finished + jobs[i].length;
    	printf("Job %d : [%d, %d]\n", i, last_finished, temp);
    	last_finished = temp;

        temp = max(last_finished - jobs[i].deadline, 0);
        if (lateness < temp)
        {
            lateness = temp;
        }
    }

    printf("Maximum lateness of schedule : %d\n", lateness);

    return 0;
}
