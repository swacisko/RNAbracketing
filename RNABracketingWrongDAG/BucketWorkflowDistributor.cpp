/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BucketWorkflowDistributor.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 3:57 PM
 */

#include "BucketWorkflowDistributor.h"

BucketWorkflowDistributor::BucketWorkflowDistributor( VI jobsPerBucket) : totalNumberOfJobs(0) {
    this->buckets = jobsPerBucket.size();
    this->jobsPerBucket = jobsPerBucket;
    
    for( int a : jobsPerBucket ) totalNumberOfJobs += a;
}

BucketWorkflowDistributor::BucketWorkflowDistributor(const BucketWorkflowDistributor& orig) {
}

BucketWorkflowDistributor::~BucketWorkflowDistributor() {
    jobsPerBucket.clear();
}

PII BucketWorkflowDistributor::getIndicesOfJob(int jobNumber) {
    int p = 0;
    while( p < buckets ){
        if( jobNumber <= jobsPerBucket[p] ) return PII( p, jobNumber );
        else{
            jobNumber -= jobsPerBucket[p];
            p++;
        }
    }
    
    return PII(-1,-1); // this should not happen. It will if jobNumber is greater than total number of jobs
}
