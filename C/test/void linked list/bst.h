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

#ifndef _BST_H_
#define _BST_H_

/* Returns negative (left<right), zero (left==right), or positive (left>right). */
typedef int comparator(void* left, void* right);
struct bst_node {
    void* data;
    struct bst_node* left;
    struct bst_node* right;
};

struct bst_node* new_node(void* data);
void free_node(struct bst_node* node);
struct bst_node** search(struct bst_node** root, comparator compare, void* data);
void insert(struct bst_node** root, comparator compare, void* data);
void delete(struct bst_node** node);

#endif

