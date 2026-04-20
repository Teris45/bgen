#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BGEN_NAME bt            // The namespace for the btree structure.
#define BGEN_TYPE int           // The data type for all items in the btree
#define BGEN_LESS return a < b; // A code fragment for comparing items
#include "bgen.h"            // Include "bgen.h" to generate the btree


int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    struct bt *tree = 0;

    for (size_t i = 0; i + sizeof(int) <= size; i+= sizeof(int)) {
        int to_insert;
        int val; 
        memcpy(&to_insert, &data[i], sizeof(int));

        bt_insert(&tree, to_insert, &val, NULL);
        bt_push_front(&tree, to_insert, NULL);
        bt_push_back(&tree, to_insert, NULL);
    }

    for (size_t i = 0; i + sizeof(int) <= size; i+= sizeof(int)) {
        int to_get;
        int val;
        int *item_mut;
        memcpy(&to_get, &data[i], sizeof(int));
        bt_contains(&tree, to_get, NULL);
        bt_get(&tree, to_get, &val, NULL);
        bt_get_mut(&tree, to_get, &val, NULL);
        bt_get_mut_ref(&tree, to_get, &item_mut, NULL);
    }


    int front_mut;
    int j = bt_front_mut(&tree, &front_mut, NULL);
    int back_mut;
    int x = bt_back_mut(&tree, &back_mut, NULL);



    bt_clear(&tree, 0);

    
    
    return 0;

}
