using System;
using System.Collections.Generic;
using UnityEngine;

public class GrowthRate
{
    // Automatic Properties
    public string Name { get; }
    public Dictionary<int, int> ToNextLevel { get; }
    public Dictionary<int, int> ToLevel { get; }

    // Private Constructor (Instances are only created with the static constructor)
    private GrowthRate(string inputName, Dictionary<int, int> inputToNextLevel, Dictionary<int, int> inputToLevel)
    {
        Name = inputName;
        ToNextLevel = inputToNextLevel;
        ToLevel = inputToLevel;
    }

    // Static Dictionary to hold all predefined GrowthRate instances
    public static Dictionary<string, GrowthRate> GrowthRateMap { get; }

    // Static constructor to initialize GrowthRateMap
    static GrowthRate()
    {
        GrowthRateMap = new Dictionary<string, GrowthRate>();

        // This dictionary will hold the calculated total experience for each level for each growth rate type
        Dictionary<string, Dictionary<int, int>> growthRatesData = new Dictionary<string, Dictionary<int, int>>
        {
            { "Fluctuating", new Dictionary<int, int>() },
            { "Slow", new Dictionary<int, int>() },
            { "Medium Slow", new Dictionary<int, int>() },
            { "Medium Fast", new Dictionary<int, int>() },
            { "Fast", new Dictionary<int, int>() },
            { "Erratic", new Dictionary<int, int>() }
        };

        // Calculate total experience to reach each level for each growth rate type
        for (int level = 2; level <= 100; level++)
        {
            // Fluctuating
            if (level < 15)
            {
                growthRatesData["Fluctuating"][level] = (int)Math.Floor(Math.Pow(level, 3) * (Math.Floor((level + 1) / 3.0) + 24) / 50.0);
            }
            else if (level >= 15 && level < 37)
            {
                growthRatesData["Fluctuating"][level] = (int)Math.Floor(Math.Pow(level, 3) * (level + 14) / 50.0);
            }
            else if (level >= 37 && level <= 100)
            {
                growthRatesData["Fluctuating"][level] = (int)Math.Floor(Math.Pow(level, 3) * (Math.Floor(level / 2.0) + 32) / 50.0);
            }

            // Slow
            growthRatesData["Slow"][level] = (int)Math.Floor(5 * Math.Pow(level, 3) / 4.0);

            // Medium Slow
            growthRatesData["Medium Slow"][level] = (int)Math.Floor((6 / 5.0) * Math.Pow(level, 3) - 15 * Math.Pow(level, 2) + 100 * level - 140);

            // Medium Fast
            growthRatesData["Medium Fast"][level] = (int)Math.Pow(level, 3);

            // Fast
            growthRatesData["Fast"][level] = (int)Math.Floor(4 * Math.Pow(level, 3) / 5.0);

            // Erratic
            if (level < 51)
            {
                growthRatesData["Erratic"][level] = (int)Math.Floor(Math.Pow(level, 3) * (100 - level) / 50.0);
            }
            else if (level >= 51 && level < 69)
            {
                growthRatesData["Erratic"][level] = (int)Math.Floor(Math.Pow(level, 3) * (150 - level) / 100.0);
            }
            else if (level >= 69 && level < 99)
            {
                growthRatesData["Erratic"][level] = (int)Math.Floor(Math.Pow(level, 3) * Math.Floor((1911 - (10 * level)) / 3.0) / 500.0);
            }
            else if (level >= 99 && level <= 100)
            {
                growthRatesData["Erratic"][level] = (int)Math.Floor(Math.Pow(level, 3) * (160 - level) / 100.0);
            }
        }

        foreach (var (rateName, totalExperienceData) in growthRatesData)
        {
            Dictionary<int, int> toLevelData = new Dictionary<int, int>();
            totalExperienceData[1] = 0;
            for (int level = 1; level < 100; level++)
            {
                toLevelData[level] = totalExperienceData[level+1] - totalExperienceData[level];
            }
            GrowthRateMap.Add(rateName, new GrowthRate(rateName, toLevelData, totalExperienceData));
        }
    }
}