#include <format>
#include <iostream>

using std::cout;
using std::format;

/*

  CHAPTER 4 CHALLENGE - LIBRARY CARD

  Data type layout:

  Title -> string -> cout << format("Label: {}\n", string);
  Author -> string -> cout << format("Label: {}\n", string);
  Publisher -> string -> cout << format("Label: {}\n", string);
  Subject -> string -> cout << format("Label: {}\n", string);
  ISBN -> string -> cout << format("Label: {}\n", string);
  WorldCat (OCLC) -> int -> cout << format("Label: {}\n", int);
  Dewey Decimal -> int -> cout << format("Label: {}\n", int);
  Year Published -> int -> cout << format("Label: {}\n", int);
  Year Acquired -> int -> cout << format("Label: {}\n", int);
  Quantity in stock -> int -> cout << format("Label: {}\n", int);

  */

struct catalog_card
{
  const char *title{};
  const char *author{};
  const char *publisher{};
  const char *subject{};
  const char *isbn{};
  const char *oclc{};
  int dewey_dec1{};
  int dewey_dec2{};
  int year_published{};
  int year_acquired{};
  int quantity{};
};

int main()
{
  catalog_card book_details{
      "The CGI Book_detailsbook_details", "William E. Weinman", "New Riders",
      "CGI (Computer network protocol)",
      "1562055712 9781562055714", "477166381",
      510, 78, 1996, 1997, 2};

  cout << format("Title: {}\n", book_details.title);
  cout << format("Author: {}\n", book_details.author);
  cout << format("Publisher: {}\n", book_details.publisher);
  cout << format("Subject: {}\n", book_details.subject);
  cout << format("ISBN: {}\n", book_details.isbn);
  cout << format("WorldCat (OCLC): {}\n", book_details.oclc);
  cout << format("Dewey Decimal: {}.{}\n", book_details.dewey_dec1, book_details.dewey_dec2);
  cout << format("Year published: {}\n", book_details.year_published);
  cout << format("Year acquired: {}\n", book_details.year_acquired);
  cout << format("Quantity: {}\n", book_details.quantity);
}
