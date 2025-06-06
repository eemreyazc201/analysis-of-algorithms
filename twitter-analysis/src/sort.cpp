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

void insertionSort (std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) {
    int size = tweets.size(); 

    if (ascending && sortBy == "tweetID") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].tweetID > tweets[i-1].tweetID) {continue;} else if (tweets[0].tweetID > tweets[i].tweetID) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].tweetID <= tweets[i].tweetID && tweets[mid+1].tweetID >= tweets[i].tweetID) {index = mid + 1; break;}
                    else if (tweets[mid+1].tweetID < tweets[i].tweetID) {head = mid + 1;}
                    else if (tweets[mid].tweetID > tweets[i].tweetID) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    } else if (ascending && sortBy == "retweetCount") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].retweetCount > tweets[i-1].retweetCount) {continue;} else if (tweets[0].retweetCount > tweets[i].retweetCount) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].retweetCount <= tweets[i].retweetCount && tweets[mid+1].retweetCount >= tweets[i].retweetCount) {index = mid + 1; break;}
                    else if (tweets[mid+1].retweetCount < tweets[i].retweetCount) {head = mid + 1;}
                    else if (tweets[mid].retweetCount > tweets[i].retweetCount) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    } else if (ascending && sortBy == "favoriteCount") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].favoriteCount > tweets[i-1].favoriteCount) {continue;} else if (tweets[0].favoriteCount > tweets[i].favoriteCount) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].favoriteCount <= tweets[i].favoriteCount && tweets[mid+1].favoriteCount >= tweets[i].favoriteCount) {index = mid + 1; break;}
                    else if (tweets[mid+1].favoriteCount < tweets[i].favoriteCount) {head = mid + 1;}
                    else if (tweets[mid].favoriteCount > tweets[i].favoriteCount) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    } else if (!ascending && sortBy == "tweetID") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].tweetID < tweets[i-1].tweetID) {continue;} else if (tweets[0].tweetID < tweets[i].tweetID) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].tweetID >= tweets[i].tweetID && tweets[mid+1].tweetID <= tweets[i].tweetID) {index = mid + 1; break;}
                    else if (tweets[mid+1].tweetID > tweets[i].tweetID) {head = mid + 1;}
                    else if (tweets[mid].tweetID < tweets[i].tweetID) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    } else if (!ascending && sortBy == "retweetCount") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].retweetCount < tweets[i-1].retweetCount) {continue;} else if (tweets[0].retweetCount < tweets[i].retweetCount) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].retweetCount >= tweets[i].retweetCount && tweets[mid+1].retweetCount <= tweets[i].retweetCount) {index = mid + 1; break;}
                    else if (tweets[mid+1].retweetCount > tweets[i].retweetCount) {head = mid + 1;}
                    else if (tweets[mid].retweetCount < tweets[i].retweetCount) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    } else if (!ascending && sortBy == "favoriteCount") {
        for (int i = 1; i < size; i++) {
            if (tweets[i].favoriteCount < tweets[i-1].favoriteCount) {continue;} else if (tweets[0].favoriteCount < tweets[i].favoriteCount) {
                Tweet temp = tweets[i]; for (int j = i; j > 0; j--) {tweets[j] = tweets[j - 1];} tweets[0] = temp;
            } else {
                int head = 0; int tail = i - 1; int index; while (head <= tail) {
                    int mid = (head + tail) / 2;
                    if (tweets[mid].favoriteCount >= tweets[i].favoriteCount && tweets[mid+1].favoriteCount <= tweets[i].favoriteCount) {index = mid + 1; break;}
                    else if (tweets[mid+1].favoriteCount > tweets[i].favoriteCount) {head = mid + 1;}
                    else if (tweets[mid].favoriteCount < tweets[i].favoriteCount) {tail = mid;}
                }

                Tweet temp = tweets[i]; for (int j = i; j > index; j--) {tweets[j] = tweets[j-1];} tweets[index] = temp;
            }
        }
    }
}

void merge (std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) {
    int size1 = mid - left + 1; int size2 = right - mid; 
    Tweet* arrL = new Tweet[size1];
    Tweet* arrR = new Tweet[size2];

    for (int i = 0; i < size1; i++) {arrL[i] = tweets[left + i];}
    for (int i = 0; i < size2; i++) {arrR[i] = tweets[mid + 1 + i];}
    
    int it1 = 0; int it2 = 0; int writer = left; 

    if (ascending && sortBy == "tweetID") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].tweetID <= arrR[it2].tweetID) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }
    } else if (ascending && sortBy == "retweetCount") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].retweetCount <= arrR[it2].retweetCount) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }    
    } else if (ascending && sortBy == "favoriteCount") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].favoriteCount <= arrR[it2].favoriteCount) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }    
    } else if (!ascending && sortBy == "tweetID") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].tweetID >= arrR[it2].tweetID) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }    
    } else if (!ascending && sortBy == "retweetCount") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].retweetCount >= arrR[it2].retweetCount) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }    
    } else if (!ascending && sortBy == "favoriteCount") {
        while (it1 < size1 && it2 < size2) {
            if (arrL[it1].favoriteCount >= arrR[it2].favoriteCount) {
                tweets[writer++] = arrL[it1++];
            } else {
                tweets[writer++] = arrR[it2++];
            }
        }    
    }

    while (it1 < size1) {tweets[writer++] = arrL[it1++];}
    while (it2 < size2) {tweets[writer++] = arrR[it2++];}

    delete [] arrL; delete [] arrR;
}

void mergeSort (std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) {
    if (left >= right) {return;}
    int mid = (left + right) / 2;
    mergeSort(tweets, left, mid, sortBy, ascending);
    mergeSort(tweets, mid + 1, right, sortBy, ascending);
    merge(tweets, left, mid, right, sortBy, ascending);
}