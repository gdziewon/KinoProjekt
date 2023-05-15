#include <string>
#include <iostream>

class Review {
public:
    Review(const std::string& reviewerName, const std::string& comment, int rating)
        : reviewerName(reviewerName), comment(comment), rating(rating) {}

    std::string getReviewerName() const { return reviewerName; }
    std::string getComment() const { return comment; }
    int getRating() const { return rating; }

    void setReviewerName(const std::string& reviewerName) { this->reviewerName = reviewerName; }
    void setComment(const std::string& comment) { this->comment = comment; }
    void setRating(int rating) { this->rating = rating; }

    void display() const {
        std::cout << "Reviewer: " << reviewerName << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Comment: " << comment << std::endl;
    }

private:
    std::string reviewerName;
    std::string comment;
    int rating;
};

