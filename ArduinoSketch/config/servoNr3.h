#include <Eigen.h>
#include "../EncoderHandler.h"
#include "../OpticalEncoderHandler.h"
#include "../ArduinoC++BugFixes.h"

#ifndef CONFIG_HOLDER_H
#define CONFIG_HOLDER_H

class ConfigHolder
{
public:
    static constexpr float getMainEncoderGearRation()
    {
        return 275.0 / 125904.0;
    }

    static std::unique_ptr<OpticalEncoderHandler> createMainEncoderHandler()
    {
        std::array<uint16_t, 512> aVec = {3720, 3718, 3718, 3711, 3706, 3706, 3705, 3703, 3703, 3701, 3697, 3696, 3696, 3705, 3710, 3714, 3720, 3722, 3721, 3714, 3712, 3708, 3712, 3712, 3711, 3707, 3708, 3711, 3707, 3702, 3696, 3694, 3692, 3689, 3684, 3682, 3681, 3680, 3678, 3674, 3671, 3668, 3668, 3659, 3656, 3648, 3639, 3639, 3636, 3632, 3627, 3623, 3618, 3620, 3611, 3606, 3601, 3594, 3590, 3587, 3589, 3582, 3578, 3562, 3552, 3544, 3534, 3524, 3519, 3511, 3505, 3499, 3497, 3497, 3498, 3495, 3488, 3478, 3476, 3460, 3448, 3440, 3436, 3432, 3426, 3423, 3422, 3420, 3418, 3416, 3408, 3399, 3393, 3386, 3379, 3379, 3382, 3390, 3399, 3403, 3411, 3414, 3415, 3412, 3401, 3384, 3372, 3366, 3361, 3359, 3356, 3357, 3348, 3346, 3340, 3329, 3308, 3292, 3281, 3268, 3261, 3252, 3247, 3239, 3225, 3220, 3212, 3194, 3171, 3155, 3134, 3120, 3097, 3077, 3058, 3052, 3052, 3043, 3037, 3030, 3016, 3006, 2992, 2989, 2973, 2966, 2962, 2951, 2945, 2941, 2932, 2933, 2922, 2915, 2909, 2899, 2888, 2880, 2873, 2868, 2868, 2859, 2854, 2842, 2837, 2828, 2819, 2812, 2805, 2795, 2777, 2761, 2746, 2730, 2722, 2714, 2701, 2692, 2691, 2688, 2687, 2676, 2666, 2655, 2647, 2640, 2637, 2635, 2631, 2632, 2628, 2629, 2624, 2626, 2619, 2616, 2614, 2607, 2606, 2602, 2604, 2603, 2606, 2605, 2604, 2602, 2600, 2596, 2594, 2591, 2588, 2584, 2581, 2575, 2567, 2561, 2552, 2551, 2548, 2551, 2550, 2545, 2541, 2529, 2520, 2515, 2506, 2495, 2494, 2492, 2498, 2496, 2498, 2496, 2493, 2490, 2493, 2494, 2494, 2492, 2490, 2492, 2497, 2492, 2492, 2491, 2492, 2494, 2490, 2492, 2488, 2486, 2481, 2483, 2478, 2480, 2479, 2479, 2482, 2482, 2479, 2477, 2478, 2473, 2470, 2476, 2483, 2489, 2494, 2492, 2492, 2493, 2495, 2492, 2495, 2496, 2496, 2500, 2502, 2507, 2515, 2523, 2531, 2541, 2539, 2546, 2557, 2570, 2586, 2598, 2608, 2606, 2611, 2614, 2616, 2617, 2620, 2623, 2628, 2631, 2638, 2647, 2650, 2662, 2666, 2672, 2680, 2687, 2691, 2698, 2705, 2708, 2719, 2725, 2731, 2732, 2737, 2748, 2762, 2771, 2787, 2802, 2813, 2823, 2834, 2848, 2851, 2860, 2864, 2875, 2880, 2874, 2889, 2901, 2912, 2922, 2926, 2932, 2943, 2953, 2955, 2961, 2965, 2972, 2982, 2991, 3001, 3012, 3020, 3027, 3035, 3044, 3057, 3068, 3074, 3080, 3090, 3098, 3107, 3111, 3115, 3116, 3122, 3124, 3127, 3126, 3122, 3119, 3127, 3132, 3131, 3132, 3143, 3156, 3164, 3168, 3178, 3188, 3207, 3214, 3217, 3222, 3237, 3253, 3269, 3289, 3302, 3320, 3338, 3370, 3385, 3391, 3390, 3401, 3407, 3407, 3409, 3420, 3425, 3432, 3436, 3439, 3442, 3444, 3448, 3452, 3457, 3465, 3470, 3476, 3480, 3477, 3480, 3486, 3491, 3495, 3498, 3502, 3508, 3515, 3526, 3538, 3549, 3556, 3568, 3578, 3582, 3584, 3584, 3586, 3591, 3604, 3610, 3612, 3614, 3613, 3612, 3614, 3620, 3623, 3626, 3628, 3628, 3631, 3630, 3628, 3629, 3626, 3629, 3633, 3637, 3642, 3650, 3658, 3668, 3675, 3677, 3676, 3674, 3674, 3676, 3679, 3688, 3692, 3694, 3694, 3692, 3689, 3683, 3677, 3676, 3674, 3677, 3676, 3685, 3689, 3682, 3678, 3678, 3682, 3694, 3700, 3700, 3707, 3698, 3696, 3699, 3716, 3723, 3727, 3728, 3729, 3725, 3725, 3727, 3727, 3727, 3729, 3732, 3732, 3735, 3737, 3735, 3733, 3733, 3732, 3732, 3731, 3728, 3727, 3725, 3721};
        std::array<uint16_t, 512> bVec = {2285, 2283, 2273, 2251, 2240, 2230, 2215, 2200, 2189, 2170, 2150, 2135, 2126, 2083, 2060, 2032, 1990, 1962, 1918, 1877, 1861, 1830, 1792, 1752, 1733, 1703, 1689, 1662, 1650, 1620, 1602, 1583, 1565, 1540, 1524, 1514, 1510, 1502, 1497, 1493, 1482, 1476, 1470, 1457, 1442, 1425, 1401, 1383, 1373, 1358, 1348, 1341, 1328, 1322, 1310, 1299, 1292, 1280, 1276, 1273, 1265, 1261, 1250, 1232, 1217, 1202, 1182, 1166, 1160, 1154, 1142, 1131, 1125, 1123, 1122, 1120, 1123, 1120, 1113, 1104, 1092, 1085, 1076, 1063, 1054, 1047, 1044, 1042, 1040, 1037, 1037, 1035, 1034, 1031, 1026, 1020, 1017, 1002, 992, 984, 978, 973, 966, 952, 941, 928, 920, 916, 915, 912, 909, 911, 904, 901, 900, 896, 891, 888, 885, 888, 887, 886, 882, 871, 862, 858, 859, 857, 858, 855, 851, 852, 863, 867, 864, 866, 869, 866, 864, 866, 869, 871, 871, 870, 872, 872, 877, 879, 882, 886, 889, 895, 899, 906, 915, 923, 929, 933, 935, 941, 943, 945, 964, 978, 987, 1011, 1037, 1056, 1064, 1084, 1102, 1120, 1134, 1161, 1179, 1188, 1204, 1228, 1249, 1264, 1278, 1287, 1300, 1325, 1350, 1357, 1372, 1384, 1394, 1402, 1407, 1418, 1430, 1435, 1442, 1451, 1457, 1466, 1482, 1491, 1499, 1503, 1514, 1522, 1527, 1533, 1537, 1540, 1548, 1555, 1566, 1577, 1589, 1602, 1614, 1621, 1633, 1649, 1661, 1679, 1706, 1730, 1743, 1778, 1806, 1832, 1854, 1900, 1912, 1925, 1939, 1954, 1965, 1970, 1969, 1968, 1968, 1973, 1976, 1978, 1981, 1988, 1973, 2002, 2010, 2017, 2034, 2046, 2053, 2068, 2074, 2080, 2093, 2113, 2129, 2146, 2155, 2161, 2163, 2177, 2200, 2218, 2230, 2267, 2283, 2324, 2347, 2378, 2400, 2433, 2471, 2516, 2544, 2574, 2592, 2605, 2613, 2622, 2634, 2642, 2657, 2667, 2684, 2704, 2718, 2738, 2751, 2774, 2794, 2821, 2829, 2832, 2839, 2848, 2850, 2853, 2870, 2874, 2888, 2899, 2902, 2910, 2913, 2912, 2918, 2921, 2929, 2936, 2942, 2946, 2949, 2947, 2947, 2950, 2952, 2954, 2956, 2964, 2975, 2980, 2988, 2988, 2988, 2986, 3001, 3022, 3038, 3056, 3066, 3070, 3072, 3080, 3087, 3104, 3103, 3094, 3081, 3078, 3077, 3080, 3080, 3085, 3090, 3101, 3109, 3116, 3117, 3117, 3117, 3112, 3102, 3095, 3094, 3103, 3106, 3109, 3121, 3134, 3144, 3154, 3163, 3170, 3174, 3183, 3188, 3189, 3190, 3187, 3187, 3190, 3192, 3188, 3204, 3210, 3211, 3212, 3209, 3205, 3199, 3188, 3178, 3169, 3163, 3164, 3166, 3162, 3160, 3156, 3166, 3179, 3184, 3187, 3187, 3192, 3195, 3192, 3196, 3196, 3197, 3193, 3191, 3186, 3183, 3182, 3182, 3181, 3180, 3183, 3180, 3179, 3177, 3176, 3175, 3172, 3174, 3174, 3170, 3170, 3158, 3148, 3145, 3136, 3125, 3120, 3110, 3093, 3081, 3064, 3052, 3038, 3025, 3009, 2996, 2980, 2964, 2950, 2935, 2917, 2890, 2874, 2852, 2838, 2833, 2834, 2830, 2822, 2818, 2809, 2805, 2799, 2789, 2778, 2774, 2772, 2770, 2766, 2767, 2770, 2771, 2764, 2758, 2747, 2735, 2730, 2722, 2707, 2699, 2687, 2673, 2659, 2650, 2645, 2638, 2630, 2620, 2614, 2607, 2596, 2582, 2571, 2561, 2564, 2571, 2582, 2593, 2604, 2607, 2570, 2547, 2537, 2525, 2511, 2500, 2480, 2473, 2469, 2463, 2454, 2449, 2444, 2428, 2412, 2400, 2386, 2372, 2358, 2348, 2343, 2333, 2323, 2316, 2298};

        return std::make_unique<OpticalEncoderHandler>(aVec, bVec);
    }

    static std::unique_ptr<EncoderHandlerInterface> createOutputEncoderHandler()
    {
        return std::make_unique<EncoderHandler>(A5);
    }

    static constexpr unsigned char getCommunicationId()
    {
        return 3;
    }

    static Eigen::Matrix<float, 5, 1> getControlParameterVector()
    {
        Eigen::Matrix<float, 5, 1> L;
        //L << 9.940239281724569, 1.3586010780478561, -0.03237764040441623, -0.03237764040441623 * 10, 4;
        L << 14.865806368082696, 2.0623236695442064, -0.07122297702645312, -0.07122297702645312 * 10, 6;
        //L << 19.76190853507559, 2.7501424347363677, -0.12380201903044662, -0.12380201903044662 * 10, 8;
        //L << 24.628722042909875, 3.422417759025543, -0.18915403084733035, -0.18915403084733035 * 10, 12;
        //L << 57.89092015732856, 7.721727677879117, -0.9336154818877859, -0.9336154818877859 * 10, 12;
        //L << 94.23296940236878, 11.862863259936727, -2.185085156962166, -2.185085156962166 * 10, 12;

        return L;
    }

    class KalmanFilter
    {
      public:
        static Eigen::Vector3f getKVector()
        {
            Eigen::Vector3f K;
            
            //K << 0.09799424580193117,
            //    2.4964409292865963,
            //    0.5652699951929046;

            //K << 0.16531265413057228,
            //    7.247273820257207,
            //    2.5269719748600346;

            //K << 0.1983825910518331,
            //    10.478680647096779,
            //    4.291072093854287;

            //K << 0.32684007265646386,
            //    28.567812385253276,
            //    18.53313095588553;

            //K << 0.3888374995706161,
            //    40.40850366768767,
            //    30.93862171115473;

            //K << 0.4791413260700308,
            //    61.21885215942826,
            //    57.39263621353391;

            //K << 0.5085413648625792,
            //    68.89605951297686,
            //    68.47216577817979;

            //K << 0.622743534980963,
            //    102.86198025189901,
            //    124.93406815357332;

            // 30 * 4 * 2 pole
            //K << 0.7316969391112194,
            //    141.316769493361,
            //    201.79065187534968;

            // 60 * 4 * 2 pole
            K << 1.2879572201280896,
                425.2887752180842,
                1089.0860221513021;

            // 100 * 4 * 2 pole
            //K << 1.8229097365190623,
            //    825.8706566376411,
            //    3075.4863531454275;

            return K;
        }


        static Eigen::Matrix3f getAMatrix()
        {
            Eigen::Matrix3f A;
            A << 1.0, 0.0012, 3.6719999999999994e-05,
            0.0, 0.994, 0.0612,
            0.0, 0.0, 1.0;

            return A;
        }

        static Eigen::Matrix3f getAInvMatrix()
        {
            Eigen::Matrix3f AInv;

            AInv << 1.0, -0.0012072434607645873, 3.7163299798792755e-05,
                0.0, 1.0060362173038229, -0.06156941649899396,
                0.0, 0.0, 1.0;

            return AInv;
        }

        static Eigen::Vector3f getBVector()
        {
            Eigen::Vector3f B;

            B << 3.6719999999999994e-05,
                0.0612,
                0.0;

            return B;
        }
    };
};

#endif
