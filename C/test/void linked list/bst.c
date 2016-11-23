/* The authors of this work have released all rights to it and placed it
in the public domain under the Creative Commons CC0 1.0 waiver
(http://creativecommons.org/publicdomain/zero/1.0/).

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Binary_search_tree_(C)?oldid=18734
*/

#include <stdlib.h>
#include "bst.h"

struct bst_node** search(struct bst_node** root, comparator compare, void* data) {
    struct bst_node** node = root;
    while (*node != NULL) {
        int compare_result = compare(data, (*node)->data);
        if (compare_result < 0)
            node = &(*node)->left;
        else if (compare_result > 0)
            node = &(*node)->right;
        else
            break;
    }
    return node;
}
void insert(struct bst_node** root, comparator compare, void* data) {
    struct bst_node** node = search(root, compare, data);
    if (*node == NULL) {
        *node = new_node(data);
    }
}
void delete(struct bst_node** node) {
    struct bst_node* old_node = *node;
    if ((*node)->left == NULL) {
        *node = (*node)->right;
        free_node(old_node);
    } else if ((*node)->right == NULL) {
        *node = (*node)->left;
        free_node(old_node);
    } else {
        struct bst_node** pred = &(*node)->left;
	while ((*pred)->right != NULL) {
	    pred = &(*pred)->right;
	}

	/* Swap values */
	void* temp = (*pred)->data;
	(*pred)->data = (*node)->data;
	(*node)->data = temp;

	delete(pred);
    }
}
