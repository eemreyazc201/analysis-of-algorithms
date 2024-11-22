#include "tweet.h"

void bubbleSort (std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) {
    int size = tweets.size(); 

    if (ascending && sortBy == "tweetID") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].tweetID > tweets[j + 1].tweetID) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }
    } else if (ascending && sortBy == "retweetCount") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].retweetCount > tweets[j + 1].retweetCount) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }        
    } else if (ascending && sortBy == "favoriteCount") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].favoriteCount > tweets[j + 1].favoriteCount) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }        
    } else if (!ascending && sortBy == "tweetID") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].tweetID < tweets[j + 1].tweetID) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }
    } else if (!ascending && sortBy == "retweetCount") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].retweetCount < tweets[j + 1].retweetCount) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }        
    } else if (!ascending && sortBy == "favoriteCount") {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (tweets[j].favoriteCount < tweets[j + 1].favoriteCount) {
                    Tweet temp = tweets[j]; tweets[j] = tweets[j + 1]; tweets[j + 1] = temp; swapped = true;
                }
            }

            if (!swapped) {break;}
        }        
    }
}

void insertionSort (std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) {}

void merge (std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) {}

void mergeSort (std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) {}