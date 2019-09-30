#include "foxer/other/helpers/tiled_csv_loader.hpp"

namespace fox {

void TiledCSVLoader::load_tilemap_array_from_file(std::string csv_file,
                                                  std::vector<int> *tilemap,
                                                  int &width, int &height) {
  width = 0;
  height = 0;
  bool first_it = true;

  std::ifstream in;
  in.open(csv_file.c_str());

  if (!in.is_open())
    return;

  std::string line;
  int n;

  while (std::getline(in, line)) {
    std::stringstream ss(line);
    while (ss >> n) {
      tilemap->push_back(n);

      if (first_it)
        ++width;

      if (ss.peek() == ',')
        ss.ignore();
    }

    first_it = false;
    ++height;
  }

  in.close();
}

} // namespace fox
