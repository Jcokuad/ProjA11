// tests/test_linked_binary_tree.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "tree/linked_binary_tree.hpp"

using namespace dsac::tree;

TEST_CASE("positions functions handles single node tree correctly") {
    LinkedBinaryTree<int> T;
    T.add_root(12);

    auto tree = T.positions();

    REQUIRE(tree.size() == 1);
    REQUIRE(tree[0].element() == 12);
    REQUIRE(T.count_left_leaves() == 0);
    REQUIRE(T.count_left_leaves_bfs() == 0);
}

TEST_CASE("positions function handles multi level tree correctly") {
    LinkedBinaryTree<int> T;
    T.add_root(60);
    auto r = T.root();

    T.add_left(r, 30);           // creates tree with:
    T.add_right(r, 20);          //                 60
    T.add_left(r.left(), 6);     //               /    |
    T.add_right(r.left(), 5);    //              30     20
                                 //             /  \   /  |
    auto l4 = r.left();          //            6    5 4    5
    T.add_left(l4.left(), 3);    //           / |
    T.add_right(l4.left(), 2);   //          3   2

    T.add_left(r.right(), 4);
    T.add_right(r.right(), 5);

    auto tree = T.positions();

    std::vector<int> res;
    for (auto n : tree) {
        res.push_back(n.element());
    }

    std::vector<int> expected_res = {3, 6, 2, 30, 5, 60, 4, 20, 5};
    REQUIRE(res == expected_res);
    REQUIRE(T.count_left_leaves() == 2);
    REQUIRE(T.count_left_leaves_bfs() == 2);
}

TEST_CASE("positions function handles right skewed tree correctly") {
    LinkedBinaryTree<int> T;

    T.add_root(50);

    auto r = T.root();
    T.add_right(r, 40);
    T.add_right(r.right(), 30);

    auto tree = T.positions();

    std::vector<int> res;
    for (auto n : tree) {
        res.push_back(n.element());
    }

    std::vector<int> expected_res = {50, 40, 30};
    REQUIRE(res == expected_res);
    REQUIRE(T.count_left_leaves() == 0);
    REQUIRE(T.count_left_leaves_bfs() == 0);
}