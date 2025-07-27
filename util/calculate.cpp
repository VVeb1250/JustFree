#include <cstdint>
#include <random>
#include <chrono>

namespace random
{
    constexpr float INV_100 = 1.0/100.0;
    constexpr float INV_10000 = 1.0/10000.0;
    // static generator
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static auto time_seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // Static distributions for common ranges
    static std::uniform_real_distribution<float> dist_percent(0.01f, 100.0f);

    /**
     * @brief genarate random number in int
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return int that completely random
     */
    int getRandomInt(const int& min, const int& max) {
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
    /**
     * @brief genarate random number in float
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return float that completely random
     */
    float getRandomFloat(const float& min, const float& max) {
        std::uniform_real_distribution<float> dist(min, max);
        
        float result = std::round(dist(gen) *100.0f) * INV_100;
        return result;
    }
    /**
     * @brief genarate random number in double
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return double that completely random
     */
    double getRandomDouble(const double& min, const double& max) {
        std::uniform_real_distribution<double> dist(min, max);
        
        double result = std::round(dist(gen) *10000.0) * INV_10000;
        return result;
    }
    /**
     * @brief genarate random true or false with sucessrate
     * @param successRatePercent sucessrate in 0.01-100.0%
     * @return result of random
     */
    bool randomSuscess(const float& successRatePercent) {
        return dist_percent(gen) <= successRatePercent;
    }
    /**
     * @brief genarate random true or false with sucessrate in int number
     * @param successRatePercent sucessrate in 0-100%
     * @param min mininum int in random range
     * @param max maxinum int in random range
     * @return result of random
     */
    bool randomSuscess(const float& successRatePercent,const uint8_t& min,const uint8_t& max) {
        float roll = getRandomFloat(min, max);
        return roll <= successRatePercent;
    }
    /**
     * @brief genarate random true or false with sucessrate in float number
     * @param successRatePercent sucessrate in any number
     * @param min mininum float in random range
     * @param max maxinum float in random range
     * @return result of random
     */
    bool randomSuscess(const float& successRatePercent,float& min, float& max) {
        float roll = getRandomFloat(min, max);
        return roll <= successRatePercent;
    }
} // namespace rd

namespace function
{
    /**
     * @brief claculate computeY number that not larger than 100
     * @param x input value
     * @param control adjust Slope of value. higher value mean has higher slope
     * @return result of calculating
     */
    float computeY(float x, float control) {
        if (x == 0) { return 0; }
        return (100.0 * x) / (x + control);
    }
    /**
     * @brief claculate computeY number that not larger than maxinum value
     * @param max maxinum value can reach
     * @param x input value
     * @param control adjust Slope of value. higher value mean has higher slope
     * @return result of calculating
     */
    float computeY(float max, float x, float control) {
        if (x == 0) { return 0; }
        return (max * x) / (x + control);
    }

} // namespace function