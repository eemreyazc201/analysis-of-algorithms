#include "tweet.h"

std::vector<Tweet> readTweetsFromFile (const std::string& filename) {
    std::vector<Tweet> tweets; std::ifstream file (filename); if (file.is_open()) {
        std::string line; std::getline(file, line); while (std::getline(file, line)) {
            std::stringstream ss (line); int tweetID, retweet_count, favorite_count;
            ss >> tweetID; ss.ignore(1, ','); ss >> retweet_count; ss.ignore(1, ','); ss >> favorite_count;
            tweets.push_back({tweetID, retweet_count, favorite_count});
        } file.close(); 
    } else {std::cerr << "Error: Unable to open file " << filename << std::endl;}   
    return tweets;
}

void writeTweetsToFile (const std::string& filename, const std::vector<Tweet>& tweets) {
    std::ofstream file (filename); if (file.is_open()) {
        file << "tweetID,retweetCount,favoriteCount\n"; for (const Tweet& tweet : tweets) {
            file << tweet.tweetID << "," << tweet.retweetCount << "," << tweet.favoriteCount << "\n";
        } file.close();
    } else {std::cerr << "Error: Unable to open file " << filename << std::endl;}
}