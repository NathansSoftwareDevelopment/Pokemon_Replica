using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using static Utils.Logger;

public class Pokemon : MonoBehaviour
{
    // Automatic Properties
    // Most types are not yet implemented and have been substituted with strings
    public string Trainer { get; private set; }

    public string Name { get; private set; }
    public Species Species { get; private set; }

    public int Level { get; private set; }
    public int Experience { get; private set; }

    public Nature Nature { get; private set; }

    public string Ability { get; private set; }

    public string Item { get; set; }

    public Type Type1 { get; set; }
    public Type Type2 { get; set; }

    public Dictionary<int, Move> Moves { get; private set; } = new Dictionary<int, Move>();

    public string Condition { get; set; }

    public Dictionary<string, int> IndividualValues { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };
    public Dictionary<string, int> EffortValues { get; set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };

    public Dictionary<string, int> MaxStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStages { get; private set; } = new Dictionary<string, int>
    {
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0},
        {"Accuracy", 0},
        {"Evasion", 0}
    };

    public uint PersonalityValue { get; private set; }

    // Private Methods
    private void SetIndividualValues(Dictionary<string, int> inputIndividualValues)
    {
        foreach (var (StatName, StatNumber) in inputIndividualValues)
        {
            Dictionary<string, int> invalidIndividualValues = inputIndividualValues.Where(Element => !IndividualValues.ContainsKey(Element.Key) || Element.Value < 0 || Element.Value > 31).ToDictionary(Element => Element.Key, Element => Element.Value);
            if (invalidIndividualValues.Any())
            {
                string allProvidedStatsList = string.Join("\n", inputIndividualValues.Select(Element => $"\t{{{Element.Key}, {Element.Value}}}"));
                string validStatsList = string.Join("\n", IndividualValues.Keys.Select(k => $"\t{{{k}, (0-31)}}"));
                string invalidStatsList = string.Join("\n", invalidIndividualValues.Select(Element => $"\t{{{Element.Key}, {Element.Value}}}"));
                throw new ArgumentException(
                    $"Pokemon -> SetIndividualValues: Invalid stat names provided.\n" +
                    $"Valid Stats\n{{\n{validStatsList}\n}}\n" +
                    $"Provided Stats\n{{\n{allProvidedStatsList}\n}}\n" +
                    $"Invalid Stats\n{{\n{invalidStatsList}\n}}"
                );
            }
        }
        foreach (var (StatName, StatNumber) in inputIndividualValues)
        {
            {
                IndividualValues[StatName] = StatNumber;
            }
        }
    }

    private void CalculatePokemonStats()
    {
        MaxStats["HitPoints"] = (int)Math.Max(Math.Floor(((2 * Species.Stats["HitPoints"] + IndividualValues["HitPoints"] + Math.Floor(EffortValues["HitPoints"] / 4.0)) * Level) / 100) + Level + 10, 1.0);
        // Use the same formula to calculate all non-HitPoints stats;
        foreach (string statName in MaxStats.Keys.ToList())
        {
            if (statName == "HitPoints")
            {
                continue;
            }
            MaxStats[statName] = (int)Math.Max(Math.Floor(((2 * Species.Stats[statName] + IndividualValues[statName] + Math.Floor(EffortValues[statName] / 4.0)) * Level) / 100 + 5) * Nature.StatMultipliers[statName], 1.0);
        }
    }

    private void SetPokemonMoves(Dictionary<int, string> inputMoveNames)
    {
        foreach (var (MoveNumber, MoveName) in inputMoveNames)
        {
            if (MoveNumber >= 1 && MoveNumber <= 4)
            {
                Moves[MoveNumber] = Move.MoveMap[MoveName];
            }
            else
            {
                throw new ArgumentOutOfRangeException($"Pokemon -> SetPokemonMoves -> {MoveNumber} ({MoveName}) Out of Range (Valid: int 1-4)");
            }
        }
    }

    public void calculateStageChanges()
    {

    }

    // Public Methods
    public void Evolve()
    {
        Debug.Log($"{Name} is Evolving!\n {Name} Evolved from {Species.Name} to {Species.Evolution.Name}");
        int currentAbilityIndex = 0;
        foreach (var (abilityNumber, abilityName) in Species.Abilities)
        {
            if (abilityName == Ability)
            {
                currentAbilityIndex = abilityNumber;
            }
        }

        Species = Species.Evolution;
        if (currentAbilityIndex != 0) Ability = Species.Abilities[currentAbilityIndex];
        Type1 = Species.Type1;
        Type2 = Species.Type2;

        CalculatePokemonStats();
    }

    public void ChangeStages(string inputStat, int stageChange)
    {

    }

    public void AddExperience(int inputExperience)
    {
        while (Experience + inputExperience >= Species.GrowthRate.ToNextLevel[Level])
        {
            inputExperience -= (Species.GrowthRate.ToNextLevel[Level] - Experience);
            Experience = 0;
            Level += 1;
        }
        Experience += inputExperience;

        if (Level >= Species.EvolutionLevel && Species.EvolutionLevel != 0)
        {
            Evolve();
        }

        CalculatePokemonStats();
    }

    public void Initialize(
        string inputName, string inputSpecies, string inputNature = "Hardy",
        int inputLevel = 1, int inputExperience = 0, string inputAbility = null,
        Dictionary<int, string> inputMoves = null, Dictionary<string, int> inputIndividualValues = null, Dictionary<string, int> inputEffortValues = null,
        string inputCondition = null
    )
    {
        Name = inputName;
        Species = Species.SpeciesMap[inputSpecies];
        Nature = Nature.NatureMap[inputNature];
        Level = inputLevel;
        Experience = inputExperience;

        if (inputAbility != null) { Ability = inputAbility; }
        if (inputMoves != null) { SetPokemonMoves(inputMoves); }
        if (inputIndividualValues != null) { SetIndividualValues(inputIndividualValues); }
        if (inputEffortValues != null) { EffortValues = inputEffortValues; }
        if (inputCondition != null) { Condition = inputCondition; }

        Type1 = Species.Type1;
        Type2 = Species.Type2;

        PersonalityValue = (uint)UnityEngine.Random.Range(0, 4294967295);
    }


    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Initialize("Bulbyboi", "Bulbasaur");
        AddExperience(100000);
        SetPokemonMoves(new Dictionary<int, string> { { 1, "Vine Whip" }, { 2, "Leech Seed" }, { 3, "Absorb" }, { 4, "Petal Dance" } });
        Log(() => Level);
        Log(() => IndividualValues);
        Log(() => Moves);
        Log(() => Species.Moves.LevelUp, "LevelUp Moves");
        Log(() => Species.Moves.LevelUp);
        Log(() => Species.Moves.Tutor);
        Log(() => Species);
        Log(() => Type1);
        HashSet<Dictionary<string, int>> myHash = new HashSet<Dictionary<string, int>>();
        myHash.Add(new Dictionary<string, int> { { "1", 2 }, { "2", 2 } });
        myHash.Add(new Dictionary<string, int> { { "2", 2 }, { "3", 2 } });
        HashSet<int> myHash2 = new HashSet<int> { 1, 2, 3 };
        HashSet<HashSet<HashSet<int>>> HashyHashHashy = new HashSet<HashSet<HashSet<int>>>();
        HashyHashHashy.Add(new HashSet<HashSet<int>> { new HashSet<int> { 1, 2, 3 }, new HashSet<int> { 4, 5, 6 } });
        HashyHashHashy.Add(new HashSet<HashSet<int>> { new HashSet<int> { 7, 8, 9 }, new HashSet<int> { 10, 11, 12 } });
        Log(() => myHash, "HashSet of Dict<str, int>");
        Log(() => myHash2, "HashSet of int");
        Log(() => HashyHashHashy, "HashSet of HashSet<HashSet<Int>>", depth: 3);
        HashSet<int>[] intArray = new HashSet<int>[] { new HashSet<int> { 1, 2, 3 }, new HashSet<int> { 4, 5, 6 } };
        Log(() => intArray, "Array of HashSet<int>");
        HashSet<string> myNull = null;
        Log(() => myNull, "null HashSet<string>");
        int[] intArray2 = new int[] { 1, 2, 3 };
        Log(() => intArray2, "Array of int");
        (string tupleString, int tupleInt, bool tupleBool) myTuple = ("tuple", 5, true);
        //Log(() => myTuple, "Tuple of string, int, bool");
        Log(() => Name, "Pokemon Name");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
