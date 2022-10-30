static bool mycmp(Job a, Job b){

        return a.profit > b.profit;

    }

    

    vector<int> JobScheduling(Job arr[], int n) 

    { 


        sort(arr,arr+n,mycmp);

        

        int maxDeadline=0;

        for(int i=0;i<n;i++){

            maxDeadline=max(maxDeadline,arr[i].dead);

        }

        

        bool vacant[maxDeadline+1]={false};

        

        int maxprofit=0;

        int count=0;

        

        for(int i=0;i<n;i++){

                for(int j=arr[i].dead;j>=1;j--){

                    if(vacant[j]==false){

                        vacant[j]=true;

                        maxprofit+=arr[i].profit;

                        count+=1;

                        break;

                    }

                }

        }

        

        vector<int> v;

        v.push_back(count);

        v.push_back(maxprofit);

        return v;

        

    } 
