#include "tweet.h"
 
int binarySearch (const std::vector<Tweet>& tweets, long long key, const std::string& sortBy) {
    int head = 0; int tail = tweets.size() - 1;

    if (sortBy == "tweetID") {
        while (head <= tail) {
            int mid = (head + tail) / 2;
            if (tweets[mid].tweetID == key) {return mid;}
            else if (tweets[mid].tweetID < key) {head = mid + 1;}
            else if (tweets[mid].tweetID > key) {tail = mid - 1;}
        }
    } else if (sortBy == "retweetCount") {
        while (head <= tail) {
            int mid = (head + tail) / 2;
            if (tweets[mid].retweetCount == key) {return mid;}
            else if (tweets[mid].retweetCount < key) {head = mid + 1;}
            else if (tweets[mid].retweetCount > key) {tail = mid - 1;}
        }
    } else if (sortBy == "favoriteCount") {
        while (head <= tail) {
            int mid = (head + tail) / 2;
            if (tweets[mid].favoriteCount == key) {return mid;}
            else if (tweets[mid].favoriteCount < key) {head = mid + 1;}
            else if (tweets[mid].favoriteCount > key) {tail = mid - 1;}
        }
    }

    return -1;    
}

int countAboveThreshold (const std::vector<Tweet>& tweets, const std::string& metric, int threshold) {
    int count = 0; int size = tweets.size();
    
    if (metric == "retweetCount") {
        for (int i = 0; i < size; i++) {if (tweets[i].retweetCount > threshold) {count++;}}
    } else if (metric == "favoriteCount") {
        for (int i = 0; i < size; i++) {if (tweets[i].favoriteCount > threshold) {count++;}}
    }

    return count;
}