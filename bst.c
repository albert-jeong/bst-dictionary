#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

static TreeNode *new_node(element item) {  // 코드 은닉
    TreeNode *temp = malloc(sizeof(TreeNode));
    if (!temp) { // 널 체크
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
static int compare(element e1, element e2) {  // 코드 은닉
    return strcmp(e1.word, e2.word);
}

TreeNode *insert_node(TreeNode *node, element key) {
    // 트리가 공백이면 새로운 노드를 반환한다.
    if (node == NULL)
        return new_node(key);

    // 그렇지 않으면 순환적으로 트리를 내려간다.
    if (compare(key, node->key) < 0)
        node->left = insert_node(node->left, key);
    else if (compare(key, node->key) > 0)
        node->right = insert_node(node->right, key);
    // 루트 포인터를 반환한다.
    return node;
}

// 이진 탐색 트리 탐색 함수
TreeNode *search_node(TreeNode *root, element key) {
    TreeNode *p = root;
    while (p) {
        int cmp = compare(key, p->key);
        if (cmp == 0)      return p;
        else if (cmp < 0)  p = p->left;
        else               p = p->right;
    }
    return NULL;  // 탐색에 실패했을 경우 NULL 반환
}

TreeNode *min_value_node(TreeNode *node) {
    TreeNode *current = node;

    // 맨 왼쪽 단말 노드를 찾으러 내려감
    while (current && current->left)
        current = current->left;
    return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.
TreeNode *delete_node(TreeNode *root, element key) {
    if (root == NULL)
        return NULL;

    int cmp = compare(key, root->key);
    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if (cmp < 0)
        root->left = delete_node(root->left, key);
    // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if (cmp > 0)
        root->right = delete_node(root->right, key);
    // 키가 루트와 같으면 이 노드를 삭제하면 됨
    else {
        // 첫 번째나 두 번째 경우
        if (root->left == NULL) {
            TreeNode *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        }
        // 세 번째 경우
        TreeNode *tmp = min_value_node(root->right);

        // 중외 순회시 후계 노드를 복사한다.
        root->key = tmp->key;
        // 중외 순회시 후계 노드를 삭제한다.
        root->right = delete_node(root->right, tmp->key);
    }
    return root;
}

// 이진 탐색 트리 출력 함수
void display_tree(TreeNode *root) {
    if (root) {
        printf("(");
        display_tree(root->left);
        printf("%s:%s", root->key.word, root->key.meaning);
        display_tree(root->right);
        printf(")");
    }
}

void free_tree(TreeNode *root) {
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
