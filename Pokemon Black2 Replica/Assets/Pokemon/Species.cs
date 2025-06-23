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

    public Species Evolution { get; private set; }
    private string EvolutionName { get; set; } = string.Empty;
    public int EvolutionLevel { get; private set; } = 0;
    [JsonProperty("evolve")]
    private Dictionary<string, object> EvolveSetter
    {
        set
        {
            EvolutionName = value["evolves-to"].ToString();
            EvolutionLevel = Convert.ToInt32(value["min-level"]);
        }
    }

    public GrowthRate GrowthRate { get; private set; }
    [JsonProperty("growth-rate")]
    private string TempGrowthRate { set { GrowthRate = GrowthRate.GrowthRateMap[value]; } }

    [JsonProperty("base-experience")]
    public int ExperienceValue { get; private set; } = 0;

    [JsonProperty("moves")]
    public LearnSet Moves { get; private set; }


    // Class for storing the Moves data
    public class LearnSet
    {
        public Dictionary<Move, int> LevelUp { get; private set; }
        [JsonProperty("level-up")]
        private Dictionary<string, int> LevelUpSetter { set { foreach (var (moveName, moveLevel) in value) { LevelUp[Move.MoveMap[moveName]] = moveLevel; } } }

        public HashSet<Move> Egg {  get; private set; }
        [JsonProperty("egg")]
        private HashSet<string> EggSetter { set { foreach (string moveName in value) Egg.Add(Move.MoveMap[moveName]); } }

        public HashSet<Move> Machine { get; private set; }
        [JsonProperty("machine")]
        private HashSet<string> MachineSetter { set { foreach (string moveName in value) Machine.Add(Move.MoveMap[moveName]); } }

        public HashSet<Move> Tutor { get; private set; }
        [JsonProperty("tutor")]
        private HashSet<string> TutorSetter { set { foreach (string moveName in value) Tutor.Add(Move.MoveMap[moveName]);  } }

        public Dictionary<Move, string> Other { get; private set; }
        [JsonProperty("other")]
        private Dictionary<string, string> OtherSetter { set { foreach (var (moveName, learnCondition) in value) { Other[Move.MoveMap[moveName]] = learnCondition; } } }

        private LearnSet()
        {
            LevelUp = new Dictionary<Move, int>();
            Egg = new HashSet<Move>();
            Machine = new HashSet<Move>();
            Tutor = new HashSet<Move>();
            Other = new Dictionary<Move, string>();
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
