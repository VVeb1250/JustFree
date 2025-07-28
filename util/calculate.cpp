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
    template<typename T>
    int getRandomInt(const T& min, const T& max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
    /**
     * @brief genarate random number in in presition 0.01
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return float that completely random
     */
    template<typename T>
    float getRandomFloat2f(const T& min, const T& max) {
        std::uniform_real_distribution<float> dist(min, max);
        return std::round(dist(gen) * 100.0f) * INV_100;
    }
    /**
     * @brief genarate random number in presition 0.0001
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return double that completely random
     */
    template<typename T>
    float getRandomFloat4f(const T& min, const T& max) {
        std::uniform_real_distribution<float> dist(min, max);
        return std::round(dist(gen) * 10000.0) * INV_10000;
    }
    /**
     * @brief genarate random number in double
     * @param min mininum random can be
     * @param max maxinum random can be
     * @return double that completely random
     */
    template<typename T>
    double getRandomDouble(const T& min, const T& max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(gen);
    }
    /**
     * @brief genarate random true or false with sucessrate
     * @param successRatePercent sucessrate in 0.01-100.0%
     * @return result of random
     */
    template<typename T>
    bool randomSuscess(const T& successRatePercent) {
        return dist_percent(gen) <= successRatePercent;
    }
    /**
     * @brief genarate random true or false with sucessrate
     * @param successRatePercent sucessrate in min - max
     * @param min mininum int in random range
     * @param max maxinum int in random range
     * @return result of random
     */
    template<typename T1, typename T2> 
    bool randomSuscess(const T1& successRatePercent,const T2& min,const T2& max) {
        float roll = getRandomFloat2f(min, max);
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
        return (100.0f * x) / (x + control);
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