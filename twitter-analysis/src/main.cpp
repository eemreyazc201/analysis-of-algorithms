#include "tweet.h"

int main () {    
    clock_t start, end;

    double tweets_BUBBLE_SORT;
    double tweets_INSERTION_SORT;
    double tweets_MERGE_SORT;

    double tweetsSA_BUBBLE_SORT;
    double tweetsSA_INSERTION_SORT;
    double tweetsSA_MERGE_SORT;

    double tweetsSD_BUBBLE_SORT;
    double tweetsSD_INSERTION_SORT;
    double tweetsSD_MERGE_SORT;

    double tweetsNS_BUBBLE_SORT;
    double tweetsNS_INSERTION_SORT;
    double tweetsNS_MERGE_SORT;

    double tweets5K_BUBBLE_SORT;
    double tweets5K_INSERTION_SORT;
    double tweets5K_MERGE_SORT;
    double tweets5K_BINARY_SEARCH;
    double tweets5K_COUNT_ABOVE_THRESHOLD;

    double tweets10K_BUBBLE_SORT;
    double tweets10K_INSERTION_SORT;
    double tweets10K_MERGE_SORT;
    double tweets10K_BINARY_SEARCH;
    double tweets10K_COUNT_ABOVE_THRESHOLD;

    double tweets20K_BUBBLE_SORT;
    double tweets20K_INSERTION_SORT;
    double tweets20K_MERGE_SORT;
    double tweets20K_BINARY_SEARCH;
    double tweets20K_COUNT_ABOVE_THRESHOLD;

    double tweets30K_BUBBLE_SORT;
    double tweets30K_INSERTION_SORT;
    double tweets30K_MERGE_SORT;
    double tweets30K_BINARY_SEARCH;
    double tweets30K_COUNT_ABOVE_THRESHOLD;

    double tweets50K_BUBBLE_SORT;
    double tweets50K_INSERTION_SORT;
    double tweets50K_MERGE_SORT;
    double tweets50K_BINARY_SEARCH;
    double tweets50K_COUNT_ABOVE_THRESHOLD;

    std::vector<Tweet> tweets = readTweetsFromFile("../data/permutations/tweets.csv");
    std::vector<Tweet> tweetsSA = readTweetsFromFile("../data/permutations/tweetsSA.csv");
    std::vector<Tweet> tweetsSD = readTweetsFromFile("../data/permutations/tweetsSD.csv");
    std::vector<Tweet> tweetsNS = readTweetsFromFile("../data/permutations/tweetsNS.csv");
    std::vector<Tweet> tweets5K = readTweetsFromFile("../data/sizes/tweets5K.csv");
    std::vector<Tweet> tweets10K = readTweetsFromFile("../data/sizes/tweets10K.csv");
    std::vector<Tweet> tweets20K = readTweetsFromFile("../data/sizes/tweets20K.csv");
    std::vector<Tweet> tweets30K = readTweetsFromFile("../data/sizes/tweets30K.csv");
    std::vector<Tweet> tweets50K = readTweetsFromFile("../data/sizes/tweets50K.csv");

    std::vector<Tweet> temp;

    temp = tweets; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets_BUBBLE_SORT: " << tweets_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets_INSERTION_SORT: " << tweets_INSERTION_SORT << " ms" << std::endl;
    temp = tweets; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets_MERGE_SORT: " << tweets_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/permutations/tweets.csv", temp);

    temp = tweetsSA; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweetsSA_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSA_BUBBLE_SORT: " << tweetsSA_BUBBLE_SORT << " ms" << std::endl;
    temp = tweetsSA; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweetsSA_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSA_INSERTION_SORT: " << tweetsSA_INSERTION_SORT << " ms" << std::endl; 
    temp = tweetsSA; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweetsSA_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSA_MERGE_SORT: " << tweetsSA_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/permutations/tweetsSA.csv", temp);

    temp = tweetsSD; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweetsSD_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSD_BUBBLE_SORT: " << tweetsSD_BUBBLE_SORT << " ms" << std::endl;
    temp = tweetsSD; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweetsSD_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSD_INSERTION_SORT: " << tweetsSD_INSERTION_SORT << " ms" << std::endl;
    temp = tweetsSD; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweetsSD_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsSD_MERGE_SORT: " << tweetsSD_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/permutations/tweetsSD.csv", temp);

    temp = tweetsNS; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweetsNS_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsNS_BUBBLE_SORT: " << tweetsNS_BUBBLE_SORT << " ms" << std::endl;
    temp = tweetsNS; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweetsNS_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsNS_INSERTION_SORT: " << tweetsNS_INSERTION_SORT << " ms" << std::endl;
    temp = tweetsNS; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweetsNS_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweetsNS_MERGE_SORT: " << tweetsNS_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/permutations/tweetsNS.csv", temp);

    temp = tweets5K; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets5K_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets5K_BUBBLE_SORT: " << tweets5K_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets5K; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets5K_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets5K_INSERTION_SORT: " << tweets5K_INSERTION_SORT << " ms" << std::endl;
    temp = tweets5K; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets5K_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets5K_MERGE_SORT: " << tweets5K_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/sizes/tweets5K.csv", temp);
    temp = tweets5K; mergeSort(temp, 0, temp.size() - 1, "tweetID", true); start = clock(); binarySearch(temp, 1773335, "tweetID"); end = clock(); tweets5K_BINARY_SEARCH = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets5K_BINARY_SEARCH: " << tweets5K_BINARY_SEARCH << " ms" << std::endl;
    temp = tweets5K; start = clock(); countAboveThreshold(temp, "favoriteCount", 250); end = clock(); tweets5K_COUNT_ABOVE_THRESHOLD = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets5K_COUNT_ABOVE_THRESHOLD: " << tweets5K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;

    temp = tweets10K; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets10K_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets10K_BUBBLE_SORT: " << tweets10K_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets10K; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets10K_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets10K_INSERTION_SORT: " << tweets10K_INSERTION_SORT << " ms" << std::endl;
    temp = tweets10K; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets10K_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets10K_MERGE_SORT: " << tweets10K_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/sizes/tweets10K.csv", temp);
    temp = tweets10K; mergeSort(temp, 0, temp.size() - 1, "tweetID", true); start = clock(); binarySearch(temp, 1773335, "tweetID"); end = clock(); tweets10K_BINARY_SEARCH = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets10K_BINARY_SEARCH: " << tweets10K_BINARY_SEARCH << " ms" << std::endl;
    temp = tweets10K; start = clock(); countAboveThreshold(temp, "favoriteCount", 250); end = clock(); tweets10K_COUNT_ABOVE_THRESHOLD = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets10K_COUNT_ABOVE_THRESHOLD: " << tweets10K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;

    temp = tweets20K; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets20K_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets20K_BUBBLE_SORT: " << tweets20K_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets20K; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets20K_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets20K_INSERTION_SORT: " << tweets20K_INSERTION_SORT << " ms" << std::endl;
    temp = tweets20K; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets20K_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets20K_MERGE_SORT: " << tweets20K_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/sizes/tweets20K.csv", temp);
    temp = tweets20K; mergeSort(temp, 0, temp.size() - 1, "tweetID", true); start = clock(); binarySearch(temp, 1773335, "tweetID"); end = clock(); tweets20K_BINARY_SEARCH = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets20K_BINARY_SEARCH: " << tweets20K_BINARY_SEARCH << " ms" << std::endl;
    temp = tweets20K; start = clock(); countAboveThreshold(temp, "favoriteCount", 250); end = clock(); tweets20K_COUNT_ABOVE_THRESHOLD = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets20K_COUNT_ABOVE_THRESHOLD: " << tweets20K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;

    temp = tweets30K; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets30K_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets30K_BUBBLE_SORT: " << tweets30K_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets30K; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets30K_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets30K_INSERTION_SORT: " << tweets30K_INSERTION_SORT << " ms" << std::endl;
    temp = tweets30K; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets30K_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets30K_MERGE_SORT: " << tweets30K_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/sizes/tweets30K.csv", temp);
    temp = tweets30K; mergeSort(temp, 0, temp.size() - 1, "tweetID", true); start = clock(); binarySearch(temp, 1773335, "tweetID"); end = clock(); tweets30K_BINARY_SEARCH = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets30K_BINARY_SEARCH: " << tweets30K_BINARY_SEARCH << " ms" << std::endl;
    temp = tweets30K; start = clock(); countAboveThreshold(temp, "favoriteCount", 250); end = clock(); tweets30K_COUNT_ABOVE_THRESHOLD = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets30K_COUNT_ABOVE_THRESHOLD: " << tweets30K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;

    temp = tweets50K; start = clock(); bubbleSort(temp, "retweetCount", true); end = clock(); tweets50K_BUBBLE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets50K_BUBBLE_SORT: " << tweets50K_BUBBLE_SORT << " ms" << std::endl;
    temp = tweets50K; start = clock(); insertionSort(temp, "retweetCount", true); end = clock(); tweets50K_INSERTION_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets50K_INSERTION_SORT: " << tweets50K_INSERTION_SORT << " ms" << std::endl;
    temp = tweets50K; start = clock(); mergeSort(temp, 0, temp.size() - 1, "retweetCount", true); end = clock(); tweets50K_MERGE_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets50K_MERGE_SORT: " << tweets50K_MERGE_SORT << " ms" << std::endl;
    writeTweetsToFile("../out/sizes/tweets50K.csv", temp);
    temp = tweets50K; mergeSort(temp, 0, temp.size() - 1, "tweetID", true); start = clock(); binarySearch(temp, 1773335, "tweetID"); end = clock(); tweets50K_BINARY_SEARCH = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets50K_BINARY_SEARCH: " << tweets50K_BINARY_SEARCH << " ms" << std::endl;
    temp = tweets50K; start = clock(); countAboveThreshold(temp, "favoriteCount", 250); end = clock(); tweets50K_COUNT_ABOVE_THRESHOLD = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "tweets50K_COUNT_ABOVE_THRESHOLD: " << tweets50K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;

    std::ofstream out("../out/results.txt");
    out << "tweets_BUBBLE_SORT: " << tweets_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets_INSERTION_SORT: " << tweets_INSERTION_SORT << " ms" << std::endl;
    out << "tweets_MERGE_SORT: " << tweets_MERGE_SORT << " ms" << std::endl;
    out << "tweetsSA_BUBBLE_SORT: " << tweetsSA_BUBBLE_SORT << " ms" << std::endl;
    out << "tweetsSA_INSERTION_SORT: " << tweetsSA_INSERTION_SORT << " ms" << std::endl;
    out << "tweetsSA_MERGE_SORT: " << tweetsSA_MERGE_SORT << " ms" << std::endl;
    out << "tweetsSD_BUBBLE_SORT: " << tweetsSD_BUBBLE_SORT << " ms" << std::endl;
    out << "tweetsSD_INSERTION_SORT: " << tweetsSD_INSERTION_SORT << " ms" << std::endl;
    out << "tweetsSD_MERGE_SORT: " << tweetsSD_MERGE_SORT << " ms" << std::endl;
    out << "tweetsNS_BUBBLE_SORT: " << tweetsNS_BUBBLE_SORT << " ms" << std::endl;
    out << "tweetsNS_INSERTION_SORT: " << tweetsNS_INSERTION_SORT << " ms" << std::endl;
    out << "tweetsNS_MERGE_SORT: " << tweetsNS_MERGE_SORT << " ms" << std::endl;
    out << "tweets5K_BUBBLE_SORT: " << tweets5K_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets5K_INSERTION_SORT: " << tweets5K_INSERTION_SORT << " ms" << std::endl;
    out << "tweets5K_MERGE_SORT: " << tweets5K_MERGE_SORT << " ms" << std::endl;
    out << "tweets5K_BINARY_SEARCH: " << tweets5K_BINARY_SEARCH << " ms" << std::endl;
    out << "tweets5K_COUNT_ABOVE_THRESHOLD: " << tweets5K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;
    out << "tweets10K_BUBBLE_SORT: " << tweets10K_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets10K_INSERTION_SORT: " << tweets10K_INSERTION_SORT << " ms" << std::endl;
    out << "tweets10K_MERGE_SORT: " << tweets10K_MERGE_SORT << " ms" << std::endl;
    out << "tweets10K_BINARY_SEARCH: " << tweets10K_BINARY_SEARCH << " ms" << std::endl;
    out << "tweets10K_COUNT_ABOVE_THRESHOLD: " << tweets10K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;
    out << "tweets20K_BUBBLE_SORT: " << tweets20K_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets20K_INSERTION_SORT: " << tweets20K_INSERTION_SORT << " ms" << std::endl;
    out << "tweets20K_MERGE_SORT: " << tweets20K_MERGE_SORT << " ms" << std::endl;
    out << "tweets20K_BINARY_SEARCH: " << tweets20K_BINARY_SEARCH << " ms" << std::endl;
    out << "tweets20K_COUNT_ABOVE_THRESHOLD: " << tweets20K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;
    out << "tweets30K_BUBBLE_SORT: " << tweets30K_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets30K_INSERTION_SORT: " << tweets30K_INSERTION_SORT << " ms" << std::endl;
    out << "tweets30K_MERGE_SORT: " << tweets30K_MERGE_SORT << " ms" << std::endl;
    out << "tweets30K_BINARY_SEARCH: " << tweets30K_BINARY_SEARCH << " ms" << std::endl;
    out << "tweets30K_COUNT_ABOVE_THRESHOLD: " << tweets30K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;
    out << "tweets50K_BUBBLE_SORT: " << tweets50K_BUBBLE_SORT << " ms" << std::endl;
    out << "tweets50K_INSERTION_SORT: " << tweets50K_INSERTION_SORT << " ms" << std::endl;
    out << "tweets50K_MERGE_SORT: " << tweets50K_MERGE_SORT << " ms" << std::endl;
    out << "tweets50K_BINARY_SEARCH: " << tweets50K_BINARY_SEARCH << " ms" << std::endl;
    out << "tweets50K_COUNT_ABOVE_THRESHOLD: " << tweets50K_COUNT_ABOVE_THRESHOLD << " ms" << std::endl;
    out.close();

    return 0;
}