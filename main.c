#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

static void strip_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

static void help_menu() {
    printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****\n");
}

int main(void) {
    char command;
    element e;
    TreeNode *root = NULL, *tmp;

    do {
        help_menu();
        command = getchar();
        getchar();  // 엔터키 제거

        switch (command) {
            case 'i':  // 삽입
                printf("단어:");
                fgets(e.word, MAX_WORD_SIZE, stdin);
                strip_newline(e.word);

                printf("의미:");
                fgets(e.meaning, MAX_MEANING_SIZE, stdin);
                strip_newline(e.meaning);

                if (search_node(root, e)) {
                    printf("이미 존재하는 단어입니다.\n");
                } else {
                    root = insert_node(root, e);
                }
                break;

            case 'd':  // 삭제
                printf("단어:");
                fgets(e.word, MAX_WORD_SIZE, stdin);
                strip_newline(e.word);

                tmp = search_node(root, e);
                if (tmp) {
                    root = delete_node(root, e);
                } else {
                    printf("해당 단어가 존재하지 않습니다.\n");
                }
                break;

            case 's':  // 탐색
                printf("단어:");
                fgets(e.word, MAX_WORD_SIZE, stdin);
                strip_newline(e.word);

                tmp = search_node(root, e);
                if (tmp) {
                    printf("의미:%s\n", tmp->key.meaning);
                } else {
                    printf("해당 단어가 존재하지 않습니다.\n");
                }
                break;

            case 'p':  // 트리 출력
                if (root) {
                    display_tree(root);
                    printf("\n");
                } else {
                    printf("사전에 단어가 하나도 없습니다.\n");
                }
                break;

            default:
                if (command != 'q') printf("존재하지 않는 명령입니다.\n");
                break;
        }
    } while (command != 'q');

    free_tree(root);
    return 0;
}
