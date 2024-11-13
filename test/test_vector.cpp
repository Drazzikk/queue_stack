#include "gtest.h"
#include "stack_queue.h"


TEST(TVector, default_constructor) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.getCapacity(), 2);
}

TEST(TVector, push_back) {
    TVector<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 10);
}

TEST(TVector, pop_back) {
    TVector<int> vec;
    vec.push_back(10);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVector, pop_back_empty_throws) {
    TVector<int> vec;
    EXPECT_THROW(vec.pop_back(), std::domain_error);
}

TEST(TVector, resize) {
    TVector<int> vec;
    vec.push_back(10);
    vec.resize(5);
    EXPECT_EQ(vec.getCapacity(), 12); 
}

TEST(TVector, resiz_throws) {
    TVector<int> vec;
    ASSERT_ANY_THROW(vec.resize(std::numeric_limits<size_t>::max()));
}


TEST(TVector, copy_constructor) {
    TVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    TVector<int> vec2 = vec1; 
    EXPECT_EQ(vec2.size(), 2);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
}

TEST(TVector, assignment_operator) {
    TVector<int> vec1;
    vec1.push_back(3);

    TVector<int> vec2;
    vec2 = vec1; 
    EXPECT_EQ(vec2.size(), 1);
    EXPECT_EQ(vec2[0], 3);
}

TEST(TVector, equality_operator_with_itself) {
    TVector<int> vec1;
    vec1.push_back(4);

    EXPECT_TRUE(vec1 == vec1);
}

TEST(TVector, equality_operator_with_other_vector) {
    TVector<int> vec1;
    vec1.push_back(4);

    TVector<int> vec2;
    vec2.push_back(4);

    EXPECT_TRUE(vec1 == vec2); 
}

TEST(TVector, inequality_operator) {
    TVector<int> vec1;
    vec1.push_back(5);

    TVector<int> vec2;
    vec2.push_back(6);

    EXPECT_TRUE(vec1 != vec2); 
}

TEST(TVectorTest, size_method) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0); 
    vec.push_back(1);
    EXPECT_EQ(vec.size(), 1); 
    vec.push_back(2);
    EXPECT_EQ(vec.size(), 2); 
}

TEST(TVectorTest, get_capacity_method) {
    TVector<int> vec;
    EXPECT_EQ(vec.getCapacity(), 2); 
    vec.push_back(1);
    EXPECT_EQ(vec.getCapacity(), 2); 
    vec.push_back(2);
    EXPECT_EQ(vec.getCapacity(), 2); 
    vec.push_back(3); 
    EXPECT_GT(vec.getCapacity(), 2); 
}

TEST(TVector, full_method) {
    TVector<int> vec;
    EXPECT_FALSE(vec.Full());

    vec.push_back(1);
    EXPECT_FALSE(vec.Full()); 

    vec.push_back(2);
    EXPECT_TRUE(vec.Full()); 
}

TEST(TVector, empty_method) {
    TVector<int> vec;
    EXPECT_TRUE(vec.Empty()); 

    vec.push_back(1);
    EXPECT_FALSE(vec.Empty()); 

    vec.pop_back(); 
    EXPECT_TRUE(vec.Empty()); 
}

TEST(TVector, index_operator_non_const) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(TVector, index_operator_const) {
    const TVector<int> vec = [] {
        TVector<int> temp;
        temp.push_back(4);
        temp.push_back(5);
        return temp;
    }();

     
    EXPECT_EQ(vec[0], 4);
    EXPECT_EQ(vec[1], 5);
}

TEST(TVectorTest, push_front) {
    TVector<int> vec;

    vec.push_front(1);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);

    vec.push_front(2);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 2); 
    EXPECT_EQ(vec[1], 1); 
}

TEST(TVectorTest,pop_front) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.pop_front();
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 2);

    vec.pop_front();
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVectorTest, pop_front_empty_throws) {
    TVector<int> vec;

    EXPECT_THROW(vec.pop_front(), std::domain_error);
}

TEST(TVectorTest, push_front_resize) {
    TVector<int> vec;

    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }

    vec.push_front(10);

    EXPECT_EQ(vec.size(), 6); 
    EXPECT_EQ(vec[0], 10);     
}