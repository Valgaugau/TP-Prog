#include <QApplication>
#include <QString>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    // return an unique hash id from key
    unsigned long int hash = 0;

    for (size_t i = 0; i < key.size(); i++) {
        hash += key[i] * std::pow(128, i);
    }

    return hash;
}

struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        if (node->key_hash < key_hash) {
                    if (left == nullptr) {
                        left = node;
                    } else {
                        left->insertNode(node);
                    }
                } else {
                    if (right == nullptr) {
                        right = node;
                    } else {
                        right->insertNode(node);
                    }
                }
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        MapNode* node = new MapNode(key, value);
               if (root == nullptr) {
                   root = node;
               } else {
                   root->insertNode(node);
               }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {
        unsigned long int key_hash = hash(key);
            MapNode* current_node = root;

            while (current_node != nullptr) {
                if (current_node->key_hash == key_hash) {
                    return current_node->value;
                } else if (current_node->key_hash > key_hash) {
                    current_node = current_node->left;
                } else {
                    current_node = current_node->right;
                }
            }

            return 0;
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Map map;
    std::vector<std::string> inserted;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
            inserted.push_back(name);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));

    printf("\n");
    for (size_t i=0; i<inserted.size()/2; i++)
        printf("map[\"%s\"]=%d\n", inserted[i].c_str(), map.get(inserted[i]));


    std::cout.flush();

    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
