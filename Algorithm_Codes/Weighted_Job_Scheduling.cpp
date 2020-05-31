#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to store a Job
struct Job {
	int start, finish, profit;
};

// Function to perform binary search on the given jobs which are
// sorted by finish time. The function returns index of the last job
// which doesn't conflict with the given job i.e. whose finish time
// is less than or equal to the start time of the given job.
int findLastNonConflictingJob(vector<Job> jobs, int n)
{
	// search space
	int low = 0;
	int high = n;

	// iterate till search space is not exhausted
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (jobs[mid].finish <= jobs[n].start)
		{
			if (jobs[mid + 1].finish <= jobs[n].start)
				low = mid + 1;
			else
				return mid;
		}
		else {
			high = mid - 1;
		}
	}

	// return negative index if no non-conflicting job is found
	return -1;
}

// Function to print the non-overlapping jobs involved in maximum profit
// using Dynamic Programming
void findMaxProfitJobs(vector<Job> &jobs)
{
	// sort jobs in increasing order of their finish times
	sort(jobs.begin(),
		jobs.end(),
		[](Job &x, Job &y) {
			return x.finish < y.finish;
		});

	// get number of jobs
	int n = jobs.size();

	// maxProfit[i] stores the maximum profit possible for the first i jobs and
	// tasks[i] stores the index of jobs involved in the maximum profit
	int maxProfit[n];
	vector<int> tasks[n];

	// initialize maxProfit[0] and tasks[0] with the first job
	maxProfit[0] = jobs[0].profit;
	tasks[0].push_back(0);

	// fill tasks[] and maxProfit[] in bottom-up manner
	for (int i = 1; i < n; i++)
	{
		// find the index of last non-conflicting job with current job
		int index = findLastNonConflictingJob(jobs, i);

		// include the current job with its non-conflicting jobs
		int currentProfit = jobs[i].profit;
		if (index != -1) {
			currentProfit += maxProfit[index];
		}

		// if including the current job leads to the maximum profit so far
		if (maxProfit[i-1] < currentProfit)
		{
			maxProfit[i] = currentProfit;

			if (index != -1) {
				tasks[i] = tasks[index];
			}
			tasks[i].push_back(i);
		}

		// excluding the current job leads to the maximum profit so far
		else {
			tasks[i] = tasks[i-1];
			maxProfit[i] = maxProfit[i-1];
		}
	}

	// maxProfit[n-1] stores the maximum profit
	cout << "The maximum profit is " << maxProfit[n-1] << endl;

	// tasks[n-1] stores the index of jobs involved in the maximum profit
	cout << "The jobs involved in the maximum profit are: ";
	for (int i: tasks[n-1])
	{
		cout << "(" << jobs[i].start << ", " << jobs[i].finish << ", "
			 << jobs[i].profit << ") ";
	}
}

int main()
{
	vector <Job> jobs {
		{ 0, 6, 60 },
		{ 1, 4, 30 },
		{ 3, 5, 10 },
		{ 5, 7, 30 },
		{ 5, 9, 50 },
		{ 7, 8, 10 }
	};

	findMaxProfitJobs(jobs);

	return 0;
}
