using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.CompilerServices;
using UnityEngine;

public class Species
{
    // Automatic Properties
    [JsonProperty("name")]
    public string Name { get; private set; } = string.Empty;

    [JsonProperty("stats")]
    public Dictionary<string, int> Stats { get; } = new Dictionary<string, int>();

    [JsonProperty("effort-values")]
    public Dictionary<string, int> EffortValues { get; } = new Dictionary<string, int>();

    public Type Type1 { get; private set; }
    public Type Type2 { get; private set; }
    [JsonProperty("types")]
    private Dictionary<int, string> TypeSetter
    {
        set
        {
            Type1 = Type.TypeMap[value[1]];
            Type2 = Type.TypeMap[value[2]];
        }
    }

    [JsonProperty("abilities")]
    public Dictionary<int, string> Abilities { get; } = new Dictionary<int, string>();

    [JsonProperty("evolve")]
    public EvolutionData EvolveData { get; private set; }
    public Species Evolution;
    private string EvolutionName => EvolveData.EvolvesTo;
    public int EvolutionLevel => EvolveData.MinimumLevel;

    public GrowthRate GrowthRate { get; private set; }
    [JsonProperty("growth-rate")]
    private string TempGrowthRate { set { GrowthRate = GrowthRate.GrowthRateMap[value]; } }

    [JsonProperty("base-experience")]
    public int ExperienceValue { get; private set; } = 0;

    [JsonProperty("moves")]
    public LearnSet Moves { get; private set; }

    // Intermediate classes for denesting JSON data
    public class EvolutionData
    {
        [JsonProperty("evolves-to")]
        public string EvolvesTo { get; private set; } = string.Empty;

        [JsonProperty("min-level")]
        public int MinimumLevel { get; private set; } = 0;

        private EvolutionData() { }
    }

    // Struct for storing the Moves data
    public class LearnSet
    {
        [JsonProperty("level-up")]
        public Dictionary<string, int> LevelUp { get; private set; }

        [JsonProperty("egg")]
        public HashSet<string> Egg { get; private set; }

        [JsonProperty("machine")]
        public HashSet<string> Machine { get; private set; }

        [JsonProperty("tutor")]
        public HashSet<string> Tutor { get; private set; }

        [JsonProperty("other")]
        public Dictionary<string, string> Other { get; private set; }

        private LearnSet()
        {
            LevelUp = new Dictionary<string, int>();
            Egg = new HashSet<string>();
            Machine = new HashSet<string>();
            Tutor = new HashSet<string>();
            Other = new Dictionary<string, string>();
        }
    }

    // Establish Species
    public static Dictionary<string, Species> SpeciesMap { get; } = new Dictionary<string, Species>();

    static Species()
    {
        string filePath = Path.Combine(Application.streamingAssetsPath, "Data", "Species.json");
        string jsonString = File.ReadAllText(filePath);

        SpeciesMap = JsonConvert.DeserializeObject<Dictionary<string, Species>>(jsonString);

        foreach (Species species in SpeciesMap.Values)
        {
            species.Evolution = (species.EvolutionName == "Special") ? species : SpeciesMap[species.EvolutionName];
        }
    }
}
