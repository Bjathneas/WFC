#include <iostream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

#include <LogCore.h>

std::string kValidChars = "1234567890abcdefghijklmnopqrstuvwxyz";

std::stringstream file_to_stringstream(std::fstream &file){
  std::stringstream ss;
  ss << file.rdbuf();
  file.close();
  return ss;
}

void purge_special(std::string &str){
  str.erase(std::remove_if(str.begin(), str.end(), [](char c){return kValidChars.find(c) == std::string::npos;}), str.end());
}
void string_lower(std::string &str){
  for(char &c : str){
    c = tolower(c);
  }
}

std::unordered_map<std::string, int> get_frequency(std::stringstream ss) {
  std::unordered_map<std::string, int> frequencies;
  std::string word;
  while(ss >> word){
    //remove all special chars and make lowercase
    string_lower(word);
    purge_special(word);
    
    frequencies[word]++;
  }
  return frequencies;
}

std::vector<std::pair<std::string, int>> get_sorted_table(std::unordered_map<std::string, int> &map) {
  std::vector<std::pair<std::string, int>> table(map.begin(), map.end());
  std::sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs){
                                            if(lhs.second == rhs.second)
                                              return lhs.first[0] < rhs.first[0];
                                            return lhs.second > rhs.second;
                                            });
  return table;
}

int main()
{
  LogCore::Logger log{"WFC"};
  //prompt user for the path
  printf("Please enter file path:\n");
  std::string file_path;
  std::cin >> file_path;
  //if file exists
  if(std::filesystem::exists(file_path)){
    std::fstream file(file_path.c_str(), std::ios_base::in);
    auto frequencies = get_frequency(file_to_stringstream(file));
    auto vec = get_sorted_table(frequencies);
    //create output file
    std::fstream output_file("WFC_output.txt", std::ios_base::trunc | std::ios_base::out);
    for(auto i : vec) {
      std::string output_line = i.first + " - " + std::to_string(i.second) + "\n";
      printf(output_line.c_str());
      output_file << output_line;
    }
    output_file.close();
  }else{
    log.error(file_path + " Does not exist");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
