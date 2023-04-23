#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::format;
using std::string;
using std::vector;

/***********************************************
 *
 *  CHAPTER 9 CHALLENGE - TRANSFORM A FILE
 *
 *  Write a program that reads a file, decode it, store its data in a structure and print the results using the Standard Template Library.
 *
 * Filename is "items.txt"
 *
 * The text file represents items in an inventory. Each line contains two "\t" characters, separating the three fields.
 *
 *  The first field is the SKU (Stock Keeping Unit), the second field is the name of the item, and the third field is the description.
 *
 * The program should store the data in a vector of structs. Each struct should have three members: SKU (string), name (string), and description (string).
 *
 * Data will be provided in the following format:
 * 1\tBox of 64 Pixels\t64 RGB pixels in a decorative box.
 * 2\tSense of Humor\tEspecially dry. Imported from England.
 * 3\tBeauty\tInner beauty. No cosmetic surgey required!
 * 4\tBar Code\tUnused. In original packaging.
 *
 * Output should be formatted as follows:
 * sku: 1, name: Box of 64 Pixels, desc: 64 RGB pixels in a decorative box.
 * sku: 2, name: Sense of Humor, desc: Especially dry. Imported from England.
 * sku: 3, name: Beauty, desc: Inner beauty. No cosmetic surgey required!
 * sku: 4, name: Bar Code, desc: Unused. In original packaging.
 *
 ************************************************/

const size_t maxstring{1024}; // size of line buffer
const char *filename{"/Users/keithhetrick/Downloads/Ex_Files_C_plusplus_EssT/Exercise Files/Chap09/items.txt"};
const char tab_char{'\t'};

class Item
{
  int _sku{};
  string _name{};
  string _desc{};

public:
  Item() { reset(); }
  Item(int sku, string &name, string &desc) : _sku(sku), _name(name), _desc(desc) {}
  Item(const Item &rhs);
  Item &operator=(const Item &rhs);
  ~Item() { reset(); }
  void reset()
  {
    _sku = 0;
    _name = _desc = "unk";
  }
  void sku(int sku) { _sku = sku; }
  int sku() const { return _sku; }
  void name(const string &name) { _name = name; }
  string name() const { return _name; }
  void desc(const string &desc) { _desc = desc; }
  string desc() const { return _desc; }
};

Item::Item(const Item &rhs)
{
  _sku = rhs._sku;
  _name = rhs._name;
  _desc = rhs._desc;
}

Item &Item::operator=(const Item &rhs)
{
  if (this != &rhs)
  {
    _sku = rhs._sku;
    _name = rhs._name;
    _desc = rhs._desc;
  }
  return *this;
}

// split a string
vector<string> strsplit(const string &s)
{
  vector<string> strs_v; // vector for results
  size_t start_loc{};
  size_t sep_loc{};
  while (true)
  {
    sep_loc = s.find(tab_char, start_loc);
    strs_v.push_back(s.substr(start_loc, sep_loc - start_loc));
    if (sep_loc == string::npos)
      break;
    start_loc = sep_loc + 1;
  }
  return strs_v;
}

int main()
{
  char buf[maxstring]{}; // buffer for reading lines in file

  // open the file
  std::ifstream infile(filename);

  // read the file
  while (infile.good())
  {
    // get the line
    infile.getline(buf, sizeof(buf));
    if (!*buf)
      break;

    // split the string
    vector<string> split_v{strsplit(buf)};
    if (split_v.size() < 3)
      continue;

    // construct the object
    Item current_item{std::stoi(split_v[0]), split_v[1], split_v[2]};
    cout << format("sku: {}, name: {}, desc: {}\n",
                   current_item.sku(), current_item.name(), current_item.desc());
  }
  infile.close();
}
