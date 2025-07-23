#ifndef BST_H
#define BST_H

#define MAX_WORD_SIZE    100
#define MAX_MEANING_SIZE 200

typedef struct {  // 데이터 형식
    char word[MAX_WORD_SIZE];  // 키필드
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode {  // 노드의 구조
    element key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *search_node(TreeNode *root, element key);
TreeNode *insert_node(TreeNode *root, element key);
TreeNode *delete_node(TreeNode *root, element key);
void display_tree(TreeNode *root);
void free_tree(TreeNode *root);
TreeNode *min_value_node(TreeNode *node);

#endif
