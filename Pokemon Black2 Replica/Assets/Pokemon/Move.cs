using Newtonsoft.Json;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class Move
{
    // Automatic Properties
    [JsonProperty("name")]
    public string Name { get; private set; }

    public Type Type { get; private set; }
    [JsonProperty("type")]
    private string TypeSetter { set { Type = Type.TypeMap[value]; } }

    [JsonProperty("damageCategory")]
    public string DamageCategory { get; private set; }

    [JsonProperty("power")]
    public int Power { get; private set; }

    [JsonProperty("accuracy")]
    public int Accuracy { get; private set; }

    [JsonProperty("PP")]
    public int PowerPoints { get; private set; }

    [JsonProperty("flinchChance")]
    public int FlinchChance { get; private set; }

        // These have yet to be implemented in the CPP-legacy so I will get back to them later
    public Dictionary<string, int> ConditionChances { get; private set; }
    public Dictionary<string, int[]> UserStageChances { get; private set; }
    public Dictionary<string, int[]> OpponentStageChances { get; private set; }
    public bool IsSpecial { get; private set; }

    // Establish Moves
    public static Dictionary<string, Move> MoveMap { get; } = new Dictionary<string, Move>();

    static Move()
    {
        string filePath = Path.Combine(Application.streamingAssetsPath, "Data", "Move.json");
        string jsonString = File.ReadAllText(filePath);

        MoveMap = JsonConvert.DeserializeObject<Dictionary<string, Move>>(jsonString);
    }
}
