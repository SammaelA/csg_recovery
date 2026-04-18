#include <fstream>
#include <cstdint>
#include <vector>

extern double eval(double x, double y, double z);
int main(int argc, char** argv)
{
  const char *points_path = argv[1];
  const char *out_distances_path = argv[2];

  std::vector<float> points;
  std::vector<float> distances;

  uint32_t num_points = 0;
  std::ifstream points_file(points_path);
  points_file.read((char*)&num_points, sizeof(uint32_t));
  points.resize(3*num_points);
  points_file.read((char*)points.data(), 3*num_points*sizeof(float));
  points_file.close();

  distances.resize(num_points);
  for (uint32_t i = 0; i < num_points; i++) {
    float x = points[3*i];
    float y = points[3*i + 1];
    float z = points[3*i + 2];
    distances[i] = -1.0f*eval(x, y, z); //the distances seem to be inverted, idk why
  }

  std::ofstream distances_file(out_distances_path);
  distances_file.write((char*)&num_points, sizeof(uint32_t));
  distances_file.write((char*)distances.data(), num_points*sizeof(float));
  distances_file.flush();
  distances_file.close();
}