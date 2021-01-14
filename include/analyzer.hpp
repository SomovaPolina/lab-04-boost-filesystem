// Copyright 2020 Your Name <your_email>

#ifndef LAB_04_BOOST_FILESYSTEM_ANALYZER_HPP
#define LAB_04_BOOST_FILESYSTEM_ANALYZER_HPP
#include <boost/filesystem.hpp>
#include <ostream>
#include <iostream>
using namespace boost;
struct account{
  std::string broker_name;
  std::vector<std::string> filenames;
  std::string number_account;
  std::string lastdate;
};
std::ostream &operator<<(std::ostream &out, const account &ac);
class analyzer {
 public:
  friend std::ostream &operator<<(std::ostream &out, const analyzer &a);
  void parse_dir_info(const filesystem::path&path_dir,
                      const std::string &broker);
  std::string get_number_account(const std::string &filename);
  bool check_filename(const filesystem::path&path_file);
  std::string get_date(const std::string& filename) const;
  void set_lastdates();
  analyzer(const filesystem::path &path_ftp);
  ~analyzer();
 private:
  filesystem::path path_to_ftp;
  std::vector<struct account*> accounts;

};

#endif  // LAB_04_BOOST_FILESYSTEM_ANALYZER_HPP

