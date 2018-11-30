/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BucketWorkflowDistributor.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:57 PM
 */

#ifndef BUCKETWORKFLOWDISTRIBUTOR_H
#define BUCKETWORKFLOWDISTRIBUTOR_H

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;


/**
 * There are some bucket, each has certain number of elements. We identify all the elements from 1 to N. We want to get the number of bucket that contains element with given index j,
 * and the number of that the element in given bucket. E.g if we have two bucket with 3 and 5 jobs, the for j=2 we get bucket no. 0 and job no 2, for j=6 we get bucket no. 1 and job no. 3,
 */
class BucketWorkflowDistributor {
public:
    BucketWorkflowDistributor( VI jobsPerBucket);
    BucketWorkflowDistributor(const BucketWorkflowDistributor& orig);
    virtual ~BucketWorkflowDistributor();
    
    /**
     * 
     * @param jobNumber number of job
     * @return 
     */
    PII getIndicesOfJob( int jobNumber );
    
    int getTotalNumberOfJobs(){ return totalNumberOfJobs; }
private:
    
    int totalNumberOfJobs;
    int buckets;
    VI jobsPerBucket;
    

};

#endif /* BUCKETWORKFLOWDISTRIBUTOR_H */

